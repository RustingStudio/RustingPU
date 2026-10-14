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
- Commit: `11fdf7f`.

## Phase 7: overlap and reuse. Done, 2026-10-14
- `rpu_top`: one local A panel buffer, two B panel buffers (CONTROL bit 1 picks the B bank). New CONTROL bit 3 `KEEP_A`: a load with it fetches only B, so A stays valid across output tiles. The host must not load a new A while a compute runs. Yosys: 8 `row_a` memories (128 x 64 bit) and 8 `row_b` memories (256 x 64 bit), each 1 write and 1 read port.
- The C store is its own FSM (`store_busy`, STATUS bit 6), so it overlaps the next compute. The next drain waits in SETTLE until the store is done, because it overwrites `mem_c`. `done` = compute finished and store done; `busy` includes the store.
- Rust `matmul_nt_i8(a, b, m, n, k)`: any m, n (padded to TILE), 1 <= k <= KMAX. It writes A, all B tiles and the C area into memory first (host writes take a cycle each, so writing B during a compute would stall it). Per block of TILE rows of A: START tile 0 (loads A + B), then for each tile it preloads the next B with `KEEP_A` into the other bank, waits for compute and load to finish, and STARTs the next one. All C tiles are read at the end.
- Check: layer 1 for batch 8 (8x784 x 784x128, random int8) bit-exact (`==`). **active/busy = 12544 / 14575 = 86.07%** at N=8, latency 1 (86.01% at latency 10, busy 14584). Plan target >= 85%: met. Cycles: A+B load 1569 + 16 tiles x 809 compute + 15 x 2 cycles between tiles (CONTROL write, then CLEAR) + last store 32 = 14575.
- N=16: active/busy = 6272 / 8311 = **75.47%** (75.38% at latency 10). Below 85% because the 1569-cycle first load is spread over only 8 tiles, and the per-tile overhead is 49 cycles (clear 1 + settle 30 + drain 16 + 2). The test asserts the 85% only at N=8.
- New test `gemm_with_ragged_shapes_is_bit_exact`: shapes (1,1,1), (N,N,N), (3, 2N+5, 9), (2N+1, 3N, 40), and (N, 4N, 1). With K=1 the store is longer than the compute. Removing the SETTLE wait for the store makes this test fail (mutation checked).
- `preload_overlaps_active_compute` now preloads with `KEEP_A` and writes bank 1's data before START. At N=16 the 64 host-write cycles were longer than the 63-cycle compute, so the test failed once the store left `compute_busy`.
- 15 tests pass at N=8 (latency 1 and 10), N=16 (latency 1 and 10) and N=24. fmt and clippy clean, Icarus PASS. Correction to phase 6: `verilator --lint-only -Wall` was not clean. It flagged `wire_b[N]` as unused (B leaves the bottom row unused). Now silenced with a lint pragma; clean at N=8, 16, 24.
- `examples/baseline.rs` prints the layer 1 line.

## Phase 8: `brain` feature. Done, 2026-10-14
- `rusting_brain = "4"` (crates.io) is an optional dependency behind the `brain` feature (owner approved Q3). The default build has no runtime dependency.
- `src/brain.rs`: `RpuMlp::from_network` quantizes each layer's `[out, in]` weights once, per output row, with the `quant.rs` rule. `predict_batch(&mut rpu, inputs)` runs every matmul on the RPU through `Rpu::matmul_nt_i8`; `predict_batch_host(inputs)` runs the same steps with `quant::matmul_nt_i8`. Both share one forward: one activation scale per batch, dequantize `acc * w_scale[row] * x_scale`, bias, activation (ReLU, softmax) on the host.
- Check: 64 random inputs through a seeded 784-128-10 network (ReLU, softmax) give outputs equal with `==` on the RPU and host int8 paths, at N = 8 and N = 16. Mutation: adding 1 to the last RPU accumulator fails the test.
- Sanity against f32 (untrained network, inputs in [0, 1)): argmax agrees on 63/64, max probability difference 0.0013.
- `data/` (the MNIST download for phase 9) is gitignored.

## Phase 9: MNIST end to end. Done, 2026-10-14
- `examples/mnist.rs` (needs `--features brain`): trains 784-128-10 with RustingBrain on the CPU (3 epochs, Adam, seeded, 20 s), saves `data/mnist/mnist-784-128-10.json`, and evaluates the 10k test images in f32, host int8 and on the RPU in batches of 64.
- N = 8: 97.26% on all three paths, 1890.6 cycles per image, 84.63% utilization. N = 16 (same JSON): 97.26% on all three, 545.0 cycles per image, 73.39%. RPU outputs equal host int8 with `==` for every batch. f32 minus int8 is 0.00 pp.
- Contradiction with the plan: N = 16 is 545 cycles per image, not ~430. The plan's N = 16 estimate leaves out the unoverlapped A + first B load of each row block (1824 cycles per block, 114 per image). Details and the N = 8 breakdown are in `docs/m1-results.md`.
- Training is reproducible: a second run from scratch wrote a byte-identical JSON.

## Phase 10: org readiness. Done, 2026-10-14
- Dead RTL deleted (Q5): `bf16_adder`, `bf16_multiplier`, `bf16_systolic_cell`, `dma_streamer`, `rpu_core_2x2/3x3/NxN`, `rpu_orchestrator`, `rpu_orchestrator_3x3/NxN`, `rpu_soc`, `sram`, `systolic_cell`, and testbenches `tb_orch_3x3`, `tb_orchestrator`, `tb_rpu`, `tb_soc`. None were in `build.rs` or the Icarus smoke test. Left: 5 RTL files and `sim/tb_tpu.sv`.
- Crate renamed `hardware_dev` to `rusting_pu` (Q7). The directory is not renamed.
- `docs/engineering.md` tracked (Q6). Hint.md is left as it is. The guide keeps Hint.md's sections, but Hint.md describes the deleted BF16 design (`rpu_bf16_soc.sv`, 16-bit bus, BF16 contract). So each section was rewritten for the current int8 design and is not a verbatim copy.
- README written from the section 5 outline. Every number in it is copied from `docs/m1-results.md`. `docs/engineering.md` now lists `src/brain.rs`, `examples/mnist.rs` and the `brain` feature.
- Check: 15 tests pass, fmt and clippy clean, Icarus PASS, lint clean at N=8, 16, 24. A fresh `git clone --branch milestone-1` passes `cargo test --release` (15 tests) and `cargo test --release --features brain` (16 tests), checked again after the README commit; the clone has no `data/`.

## Questions for owner
None open. Q3 answered 2026-10-14: `rusting_brain` from crates.io, approved. Q4 answered 2026-10-14: download a dataset; MNIST is in the gitignored `data/mnist/`.
