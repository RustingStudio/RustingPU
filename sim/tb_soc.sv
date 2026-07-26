`timescale 1ns / 1ps

module tb_soc;
    logic clk, reset;

    logic cpu_we;
    logic [3:0] cpu_addr;
    logic [7:0] cpu_wdata_a, cpu_wdata_b;
    logic dma_start;

    logic [7:0] c00, c01, c10, c11;

    rpu_soc uut (.*);

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $monitor("Time: %0t | DMA Addr: %d | C00: %d  C01: %d  C10: %d  C11: %d",
                 $time, uut.dma_addr, c00, c01, c10, c11);

        reset = 1; cpu_we = 0; dma_start = 0;
        #10;

        cpu_we = 1;

        cpu_addr = 0;
        cpu_wdata_a = {4'd3, 4'd1};
        cpu_wdata_b = {4'd6, 4'd5};
        #10;

        cpu_addr = 1;
        cpu_wdata_a = {4'd4, 4'd2};
        cpu_wdata_b = {4'd8, 4'd7};
        #10;

        cpu_we = 0;
        #10;

        reset = 0;
        dma_start = 1;
        #10;
        dma_start = 0;

        #60;

        $display("--------------------------------");
        $display("FINAL MATRIX C (Calculated via DMA):");
        $display("[ %d   %d ]", c00, c01);
        $display("[ %d   %d ]", c10, c11);
        $display("--------------------------------");

        $finish;
    end
endmodule
