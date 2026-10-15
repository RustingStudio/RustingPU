# RustingPU: a plain guide for the owner

This guide explains the project without assuming you know chip design. Read it top to bottom once. Then use it as a dictionary when something in `docs/perf-log.md` or in a chat makes no sense. Last updated 2026-10-15.

## 1. What this project is, in one paragraph

RustingPU (the "RPU") is a small AI chip that you are designing yourself. It does one job: it multiplies big tables of numbers (matrices), because that is almost all the work of a neural network. Google's TPU is the same idea at a much larger size. Today the RPU exists only as a design file and runs inside a simulator on your PC. The next step is to put it on your FPGA board, the Sipeed Tang Mega 60K. Later, a bigger FPGA can run a bigger RPU. If the design is good, it could one day become a real chip.

## 2. The parts, from small to big

```text
 your PC (Rust program)                     the RPU
 ┌─────────────────────┐   host link   ┌──────────────────────────────────────┐
 │ loads the network   │ ────────────> │ memory: holds weights and images     │
 │ sends images        │               │         │                            │
 │ reads the answers   │ <──────────── │         v                            │
 └─────────────────────┘               │ loader: copies a piece into the array│
                                       │         │                            │
                                       │         v                            │
                                       │ N x N array of tiny multipliers      │
                                       │         │                            │
                                       │         v                            │
                                       │ store: writes results back to memory │
                                       └──────────────────────────────────────┘
```

- **PE (processing element):** one tiny calculator. It multiplies two small numbers and adds the result to a running sum. That is one **MAC** (multiply and accumulate).
- **Array:** N × N PEs in a square grid. N = 8 means 64 PEs, N = 64 means 4,096 PEs. Bigger N means more work per clock tick.
- **Systolic:** numbers flow through the grid like water through pipes. Each PE hands its numbers to its neighbour on every tick. Data is read from memory once and then reused by a whole row or column of PEs. That reuse is why this kind of chip uses little energy.
- **Memory:** where the network's weights and the input images wait.
- **Sequencer:** a small controller inside the RPU. It cuts a big matrix into N × N pieces (**tiles**) and feeds them through the array one after another, so the PC only has to say "multiply these two matrices".
- **Host:** your PC. **Host link:** the cable or bus between PC and RPU. The PC sends the images and reads back the answers over it.

## 3. The test problem: MNIST

MNIST is 10,000 small pictures of handwritten digits, 0 to 9. The network looks at each picture and guesses the digit. It is the "hello world" of AI chips.

- Our network is a 784-128-10 MLP: 784 pixels in, 128 hidden values, 10 scores out.
- One picture needs about 100,000 multiplications.
- Accuracy is **97.25%**: 9,725 of 10,000 guesses are right.
- The RPU gives exactly the same answers as the same math done on the PC with the same small numbers. Every change is checked for this, picture by picture. If one answer differs, the change is wrong.

## 4. How to read the numbers

**Clock, cycle, MHz.** A chip works in ticks. One tick is one **cycle**. 100 MHz means 100 million ticks per second.

**Cycles per image.** How many ticks the RPU needs for one picture.

> time per picture = cycles per image ÷ clock speed
>
> Example: 1,624 cycles at 100 MHz = 16 microseconds = about 62,000 pictures per second.

We count cycles and not seconds because the clock speed of the real board is not known yet. The design runs in a simulator, not on the board.

**Utilization.** The share of time the array is really multiplying. 98% means the PEs almost never wait. Waiting PEs still use power, so a high value also means less wasted energy.

**Host words written / read per image.** How much data must go over the cable per picture. One word is 8 bytes. Fewer words means a slower cable is enough, and less energy is spent moving data.

**TOPS.** Trillions of operations per second. This is the usual speed rating of AI chips. One MAC counts as 2 operations.

> TOPS = N × N × clock × 2 ÷ 1,000,000,000,000

**TOPS per watt.** How much work you get from one watt of electricity. For a small, low-power chip like a TPU this is the most important number.

**Batch.** How many pictures are sent together. We use 64 by default and also log 256.

## 5. Where we are now

| Array | Where it can run | Cycles per image | Pictures per second (clock is a guess) |
|---|---|---:|---:|
| 8 × 8 | Tang Mega 60K (your board) | 1,624 | ~62,000 at 100 MHz |
| 16 × 16 | maybe Tang Mega 60K (not chosen) | 405 | ~250,000 at 100 MHz |
| 32 × 32 | mid FPGA, e.g. Kria K26 | 103 | ~2.4 million at 250 MHz |
| 64 × 64 | big FPGA, e.g. Xilinx VU9P | 27 | ~9 million at 250 MHz |

At the start of this work, 8 × 8 needed 1,891 cycles per image (now 14% fewer) and 16 × 16 needed 545 (now 26% fewer). The data sent per image dropped from 324 words to 101.5, and the data read back from 72 words to 5.

Rough comparison with real chips, as a speed rating (TOPS) and energy rating (TOPS per watt). These are estimates, not measurements:

| Chip | TOPS | TOPS per watt |
|---|---:|---:|
| RPU 8 × 8 on Tang Mega 60K | ~0.013 | ~0.005 |
| RPU 64 × 64 on a big FPGA | ~2 | ~0.05 |
| RTX 3060 graphics card | ~100 | ~0.6 |
| Google TPU v1 (2015) | 92 | ~2.3 |
| RPU as a real chip on a modern process (estimate) | depends on N | ~3 to 8 |

An FPGA is a test bench. The same design uses about 14 times more energy on an FPGA than on a real chip. The FPGA proves that the design is correct. The energy numbers that matter only come with a real chip.

## 6. Words you will see

| Word | Meaning |
|---|---|
| ASIC | A real, custom chip made in a factory. Fast and efficient, very expensive to make. |
| FPGA | A chip that can be rewired by a file. Slower than an ASIC, but you can try a design for the price of a board. |
| Bitstream | The file that rewires the FPGA into the RPU. |
| RTL, SystemVerilog | The language the chip is written in (files in `rtl/`). |
| Verilator | The simulator. It turns the RTL into a program that runs on your PC. |
| Synthesis, yosys | Turning RTL into a list of FPGA parts. It tells us how big the design is. |
| LUT | The basic logic block of an FPGA. How "big" a design is is mostly counted in LUTs. |
| FF, DFF | Flip-flop: one bit of storage. |
| DSP | A ready-made multiplier block on the FPGA. One PE needs about one DSP. |
| BSRAM, BRAM | Block memory on the FPGA. |
| LUT RAM | Memory built out of LUTs when block memory runs out. It uses up logic space. |
| DDR3 | The large memory chip next to the FPGA. Your core board already has one. |
| Fmax | The highest clock speed at which the design still works on a given chip. |
| INT8 | Whole numbers from -127 to 127. The RPU computes with these to save energy and space. |
| Quantization | Turning the network's precise numbers into INT8. Requantization does the same between layers, inside the RPU. |
| GEMM | A matrix multiplication. One network layer is one GEMM. |
| Tile, panel | A piece of a matrix that fits the array (tile) and the strip of data it needs (panel). |
| Bias, ReLU | Two small steps after each layer: add a number, then turn negatives into zero. |
| Bit-exact | The RPU's answer equals the PC's answer in every bit. |
| Mutation test | We break the design on purpose and check that a test notices. If no test notices, the tests are too weak. |
| Item | One improvement, logged in `docs/perf-log.md` with numbers before and after. |
| N | The array size: N × N PEs. |
| LOAD_BEATS | How many memory rows the loader reads per tick. 1 on your board, 2 for big FPGAs. |
| QUANT_PARTS | How many ticks the requantization of one row takes. 4 on your board, 1 for big arrays. |
| Host link, wall cycles | The cable to the PC, and the total ticks including the time spent waiting for that cable. |

## 7. What happened so far

- **Milestone 1 (done):** the MNIST network runs on the simulated RPU with bit-exact answers. The frozen numbers are in `docs/m1-results.md`.
- **Performance work (items 1 to 28, done):** 25 improvements kept, 2 rejected because they did not help, and 1 bug fix. The main ideas:
  - Keep the weights in RPU memory instead of sending them again with every batch (item 2).
  - Load the next piece of data while the array works on the current one (items 3, 5, 9, 12).
  - Do bias, ReLU and requantization inside the RPU, so the hidden layer never goes back to the PC (item 7).
  - Read and write only the useful parts of the results (items 16, 17).
  - Let big arrays load faster and store results faster (items 14, 18, 19, 20).
  - Do not reload weights that are still in place (item 22).
  - A wider path from the PC into RPU memory, and wall cycles as a second number (item 23).
  - Write the next pictures while the array still works on the current ones; the PC's writes wait while the RPU stores results (items 24, 25).
  - Start the next matrix multiplication as early as the results of the one before allow (items 27, 28). Now the 64 × 64 array is busy 99.5% of the time with useful work.
- The full log is `docs/perf-log.md`. The report page sums it up: https://claude.ai/artifact/GdpyGzsceWja15q26JuGrY

## 8. Your decisions so far

| Question | Your answer | What it means |
|---|---|---|
| Hardware bias, ReLU, requantization (P1) | Yes | Done in item 7. |
| Bigger designs than your board | Yes, on FPGAs you can buy, no ASIC for now | Every feature must also work for N = 32 and 64. |
| Batch 256 | Configurable, log both | Batch 64 stays the main number. |
| Q2: first array size on the board | 8 × 8 | Safe fit. 16 × 16 can be tried later. |
| Q3: real DSP count on the board | Left to the agent | Gowin's own tool (Gowin EDA) is installed at the start of milestone 2. It is needed there anyway to make the bitstream. |
| Q4: DDR3 | Yes, plan it for milestone 3 | The DDR3 chip is already on your core board. Nothing to buy for it. |
| Q6: faster requantization for big arrays | Yes | QUANT_PARTS = 1 is the default above N = 16 (commit `a8b5e28`). |
| Q7: PC writes while the RPU reads | Arbiter | The PC's writes wait while the RPU stores results into memory (done in item 25). Simple, and it prepares for DDR3. |
| Q8: the cable is the limit for big arrays | Wider write path first, count wall cycles | Done in item 23. DDR3 input storage comes in milestone 3. |

## 9. What comes next

1. **Simulation work is done for now.** On every array size the array is busy with useful work at least 98% of the time, so no change is expected to gain 2% or more. The open questions are at the end of `docs/perf-log.md`.
2. **Milestone 2, the board.**
   1. Install Gowin EDA (free Education edition).
   2. Build the 8 × 8 RPU bitstream.
   3. Measure the real Fmax and the real DSP count.
   4. Make an LED blink.
   5. Talk to the PC over UART.
   6. Run all 10,000 MNIST pictures and check that the board's answers equal the simulator's, bit for bit.
   7. Make a photo or video for the launch.
3. **Milestone 3, DDR3:** bigger networks that do not fit in the FPGA's own memory.
4. **Later, big FPGAs:** N = 32 or 64 on a rented or bought big FPGA (for example an AWS F1 instance with a VU9P).

## 10. What you need to do or buy

- **For milestone 2:** a USB JTAG/UART debugger that Gowin Programmer supports for the GW5A chip, or the Tang Mega 60K Dock board, which has one built in. Your core board has only an 8-pin JST SH1.0 connector, and the cables in the box are not a debugger. Check Sipeed's compatibility list before buying.
- **Power for the core board without the Dock:** the Sipeed wiki does not say how. Check the schematic before you connect power, or buy the Dock.
- **Before Gowin EDA:** read the marking on the FPGA chip (GW5AT-LV60PG484A or similar). The tool needs the exact part name.
- **Nothing for DDR3.** It is already on the board.

## 11. How to run it yourself

From the repository folder:

```bash
cargo test --release                                   # all correctness checks, 8 × 8 (a minute or less)
cargo run --release --features brain --example mnist   # 10,000 MNIST pictures on the simulated RPU
RPU_N=16 cargo run --release --features brain --example mnist   # same with 16 × 16
RPU_N=64 RPU_LOAD_BEATS=2 cargo run --release --features brain --example mnist   # a big array
```

The MNIST run prints the accuracy, the cycles per image, the utilization and the host words. The first run trains the network (about 20 seconds). The MNIST files must be in `data/mnist/`.

## 12. Where things are

| Path | What it is |
|---|---|
| `rtl/` | The chip itself (SystemVerilog). `rpu_top.sv` is the main file. |
| `src/lib.rs` | The Rust driver that talks to the RPU, and most tests. |
| `src/brain.rs` | Runs a RustingBrain network on the RPU. |
| `examples/mnist.rs` | The MNIST benchmark. |
| `docs/perf-log.md` | Every improvement with numbers, and the open questions. |
| `docs/engineering.md` | The detailed design, for engineers. |
| `docs/plan-milestone-1.md` | The plan, including milestone 2 on the board. |
| `docs/m1-results.md` | The frozen milestone 1 numbers. |
| `README.md` | The public summary. |

## 13. How to work with Claude on this

- If an answer is too technical, say "explain simpler" or "what does X mean". Nothing here assumes you already know it.
- When you get a question, it is enough to say "do what you recommend". Each question comes with a recommendation.
- Nothing is pushed, merged into `main` or released without your word. All work stays on the local `rpu-perf` branch.
