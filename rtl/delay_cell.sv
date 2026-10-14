module delay_cell #(
    parameter int W = 16
) (
    input  logic clk, reset,
    input  logic [W-1:0] data_in,
    output logic [W-1:0] data_out
);
    always_ff @(posedge clk) begin
        if (reset) data_out <= '0;
        else       data_out <= data_in;
    end
endmodule
