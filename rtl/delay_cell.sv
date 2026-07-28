module delay_cell (
    input  logic clk, reset,
    input  logic [15:0] data_in,
    output logic [15:0] data_out
);
    always_ff @(posedge clk) begin
        if (reset) data_out <= 16'd0;
        else       data_out <= data_in;
    end
endmodule
