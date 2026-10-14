# RustingPU

RustingPU is an 8x8 INT8 systolic-array accelerator in SystemVerilog, driven from Rust. It runs a RustingBrain MNIST MLP at **97.26% test accuracy**, identical to the CPU int8 reference and 0.00 pp from f32, in **1890.6 cycles per image** at **84.63% array utilization**. The array size is a build parameter; at 16x16 the same network takes 545.0 cycles per image at 73.39%.

This will not beat a GPU or your CPU on speed, and the simulation is far slower than either. The point is a complete chip design, from PE to DMA to driver, running a model trained by its own framework, with every result checked bit for bit against a software reference. The RPU does matrix multiplication only: the host quantizes, adds bias and applies activations. Until milestone 2 every number comes from Verilator, not silicon.

## Numbers

MNIST, 10,000 test images, 784-128-10 MLP (ReLU, softmax) trained with RustingBrain 4.0.0 on the CPU. Measured 2026-10-14 at commit `da4e054` plus `examples/mnist.rs`; details in [`docs/m1-results.md`](docs/m1-results.md).

| | N = 8 | N = 16 |
|---|---:|---:|
| f32 accuracy | 97.26% | 97.26% |
| Host int8 accuracy | 97.26% | 97.26% |
| RPU accuracy | 97.26% | 97.26% |
| Cycles per image | 1890.6 | 545.0 |
| Array utilization | 84.63% | 73.39% |

```bash
cargo run --release --features brain --example mnist          # N = 8
RPU_N=16 cargo run --release --features brain --example mnist # N = 16
```

## How it works

```text
host (Rust)                          RPU (SystemVerilog, simulated by Verilator)
  RpuMlp: quantize activations         register file: CONTROL, STATUS, A/B/C base, K
  write A, B to RPU memory  ----bus--> 1 MB memory, 8*N-bit beats
  start tiles, read C                  load FSM: A panel + two B panels (double-buffered)
  dequantize, bias, ReLU,              N x N array of int8 x int8 -> int32 PEs,
  softmax                              output-stationary, K streamed one per cycle
                                       C drained by shifting rows, stored while the
                                       next tile computes
```

The array computes `C[i][j] = sum_k A[i][k] * B[j][k]` for N x K panels, K up to 1024. A weight matrix `[out, in]` is used as B directly. Rust tiles larger matrices: A stays loaded across all output tiles of a row block, and the next B loads while the current tile computes. The full design is in [`docs/engineering.md`](docs/engineering.md).

## Build

Needs Rust, Verilator (5.052 tested) and a C++ compiler. Icarus and yosys are optional (smoke test, resource checks).

```bash
cargo test --release                   # bit-exact tests against the host int8 reference
cargo test --release --features brain  # plus the RustingBrain MLP test
RPU_N=16 cargo test --release          # another array size
```

The MNIST example reads the four unpacked IDX files from `data/mnist/` (not in the repository; download them from any MNIST mirror). The first run trains the network (about 20 s) and saves it there.

## Limits

- Simulation only. No FPGA bitstream, no host link.
- INT8 matmul only. Bias, ReLU, softmax and quantization run on the host. No convolution, no BF16 or FP32.
- K is at most 1024 per panel; partial sums over K are not split across jobs.
- All operands must fit in the 1 MB RPU memory.
- One A buffer: the first load of each block of N rows of A does not overlap compute. That is most of the gap between busy and streaming cycles.

## Roadmap

1. Milestone 2: the RPU on a Sipeed Tang Mega 60K (Gowin GW5AT-60), with the same predictions bit for bit as Verilator.
2. Bias and ReLU in hardware.
3. DDR3 for models larger than on-chip BSRAM.
