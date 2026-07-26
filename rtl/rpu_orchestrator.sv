module rpu_orchestrator (
    input  logic clk,
    input  logic reset,

    input  logic [3:0] a0_flat,
    input  logic [3:0] a1_flat,

    input  logic [3:0] b0_flat,
    input  logic [3:0] b1_flat,

    output logic [7:0] c00, c01, c10, c11
);

    logic [3:0] a1_skewed;
    logic [3:0] b1_skewed;

    delay_cell delay_a1 (
        .clk(clk), .reset(reset),
        .data_in(a1_flat),
        .data_out(a1_skewed)
    );

    delay_cell delay_b1 (
        .clk(clk), .reset(reset),
        .data_in(b1_flat),
        .data_out(b1_skewed)
    );

    rpu_core_2x2 core (
        .clk(clk),
        .reset(reset),
        .a0_in(a0_flat),
        .a1_in(a1_skewed),
        .b0_in(b0_flat),
        .b1_in(b1_skewed),
        .c00(c00), .c01(c01), .c10(c10), .c11(c11)
    );

endmodule
