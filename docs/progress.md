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

## Questions for owner
