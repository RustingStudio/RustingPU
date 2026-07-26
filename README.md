## To compile RPU use
```
iverilog -g2012 -o cpu_sim rtl/full_adder.sv rtl/add_sub_4bit.sv rtl/mux_2to1.sv rtl/mini_alu.sv rtl/register_4bit.sv rtl/datapath.sv rtl/control_unit.sv rtl/cpu.sv rtl/multiplier.sv sim/tb_cpu.sv
```

## And to test if it worked, use
```
vvp cpu_sim
```
