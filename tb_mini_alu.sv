`timescale 1ns / 1ps

module tb_mini_alu;
    logic [3:0] a, b;
    logic sub_mode;
    logic op_select;
    logic [3:0] result;

    mini_alu uut (.a(a), .b(b), .op_select(op_select), .result(result), .sub_mode(sub_mode));

    initial begin
        $monitor("Time: %0t | A: %04b | B: %04b | OpSelect: %b | RESULT: %04b | Sub Mode:",
                 $time, a, b, op_select, result, sub_mode);

        a = 4'b0011; b = 4'b0001; op_select = 0; sub_mode = 0;
        #10;

        a = 4'b0011; b = 4'b0001; op_select = 1; sub_mode = 0;
        #10;

        $finish;
    end
endmodule
