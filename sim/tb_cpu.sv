`timescale 1ns / 1ps

module tb_cpu;
    logic clk, reset;
    logic [3:0] cpu_out;

    cpu uut (.clk(clk), .reset(reset), .cpu_out(cpu_out));

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $monitor("Time: %0t | PC (Clock Cycle) | CPU_OUT (Accumulator): %d", $time, cpu_out);

        reset = 1;
        #10;

        reset = 0;

        #70;

        $finish;
    end
endmodule
