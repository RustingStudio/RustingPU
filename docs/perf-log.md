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
| 5 shadow accumulator | 8 | 97.26% | 1743.2 | 91.78% | 124.5 / 72.0 | 14.5 s |
| 5 shadow accumulator | 16 | 97.26% | 478.0 | 83.68% | 117.7 / 72.0 | 17.6 s |
| 5 shadow accumulator | 12 | 97.26% | 939.7 | 87.36% | 179.8 / 108.1 | 19.7 s |
| 6 operand register | 8 | 97.26% | 1743.2 | 91.78% | 124.5 / 72.0 | 14.6 s |
| 6 operand register | 16 | 97.26% | 478.0 | 83.68% | 117.7 / 72.0 | 17.7 s |
| 8 simulation speed | 8 | 97.26% | 1743.2 | 91.78% | 124.5 / 72.0 | 5.5 s |
| 8 simulation speed | 16 | 97.26% | 478.0 | 83.68% | 117.7 / 72.0 | 6.1 s |
| 9 serpentine B order | 8 | 97.26% | 1643.8 | 97.34% | 124.3 / 72.0 | 5.2 s |
| 9 serpentine B order | 16 | 97.26% | 435.4 | 91.87% | 117.6 / 72.0 | 5.7 s |
| 9 serpentine B order | 12 | 97.26% | 867.7 | 94.62% | 179.6 / 108.1 | 6.9 s |
| 11 GEMM sequencer | 8 | 97.26% | 1643.8 | 97.33% | 115.5 / 72.0 | 5.3 s |
| 11 GEMM sequencer | 16 | 97.26% | 435.5 | 91.86% | 115.5 / 72.0 | 5.8 s |
| 11 GEMM sequencer | 12 | 97.26% | 867.7 | 94.61% | 175.3 / 108.1 | 6.9 s |
| 12 stream during the first load | 8 | 97.26% | 1625.4 | 98.44% | 115.5 / 72.0 | 6.1 s |
| 12 stream during the first load | 16 | 97.26% | 420.8 | 95.06% | 115.5 / 72.0 | 6.4 s |
| 12 stream during the first load | 12 | 97.26% | 851.5 | 96.41% | 175.3 / 108.1 | 7.8 s |
| 7 hardware requantization | 8 | 97.25% | 1625.5 | 98.43% | 101.5 / 8.0 | 4.7 s |
| 7 hardware requantization | 16 | 97.25% | 420.9 | 95.04% | 101.5 / 8.0 | 5.0 s |
| 7 hardware requantization | 12 | 97.25% | 851.5 | 96.41% | 152.6 / 9.0 | 5.6 s |

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
- Commit: `f1c03fa`.

## Item 5: per-tile overhead (shadow accumulator). Done, 2026-10-14
- RTL: each PE keeps a running sum and a shadow register (`accumulator`). A last flag enters with the last k of a tile and goes through row i's skew with A, so it reaches each PE with that PE's last product; the PE moves the finished sum into the shadow and restarts the running sum at zero. The settle and drain are now a separate FSM (`drain_state`: SETTLE, SHIFT) that works on the shadows, and the compute FSM is only CLEAR, STREAM, FINISH. COMPUTE_BUSY drops when the stream ends, so the driver starts the next tile while the last one settles, drains and stores. The array is no longer reset in CLEAR (that would wipe the shadows); the running sums are zero between tiles because the array gets zeros outside STREAM. The driver did not change.
- A stream may start during a pending drain only if K >= 3N (`OVERLAP_K_MIN = SETTLE_STEPS + N`) and no C store is running; otherwise CLEAR waits for the drain. Timing: the drain's last shift must come before PE (0, 0) takes the new sum (K + 1 cycles after the new stream starts). With the fastest START (3 cycles after the stream ends) 3N - 2 would do; with a host that polls COMPUTE_BUSY, 3N - 3. The test `start_right_after_stream_end` does that polling start for K = 3N - 4 to 3N and fails when the threshold is lowered to 3N - 4, as this timing predicts. MNIST has K = 784 and 128, far above 3N.
- Expected: per tile that is not followed by a row-block switch, the 3N + 1 cycles of clear, settle and drain go away, minus the read latency of the B preload, which the stream now waits for (the port is the limit). That is 15 tiles x 8 blocks (layer 1) + 1 x 8 (layer 2) per batch of 64 at N = 8, and 7 x 4 at N = 16: about -50 and -21 cycles per image.
- Measured, cycles per image: 1785.2 to 1743.2 at N = 8 (-2.4%), 497.7 to 478.0 at N = 16 (-4.0%), 963.1 to 939.7 at N = 12 (-2.4%). Utilization 89.62% to 91.78%, 80.37% to 83.68%, 85.24% to 87.36%. What is left per tile is about 6 cycles: the B preload's read latency and the host handshake (poll, CONTROL write, START accepted, CLEAR). Accuracy 97.26%, RPU equal to host int8 for every image; host words unchanged (124.5 / 72.0 and 117.7 / 72.0).
- Wall time: 13.4 to 14.5 s at N = 8, 16.4 to 17.6 s at N = 16, but 8.0 to 19.7 s at N = 12 (both measured twice; HEAD measured again in a separate worktree: 8.0 s). The generated C++ grew by 32% at N = 12, and the C++ is compiled with `-Os`: the same tree built with `-O2` runs N = 12 in 7.5 s and N = 8 in 6.2 s. So the regression is how `-Os` compiles the larger eval function, not the simulated design; item 8 takes it up.
- Layer 1 for batch 8 (`layer1_batch8_is_bit_exact_and_mostly_streaming`, N = 8): 86.07% to 87.97% streaming (busy 14,575 to 14,260).
- Synthesis, `rpu_top` (same command as item 3), before / after:

  | N | Family | LUT | ALU | DFF | MULT9X9 | SDPX9B (BSRAM) | RAM16SDP4 (LUT RAM) |
  |---|---|---:|---:|---:|---:|---:|---:|
  | 8 | gw5a | 22,162 / 22,091 | 3,336 / 3,347 | 4,874 / 6,954 | 0 / 0 | 16 / 16 | 2,112 / 2,112 |
  | 8 | gw2a | 12,217 / 12,506 | 2,312 / 2,323 | 4,874 / 6,954 | 64 / 64 | 16 / 16 | 2,112 / 2,112 |
  | 16 | gw5a | 68,538 / 68,634 | 12,551 / 12,562 | 18,571 / 26,810 | 0 / 0 | 64 / 64 | 4,224 / 4,224 |
  | 16 | gw2a | 30,749 / 30,814 | 8,455 / 8,466 | 18,571 / 26,810 | 256 / 256 | 64 / 64 | 4,224 / 4,224 |

  The cost is registers: +2,080 DFF at N = 8 and +8,239 at N = 16 (+43% and +44%), that is 32 shadow bits and one last-flag bit per PE plus the last-flag skew. LUT changes by -71 to +289 (the shadow reuses the drain multiplexer the old accumulator had), ALU by +11, BSRAM and LUT RAM not at all. LUT is the scarce resource on the GW5AT-LV60; its registers (59,904, one per LUT4) are not: 26,810 is 45% of them. So the cost is accepted for -2.4% and -4.0% cycles.
  - Longest combinational path of the PE (`synth_gowin -noiopads`, `delete t:DFF*`, `ltp`; `ltp -noff` does not know the Gowin DFF cells and walks through them): 33 cells before and after, the 32-bit ALU carry chain plus one LUT, at gw5a and gw2a. The shadow does not lengthen it.
- Tests: `next_tile_streams_during_drain` (8 tiles, K = 25N, bit-exact, and the idle cycles are at most the first load, the last settle, drain and store, and read latency + 8 per tile); `start_right_after_stream_end`; `gemm_with_ragged_shapes_is_bit_exact` adds 2N x 4N GEMMs with K = 3N - 1, 3N and 3N + 1. The Icarus smoke test drives the last flag. Mutations: threshold N fails the ragged test; no overlap at all fails `next_tile_streams_during_drain`; ignoring a running store fails the ragged test; no restart of the running sum fails 8 tests; threshold 3N - 4 fails `start_right_after_stream_end`. Thresholds 3N - 1 to 3N - 3 pass, which is correct by the timing above. All tests pass at N = 4, 8, 12, 16 and 24 (READ_LATENCY 1) and at N = 4, 8, 12 and 16 with READ_LATENCY 10, and with the brain feature at N = 8, 12 and 16. Verilator lint is clean at N = 8, 12 and 16.
- Load: `uptime` 2.80.
- Commit: `45a1c32`.

## Item 6: Fmax proxy. Done, 2026-10-14
- Method. Two proxies, both on `rpu_top` after `synth_gowin -noiopads` with `rpu_sim_memory` as a black box:
  - `ltp` after deleting every sequential cell (`delete t:DFF* t:SDPX9B t:RAM16SDP* t:*rpu_sim_memory*`), so that paths start and end at registers and memories. `ltp` counts cells, so a 32-cell carry chain looks longest even though carry cells are fast; a script also counts LUT and MUX2 levels on the deepest path.
  - `sta` after `read_verilog -lib -specify +/gowin/cells_sim.v`: arrival times in ps from the specify blocks of the yosys Gowin cell models. ALU, MULT9X9 and SDPX9B have no timing arcs there, so carry chains, gw2a multipliers and BSRAM reads count as zero. This is a proxy, not Gowin timing.
- Before (`45a1c32`):
  - `ltp`: 33 cells at N = 8 and 16, gw5a and gw2a: the PE's 32-bit accumulate (32 ALU + 1 LUT), as the backlog guessed. By logic levels it is not the longest: the deepest paths start at the panel read and end in the edge PEs' multipliers, which took their operands straight from the panel read multiplexer (row 0 and column 0 have no skew register). 12 LUT/MUX2 levels + MULT9X9 at N = 8 gw2a, 23 levels + 4 ALU at N = 8 gw5a (soft multiplier), 20 + 8 ALU at N = 16 gw5a, 13 at N = 16 gw2a.
  - `sta`, gw5a: 12,443 ps at N = 4, 12,607 ps at N = 8, on the panel read, the lane multiplexer and the soft multiplier of PE (0, 0).
- Fix: an operand register (`OPERAND_STAGES = 1`) between the panel read and the array for A, B and the last flag. Every PE multiplier now starts from a flip-flop. The settle is one cycle longer (`SETTLE_STEPS = OPERAND_STAGES + 2N - 2 + PE_LATENCY - 1`). Writing that down showed the settle had one cycle of slack since item 5 (the shadow takes the sum PE_LATENCY - 1 cycles after the last product enters, not PE_LATENCY); it is now exact, so the drain did not get longer. `OVERLAP_K_MIN` stays 3N.
- After:
  - LUT/MUX2 levels on the deepest path: 12 (N = 8 gw2a), 12 (N = 8 gw5a), 11 (N = 16 gw5a), 13 (N = 16 gw2a), all ending at a register; no multiplier on any of them. `ltp` is still 33 (the accumulate).
  - `sta`, gw5a: 8,155 ps at N = 4 (-34%), 7,936 ps at N = 8 (-37%). The critical path is now the B panel read: `stream_beat` register, RAM16SDP4 (LUT RAM) read, 4 LUT4 and the MUX2_LUT5/6 lane tree into `b_operand`.
  - `sta`, gw2a, N = 8: 7,910 to 8,300 ps. Not a regression: MULT9X9 has no timing arcs, so gw2a `sta` never saw the multiplier path the register removes. Its longest timed path before and after is the same B panel read and multiplexer, ending at the first skew register before and at `b_operand` after; the 390 ps are a different LUT mapping of that multiplexer.
- So the 32-bit accumulate is not the critical path; the panel read into the multiplier was, and now the B panel read alone is. PE_LATENCY stays 2.
- Cycles and accuracy are unchanged, as expected (the settle is as long as before): 97.26%, RPU equal to host int8 for every image, 1743.2 and 478.0 cycles per image, 91.78% and 83.68%, 124.5 / 72.0 and 117.7 / 72.0 host words. Wall time 14.6 s (N = 8) and 17.7 s (N = 16).
- Synthesis, `rpu_top` (same command as item 3, default flow), before / after:

  | N | Family | LUT | ALU | DFF | MULT9X9 | SDPX9B (BSRAM) | RAM16SDP4 (LUT RAM) |
  |---|---|---:|---:|---:|---:|---:|---:|
  | 8 | gw5a | 22,091 / 35,155 | 3,347 / 3,347 | 6,954 / 7,083 | 0 / 0 | 16 / 16 | 2,112 / 2,112 |
  | 8 | gw2a | 12,506 / 12,762 | 2,323 / 2,323 | 6,954 / 7,083 | 64 / 64 | 16 / 16 | 2,112 / 2,112 |
  | 16 | gw5a | 68,634 / 117,706 | 12,562 / 12,562 | 26,810 / 27,067 | 0 / 0 | 64 / 64 | 4,224 / 4,224 |
  | 16 | gw2a | 30,814 / 29,851 | 8,466 / 8,466 | 26,810 / 27,067 | 256 / 256 | 64 / 64 | 4,224 / 4,224 |

  - The register costs +129 DFF at N = 8 and +257 at N = 16 (16N + 1). On gw2a, which maps the multipliers to MULT9X9 as the board's DSPs would, LUT changes by +256 and -963.
  - The gw5a LUT growth is not the register. Yosys has no DSP mapping for gw5a, so every multiplier is soft logic, and ABC9 maps for delay: once the multiplier no longer sits behind the panel multiplexer, the critical path is shorter, and ABC9 spends area to make every multiplier faster too. With a fixed delay target (`synth_gowin -run :map_luts; abc9 -maxlut 8 -W 500 -D 50000; synth_gowin -run map_cells:`) the LUT count is unchanged: 20,855 / 20,828 at N = 8, 67,490 / 67,477 at N = 16. gw5a LUT counts here are only an upper bound anyway (`docs/resources.md`: N = 16 needs DSP multipliers on the board).
- Next path, not changed in this item: the B panels are in LUT RAM (item 3), so the read is a LUT RAM read plus a multiplexer tree. Moving them to BSRAM (a single linear address register, as for A) would put a registered read there and free about 2,048 RAM16SDP4 at N = 8, but it needs 128 SDPX9B at N = 16, more than the 118 on the GW5AT-LV60. It changes speed only on the board (no cycle gain in simulation), so it is a question for milestone 2, not a loop item.
- Tests: the whole suite covers the new timing; mutations: the last flag not registered with the operands fails 9 tests at N = 8 and 16; the settle one cycle shorter fails 9 tests. The overlap threshold passes at 3N - 1 and 3N - 3 and fails at 3N - 4 (`start_right_after_stream_end`), the same boundary as item 5. All pass at N = 8 and 16, READ_LATENCY 1 and 10; Icarus smoke test and Verilator lint clean.
- Load: `uptime` 4.5 (MNIST), 3.9 (synthesis).
- Commit: `f826a78`.

## Item 7: hardware bias, ReLU and requantization. Done, 2026-10-14
- P1 approved by the owner (2026-10-14). Before: the host read layer 1's C (int32), dequantized it, added the bias, applied ReLU, quantized it again with a per-batch scale and wrote it back as layer 2's A: 64 of the 72 words read and 16 of the 115.5 words written per image.
- Fix:
  - CONTROL bit 7 QUANT: the C store requantizes each row to int8 and writes one beat per row, `y = clamp(round((acc + bias[j]) * mult[j] / 2^shift[j]), relu ? 0 : -127, 127)`, ties up. With GEMM the rows land in the column-major A panel layout of the next GEMM, so layer 2 reads layer 1's output straight from RPU memory. The per-column parameters (int32 bias in the accumulator domain, u16 mult, 6-bit shift, relu) are written to a QPARAM window at `0x0800_0000`, one 64-bit word per column, in ceil(N/4) lanes so that a row takes 4 cycles, as many as the int32 store.
  - Host side: `quant::Requant` (the reference rule and `Requant::new` from float scales), `Rpu::upload_a`, `gemm_i32`, `gemm_requant` with a `ResidentA` handle, and `RpuMlp::calibrate`, which fixes the hidden layer's output scale to `absmax / 127` of its output on calibration inputs (a static scale, as a TPU uses). `examples/mnist.rs` calibrates on the first 1,000 training images, not on the test set.
- Accuracy: 97.25% (9,725 correct), RPU equal to host int8 for every image; f32 97.26%. **-0.01 pp against f32 and against item 12 (97.26%)**, from the static output scale of layer 1 (one image). Calibrated on the test batch itself, the fused path gives the same outputs as the per-batch scales (`calibrated_mlp_keeps_hidden_activations_on_the_rpu`), so the loss is the calibration range, not the rounding rule.
- Host words per image: written 115.5 to 101.5 (-12%), read 72.0 to 8.0 (-89%; only layer 2's C). At N = 12, 175.3 / 108.1 to 152.6 / 9.0. All host words together: 187.5 to 109.5 (-42%) at N = 8 and 16.
- Cycles: +785 busy cycles in total at every N (5 per batch: the requant pipeline after the last C store of layer 1), 0.08 per image: 1625.4 to 1625.5, 420.8 to 420.9, 851.5 to 851.5 cycles per image; streaming 98.44% to 98.43%, 95.06% to 95.04%, 96.41% to 96.41%.
- Wall time 4.7 s, 5.0 s and 5.6 s (load 2.9).
- Synthesis, `rpu_top`, before (item 12) / after:

  | N | Family | LUT | ALU | DFF | MULT9X9 | SDPX9B (BSRAM) | RAM16SDP4 (LUT RAM) |
  |---|---|---:|---:|---:|---:|---:|---:|
  | 8 | gw5a | 22,514 / 31,233 | 3,551 / 4,036 | 7,201 / 7,977 | 0 / 0 | 16 / 20 | 2,112 / 2,112 |
  | 8 | gw2a | 12,434 / 12,347 | 2,527 / 3,025 | 7,201 / 7,977 | 64 / 69 | 16 / 20 | 2,112 / 2,112 |
  | 16 | gw5a | 71,739 / 87,767 | 12,755 / 13,759 | 27,186 / 28,478 | 0 / 0 | 64 / 72 | 4,224 / 4,224 |
  | 16 | gw2a | 29,920 / 29,268 | 8,659 / 9,494 | 27,186 / 28,478 | 256 / 265 | 64 / 72 | 4,224 / 4,224 |

  - The requantizer is ceil(N/4) lanes of a 33 x 17-bit multiply, a rounding add, a shift of up to 48 and a clamp. On gw2a, which maps multipliers to DSPs as the board would, it costs 5 MULT9X9 at N = 8 (2 lanes) and 9 at N = 16 (4 lanes), about 500 to 840 ALU and no LUT beyond the noise. On gw5a yosys has no DSP mapping, so the multipliers are soft logic. With the fixed `abc9 -D 50000` flow: N = 8 gw5a 21,104 to 25,083 LUT (+3,979), N = 16 67,729 to 75,607 (+7,878).
  - The parameters take 4 SDPX9B at N = 8 and 8 at N = 16 (one 55-bit word per column, 4 * ceil(1024/N) per lane). At N = 16 that is 72 of the 118 SDPX9B of the GW5AT-LV60.
  - Timing (yosys `sta`, N = 8, same flow as item 6): the first version did the bias add, multiply, rounding, shift and clamp in one stage after the parameter read. Its worst path was that stage on gw5a: 16,404 ps against 8,742 for item 12. Split into five stages (read; bias add and multiply; rounding add; shift; clamp), the requantizer is on no worst path: gw5a 12,359 ps (row A read bypass of the load), gw2a 9,261 ps (B operand path, as item 12 at 8,254). The default flow is noisy here: with the fixed `abc9 -D 50000` mapping, item 12 / item 7 are 17,532 / 12,593 ps on gw5a and 12,640 / 12,359 ps on gw2a, the worst paths in the sequencer and the row A bypass, not in the requantizer. The four extra stages cost 3 cycles per batch and about 390 DFF at N = 8 (50 bits and a few flags per lane and stage).
- Tests: `gemm_requant_matches_the_host_rule` (6 shapes, random and calibrated parameters, ReLU on and off, host words = n parameters + 7 registers), `requantized_output_feeds_the_next_gemm` (layer 2 reads layer 1's output in RPU memory; only the last C is read back), `requant_follows_the_float_rule_within_one_step`, `requant_edges` (ties, saturation, zero scales) and `calibrated_mlp_keeps_hidden_activations_on_the_rpu` (3 layers, ReLU and linear, RPU equal to host, calibrated on the test batch equal to the unfused path within 1% of the output range, measured equal). RTL mutations, each caught: no rounding, relu ignored, -128 instead of -127 as the lower clamp, a wrong parameter address, the int32 C stride with QUANT, DONE that ignores any stage of the requant pipeline, a stage that takes the valid, part, address, shift or relu of the wrong stage, a logical instead of an arithmetic shift, tile column 0 for every parameter read, a zero-extended bias, the requant stage without QUANT. Driver mutations, each caught: the last layer fused, ReLU off, no scale hand-over between fused layers, activations at one address, a calibration at 100 instead of 127, the bias dropped, a calibration on the signed maximum. Not caught: BUSY that ignores the last requant stages (the driver waits for DONE, which is checked), and the lane guard `part * L + l < N` removed (writes past byte N - 1 are dropped anyway; kept for clarity). All tests pass at N = 4, 8, 12 and 16, READ_LATENCY 1 and 10, with the brain feature; Icarus smoke test and Verilator lint (N = 8, 12, 16) clean.
- Load: `uptime` 2.9 (MNIST), 3 to 31 (synthesis, run in parallel).
- Commit: `16d185b`.

## Item 8: simulation speed. Done, 2026-10-14
- Wall time of the MNIST example (10k images, host int8 included), N = 8 / N = 16, all at `f826a78`, measured back to back:

  | Build | N = 8 | N = 16 |
  |---|---:|---:|
  | C++ `-Os` (before) | 14.4 s, 14.4 s | 17.7 s, 17.5 s |
  | C++ `-O2` | 5.9 s | 6.2 s |
  | C++ `-O3` | 5.9 s | 6.3 s |
  | C++ `-O2`, Verilator `-O3 --x-assign fast --x-initial fast` | 5.9 s | 6.3 s |
  | C++ `-O2`, no redundant evals (after) | 5.5 s, 5.6 s, 5.5 s | 6.1 s, 6.1 s, 6.2 s |

- Kept: `-O2` in `build.rs` (-59% and -65%), and the wrapper no longer evaluates the model in `rpu_busy`, `rpu_done` and in `rpu_read` when the address did not change. Every call that changes an input already evaluates before it returns, so the outputs are settled between calls; the driver's wait loops called `eval` three times per cycle, now two. That is a further -6% at N = 8 and about -1% at N = 16, where the larger model makes the clocked evals dominate.
- Not kept: `-O3` and the Verilator flags gain nothing measurable, so the build stays as it was there.
- Not done: bulk FFI. Every host word written is one bus cycle in the model, so a bulk call would save only the call itself, a few ns, against about 300 ns of simulation per cycle (5.5 s / 17.4 M cycles). Not worth the API.
- Build time of the N = 16 example: 21.3 s to 18.1 s.
- Simulated cycles, accuracy and host words are unchanged (1743.2 and 478.0 cycles per image, 97.26%, RPU equal to host int8 for every image).
- Tests: all pass at N = 8 and 16, READ_LATENCY 1 and 10. Mutation: `rpu_read` that never evaluates after changing the address fails 5 tests.
- Load: `uptime` 2.1 to 3.5.
- Commit: `bac9d6e`.

## Item 9: serpentine B order at a row block change. Done, 2026-10-14
- Profile after item 8 (N = 16, batch 64, per batch): 4,992 busy cycles are not streaming. About 1,830 are the first A + B load of each layer, about 2,440 are the exposed part of the A + B load at each of the 6 later row block changes (2K beats overlapping one K-cycle tile, item 3), about 216 the per-tile handshake and about 140 the last settle, drain and store of each layer. At N = 8 the row block changes are about 6,030 of 9,150. So the row block change was the largest item: expected -38 cycles per image at N = 16 (-8%) and -94 at N = 8 (-5.4%).
- Fix: odd row blocks walk the B tiles backwards, so a row block starts with the B tile the block before ended with, and that B is still in its bank. A new CONTROL bit 5 (KEEP_B) loads only A; the B bank keeps its contents and is marked valid at the end of the load. At a row block change, `matmul_resident` preloads only the next A (K beats, as long as a B preload) into the other A bank, on the B bank of the running tile, and the next START computes at once. The C tiles keep their places, so the results are in the same order.
- Measured, cycles per image: 1743.2 to 1643.8 at N = 8 (-5.7%), 478.0 to 435.4 at N = 16 (-8.9%), 939.7 (item 5) to 867.7 at N = 12 (-7.7%). Streaming 91.78% to 97.34%, 83.68% to 91.87%, 87.36% to 94.62%. Accuracy 97.26%, RPU equal to host int8 for every image. Host words written 124.5 to 124.3 and 117.7 to 117.6 (no B_BASE write at a row block change); reads unchanged.
- What is left per batch: the first A + B load of each layer (1,824 cycles: 28.5 cycles per image, 1.7% at N = 8 and 6.5% at N = 16), about 6 cycles of handshake per tile, and the last settle, drain and store of each layer.
- Synthesis, `rpu_top` (same command as item 3), before (item 6) / after:

  | N | Family | LUT | ALU | DFF | MULT9X9 | SDPX9B (BSRAM) | RAM16SDP4 (LUT RAM) |
  |---|---|---:|---:|---:|---:|---:|---:|
  | 8 | gw5a | 35,155 / 31,728 | 3,347 / 3,347 | 7,083 / 7,085 | 0 / 0 | 16 / 16 | 2,112 / 2,112 |
  | 8 | gw2a | 12,762 / 12,755 | 2,323 / 2,323 | 7,083 / 7,085 | 64 / 64 | 16 / 16 | 2,112 / 2,112 |
  | 16 | gw5a | 117,706 / 117,835 | 12,562 / 12,562 | 27,067 / 27,069 | 0 / 0 | 64 / 64 | 4,224 / 4,224 |
  | 16 | gw2a | 29,851 / 29,320 | 8,466 / 8,466 | 27,067 / 27,069 | 256 / 256 | 64 / 64 | 4,224 / 4,224 |

  The RTL change is two flip-flops (the KEEP_B bit and its copy for the running load) and two gates; the LUT differences are ABC9 mapping noise (item 6).
- Tests: `keep_b_load_fills_only_a` (while B bank 0 computes, a KEEP_B load with B_BASE on another B fills only A bank 1; the next START computes the old B with the new A). `next_tile_streams_during_drain` now also runs a 3 x 3 tile GEMM and checks the same idle bound, which allows no B load at a row block change. Mutations: an issue side that ignores KEEP_B fails 2 tests, a receive side that ignores it fails 3, the forward order in every row block fails 2, a B bank that flips at the row block change fails 2, and a full A + B preload at the row block change fails the idle bound. All tests pass at N = 4, 8, 12 and 16, READ_LATENCY 1 and 10, with the brain feature; Icarus smoke test and Verilator lint (N = 8, 12, 16) clean.
- Load: `uptime` 3.8 (MNIST).
- Commit: `d8a3413`.

## Item 10: prefetch the next GEMM's first B tile. Rejected without implementation, 2026-10-14
- Idea: load the first B tile of layer 2 while layer 1 still runs, so only A of the first tile is exposed.
- The single read port is busy with a preload during every tile except the last one of a GEMM. The prefetch could only use the last tile of layer 1 and would hide at most one B panel per batch: 256 beats at N = 8, about 4 cycles per image (0.2%). Below the 2% bar, so not built.
- Also considered and not built: a larger batch (changes quantization, so the numbers would not be comparable), a second read port or a wider bus (breaks the 8N-bit bus rule).

## Item 11: GEMM sequencer. Done, 2026-10-14
- Profile after item 9 (N = 8, per image): 124.3 host words written. Most are the activations; the per-tile register writes of `matmul_resident` (START, the next B_BASE or A_BASE, the PRELOAD, the next C_BASE: about 4 writes for each of 144 tiles per batch of 64) are about 9. Expected -7% host words written at N = 8 and -2% at N = 16, no change in cycles.
- Fix: a sequencer in `rpu_top` runs the tile schedule of item 9. The host writes K_LEN, A_BASE, B_BASE, C_BASE, PANEL (word 8, beats per panel), TILES (word 9, row blocks and B tiles) and CONTROL bit 6 (GEMM), and waits for DONE: 7 register writes per GEMM. The sequencer issues START and PRELOAD as the driver did and moves the base registers itself: A and B by PANEL beats, C by one 4N-beat tile within a row block and by a row of tiles at a row block change. BUSY covers the sequencer and DONE waits for it.
- Measured, host words written per image: 124.3 to 115.5 at N = 8 (-7.1%), 117.6 to 115.5 at N = 16 (-1.8%), 179.6 to 175.3 at N = 12 (-2.4%). Reads unchanged. Cycles per image 1643.8 to 1643.8, 435.4 to 435.5, 867.7 to 867.7: the sequencer takes as many cycles per tile as the polling host (a write is one cycle, a status read takes none), so the handshake did not shrink. Accuracy 97.26%, RPU equal to host int8 for every image.
- Synthesis, `rpu_top`, before (item 9) / after:

  | N | Family | LUT | ALU | DFF | MULT9X9 | SDPX9B (BSRAM) | RAM16SDP4 (LUT RAM) |
  |---|---|---:|---:|---:|---:|---:|---:|
  | 8 | gw5a | 31,728 / 25,614 | 3,347 / 3,514 | 7,085 / 7,170 | 0 / 0 | 16 / 16 | 2,112 / 2,112 |
  | 8 | gw2a | 12,755 / 11,806 | 2,323 / 2,490 | 7,085 / 7,170 | 64 / 64 | 16 / 16 | 2,112 / 2,112 |
  | 16 | gw5a | 117,835 / 75,375 | 12,562 / 12,720 | 27,069 / 27,153 | 0 / 0 | 64 / 64 | 4,224 / 4,224 |
  | 16 | gw2a | 29,320 / 28,110 | 8,466 / 8,624 | 27,069 / 27,153 | 256 / 256 | 64 / 64 | 4,224 / 4,224 |

  The LUT drops are ABC9 noise. With the fixed `abc9 -D 50000` flow (item 6), N = 8 gw5a goes from 20,830 to 21,060 LUT (+1.1%); the sequencer costs about 230 LUT, 167 ALU (the counters and base adders) and 85 DFF.
- Tests: `gemm_writes_its_registers_once` (a 3 x 3 tile GEMM is bit-exact and writes the A words plus 7). All GEMM tests now run through the sequencer, including the idle bound of `next_tile_streams_during_drain`. Mutations, each caught: no direction flip at a row block change fails 4 tests, no B bank flip 2, no KEEP_B at a row block change 1 (the idle bound), a C step of one tile at a row block change 4, the wrong A bank 4, DONE not gated by the sequencer 3, a GEMM that ends after the first row block 4, a next START that does not wait for the preload 1, a sequencer stuck after START 5. All tests pass at N = 4, 8, 12 and 16, READ_LATENCY 1 and 10, with the brain feature; Icarus smoke test and Verilator lint (N = 8, 12, 16) clean.
- Load: `uptime` 2.7 to 3.2.
- Commit: `9002fc3`.

## Item 12: stream during the first load of a GEMM. Done, 2026-10-14
- Profile after item 11 (per batch of 64): the first A + B load of each GEMM is still exposed, 2Kp beats before the first stream (Kp = N * ceil(K/N)): 1,824 cycles at N = 8 and N = 16, 28.5 cycles per image, 6.5% of the cycles at N = 16. Both panels were stored row by row, so the stream had to wait for the last row. Stored column by column, column c of A and B is in after 2N(c + 1) beats while the stream reads it from cycle Nc, so the stream can start after about Kp + N beats and end with the load. Expected about K - 2N cycles less per GEMM: -13 cycles per image, -3% at N = 16 and -0.8% at N = 8.
- Fix:
  - `pack_panels` stores every A and B panel column by column (beat c of rows 0..N-1, then beat c + 1), and the load walks the same order: per column the A rows, then the B rows.
  - A START is held in a launch register until the compute is free and the load is far enough: K + 2N beats in for A and B, N + 1 for one panel, or the load is done. The bound is Kp + N - 2 and N - 2 beats (engineering.md, section 8), so 3 beats of margin; the tests pass with both thresholds 3 lower and fail with 4 lower.
  - A START is now taken while a compute runs, so the sequencer starts tile t + 1 as soon as the load of t is done and the compute has taken t: one START per tile, no PRELOAD. Tile t + 1 then streams right after t, from a load that may still run.
- Measured, cycles per image: 1643.8 to 1625.4 at N = 8 (-1.1%), 435.5 to 420.8 at N = 16 (-3.4%), 867.7 to 851.5 at N = 12 (-1.9%). Streaming 97.33% to 98.44%, 91.86% to 95.06%, 94.61% to 96.41%. Accuracy 97.26%, RPU equal to host int8 for every image. Host words unchanged. Layer 1 for batch 8 at N = 8 streams 93.21% of its busy cycles (87.97% before).
- Wall time 5.3 to 6.1 s and 5.8 to 6.4 s: measured under load 8.4 from another program, not comparable; the simulated work is smaller.
- Synthesis, `rpu_top`, before (item 11) / after:

  | N | Family | LUT | ALU | DFF | MULT9X9 | SDPX9B (BSRAM) | RAM16SDP4 (LUT RAM) |
  |---|---|---:|---:|---:|---:|---:|---:|
  | 8 | gw5a | 25,614 / 22,514 | 3,514 / 3,551 | 7,170 / 7,201 | 0 / 0 | 16 / 16 | 2,112 / 2,112 |
  | 8 | gw2a | 11,806 / 12,434 | 2,490 / 2,527 | 7,170 / 7,201 | 64 / 64 | 16 / 16 | 2,112 / 2,112 |
  | 16 | gw5a | 75,375 / 71,739 | 12,720 / 12,755 | 27,153 / 27,186 | 0 / 0 | 64 / 64 | 4,224 / 4,224 |
  | 16 | gw2a | 28,110 / 29,920 | 8,624 / 8,659 | 27,153 / 27,186 | 256 / 256 | 64 / 64 | 4,224 / 4,224 |

  With the fixed `abc9 -D 50000` flow, N = 8 gw5a goes from 21,060 to 21,104 LUT. The A panels stay in BSRAM: the stream reads one address per row memory per cycle while the load writes another.
- Caveat: the launch threshold assumes that a load brings one beat per cycle without gaps, which holds for the BSRAM memory of milestone 2. A memory that can stall reads (DDR) needs a stall-aware check.
- Tests: all GEMM tests run the new order. `next_tile_streams_during_drain` now bounds the first load at K + 2N idle cycles instead of 2K. Mutations, each caught: A rows only in each column fails 15 tests, a receive side or an issue side that returns to A after a B-only column 5 each, no launch at the end of a load (a K that never reaches the threshold) 1, a launch that ignores the threshold 5, no early launch at all 1 (the idle bound), a sequencer that starts the next load before the compute took the tile 1. The threshold sweep: K + 2N - 3 passes, K + 2N - 4 fails; N - 2 passes, N - 3 fails. All tests pass at N = 4, 8, 12 and 16, READ_LATENCY 1 and 10, with the brain feature; Icarus smoke test and Verilator lint (N = 8, 12, 16) clean.
- Load: `uptime` 8.4 to 9.9 (another program).

## Profile after item 12, 2026-10-14. No candidate reaches 2%
Overhead at N = 16, per batch of 64 (busy 26,931 cycles, streaming 25,600):
- The exposed part of the first load of each GEMM, K + 2N beats: 816 (layer 1) + 160 (layer 2) = 976 cycles, 15.3 cycles per image, 3.6%. With one 8N-bit read port, A and B arrive at half the stream rate, so the stream cannot start earlier without a second port or a wider bus (both outside the rules). Prefetching B while the host writes A does not reduce busy cycles, because the prefetch is busy too (see item 10). A larger batch would amortize it, but changes the activation scale and so the numbers (see item 10).
- The port idles for about the read latency + 3 cycles between two tile loads: about 4 cycles x 36 tiles = 144 cycles, 2.3 per image, 0.5%.
- The C store and drain of the last tile of each GEMM: about 170 cycles, 2.7 per image, 0.6%.

At N = 8 the whole overhead is 25.4 cycles per image (1.6%).

Host words: 115.5 written (A of both layers, 114 words, and 7 register writes per GEMM) and 72.0 read (C). Reading only the columns of layer 2 that hold outputs (10 of 16) would read 69 words: -1.6% of all host words. Below 2%, not built.

## Questions for owner
1. P1 (bias, ReLU and requantization in hardware, item 7): approve it? It would cut the C reads from 72 to about 18 words per image (int8 instead of int32) and let layer 2 start without the host.
2. Milestone 2 at N = 16: the two B banks use 4,224 RAM16SDP4 (LUT RAM). Moving them to BSRAM would need 128 SDPX9B with the A banks, more than the 118 that the GW5AT-LV60 has. Keep N = 8 for the first bitstream, or keep B in LUT RAM at N = 16?
3. DSP counts on the gw5a are not known: yosys maps the multipliers to LUTs on that family. Gowin EDA would give the real numbers, but the loop rules forbid installing it.
4. Milestone 3 (DDR3): the early launch of item 12 assumes a memory that never stalls a read. A DDR controller needs a stall-aware launch check. Plan it for milestone 3?
5. A larger batch (for example 256) would amortize the first load of each GEMM (about -2.7% cycles at N = 16), but it changes the activation scale per batch, so the predictions can change. Allowed?
