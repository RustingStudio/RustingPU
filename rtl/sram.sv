module sram (
    input  logic clk,
    input  logic we,
    input  logic [3:0] addr,
    input  logic [7:0] wdata,
    output logic [7:0] rdata
);

    logic [7:0] memory [0:15];

    initial begin
        for (int i = 0; i < 16; i++) begin
            memory[i] = 8'd0;
        end
    end

    always_ff @(posedge clk) begin
        if (we) begin
            memory[addr] <= wdata;
        end
    end

    assign rdata = memory[addr];

endmodule
