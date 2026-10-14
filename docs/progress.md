# Milestone 1 progress

Spec: `docs/plan-milestone-1.md`, section 3. One entry per phase or sub-step.

## Phase 0: build hygiene. Done, 2026-10-14
- `build.rs` passes `-Mdir $OUT_DIR/obj_dir` to Verilator. The root `obj_dir/` is deleted.
- Fixed existing clippy errors (3x `div_ceil`, test module not last).
- Added `examples/baseline.rs`; numbers in `docs/baseline.md`.
- Check: fmt, clippy `-D warnings`, `cargo test --release` (4 passed) all clean in the working tree. Icarus smoke test runs.
- Baseline: load A+B **384** cycles, compute+store C **217** cycles.
- Commit: see `git log` (phase 0 commit).

## Questions for owner
