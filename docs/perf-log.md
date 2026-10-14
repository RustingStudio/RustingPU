# Performance log

Loop: `loop-prompts/rpu-perf.md`, branch `rpu-perf` (from `milestone-1` at `924f884`). Every row is measured with `examples/mnist.rs` on the 10k MNIST test images, using the same trained network (`data/mnist/mnist-784-128-10.json`, MD5 `82d91856abb13afa577d5e0b28fa1756`), batch 64, memory read latency 1. Host-link words are 64-bit words per image: written counts every host bus write (memory and registers), read counts memory words only (status and counter polls are left out, because how often a real host polls depends on the transport).

## Summary

| Item | N | Accuracy (RPU = host int8) | Cycles per image | Utilization | Words written / read per image | Wall time |
|---|---:|---:|---:|---:|---:|---:|
| baseline (`924f884`) | 8 | 97.26% | 1890.6 | 84.63% | 324.0 / 72.0 | 15.4 s |
| baseline (`924f884`) | 16 | 97.26% | 545.0 | 73.39% | 317.2 / 72.0 | 22.8 s |
| 2 resident weights | 8 | 97.26% | 1890.6 | 84.63% | 124.3 / 72.0 | 14.2 s |
| 2 resident weights | 16 | 97.26% | 545.0 | 73.39% | 117.6 / 72.0 | 17.6 s |

## Item 1: host-link counter. Done, 2026-10-14
- `Rpu::host_words_written()` and `Rpu::host_words_read()`; the MNIST example prints both per image. No behaviour change: cycles and accuracy are as in `docs/m1-results.md`.
- Test `host_word_counters_count_bus_traffic`: a K = N preload writes exactly 2 x N x N/8 memory words plus 5 register writes, and `read_c` reads exactly 4N x N/8 words.
- Breakdown at N = 8, per image: the activations are 98 words (layer 1) + 16 (layer 2); the weights, written again for every batch of 64, are 196 + 4 words; the rest (about 10) are register writes. Reads are the int32 C tiles: 64 words (128 outputs) + 8 (10 outputs padded to 16).
- So **61% of the written words are weights rewritten on every batch**. That is item 2.
- Load during the measurement: `uptime` 3.63.
- Commit: `b047b15`.

## Item 2: resident weights. Done, 2026-10-14
- `Rpu::upload_b(base, b, n, k)` writes B once and returns a `ResidentB`; `Rpu::matmul_resident(a, m, &b, scratch)` runs the GEMM against it and writes only A. `matmul_nt_i8` is now `upload_b` at beat 0 plus `matmul_resident`, so its schedule and cycles are unchanged. `RpuMlp::predict_batch` (now `&mut self`) uploads every layer's weights on the first call and again only for a different `Rpu`.
- Words written per image: 324.0 to 124.3 at N = 8 (-62%), 317.2 to 117.6 at N = 16 (-63%). The one-time upload is in these numbers, spread over the 10k images (about 1.3 words per image). Reads and cycles are unchanged, as expected.
- What is left per image at N = 8: 114 words of activations, about 10 register writes, and 72 words of int32 C read back. Most of what remains crosses the link because the host does dequantization, bias and ReLU between the layers (item 7, needs P1).
- Tests: `resident_b_serves_many_a_and_any_placement` (B before and after the scratch area, three m values, one upload), `resident_b_rejects_overlapping_scratch`, and the MLP test now runs a second batch on the same RPU (checks that fewer words than the layer 1 weights are written) and a third on a new RPU. Mutations: uploading on every call fails the word check; never re-uploading for a new RPU fails the `ResidentB` owner check. All pass at N = 8 and 16, READ_LATENCY 1 and 10.
- Load: `uptime` 2.27.
