module bf16_systolic_cell (
    input  logic clk,
    input  logic reset,
    input  logic [15:0] a_in,
    input  logic [15:0] b_in,
    output logic [15:0] a_out,
    output logic [15:0] b_out,
    output logic [15:0] accumulator
);

    logic [15:0] wire_mult_result;
    logic [15:0] wire_add_result;

    bf16_multiplier mul (
        .a(a_in),
        .b(b_in),
        .result(wire_mult_result)
    );

    bf16_adder acc (
        .a(wire_mult_result),
        .b(accumulator),
        .result(wire_add_result)
    );

    always_ff @(posedge clk) begin
        if (reset) begin
            accumulator <= 16'd0;
            a_out       <= 16'd0;
            b_out       <= 16'd0;
        end else begin
            accumulator <= wire_add_result;
            a_out       <= a_in;
            b_out       <= b_in;
        end
    end

endmodule
