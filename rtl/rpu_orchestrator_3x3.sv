module rpu_orchestrator_3x3 (
    input  logic clk,
    input  logic reset,

    input  logic [3:0] a0_flat, a1_flat, a2_flat,
    input  logic [3:0] b0_flat, b1_flat, b2_flat,

    output logic [7:0] c00, c01, c02,
    output logic [7:0] c10, c11, c12,
    output logic [7:0] c20, c21, c22
);

    logic [3:0] a1_skewed, b1_skewed;
    logic [3:0] a2_delay1, a2_skewed;
    logic [3:0] b2_delay1, b2_skewed;

    delay_cell d_a1   (.clk(clk), .reset(reset), .data_in(a1_flat), .data_out(a1_skewed));
    delay_cell d_b1   (.clk(clk), .reset(reset), .data_in(b1_flat), .data_out(b1_skewed));

    delay_cell d_a2_0 (.clk(clk), .reset(reset), .data_in(a2_flat),   .data_out(a2_delay1));
    delay_cell d_a2_1 (.clk(clk), .reset(reset), .data_in(a2_delay1), .data_out(a2_skewed));

    delay_cell d_b2_0 (.clk(clk), .reset(reset), .data_in(b2_flat),   .data_out(b2_delay1));
    delay_cell d_b2_1 (.clk(clk), .reset(reset), .data_in(b2_delay1), .data_out(b2_skewed));

    rpu_core_3x3 core (
        .clk(clk), .reset(reset),
        .a0_in(a0_flat), .a1_in(a1_skewed), .a2_in(a2_skewed),
        .b0_in(b0_flat), .b1_in(b1_skewed), .b2_in(b2_skewed),
        .c00(c00), .c01(c01), .c02(c02),
        .c10(c10), .c11(c11), .c12(c12),
        .c20(c20), .c21(c21), .c22(c22)
    );

endmodule
