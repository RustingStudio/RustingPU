# RPU Engineering Guide

This is the engineering reference for the RPU. It describes the active code, how the simulation is wired, and the rules that keep Rust and RTL in agreement. It started as `Hint.md` (the BF16 design) and was rewritten for the int8 design of milestone 1. The plan is `docs/plan-milestone-1.md`; measured numbers per phase are in `docs/progress.md`.

## 1. Current design

The RPU is an N x N int8 systolic array (N = 8 by default) driven from Rust through a Verilator model:

```text
Rust API (src/lib.rs)
  -> C ABI in verilated_wrapper/
  -> Verilator model of rtl/rpu_top.sv
       register file, panel buffers, load / compute / store FSMs
       rtl/rpu_sim_memory.sv   1 MB external memory model, 8*N-bit beats
       rtl/rpu_array.sv        N x N output-stationary array + input skew
         rtl/int8_cell.sv      one PE: int8 x int8 -> int32 accumulate
         rtl/delay_cell.sv     skew registers
```

The array computes an NT GEMM: `C[i][j] = sum_k A[i][k] * B[j][k]`, with A and B both N x K, 1 <= K <= KMAX (1024). Each PE holds a running int32 sum and a shadow register with the finished sum of the tile before, so one tile drains while the next streams. Larger matrices are tiled by Rust; the physical array does not grow.

`cargo test` builds the RTL with Verilator and links it into the crate. There is no FPGA driver yet (milestone 2). `rpu_sim_memory.sv` stands in for the on-chip BSRAM store.

The public API:

```rust
use rusting_pu::{Rpu, TILE};

let mut rpu = Rpu::new()?;
let c = rpu.matmul_nt_i8(&a, &b, m, n, k)?; // A m x k, B n x k, C m x n, all row-major
```

Lower-level methods:

```text
upload_b(base, b, n, k)           write B once; returns a ResidentB handle
matmul_resident(a, m, &b, scratch) GEMM against a resident B; A and C go from `scratch`
run_tile_i8(a, b)                 one N x N x N tile
run_panel_i8(a, b, k)             one N x k x N panel job
preload_panel_i8(bank, a, b, k)   load A and B into a local bank, return when loaded
start(bank) / read_c(bank)
cycles()                          busy cycles since the last START
active_cycles() / busy_cycles()   free-running counters since reset
host_words_written() / _read()    host bus traffic since new (reads: memory only)
busy() / done() / load_busy() / compute_busy() / status()
```

`src/quant.rs` holds the host side of the int8 contract: symmetric per-row quantization, the reference `matmul_nt_i8`, and dequantization. Every RTL result is compared with `==` against it.

## 2. Build and test

Tools: `rustc`/`cargo`, Verilator (5.052 is tested), Icarus (`iverilog`, `vvp`) for the smoke test, and yosys for the resource checks.

```bash
cargo build
cargo test --release
cargo fmt --all --check
cargo clippy --all-targets -- -D warnings
cargo run --release                     # one tile, checked against the host reference
cargo run --release --example baseline  # cycle counts, see docs/progress.md
```

Build-time parameters are environment variables read by `build.rs`:

```bash
RPU_N=16 cargo test --release            # array size (default 8)
RPU_READ_LATENCY=10 cargo test --release # memory read latency in cycles (default 1)
```

They become `-GN` / `-GREAD_LATENCY` for Verilator and are re-exported to Rust, so `TILE` always equals the RTL `N`. `build.rs` clears the Verilator `obj_dir` before each run; stale generated files from another N do not compile.

Icarus smoke test of the array alone (N = 4):

```bash
iverilog -g2012 -o tpu_sim rtl/delay_cell.sv rtl/int8_cell.sv rtl/rpu_array.sv sim/tb_tpu.sv
vvp -n tpu_sim   # prints PASS: 4x4 int8 tile bit-exact
```

Lint:

```bash
verilator --lint-only -Wall -GN=8 --top-module rpu_top \
  rtl/int8_cell.sv rtl/delay_cell.sv rtl/rpu_array.sv rtl/rpu_sim_memory.sv rtl/rpu_top.sv
```

Simulated cycles are RTL cycles, not wall-clock time. The Verilator run time says nothing about FPGA speed.

## 3. Register and memory protocol

The top-level host port is a synchronous memory-mapped bus with 32-bit word addresses and 64-bit data: `mem_we`, `mem_addr`, `mem_wdata`, `mem_rdata`. A write happens on the clock edge with `mem_we` high (so each host write costs one cycle in simulation). Reads are combinational.

### Register map

| Word address | Name | Write | Read |
|---:|---|---|---|
| 0 | CONTROL | command bits | 0 |
| 1 | STATUS | ignored | status bits |
| 2 | A_BASE | A panel beat address | A_BASE |
| 3 | B_BASE | B panel beat address | B_BASE |
| 4 | C_BASE | C tile beat address | C_BASE |
| 5 | K_LEN | K of the next load (reset value N) | K_LEN |
| 6 | ACTIVE | ignored | cycles the array streamed since reset |
| 7 | BUSY | ignored | cycles busy (load, compute or store) since reset |
| `0x1000_0000 + w` | memory | 64-bit word w | 64-bit word w |

### CONTROL bits

```text
bit 0 START    compute on the selected banks; if the B bank is not loaded, load first
bit 1 BANK     local B bank 0 or 1
bit 2 PRELOAD  load into the selected banks; may overlap a compute on the other banks
bit 3 KEEP_A   the load fetches only B; the A banks keep their contents
bit 4 A_BANK   local A bank 0 or 1: the bank a load fills and a compute reads
```

There are two local A buffers and two local B buffers. A B bank is marked valid when its load ends; the A banks are not tracked. **Never load A into the A bank of a running compute** (a load without KEEP_A and with the same A_BANK): it overwrites the A the compute is reading. `preload_panel_i8` and `start` use the same number for both banks.

Each panel row keeps both A banks in one memory, A bank 1 from beat `ROW_BEATS`. The A read address is one register (`stream_a_addr`), so yosys folds it into a synchronous BSRAM read port. An address made of two registers with different enables (`{bank, beat}`) is not folded and the memory goes to LUT RAM; the B panels are mapped that way today (see `docs/perf-log.md`, item 3).

### STATUS bits

```text
bit 0 BUSY            load, compute, drain or store running
bit 1 DONE            compute finished, drained and C stored
bit 2 LOAD_BUSY
bit 3 COMPUTE_BUSY    CLEAR or STREAM; the settle and drain after it do not count
bit 4 LOCAL_VALID_0   bank 0 loaded and not yet computed
bit 5 LOCAL_VALID_1
bit 6 STORE_BUSY      C store running (overlaps the next compute)
```

### Memory layout

Memory moves 8*N-bit beats (N int8 values in N/8 host words rounded up, lowest word first; when N is not a multiple of 8, the top bytes of a beat's last word are padding). Base registers hold beat addresses.

- A and B panels: N rows one after the other. Each row is padded to `ceil(K/N)` beats, with k = 0 in the lowest byte.
- C tile: row-major int32, 4 beats per row (two int32 per host word, low half first).

Rust decides where operands live. `preload_panel_i8` uses a fixed per-bank layout (A, B, C of each bank). `matmul_nt_i8` writes B (all its tiles) from beat 0, then calls `matmul_resident` with the scratch area right after B: all A blocks, then a C area with one tile per output tile. `RpuMlp` uploads each layer's weights once, back to back from beat 0, and puts the scratch area after the last layer; each batch writes only its activations. A `ResidentB` remembers which `Rpu` it was uploaded to, and `matmul_resident` panics if the scratch area overlaps B.

### State machines

```text
load (issue and receive sides, one beat per cycle):
  A rows (unless KEEP_A) into A bank A_BANK, then B rows into B bank BANK; the
  B bank is marked valid at the end,
  or the compute starts if the load came from START

compute:
  IDLE -> CLEAR   set up the stream; wait while the drain of the tile before
                  could still overwrite this tile's sums (see below)
       -> STREAM  K cycles, one k per cycle from the local panels; the last k
                  carries the last flag
       -> FINISH  (the next START is accepted from here)

drain (separate, starts when a STREAM ends):
  IDLE -> SETTLE  2N - 2 + PE_LATENCY cycles until the last sum lands in the
                  shadow registers, then wait for the C store of the tile before
       -> SHIFT   N cycles, the shadows shift one row down per cycle into mem_c
       -> IDLE

store (separate, starts when SHIFT ends):
  4N beats, one per cycle; the memory never stalls a write
```

## 4. Systolic dataflow

During stream cycle k, row i of the array gets `A[i][k]` and column j gets `B[j][k]`. `rpu_array.sv` skews row i and column j by i and j cycles so matching values meet at PE (i, j).

Each `int8_cell` is two stages (`PE_LATENCY = 2`):

```text
product      <= a_in * b_in                (int16)
last_product <= last_in
sum          <= last_product ? 0 : sum + sign_extend(product)
accumulator  <= drain ? acc_in                                  (the shadow)
              : last_product ? sum + sign_extend(product) : accumulator
a_out <= a_in;  b_out <= b_in;  last_out <= last_in
```

The last flag enters with the last k of a tile and goes through the same skew as row i of A, so it reaches each PE with that PE's last product. The PE then moves the finished sum into the shadow register and restarts its running sum at zero, and the next tile's first product can arrive the cycle after. Outside STREAM the array gets zeros, so the running sums stay zero between tiles; the array is reset only with the RPU.

The settle time `2N - 2 + PE_LATENCY` is exact: one cycle shorter loses the last sum of PE (N-1, N-1). The tests include a case where only the last k is nonzero to catch that. During SHIFT each shadow loads the shadow of the PE above, so the bottom row `c_row` delivers C row N-1, then N-2, ..., one per cycle.

A STREAM may start while the drain before is pending only if its K is at least `OVERLAP_K_MIN = SETTLE_STEPS + N` (3N) and no C store is running (a running store could delay the drain). Otherwise CLEAR waits until the drain is done. The drain shifts must end before PE (0, 0) takes the new tile's sum, K + 1 cycles after the new stream starts. A STREAM starts at the earliest 3 cycles after the one before ends (FINISH, then CLEAR), so 3N - 2 would be enough; a host that polls COMPUTE_BUSY starts one cycle later. `start_right_after_stream_end` runs that case and fails once the threshold is 3N - 4.

## 5. File overview

- `Cargo.toml`: crate `rusting_pu`, build dependency `cc`. The optional `brain` feature adds `rusting_brain` (crates.io); the default build has no runtime dependency.
- `build.rs`: runs Verilator on the five active RTL files with `rpu_top` as top, compiles the generated C++ and the wrapper. Update its file list when RTL files change.
- `src/lib.rs`: FFI, `Rpu`, memory packing, the GEMM scheduler and the hardware tests.
- `src/quant.rs`: quantization and the reference int8 GEMM.
- `src/brain.rs` (feature `brain`): `RpuMlp`, a RustingBrain dense network with int8 weights; `predict_batch` runs the matmuls on the RPU, `predict_batch_host` on the host reference.
- `src/main.rs`: one-tile demo. `examples/baseline.rs`: cycle counts. `examples/mnist.rs` (feature `brain`): MNIST end to end, see `docs/m1-results.md`.
- `verilated_wrapper/`: the C ABI (`rpu_new/free/reset/tick/cycles/write/read/busy/done`). Keep Verilator types out of Rust. When top-level ports change, update the wrapper and the Rust FFI together.
- `rtl/`: the five active files above. `sim/tb_tpu.sv`: Icarus smoke test. The old BF16 and integer experiments were deleted in phase 10; git history keeps them.

## 6. Int8 contract

- Inputs are int8 in [-127, 127] (symmetric quantization never produces -128; the RTL handles -128 too).
- Products are int16, accumulators int32. K = 1024 at 127 * 127 is 16,516,096, far from overflow.
- The RTL result must equal `quant::matmul_nt_i8` exactly. Use `==`, never a tolerance.
- Weights get one symmetric scale per output row (per row of B), the RustingBrain rule. Activations get one scale for the whole batch. Dequantization is host-side.

## 7. Changing N

N is one build parameter: `RPU_N`. It does not need to be a multiple of 8 or a power of 2: a beat that does not fill its last 64-bit host word is padded in memory. Tests pass at N = 4, 8, 12, 16 and 24. Resources grow with N^2 (see `docs/resources.md`); at N = 16 the LUT-only mapping is too large for the GW5AT-LV60, so N = 16 needs DSPs.

When Verilator reports width warnings after a change, size the counter and its terminal constant with the same `$clog2` width and cast explicitly. Do not disable width warnings globally.

## 8. Scheduling larger matrices

`matmul_nt_i8` keeps the array streaming:

```text
write A blocks into memory (B is already resident; host writes are slow: do them first)
tile t = (row block r, B tile j), on B bank t % 2 and A bank r % 2
START tile 0                          (loads A0 + B0, then computes)
for each tile t:
  if tile t+1 is in the same row block: preload B(j+1) with KEEP_A
  else:                                 preload A(r+1) + B0 into the other A bank
  (either preload overlaps compute t)
  wait until the stream of t and the preload are done
  (the settle, drain and store of t overlap the stream of t+1)
  START tile t+1
wait for DONE, read all C tiles
```

Layer 1 of the MLP for batch 8 (8x784 x 784x128) streams 87.97% of its busy cycles at N = 8. The overhead is the first A + B load (1569 cycles), about 6 cycles per tile (the B preload's read latency and the host handshake) and the settle, drain and store of the last tile. With more than one row block, only the first block's A + B load is exposed in full; the next block's A + B load (2K cycles) overlaps the last tile of the block before (K cycles), so about K cycles per later block stay exposed. One read port moves one beat per cycle, so a B load already takes as long as a tile's stream: the A load cannot hide completely.

K must fit in one panel (K <= KMAX). Partial sums over K are not split across jobs.

## 9. Common problems

- `Invalid module instantiation` near an instance name: the name is a SystemVerilog keyword. Use `pe_cell`, not `cell`.
- Wrong results only for some K or N: check the settle time and the beat/lane counters first. A one-cycle-short settle loses the last product.
- Verilator `SELRANGE` on a part-select of a 2-D packed array: copy the row into a flat `logic [W-1:0]` first, then part-select.
- Yosys has no slang plugin here: use packed array ports.
- Icarus cannot index packed arrays with a non-constant loop variable: use a flat bit view.
- A rebuild with a different `RPU_N` fails in generated C++: `build.rs` clears `obj_dir`; if it still fails, `cargo clean`.

## 10. Development order

1. Keep every bit-exact test passing at N = 8 and N = 16, and at READ_LATENCY 1 and 10.
2. Change one RTL behaviour at a time.
3. Add a Rust test that compares with `==` against the host reference, and check that it fails when the change is broken (mutation).
4. Run fmt, clippy, `cargo test --release`, the lint and the Icarus smoke test.
5. Record measured cycles in `docs/progress.md`. If a number contradicts the plan, record the real number and its cause.

The key invariant: the Rust packing, the register protocol and the RTL memory layout must agree. If they disagree, the RPU produces plausible but wrong matrices.
