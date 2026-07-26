`timescale 1ns / 1ps

module tb_rpu;
    logic clk, reset;
    logic [3:0] a0, a1, b0, b1;
    logic [7:0] c00, c01, c10, c11;

    rpu_core_2x2 uut (
        .clk(clk), .reset(reset),
        .a0_in(a0), .a1_in(a1), .b0_in(b0), .b1_in(b1),
        .c00(c00), .c01(c01), .c10(c10), .c11(c11)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $monitor("Time: %0t | C00: %d | C01: %d | C10: %d | C11: %d",
                 $time, c00, c01, c10, c11);

        reset = 1; a0=0; a1=0; b0=0; b1=0;
        #10;
        reset = 0;

        a0 = 1; a1 = 0;
        b0 = 5; b1 = 0;
        #10;

        a0 = 2; a1 = 3;
        b0 = 7; b1 = 6;
        #10;

        a0 = 0; a1 = 4;
        b0 = 0; b1 = 8;
        #10;

        a0 = 0; a1 = 0;
        b0 = 0; b1 = 0;
        #10;

        #10;

        $display("MATRIX C:");
        $display("[ %d   %d ]", c00, c01);
        $display("[ %d   %d ]", c10, c11);

        $finish;
    end
endmodule
