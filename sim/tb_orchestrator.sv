`timescale 1ns / 1ps

module tb_orchestrator;
    logic clk, reset;
    logic [3:0] a0, a1, b0, b1;
    logic [7:0] c00, c01, c10, c11;

    rpu_orchestrator uut (
        .clk(clk), .reset(reset),
        .a0_flat(a0), .a1_flat(a1), .b0_flat(b0), .b1_flat(b1),
        .c00(c00), .c01(c01), .c10(c10), .c11(c11)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $monitor("Time: %0t | A=[%d, %d] B=[%d, %d] | C00:%d C01:%d C10:%d C11:%d",
                 $time, a0, a1, b0, b1, c00, c01, c10, c11);

        reset = 1; a0=0; a1=0; b0=0; b1=0;
        #10;
        reset = 0;

        a0 = 1; a1 = 3;
        b0 = 5; b1 = 6;
        #10;

        a0 = 2; a1 = 4;
        b0 = 7; b1 = 8;
        #10;

        a0 = 0; a1 = 0;
        b0 = 0; b1 = 0;

        #30;

        $display("FINAL MATRIX C:");
        $display("[ %d   %d ]", c00, c01);
        $display("[ %d   %d ]", c10, c11);
        $finish;
    end
endmodule
