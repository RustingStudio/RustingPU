module rpu_core_2x2 (
    input  logic clk,
    input  logic reset,
    input  logic [3:0] a0_in,
    input  logic [3:0] a1_in,
    input  logic [3:0] b0_in,
    input  logic [3:0] b1_in,
    output logic [7:0] c00,
    output logic [7:0] c01,
    output logic [7:0] c10,
    output logic [7:0] c11
);

    logic [3:0] wire_a_00_to_01;
    logic [3:0] wire_a_10_to_11;
    logic [3:0] wire_b_00_to_10;
    logic [3:0] wire_b_01_to_11;

    logic [3:0] dump_a01, dump_a11;
    logic [3:0] dump_b10, dump_b11;

    systolic_cell cell_00 (
        .clk(clk), .reset(reset),
        .a_in(a0_in),           .b_in(b0_in),
        .a_out(wire_a_00_to_01),.b_out(wire_b_00_to_10),
        .accumulator(c00)
    );

    systolic_cell cell_01 (
        .clk(clk), .reset(reset),
        .a_in(wire_a_00_to_01), .b_in(b1_in),
        .a_out(dump_a01),       .b_out(wire_b_01_to_11),
        .accumulator(c01)
    );

    systolic_cell cell_10 (
        .clk(clk), .reset(reset),
        .a_in(a1_in),           .b_in(wire_b_00_to_10),
        .a_out(wire_a_10_to_11),.b_out(dump_b10),
        .accumulator(c10)
    );

    systolic_cell cell_11 (
        .clk(clk), .reset(reset),
        .a_in(wire_a_10_to_11), .b_in(wire_b_01_to_11),
        .a_out(dump_a11),       .b_out(dump_b11),
        .accumulator(c11)
    );

endmodule
