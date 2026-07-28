`timescale 1ns / 1ps

module tb_tpu;
    parameter N = 2;
    logic clk, reset;
    logic [15:0] a_flat [0:N-1];
    logic [15:0] b_flat [0:N-1];
    logic [15:0] c [0:N-1][0:N-1];

    rpu_orchestrator_bf16 #(.N(N)) uut (.*);

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    function real bf16_to_real(input logic [15:0] bf);
        real res;
        int exp;
        real fract;
        if (bf == 16'd0) return 0.0;
        exp = bf[14:7] - 127;
        fract = 1.0 + (bf[6:0] / 128.0);
        res = fract * (2.0 ** exp);
        if (bf[15]) res = -res;
        return res;
    endfunction

    initial begin
        reset = 1;
        a_flat[0]=0; a_flat[1]=0; b_flat[0]=0; b_flat[1]=0;
        #10;
        reset = 0;

        $display("STARTING TENSOR PROCESSING");


        a_flat[0] = 16'h3FC0; // 1.5
        a_flat[1] = 16'h0000; // 0.0
        b_flat[0] = 16'h4000; // 2.0
        b_flat[1] = 16'h0000; // 0.0
        #10;

        a_flat[0] = 16'h4000; // 2.0
        a_flat[1] = 16'h3F80; // 1.0
        b_flat[0] = 16'h0000; // 0.0
        b_flat[1] = 16'h4040; // 3.0
        #10;

        a_flat[0]=0; a_flat[1]=0; b_flat[0]=0; b_flat[1]=0;

        #40;

        $display("\nMATRIX C");
        $display("[ %f   %f ]", bf16_to_real(c[0][0]), bf16_to_real(c[0][1]));
        $display("[ %f   %f ]", bf16_to_real(c[1][0]), bf16_to_real(c[1][1]));
        $display("");

        $finish;
    end
endmodule
