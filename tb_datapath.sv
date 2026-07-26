`timescale 1ns / 1ps

module tb_datapath;
    logic clk, reset;
    logic [3:0] data_in;
    logic sub_mode, op_select;
    logic [3:0] out;

    datapath uut (
        .clk(clk), .reset(reset), .data_in(data_in),
        .sub_mode(sub_mode), .op_select(op_select), .out(out)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $monitor("Time: %0t | Reset: %b | Data_in: %d | Sub: %b | ACCUMULATOR (Out): %d",
                 $time, reset, data_in, sub_mode, out);

        reset = 1; data_in = 0; sub_mode = 0; op_select = 0;
        #10;

        reset = 0; data_in = 3; sub_mode = 0;
        #10;

        data_in = 2; sub_mode = 0;
        #10;

        data_in = 1; sub_mode = 1;
        #10;

        $finish;
    end
endmodule
