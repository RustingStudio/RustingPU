# Performance log

Loop: `loop-prompts/rpu-perf.md`, branch `rpu-perf` (from `milestone-1` at `924f884`). Every row is measured with `examples/mnist.rs` on the 10k MNIST test images, using the same trained network (`data/mnist/mnist-784-128-10.json`, MD5 `82d91856abb13afa577d5e0b28fa1756`), batch 64, memory read latency 1. Host-link words are 64-bit words per image: written counts every host bus write (memory and registers), read counts memory words only (status and counter polls are left out, because how often a real host polls depends on the transport).

## Summary

| Item | N | Accuracy (RPU = host int8) | Cycles per image | Utilization | Words written / read per image | Wall time |
|---|---:|---:|---:|---:|---:|---:|
| baseline (`924f884`) | 8 | 97.26% | 1890.6 | 84.63% | 324.0 / 72.0 | 15.4 s |
| baseline (`924f884`) | 16 | 97.26% | 545.0 | 73.39% | 317.2 / 72.0 | 22.8 s |
| 2 resident weights | 8 | 97.26% | 1890.6 | 84.63% | 124.3 / 72.0 | 14.2 s |
| 2 resident weights | 16 | 97.26% | 545.0 | 73.39% | 117.6 / 72.0 | 17.6 s |
| 3 second A buffer | 8 | 97.26% | 1785.2 | 89.62% | 124.5 / 72.0 | 13.7 s |
| 3 second A buffer | 16 | 97.26% | 497.7 | 80.37% | 117.7 / 72.0 | 16.7 s |
| 4 N = 12 | 12 | 97.26% | 963.1 | 85.24% | 179.8 / 108.1 | 8.0 s |

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
- Commit: `2473f2d`.

## Item 3: second A buffer. Done, 2026-10-14
- RTL: two local A banks, selected by the new CONTROL bit 4 (A_BANK); a load fills A bank A_BANK, a compute reads the A bank given with its START (or with the load that START triggered). `matmul_resident` numbers its tiles t = (row block r, B tile j) and uses B bank t % 2 and A bank r % 2; the preload during the last tile of a row block is A(r + 1) + B0 into the other banks instead of nothing. `preload_panel_i8` and `start` use the same number for the A and B bank, so the low-level double buffering now covers A too.
- Cycles per image: 1890.6 to 1785.2 at N = 8 (-5.6%), 545.0 to 497.7 at N = 16 (-8.7%). Utilization 84.63% to 89.62% and 73.39% to 80.37%. Predictions are unchanged and equal to host int8 for every image.
- The backlog expected about 1660 and 430. Those numbers assumed the whole A + B load of every row block (1824 / N cycles per image) disappears. Two things keep part of it:
  - The first row block of each layer in each batch still loads with nothing to overlap (the host works between layers): 1 of 8 blocks at N = 8, 1 of 4 at N = 16 (batch 64).
  - The next block's A + B load (2K beats) overlaps only the last tile of the block before (K + clear, settle and drain cycles). The read port moves one beat per cycle, so every B preload already takes as long as a tile's stream; there is no idle port time to hide the rest of A. About K - 25 (N = 8) or K - 50 (N = 16) cycles per later block stay exposed.
  - This model predicts 1785 and 498, as measured. Hiding the rest needs more read bandwidth (two beats per cycle for loads) or fewer loads (for example, batching the layers so A stays longer); neither is in this item.
- Host words written per image: 124.3 to 124.5 and 117.6 to 117.7 (one more A_BASE write per row block). Reads unchanged.
- Synthesis, `rpu_top` with `rpu_sim_memory` as a black box (`read_verilog -sv -lib rtl/rpu_sim_memory.sv`, then `chparam -set N $N rpu_top; synth_gowin -family $FAMILY -top rpu_top; stat`), yosys 0.66. LUT is LUT1 to LUT4, DFF is all DFF types; before / after:

  | N | Family | LUT | ALU | DFF | MULT9X9 | SDPX9B (BSRAM) | RAM16SDP4 (LUT RAM) |
  |---|---|---:|---:|---:|---:|---:|---:|
  | 8 | gw5a | 22,131 / 22,162 | 3,328 / 3,336 | 4,863 / 4,874 | 0 / 0 | 16 / 16 | 2,112 / 2,112 |
  | 8 | gw2a | 13,262 / 12,217 | 2,304 / 2,312 | 4,863 / 4,874 | 64 / 64 | 16 / 16 | 2,112 / 2,112 |
  | 16 | gw5a | 68,539 / 68,538 | 12,544 / 12,551 | 18,561 / 18,571 | 0 / 0 | 64 / 64 | 4,224 / 4,224 |
  | 16 | gw2a | 31,033 / 30,749 | 8,448 / 8,455 | 18,561 / 18,571 | 256 / 256 | 64 / 64 | 4,224 / 4,224 |

  The second A bank costs no BSRAM: a row memory is at most 128 beats deep and one SDPX9B is 512 deep, so doubling the depth fits the same blocks. The first version indexed A as `row_a[bank][beat]`; yosys could not fold the two address registers (different enables) into a synchronous read port, so every A memory went to LUT RAM (0 SDPX9B, 4,160 RAM16SDP4, +4.4k LUT4 at N = 8). Keeping both banks in one memory with a single address register (`stream_a_addr`) fixed it.
  - Found on the way: the B panels have been in LUT RAM since milestone 1, for the same reason (`row_b[bank][beat]`). At N = 8, the same fix would move them to 16 more SDPX9B and free about 2,048 RAM16SDP4. At N = 16 it needs 64 more SDPX9B, 128 in all, more than the 118 on the GW5AT-LV60, so the B panels must stay partly in LUT RAM there (or be packed differently). This is resource use, not speed; it is logged here for milestone 2 and not changed now.
- Tests: `preload_overlaps_active_compute` now preloads a new A and B (K = 3N) into bank 1 while bank 0 computes, and checks both results. `gemm_with_ragged_shapes_is_bit_exact` adds a GEMM with one B tile (3N x 30 x 5), where every tile after the first preloads a new A. Mutations: a load that ignores A_BANK, a preloaded START that ignores A_BANK, and a read address that ignores the bank each fail 3 tests. All pass at N = 8 and 16, READ_LATENCY 1 and 10; Icarus smoke test and Verilator lint (N = 8 and 16) are clean.
- Load: `uptime` 2.84.
- Commit: `8027634`.

## Item 4: N not a multiple of 8. Done, 2026-10-14
- A beat stays 8N bits on the RPU side. In memory, a beat takes N/8 host words rounded up; at N = 12 that is 2 words (16 bytes) for 12 bytes. `rpu_sim_memory` drops the padding bytes on a DMA read and writes zeros there on a C store; the driver pads each beat to whole words (`pack_rows`) and reads only the first N bytes of each beat back (`unpack_i32`). The `N % 8` asserts in Rust and in `rpu_sim_memory` are gone; `rpu_top` needed no change.
- N = 12 MNIST: 97.26% on the RPU, equal to host int8 for every image; 963.1 cycles per image, 85.24% streaming, 8.0 s wall time. N = 8 and 16 are unchanged: 1785.2 and 497.7 cycles per image, 124.5 and 117.7 words written.
- N = 12 pays for padding: streaming is 821 cycles per image instead of the ideal 706 (784 x 128 + 128 x 10 MACs at 144 per cycle), because 64 rows pad to 72 (6 row blocks), 128 outputs to 132 and 10 to 12. Host words per image are 179.8 written and 108.1 read, against 124.5 and 72.0 at N = 8: a 12-byte beat in 16 bytes of host words wastes a quarter of every A word and every C word. A packed host format would remove that; it only matters once a real link carries these words (milestone 2).
- Synthesis of `rpu_top` at N = 12 (same command as item 3): gw5a 42,824 LUT, 7,204 ALU, 10,581 DFF, 36 SDPX9B, 3,264 RAM16SDP4; gw2a 24,581 LUT, 4,900 ALU, 10,581 DFF, 144 MULT9X9, 36 SDPX9B, 3,264 RAM16SDP4. N = 8 and 16 are unchanged (`rpu_top` did not change; `rpu_sim_memory` is a black box there).
- Tests: the whole suite passes at N = 4, 8, 12, 16 and 24 (READ_LATENCY 1), and with the brain feature at N = 8, 12 and 16, READ_LATENCY 1 and 10. Mutations at N = 12: reading the padding bytes back as C values fails 7 tests; packing beats by host word instead of by N values fails 5. Verilator lint is clean at N = 8, 12 and 16.
- Load: `uptime` 2.51.
