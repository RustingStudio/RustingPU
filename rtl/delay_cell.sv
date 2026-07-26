module delay_cell (
    input  logic clk,
    input  logic reset,
    input  logic [3:0] data_in,
    output logic [3:0] data_out
);
    always_ff @(posedge clk) begin
        if (reset)
            data_out <= 4'd0;
        else
            data_out <= data_in;
    end
endmodule
