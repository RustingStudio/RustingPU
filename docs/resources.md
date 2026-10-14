# Resource use

Synthesis only (no place and route), `yosys 0.66`, top `rpu_array` (the N x N INT8 PE array
with its input skew registers; no SoC, buffers or DMA). Gowin EDA is not installed yet, so
the GW5A DSP count is deferred to milestone 2, step 0.

Command (N = 8 or 16, FAMILY = gw5a or gw2a):

```sh
yosys -p "read_verilog -sv rtl/delay_cell.sv rtl/int8_cell.sv rtl/rpu_array.sv; \
          chparam -set N $N rpu_array; synth_gowin -family $FAMILY -top rpu_array; stat"
```

## Phase 3, 2026-10-14

| N | Family | LUT1-4 | ALU | LUT+ALU | DFF | MULT9X9 | MUX2_LUT5-8 |
|---|---|---|---|---|---|---|---|
| 8 | gw5a | 21,186 | 3,072 | 24,258 | 4,416 | 0 | 12,802 |
| 16 | gw5a | 84,768 | 12,288 | 97,056 | 18,048 | 0 | 51,232 |
| 8 | gw2a | 0 | 2,048 | 2,048 | 4,416 | 64 | 0 |
| 16 | gw2a | 0 | 8,192 | 8,192 | 18,048 | 256 | 0 |

- **gw5a is LUT-only.** Yosys 0.66 has no DSP inference for gw5a, so every 8x8 multiply is
  built from LUTs: about 379 LUT+ALU per PE (plan estimate: ~411). N=16 LUT-only needs
  97k LUT+ALU, 162% of the 59,904 LUT4 on the GW5AT-LV60. N=16 therefore needs DSP
  multipliers, as the plan says. The real GW5A DSP count must come from Gowin EDA.
- **gw2a shows what DSP inference does.** One MULT9X9 per PE, the 32-bit accumulator in 32
  ALU cells, and no LUTs at all. 69 DFF per PE (8+8 pass-through, 16 product, 32 acc, plus
  the skew chain; unused right-column a_out and bottom-row b_out are removed).
- The DFF count is identical across families: the product register is kept in both.
- IBUF/OBUF (130 / 2,048) are not counted: they exist only because the array is the top
  module here. Inside `rpu_top` these are internal nets.
