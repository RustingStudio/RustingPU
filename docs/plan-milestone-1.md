# RustingPU: plan to milestone 1

Written 2026-10-14 against commit `16d1b17`. This is a plan for the owner to approve. No RTL or Rust has been changed.

**Update, 2026-10-14:** the owner bought a **Sipeed Tang Mega 60K core board** (GW5AT-LV60, without the Dock). Sections 2.2, 2.3, 2.6, 3, 4 and 6 now target that board. The main changes:
- A 16x16 array may now fit. Phase 3 counts the DSPs, and phase 9 also runs MNIST at N=16.
- All MNIST weights fit in on-chip BSRAM, so milestone 2 does not need DDR3.
- The build moves to Gowin EDA.
- A USB JTAG/UART debugger is needed, because the core board has no USB port.

**Milestone 1:** a RustingBrain MNIST MLP runs end to end on the Verilator RPU. Its accuracy is identical to a host int8 reference and within 0.5 percentage points of the f32 model, and cycles per inference are reported.
**Milestone 2 (launch):** the same model runs on a real Gowin board. We report Fmax and resource use, and publish a photo or video.

## 1. What I measured

All numbers come from a clean copy of the repo in a scratch directory. Cycle counts come from `Rpu::cycles()`. Resource counts come from `yosys 0.66 synth_gowin -family gw2a`, which runs synthesis only, without place and route.

| What | Result |
|---|---|
| `cargo test` in the working tree | **Fails.** `obj_dir/` holds stale `Vrpu_bf16_soc___024root__{1,2,3}*.cpp` files from an older Verilator run. `build.rs` globs every `Vrpu_bf16_soc*.cpp`, so the stale files are compiled against new headers. A fresh copy passes all 4 tests. |
| Load A+B, 128 words | **384 cycles**: 3 cycles per word. `rpu_sim_memory` accepts a new request only when `rd_ready` is low, so every word costs request, response and one bubble. |
| Compute and store C | **217 cycles**: clear 1 + stream 8 + drain 16 + store 64 x 3. |
| Array utilization, 8x8x8 tile in steady state | The array streams for 8 of about 514 cycles per tile (128 host-write ticks + 384 load). That is **about 1.6%**, or 2.1% if host writes are ignored. The brief's 12% estimate assumed 1 word per cycle. |
| 8x784 @ 784x128, the MNIST MLP layer 1 for a batch of 8 | 1568 tile jobs, **1.74 s of Verilator wall time**. A full 10k-image test set would take about 36 minutes. |
| Multiplier rounding | Of 1118 products of BF16 values in [1, 2), **511 (46%)** differ from round-to-nearest-even. The multiplier truncates. The existing tests miss this because they use small integers, and the dynamic test allows an error of 0.1. |
| Multiplier overflow | `2^100 * 2^100` returns `0x2380` (about 1.4e-17). `exp_c` wraps. |
| BF16 accumulator | `256 + 1 + 1 + 1 + 1 + 1 + 1 + 1` returns 256. The exact answer is 263. Every `+1` is lost to round-to-even at 8 bits of precision. |
| BF16 PE (current, yosys `synth_gowin` for GW2A) | 747 LUT + 213 ALU = **~960 LUT4**, 48 FF, 1 MULT9X9. The adder alone is about 700 LUT4: alignment, an 11-step normalize loop and rounding. |
| INT8 x INT8 + INT32 PE (sketch, 2-stage, GW2A) | 32 LUT + 32 ALU = **~64 LUT4**, 64 FF, 1 MULT9X9. Without a DSP block it is ~411 LUT4. |

All five weak spots in the brief are real. Two of them are worse than stated: utilization is about 1.6%, not 12%, and the build is currently broken in place.

## 2. Decisions

### 2.1 Number format: INT8 x INT8 with an INT32 accumulator

Choose INT8 and replace BF16. Do not add INT8 next to BF16.

- **It fits; BF16 does not.** 64 BF16 PEs need about 61k LUT4. That is 3x the 20,736 LUT4 on the GW2A-18, and more than the 59,904 LUT4 on the Mega 60K, before any controller logic. An FP32 accumulator would make the adder larger still. 64 INT8 PEs need about 4.1k LUT4, 4.1k FF and 64 9x9 multipliers.
- **Pipelining is easy.** An integer accumulate is one carry chain, so `acc <= acc + p` closes in one cycle after a registered product. A floating-point accumulate has a loop-carried latency of several cycles once the adder is pipelined. That forces interleaved accumulators or a stalled array. INT8 solves weak spots 1, 2 and 4 together.
- **Tests become bit-exact.** int8 products summed in int32 are exact, and host-side partial sums in `i32` are exact too. Every RTL test compares with `==`, so no tolerance can hide a bug.
- **It matches RustingBrain.** `src/quantized.rs` already defines per-row symmetric int8 weights (`scale = absmax / 127`). The RPU reuses that scheme for weights. Activations get one symmetric scale per batch per layer, computed on the host.
- **Hint.md, section 10.** Its rule "one format, one PE type" still holds. Its choice of BF16 first was made before anyone had resource numbers. The numbers above overturn it.
- **Overflow headroom.** `|a*b| <= 127*127` with symmetric quantization. For K <= 1024 the sum stays below 2^24, far inside i32.

What we lose is the ability to run unquantized models. That is acceptable: every FPGA inference demo in this class is int8.

### 2.2 Array size: N is a parameter; build 8x8 first, aim for 16x16 on the Mega 60K

GW5AT-LV60 resources: 59,904 LUT4, 59,904 FF, 118 DSP (the wiki says "18x18"), and 2,124 Kbit BSRAM in 118 blocks. Yosys knows two relevant GW5A primitives: `MULT12X12`, and `MULTADDALU12X12` (two 12x12 multipliers, an adder and an accumulator).

Per-PE cost: ~64 LUT4 and 64 FF with a DSP, or ~411 LUT4 without one (section 1).

| Array | PEs | With 236 12x12 multipliers (2 per DSP) | With 118 multipliers (1 per DSP) |
|---|---|---|---|
| 8x8 | 64 | ~4k LUT, 4k FF: trivial | same: trivial |
| 12x12 | 144 | ~9k LUT | 118 DSP + 26 LUT multipliers: ~18k LUT, fits |
| 16x16 | 256 | 236 DSP + 20 LUT multipliers: ~23k LUT + ~5k controller = **~48%**, FF ~34%: fits | 138 LUT multipliers: ~64k LUT, **does not fit** |

Whether one GW5A DSP holds two 12x12 multipliers decides between 16x16 and 12x12. The primitive list suggests it does, but this is not verified.

The installed Yosys (0.66) infers DSPs only for `gw1n` and `gw2a`. For `gw5a` it maps every multiply to LUTs. So the real count must come from **Gowin EDA** (phase 3), or from instantiating `MULT12X12` directly.

Milestone 1 runs every phase at N=8 because it simulates faster. Phase 9 then reruns the bit-exact suite and MNIST at N=16. The size for milestone 2 comes from the phase 3 Gowin EDA report. The fallback is N=12, which needs no RTL change: the tile is a parameter.

### 2.3 Dataflow, memory bus and utilization

The fix is K streaming. Bus width alone is not enough.

- **Hardware K accumulation with K-length panels.** The local A panel is `N x KMAX` and the local B panel is also `N x KMAX`. The RPU computes `C = A * B^T`, an NT GEMM. A RustingBrain weight matrix is `[out, in]` row-major, so 8 output rows of W are already one contiguous B panel. Activations `[batch, in]` are A panels in the same layout. One load path serves both operands. The array streams all K cycles without clearing, then drains once. For layer 1 (K=784) that means 784 stream cycles per output tile instead of 98 separate 25-cycle jobs. Use KMAX = 1024: 8 KB per panel, 4 panels with double buffering, 32 KB, about 15 of 46 BSRAM blocks.
- **A-panel reuse.** One batch tile of activations is used for all 16 output tiles of layer 1. Only B panels are reloaded.
- **64-bit pipelined bus in simulation.** One beat carries 8 int8 values, with one request per cycle and a configurable read latency. A B panel is 784 beats and its compute is 784 cycles, so the two are balanced. With double-buffered B panels, the load overlaps compute.

| Stage | Bottleneck per output tile (layer 1, batch 8) | Array utilization |
|---|---|---|
| Today (measured) | 3 cycles per 16-bit word, 98 jobs | ~1.6% |
| After phase 3 (INT8, 2 values per 16-bit word, still 3 cycles per word) | ~192 load cycles per 8-cycle job | ~4% |
| After phase 5 (K streaming, old bus) | B panel = 3136 words x 3 = 9408 cycles per 784 compute | ~8% |
| After phase 6 (64-bit pipelined bus, no overlap) | 784 load + 784 compute | ~48% |
| After phase 7 (double-buffered B, A reuse) | max(784, 784) + ~24 skew/drain | **~90-95%** (target ≥ 85%) |

**Bus width scales with N.** A beat carries N int8 values: 64 bits at N=8, 128 bits at N=16. Make the width `8*N` from the start.

**Milestone 2 memory is BSRAM, not DDR3.** The Mega 60K has 2,124 Kbit (~265 KB) of BSRAM. MNIST needs:
- int8 weights and scales: ~102 KB
- panels at N=16: ~48 KB (A plus double-buffered B, KMAX=1024)
- activations: a few KB

That is about 155 KB, so it fits on chip. The "external memory" behind the `rd_*`/`wr_*` ports becomes a wide BSRAM store, loaded over UART. 118 blocks of up to 36 bits each give 128 bits per cycle with room to spare. The phase 6 simulated memory therefore models this store: latency 1-2, one beat per cycle. The 512 MB DDR3 (Gowin IP) is needed only for models bigger than about 150 KB; it comes after launch.

**Cycles per inference, estimated after phase 7:**
- **N=8, batch 8:** layer 1 is 16 x ~808 cycles; layer 2 (K=128, 10 outputs padded to 16) is 2 x ~152; plus one A-panel load and the C stores. That is ~14k cycles per 8 images, **~1.75k cycles per image**.
- **N=16, batch 16:** layer 1 is 8 x ~832; layer 2 is 1 x ~176. That is ~6.9k cycles per 16 images, **~430 cycles per image**.

Today's design needs ~100k cycles per image. This is also the main fix for simulation wall time: the full test set drops from ~36 minutes to well under one.

### 2.4 PE pipeline and drain

- **PE:** stage 1 registers `a*b` (the DSP output register). Stage 2 computes `acc <= (clear ? 0 : acc) + p`. The critical path is a 32-bit carry chain. Nothing floating-point is left.
- **Drain:** replace the one-cycle copy of N*N values in `COMPUTE_DRAIN` with a row shift. In drain mode each accumulator loads its left neighbour's value. The right column emits N values of 32 bits per cycle into the C buffer. Draining takes N cycles, and the cost grows with N instead of N². The extra skew from the PE pipeline stage is added to the drain count. Overlapping drain with the next tile through shadow accumulators is cut from milestone 1; it costs 8 cycles out of ~808.

### 2.5 Where the RustingBrain backend lives: in RustingPU, behind a `brain` feature

- RustingBrain needs **no changes**. `Network::layers()` already exposes `weights` (`[out, in]` row-major), `biases` and `activation` as public fields.
- RustingBrain's README promises "no C++ build step". An `rpu` feature inside RustingBrain would pull Verilator and `cc` into its build. The dependency should point the other way.
- API: `RpuMlp::from_network(&Network) -> RpuMlp` quantizes weights once. `RpuMlp::predict_batch(&mut self, rpu, inputs)` returns logits. The same struct has a host int8 path, which serves as the bit-exact reference.
- **On the RPU:** matmul only. **On the host:** activation quantization, dequantization (`acc * w_scale[row] * x_scale`), bias, ReLU and softmax. A hardware bias/ReLU stage (Hint.md, section 11) is cut from milestone 1.
- `rusting_brain` becomes an optional dependency. That needs owner approval; see section 6.

### 2.6 Board: Tang Mega 60K core board (bought)

The owner bought this board, so the comparison below is kept only as history. What the Mega 60K means for the plan:

- **Capacity:** about 3x the LUTs of the 20K parts and 2.6x the BSRAM. 16x16 is plausible (section 2.2), and MNIST lives entirely on chip (section 2.3).
- **Board:** the core board has the FPGA, DDR3, flash, and **JTAG + UART on a JST SH1.0 8-pin connector**. USB-JTAG, USB 3.0, HDMI, Ethernet, LEDs and keys are all on the separate Dock. Programming and the UART host link therefore need an external USB JTAG/UART debugger on the 8-pin port. The two 8P leads in the box are cables only. How the core board is powered without the Dock is not documented on the wiki; see Q1.
- **Toolchain:** Gowin EDA, Education V1.9.11.03 or later (per the Sipeed wiki). Open-source tools are not a viable primary flow: Yosys 0.66 has no `gw5a` DSP inference, and nextpnr support for GW5AT-60 is unverified.
- **Fmax:** GW5A is a newer, faster family than GW2A. Target ≥ 100 MHz; measure in milestone 2.

Earlier comparison (written before the purchase):

| | Tang Nano 20K | Tang Primer 20K (Dock) | Tang Mega 138K |
|---|---|---|---|
| Price (resellers, 2026) | ~$27-34 | ~$70 core, ~$90 Dock kit | ~$90 core; Console kits $265-350 |
| FPGA | GW2AR-18 | GW2A-LV18 (same fabric) | GW5AST-138 |
| LUT4 / FF | 20,736 / 15,552 | 20,736 / 15,552 | 138,240 / - |
| Multipliers | 48 x 18x18 | 48 x 18x18 | 298 DSP |
| BSRAM | 828 Kbit (46 blocks) | 828 Kbit | 6,120 Kbit |
| External memory | 64 Mbit 32-bit SDR SDRAM, in the package | 128 MB DDR3 (sources disagree; one says 1 GB) | 1 GB 32-bit DDR3 |
| Host link | USB-C, onboard JTAG and UART bridge | USB-C JTAG and UART, 10/100 Ethernet on the Dock | PCIe, Ethernet, USB |
| 8x8 INT8 | fits | fits | fits; 16x16 also fits |

The earlier recommendation was the Tang Nano 20K, for its price and its simple SDRAM. The owner's choice of the Mega 60K replaces it. That choice removes the external-memory problem for MNIST entirely, which is a better trade.

## 3. Milestone 1 phases

Each phase should take under 2 hours and ends with a concrete check. Every RTL phase keeps a bit-exact Rust reference test. Run `cargo fmt`, `cargo test` and the Icarus smoke test at the end of each phase.

| # | Phase | Check |
|---|---|---|
| 0 | **Build hygiene.** Point Verilator `-Mdir` at `$OUT_DIR/obj_dir` so stale files can never be globbed, and delete the root `obj_dir/`. Add `examples/baseline.rs`, which prints the cycle counts in section 1, and record them in `docs/baseline.md`. | `cargo test` passes in the working tree. Baseline shows load 384 and compute+store 217. |
| 1 | **Host int8 reference.** Add `src/quant.rs` with: per-row int8 weight quantization (same rule as RustingBrain `quantized.rs`), per-batch symmetric activation quantization, `matmul_nt_i8(a, b) -> Vec<i32>`, and dequantization. No RTL changes. | Unit tests: the i32 matmul equals a naive i64 sum; quantize-then-dequantize error ≤ scale/2. |
| 2 | **Bit-exact harness first.** Write the failing tests: random int8 tiles including -127, 127 and 0, compared with `==` against phase 1. | The tests exist and fail against the BF16 RTL. |
| 3 | **INT8 PE and array.** Add `int8_cell.sv` (2-stage PE) and make the orchestrator width-generic. `mem_c` becomes 32-bit, and C is stored as lo/hi 16-bit words on the existing bus. Add `Rpu::run_tile_i8`. Remove the BF16 cell, multiplier and adder from `build.rs`. Update `sim/tb_tpu.sv`. | Phase 2 tests pass on 1000 random tiles. Gowin EDA synthesis of the array at N=8 and N=16 for GW5AT-LV60 is written to `docs/resources.md`: LUT, FF, and how many DSP multipliers are actually mapped. If Gowin EDA is not installed yet, record the `yosys synth_gowin -family gw5a` LUT-only numbers and do the DSP count in milestone 2, step 1. |
| 4 | **Shift drain.** Replace the N*N copy in `COMPUTE_DRAIN` with a row shift (N cycles). | Bit-exact tests pass. Compute cycles go from 25 to about 1 + 8 + skew + 8, printed by the baseline example. The synthesized SoC has no 64:1 mux on `mem_c`. |
| 5 | **K streaming.** Add a `K_LEN` register and local A and B panels of `N x KMAX` (KMAX=1024). Stream K_LEN cycles without clearing. Add counters `active_cycles` (array streaming) and `busy_cycles` to the STATUS block. | Bit-exact for K in {1, 7, 8, 9, 64, 784, 1024}. 8x784 x 784x8 computes in 784 + ~24 cycles. |
| 6 | **Wide pipelined memory.** `rpu_sim_memory` gets `8*N`-bit beats (64 at N=8, 128 at N=16), one request per cycle, a `READ_LATENCY` parameter and at least 1 MB. It models the milestone-2 BSRAM store. The host port and ABI become 32-bit address and 64-bit data words (a beat is N/8 words). Panel loads move N values per beat. | Panel load takes 784 + latency cycles. Bit-exact with READ_LATENCY of 1 and 10. |
| 7 | **Overlap and reuse.** Double-buffer the B panel. Keep the A panel valid across output tiles (a `KEEP_A` control bit). Rust schedules output tiles ping-pong. | Layer 1 for batch 8 (8x784 x 784x128) is bit-exact, with `active/busy` ≥ 85%. Cycle total recorded. |
| 8 | **`brain` feature.** `RpuMlp::from_network`, with a host int8 path and an RPU path that share all quantization code. | 64 random inputs through a seeded 784-128-10 network give **bit-identical logits** on the host int8 path and the RPU path. |
| 9 | **MNIST end to end.** `examples/mnist.rs`: train 784-128-10 (ReLU, softmax) with RustingBrain on the **CPU** (seeded, a few epochs; no GPU, so the GPU lock does not apply). Save JSON. Evaluate the 10k test images in f32, host int8 and RPU. Print accuracy, cycles per image and utilization. Run once at N=8 and once at N=16. | RPU accuracy equals host-int8 accuracy exactly at both sizes. f32 minus int8 is at most 0.5 pp. Numbers go to `docs/m1-results.md` with commit and date. |
| 10 | **Org readiness.** Write the README (section 5). Track the engineering guide in `docs/` (it is gitignored today). Delete dead RTL (section 6, Q5). Rename the crate. | `cargo test` passes on a fresh clone, and README numbers match `docs/m1-results.md`. |

**Time:** 11 phases of up to 2 hours each is about 22 hours. With 2x debugging slack that is about 44 hours, or 3-4 weeks at about 12 hours per week. That fits the timebox.

**Cut from milestone 1 to fit:**
- hardware bias, ReLU and requantization
- drain overlap through shadow accumulators
- a descriptor or command-queue DMA (Rust still issues one command per output tile)
- conv layers
- BF16 or FP32 support
- any transport other than Verilator

**Risks:**
- *Verilator wall time before phase 7 is slow* (~36 minutes for the full test set). Run the 10k-image set only after phase 7, and use 512 images before that.
- *MNIST is not on disk.* FashionMNIST is, at `~/Code/ai/ml/mllearn/data/FashionMNIST/raw/` (see Q4).
- *The phase 5 local panels are a large unpacked array.* Verilator handles it. On the FPGA it must infer BSRAM, so access must be one read port per panel per cycle. Keep that shape from the start.

## 4. Milestone 2 outline (launch)

0. **Host link hardware:** connect a USB JTAG/UART debugger to the core board's 8-pin JST SH1.0 port (Q1). Program a bitstream from Gowin Programmer. Confirm DSP and LUT counts for N=8 and N=16 in Gowin EDA if phase 3 could not.
1. **Bring-up:** blinky (the core board LED or a header pin), then UART loopback through the debugger's UART, then a UART command decoder. The decoder turns packets into the same register and memory writes that the Verilator ABI uses. On the Rust side, add a `Transport` trait with Verilator and UART implementations; that is the first point where two implementations exist.
2. **Memory:** a BSRAM store (~160 KB, `8*N` bits wide) behind the existing `rd_*` and `wr_*` valid/ready ports, replacing `rpu_sim_memory`. Its timing matches the phase 6 model, so the RTL above it does not change. No DDR3 and no Gowin DDR IP.
3. **Synthesis:** Gowin EDA Education ≥ V1.9.11.03, device GW5AT-LV60PG484A (version B). Choose N=16 if it fits with DSP multipliers and meets timing, else N=12, else N=8. Report Fmax (target ≥ 100 MHz), LUT, FF, DSP, BSRAM and timing slack.
4. **Run:** download weights once (~100 KB over UART). Stream the 10k test images (7.8 MB, ~30 s at 3 Mbaud). The FPGA's predictions must equal the Verilator predictions bit for bit. Report device cycles per image x Fmax as images per second, with host-link time reported separately.
5. **Launch material:** photo or short video of the board classifying digits. Write `docs/m2-results.md` and add a resource table to the README.

## 5. README outline for the org

**Headline (fill in after phase 9; no numbers before they are measured):**

> RustingPU is an NxN (8x8 or 16x16, whichever was measured) INT8 systolic-array accelerator in SystemVerilog, driven from Rust. It runs a RustingBrain MNIST MLP at **X% test accuracy**, identical to the CPU int8 reference and Y pp from f32, in **Z cycles per image** at **U% array utilization**.

After milestone 2, add: "on a Sipeed Tang Mega 60K (Gowin GW5AT-60) at F MHz, using L LUTs and D DSPs."

**Scope statement:**

> This will not beat a GPU or your CPU on speed, and the simulation is far slower than either. The point is a complete chip design, from PE to DMA to driver, running a model trained by its own framework, with every result checked bit for bit against a software reference. The RPU does matrix multiplication only: the host quantizes, adds bias and applies activations. Until milestone 2 every number comes from Verilator, not silicon.

**Sections:**
- Numbers (table with commit, date and command)
- How it works: diagram of PE, array, panels, DMA and host
- Build: `cargo test`, `cargo run --release --example mnist`
- Limits
- Roadmap: milestone 2, then hardware bias/ReLU, then DDR3 for models larger than on-chip BSRAM

## 6. Questions for owner

1. **Debugger and power for the core board:** the core board (without the Dock) has only a JTAG + UART 8-pin JST SH1.0 port; the two 8P leads in the box are cables. Do you have a USB JTAG/UART debugger that Gowin Programmer supports for GW5A? Check Sipeed's compatibility list before buying. Or will you buy the Mega 60K Dock? How will you power the core board without the Dock? The Sipeed wiki does not say; check the core board schematic before applying power.
2. **Deadline:** is there a target date for milestone 1 or 2? The plan assumes 3-4 weeks part time for milestone 1.
3. **New dependency:** may RustingPU take `rusting_brain` as an *optional* dependency behind a `brain` feature? From crates.io `4`, git, or a path? No other new crates are needed. The existing `cc` build dependency is enough.
4. **Dataset:** download MNIST (~11 MB, never committed), or use the FashionMNIST already on disk? FashionMNIST is a harder task, so its accuracy number is less recognizable.
5. **Dead RTL:** delete the BF16 path and the old integer experiments (`systolic_cell.sv`, `rpu_core_*`, `rpu_orchestrator*.sv` except the active one, `rpu_soc.sv`, `sram.sv`, `dma_streamer.sv` and their testbenches)? Git history keeps them. The default is to delete; the alternative is moving them to `rtl/legacy/`.
6. **Hint.md is in `.gitignore`.** Is it meant to be private? The org repo needs its engineering guide tracked. The default is `docs/engineering.md`.
7. **Naming:** rename the crate `hardware_dev` to `rusting_pu`, and the repo directory to match? The brief says `/home/vasylt/Code/hardware`; the repo is at `/home/vasylt/Code/rusting/hardware`.
8. **Toolchain for milestone 2:** the plan uses Gowin EDA Education (≥ V1.9.11.03, free download). Open-source tools lack `gw5a` DSP inference. Is a proprietary build step acceptable for the org repo? Gowin EDA is only for the FPGA build; `cargo test` stays Verilator-only.
9. **Exact part:** the listing says "GW5AST"; the Sipeed wiki says GW5AT-LV60PG484A. Please read the marking on the chip, because Gowin EDA needs the exact device.
