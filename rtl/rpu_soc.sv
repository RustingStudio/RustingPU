module rpu_soc (
    input logic clk,
    input logic reset,
    input logic cpu_we,
    input logic [3:0] cpu_addr,
    input logic [7:0] cpu_wdata_a,
    input logic [7:0] cpu_wdata_b,
    input logic dma_start,
    output logic [7:0] cpu_rdata
);

    logic [3:0] dma_addr;
    logic [3:0] active_addr;
    logic [7:0] sram_a_out, sram_b_out;

    assign active_addr = cpu_we ? cpu_addr : dma_addr;

    sram memory_a (
        .clk(clk), .we(cpu_we), .addr(active_addr),
        .wdata(cpu_wdata_a), .rdata(sram_a_out)
    );

    sram memory_b (
        .clk(clk), .we(cpu_we), .addr(active_addr),
        .wdata(cpu_wdata_b), .rdata(sram_b_out)
    );

    dma_streamer dma (
        .clk(clk), .reset(reset), .start(dma_start),
        .sram_addr(dma_addr), .rpu_valid()
    );

    logic [7:0] c00, c01, c10, c11;

    rpu_orchestrator math_core (
        .clk(clk), .reset(reset),
        .a1_flat(sram_a_out[7:4]), .a0_flat(sram_a_out[3:0]),
        .b1_flat(sram_b_out[7:4]), .b0_flat(sram_b_out[3:0]),
        .c00(c00), .c01(c01), .c10(c10), .c11(c11)
    );

    always_comb begin
        case (cpu_addr)
            4'd4: cpu_rdata = c00;
            4'd5: cpu_rdata = c01;
            4'd6: cpu_rdata = c10;
            4'd7: cpu_rdata = c11;
            default: cpu_rdata = 8'd0;
        endcase
    end

endmodule
