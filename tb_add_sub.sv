`timescale 1ns / 1ps

module tb_add_sub;
    logic [3:0] a;
    logic [3:0] b;
    logic sub_mode;
    logic [3:0] result;
    logic cout;

    add_sub_4bit uut (
        .a(a),
        .b(b),
        .sub_mode(sub_mode),
        .result(result),
        .cout(cout)
    );

    initial begin
        $monitor("Time: %0t ns | A: %d | B: %d | Mode: %b | RESULT: %d | CarryOut: %b",
                 $time, a, b, sub_mode, result, cout);
        a = 5; b = 3; sub_mode = 0;
        #10;

        a = 10; b = 2; sub_mode = 0;
        #10;

        a = 7; b = 4; sub_mode = 1;
        #10;

        a = 15; b = 5; sub_mode = 1;
        #10;

        a = 3; b = 5; sub_mode = 1;
        #10;

        $finish;
    end
endmodule
