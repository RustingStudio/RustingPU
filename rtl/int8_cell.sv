// INT8 x INT8 + INT32 processing element, 2 stages.
// Stage 1 registers the product (the DSP output register on an FPGA).
// Stage 2 accumulates: a single 32-bit carry chain.
// drain: load acc_in (the left neighbour) instead, so the array shifts out one column per cycle.
module int8_cell (
    input  logic clk,
    input  logic reset,
    input  logic signed [7:0] a_in,
    input  logic signed [7:0] b_in,
    output logic signed [7:0] a_out,
    output logic signed [7:0] b_out,
    input  logic drain,
    input  logic signed [31:0] acc_in,
    output logic signed [31:0] accumulator
);

    logic signed [15:0] product;

    always_ff @(posedge clk) begin
        if (reset) begin
            product     <= '0;
            accumulator <= '0;
            a_out       <= '0;
            b_out       <= '0;
        end else begin
            product     <= a_in * b_in;
            accumulator <= drain ? acc_in : accumulator + {{16{product[15]}}, product};
            a_out       <= a_in;
            b_out       <= b_in;
        end
    end

endmodule
