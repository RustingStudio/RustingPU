# Baseline (BF16 RTL, before milestone 1 changes)

Measured 2026-10-14 with `cargo run --release --example baseline` on branch `milestone-1`, Verilator 5.052.
One 8x8 tile job, cycle counts from `Rpu::cycles()`.

| Step | Cycles |
|---|---|
| Load A+B (128 16-bit words, 3 cycles per word) | 384 |
| Compute + store C (clear 1 + stream 8 + drain 16 + store 64 x 3) | 217 |

These match plan section 1.
