module register_4bit (
    input  logic clk,
    input  logic reset,
    input  logic [3:0] d,
    output logic [3:0] q
);

    always_ff @(posedge clk) begin
        if (reset == 1'b1) begin
            q <= 4'b0000;
        end else begin
            q <= d;
        end
    end

endmodule
