# Milestone 1 progress

Spec: `docs/plan-milestone-1.md`, section 3. One entry per phase or sub-step.

## Phase 0: build hygiene. Done, 2026-10-14
- `build.rs` passes `-Mdir $OUT_DIR/obj_dir` to Verilator. The root `obj_dir/` is deleted.
- Fixed existing clippy errors (3x `div_ceil`, test module not last).
- Added `examples/baseline.rs`; numbers in `docs/baseline.md`.
- Check: fmt, clippy `-D warnings`, `cargo test --release` (4 passed) all clean in the working tree. Icarus smoke test runs.
- Baseline: load A+B **384** cycles, compute+store C **217** cycles.
- Commit: `823684d`.

## Phase 1: host int8 reference. Done, 2026-10-14
- `src/quant.rs`: `quantize_rows` (per-row, RustingBrain rule), `quantize_tensor` (one scale per batch), `matmul_nt_i8` (NT GEMM, exact i32), `dequantize`. Test-only `XorShift` PRNG (no `rand` dependency).
- Check: i32 matmul == naive i64 sum for (1,1,1), (8,8,8), (3,5,7), (8,16,784), (9,10,1024); all -127 at K=1024 = 16,516,096 exact; quantize-then-dequantize error <= scale/2 for per-row and per-tensor. 10 tests pass, fmt and clippy clean. No RTL change.

## Phase 2: bit-exact harness first. Done, 2026-10-14
- `Rpu::run_tile_i8(a, b) -> Vec<i32>` with the phase 3 bus layout: two int8 per 16-bit word, C as lo/hi 16-bit words. NT semantics, same as `quant::matmul_nt_i8`.
- Tests `int8_edge_tiles_are_bit_exact` (0, 127, -127, mixed signs, ramp) and `int8_random_tiles_are_bit_exact` (1000 seeded tiles, -127/0/127 forced 3/16 of the time). Both compare with `==`.
- They are `#[ignore]` so the full check stays green. Check: `cargo test --release -- --ignored` runs both and **both fail** against the BF16 RTL (first mismatch: all-127 tile). Normal test run: 10 passed, 2 ignored.
- Commit: `816fcf4`.

## Phase 3: INT8 PE and array. Done, 2026-10-14
- `rtl/int8_cell.sv`: 2-stage PE (registered `a*b`, then `acc + p`). `rtl/rpu_array.sv` (was `rpu_orchestrator_bf16.sv`): int8 array with packed ports (Yosys does not take unpacked array ports). `rtl/rpu_top.sv` (was `rpu_bf16_soc.sv`): int8 A/B buffers (two int8 per 16-bit word), 32-bit `mem_c`, C stored as lo/hi words, NT stream order for B. `delay_cell` has a width parameter.
- Drain is `2N - 2 + PE_LATENCY` = 16 cycles at N=8, exact: with one cycle less, both bit-exact tests fail (checked by mutation).
- `build.rs` compiles only `delay_cell`, `int8_cell`, `rpu_array`, `rpu_sim_memory`, `rpu_top`. All BF16 Rust API removed; `Rpu::run_tile_i8`, `preload_tile_i8`, `start`, `read_c` remain.
- `sim/tb_tpu.sv` is now a self-checking int8 array test (N=4, includes -127 x -127). Run:
  `iverilog -g2012 -o tpu_sim rtl/delay_cell.sv rtl/int8_cell.sv rtl/rpu_array.sv sim/tb_tpu.sv && vvp -n tpu_sim` prints `PASS: 4x4 int8 tile bit-exact`. With the drain wait 2 cycles short it fails.
- Check: 1000 random tiles + edge tiles bit-exact (`==`). 10 tests pass. fmt, clippy clean.
- Cycles (`examples/baseline.rs`): load A+B **192** (64 words x 3), compute+store **409** (clear 1 + stream 8 + drain 16 + store 128 words x 3).
- Synthesis (yosys `synth_gowin`, `docs/resources.md`): gw5a LUT-only N=8 24,258 LUT+ALU, N=16 97,056 (162% of GW5AT-LV60, so N=16 needs DSPs); gw2a N=8 64 MULT9X9 + 2,048 ALU + 0 LUT, N=16 256 MULT9X9 + 8,192 ALU. GW5A DSP count deferred to milestone 2 (Gowin EDA not installed).
- Commit: `f35f1d0`.

## Phase 4: shift drain. Done, 2026-10-14
- `int8_cell` has `drain` and `acc_in`: with `drain` high the accumulator loads its left neighbour. `rpu_array` outputs only the right column (`c_col`); column 0 shifts in zero.
- `rpu_top`: `COMPUTE_SETTLE` waits `2N - 2 + PE_LATENCY` (16) cycles for the last product, then `COMPUTE_DRAIN` shifts N (8) cycles and writes one `N*32`-bit word per cycle into `mem_c[col]`. The store reads it with row/col/half counters (no power-of-2 assumption on N).
- Check: 1000 random tiles + edge tiles bit-exact (`==`), 10 tests pass, fmt and clippy clean. Icarus `tb_tpu.sv` (now drives `drain` and collects `c_col` over N cycles): PASS.
- Cycles (`examples/baseline.rs`): load A+B 192, compute+store **417** (clear 1 + stream 8 + settle 16 + drain 8 + store 384). The compute part is 33 cycles, up from 25: the old drain copied all of C in one cycle, the shift takes N cycles. That is the plan's 1 + 8 + skew + 8 with skew = 16.
- Mux check (yosys `proc; opt; memory -nomap; opt` on `rpu_top`): before, yosys printed "Replacing memory \mem_c with list of registers" (64 x 32-bit registers, 64:1 read mux). Now `mem_c` is one `$mem_v2`, 8 x 256 bit, 1 write port, 1 read port. No register-mapped `mem_c`.
- Commit: `d12ddb1`.

## Phase 5: K streaming. Done, 2026-10-14
- `rpu_top` has `KMAX = 1024` and new registers: `K_LEN` (5, reset value N), `ACTIVE_LO/HI` (6/7, cycles the array streams), `BUSY_LO/HI` (8/9, cycles busy). Both counters run free from reset; the host takes differences.
- The local A and B panels are one memory per array row, `[bank][KMAX/2]` x 16 bit. Yosys sees 16 memories with 1 write and 1 read port each (was 2 memories with 8 read ports). Each bank remembers the K_LEN it was loaded with, so a preload with another K can overlap a compute.
- External layout per bank: A panel, B panel (`N * KMAX/2` words each), C tile. Each row is packed on its own and padded to an even k, so odd K works on the 16-bit bus. Bank 1 now starts at `0x1000 + 8320`.
- Rust: `run_panel_i8(a, b, k)`, `preload_panel_i8(bank, a, b, k)`, `active_cycles()`, `busy_cycles()`. `run_tile_i8` is `run_panel_i8` with k = N.
- Check: bit-exact (`==`) for K in {1, 7, 8, 9} (20 random panels each), 64 (10), 784 and 1024 (3 each), and all -127 at K=1024 (16,516,096 per PE). Each job adds exactly K to `active_cycles`. 12 tests pass, fmt and clippy clean, Icarus PASS.
- Cycles (`examples/baseline.rs`): 8x784 x 784x8 compute **809 = 784 + 25** (clear 1 + settle 16 + drain 8), store C 384, total 1193. The plan said 784 + ~24.
- Commit: `6fcf3ab`.

## Phase 6: wide pipelined memory. Done, 2026-10-14
- `rpu_sim_memory`: 1 MB in `8*N`-bit beats, one read request per cycle, data `READ_LATENCY` cycles later (`rd_resp_valid`), one write beat per cycle with no stall. The host port moves 64-bit words, N/8 per beat. It requires N to be a multiple of 8 (64-bit host words), not a power of 2.
- Host bus and ABI: 32-bit address, 64-bit data. Registers 0-7 (`CONTROL, STATUS, A_BASE, B_BASE, C_BASE, K_LEN, ACTIVE, BUSY`); memory word w is at `0x1000_0000 + w`. Base registers are beat addresses. The two external banks are gone: one flat memory, and Rust puts each local bank's A, B and C at its own addresses.
- Load: an issue side requests one beat per cycle (A rows, then B rows, each row padded to whole beats); a receive side writes each response into the per-row panel buffer (`8*N` bits wide, 1 write and 1 read port). Stream reads lane `k mod N` of beat `k / N` with counters, no division.
- The drain now shifts rows down (was columns right), so `mem_c[row]` holds a C row and the store writes it as 4 beats, one per cycle. C store at N=8: 32 cycles (was 384).
- `build.rs`: `RPU_N` (default 8) and `RPU_READ_LATENCY` (default 1) set `-GN` and `-GREAD_LATENCY`; Rust `TILE` comes from `RPU_N`. The Verilator `obj_dir` is now cleared before each run: a rebuild with N=24 left `Vrpu_top___024root__1.cpp`, which the N=8 build then compiled and failed on.
- Check: all 13 tests bit-exact (`==`) with READ_LATENCY 1 and 10, at N=8 and N=16; also at N=24 (latency 1). New test `panel_load_moves_one_beat_per_cycle`: preload busy cycles = `2 * N * ceil(K/N) + READ_LATENCY` for K in {1, 9, 784}. Verilator `--lint-only -Wall` clean at N=8, 16, 24. fmt, clippy clean, Icarus PASS.
- Cycles (`examples/baseline.rs`, N=8): K=784 load A+B **1569** at latency 1 and **1578** at latency 10, that is 784 beats per panel + latency. Compute 809, store 32. N=16: load 1569, compute 833, store 64.

## Questions for owner
