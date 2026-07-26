## To compile RPU use
```
iverilog -g2012 -o cpu_sim full_adder.sv add_sub_4bit.sv mux_2to1.sv mini_alu.sv register_4bit.sv datapath.sv control_unit.sv cpu.sv tb_cpu.sv
```

## And to test if it worked, use
```
vvp cpu_sim
```
