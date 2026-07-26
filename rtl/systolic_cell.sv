module systolic_cell (
    input  logic clk,
    input  logic reset,
    input  logic [3:0] a_in,
    input  logic [3:0] b_in,
    output logic [3:0] a_out,
    output logic [3:0] b_out,
    output logic [7:0] accumulator
);

    always_ff @(posedge clk) begin
        if (reset) begin
            accumulator <= 8'd0;
            a_out <= 4'd0;
            b_out <= 4'd0;
        end else begin
            accumulator <= (a_in * b_in) + accumulator;

            a_out <= a_in;
            b_out <= b_in;
        end
    end

endmodule
