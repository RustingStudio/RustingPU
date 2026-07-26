module mac_unit (
    input  logic clk,
    input  logic reset,
    input  logic [3:0] a,
    input  logic [3:0] b,
    output logic [7:0] accumulator
);

    always_ff @(posedge clk) begin
        if (reset)
            accumulator <= 8'b00000000;
        else
            accumulator <= (a * b) + accumulator;
    end

endmodule
