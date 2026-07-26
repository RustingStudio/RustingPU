`timescale 1ns / 1ps

module tb_d_ff;
    logic clk;
    logic d;
    logic q;

    d_ff uut (
        .clk(clk),
        .d(d),
        .q(q)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, tb_d_ff);

        d = 0;

        #12;
        d = 1;

        #15;
        d = 0;

        #20;
        $finish;
    end
endmodule
