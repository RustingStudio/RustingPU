module rpu_core_3x3 (
    input  logic clk,
    input  logic reset,

    input  logic [3:0] a0_in, a1_in, a2_in,

    input  logic [3:0] b0_in, b1_in, b2_in,

    output logic [7:0] c00, c01, c02,
    output logic [7:0] c10, c11, c12,
    output logic [7:0] c20, c21, c22
);

    logic [3:0] w_a_00_01, w_a_01_02, dump_a_02;
    logic [3:0] w_a_10_11, w_a_11_12, dump_a_12;
    logic [3:0] w_a_20_21, w_a_21_22, dump_a_22;

    logic [3:0] w_b_00_10, w_b_10_20, dump_b_20;
    logic [3:0] w_b_01_11, w_b_11_21, dump_b_21;
    logic [3:0] w_b_02_12, w_b_12_22, dump_b_22;

    systolic_cell c_00 (.clk(clk), .reset(reset), .a_in(a0_in), .b_in(b0_in), .a_out(w_a_00_01), .b_out(w_b_00_10), .accumulator(c00));
    systolic_cell c_01 (.clk(clk), .reset(reset), .a_in(w_a_00_01), .b_in(b1_in), .a_out(w_a_01_02), .b_out(w_b_01_11), .accumulator(c01));
    systolic_cell c_02 (.clk(clk), .reset(reset), .a_in(w_a_01_02), .b_in(b2_in), .a_out(dump_a_02), .b_out(w_b_02_12), .accumulator(c02));

    systolic_cell c_10 (.clk(clk), .reset(reset), .a_in(a1_in), .b_in(w_b_00_10), .a_out(w_a_10_11), .b_out(w_b_10_20), .accumulator(c10));
    systolic_cell c_11 (.clk(clk), .reset(reset), .a_in(w_a_10_11), .b_in(w_b_01_11), .a_out(w_a_11_12), .b_out(w_b_11_21), .accumulator(c11));
    systolic_cell c_12 (.clk(clk), .reset(reset), .a_in(w_a_11_12), .b_in(w_b_02_12), .a_out(dump_a_12), .b_out(w_b_12_22), .accumulator(c12));

    systolic_cell c_20 (.clk(clk), .reset(reset), .a_in(a2_in), .b_in(w_b_10_20), .a_out(w_a_20_21), .b_out(dump_b_20), .accumulator(c20));
    systolic_cell c_21 (.clk(clk), .reset(reset), .a_in(w_a_20_21), .b_in(w_b_11_21), .a_out(w_a_21_22), .b_out(dump_b_21), .accumulator(c21));
    systolic_cell c_22 (.clk(clk), .reset(reset), .a_in(w_a_21_22), .b_in(w_b_12_22), .a_out(dump_a_22), .b_out(dump_b_22), .accumulator(c22));

endmodule
