// INT8 x INT8 + INT32 processing element, 2 stages.
// Stage 1 registers the product (the DSP output register on an FPGA).
// Stage 2 accumulates: a single 32-bit carry chain.
// last_in marks the last k of a tile and travels with a. On the last product the sum
// goes to the shadow register (accumulator) and the running sum restarts at zero, so
// the next tile can stream while this one drains.
// drain: the shadow loads acc_in (the PE above), so the array shifts out one row per cycle.
module int8_cell (
    input  logic clk,
    input  logic reset,
    input  logic signed [7:0] a_in,
    input  logic signed [7:0] b_in,
    input  logic last_in,
    output logic signed [7:0] a_out,
    output logic signed [7:0] b_out,
    output logic last_out,
    input  logic drain,
    input  logic signed [31:0] acc_in,
    output logic signed [31:0] accumulator
);

    logic signed [15:0] product;
    logic last_product;
    logic signed [31:0] sum;
    logic signed [31:0] sum_next;

    assign sum_next = sum + {{16{product[15]}}, product};

    always_ff @(posedge clk) begin
        if (reset) begin
            product      <= '0;
            last_product <= 1'b0;
            sum          <= '0;
            accumulator  <= '0;
            a_out        <= '0;
            b_out        <= '0;
            last_out     <= 1'b0;
        end else begin
            product      <= a_in * b_in;
            last_product <= last_in;
            sum          <= last_product ? '0 : sum_next;
            if (drain) accumulator <= acc_in;
            else if (last_product) accumulator <= sum_next;
            a_out        <= a_in;
            b_out        <= b_in;
            last_out     <= last_in;
        end
    end

endmodule
