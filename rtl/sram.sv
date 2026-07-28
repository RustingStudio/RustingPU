module sram #(
    parameter DEPTH = 64,
    parameter WIDTH = 16
)(
    input  logic clk,
    input  logic we,
    input  logic [$clog2(DEPTH)-1:0] addr,
    input  logic [WIDTH-1:0] wdata,
    output logic [WIDTH-1:0] rdata
);

    logic [WIDTH-1:0] memory [0:DEPTH-1];

    initial begin
        for (int i = 0; i < DEPTH; i++) begin
            memory[i] = '0;
        end
    end

    always_ff @(posedge clk) begin
        if (we) begin
            memory[addr] <= wdata;
        end
    end
    assign rdata = memory[addr];

endmodule
