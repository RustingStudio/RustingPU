`timescale 1ns / 1ps

module tb_orch_3x3;
    logic clk, reset;
    logic [3:0] a0, a1, a2, b0, b1, b2;
    logic [7:0] c00, c01, c02, c10, c11, c12, c20, c21, c22;

    rpu_orchestrator_3x3 uut (
        .clk(clk), .reset(reset),
        .a0_flat(a0), .a1_flat(a1), .a2_flat(a2),
        .b0_flat(b0), .b1_flat(b1), .b2_flat(b2),
        .*
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        reset = 1;
        a0=0; a1=0; a2=0; b0=0; b1=0; b2=0;
        #10;
        reset = 0;

        a0=1; a1=1; a2=1;  b0=2; b1=2; b2=2;
        #10;

        a0=1; a1=1; a2=1;  b0=2; b1=2; b2=2;
        #10;

        a0=1; a1=1; a2=1;  b0=2; b1=2; b2=2;
        #10;

        a0=0; a1=0; a2=0;  b0=0; b1=0; b2=0;

        #60;

        $display("FINAL MATRIX C (3x3):");
        $display("[ %d   %d   %d ]", c00, c01, c02);
        $display("[ %d   %d   %d ]", c10, c11, c12);
        $display("[ %d   %d   %d ]", c20, c21, c22);

        $finish;
    end
endmodule
