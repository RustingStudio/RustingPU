module rpu_sim_memory #(
    parameter int WORDS = 4096,
    parameter int ADDR_W = 12,
    parameter int READ_LATENCY = 1,
    parameter int WRITE_LATENCY = 1
) (
    input  logic clk,
    input  logic reset,

    input  logic host_we,
    input  logic host_bank,
    input  logic [ADDR_W-1:0] host_addr,
    input  logic [15:0] host_wdata,
    output logic [15:0] host_rdata,

    input  logic rd_valid,
    input  logic rd_bank,
    input  logic [ADDR_W-1:0] rd_addr,
    output logic rd_ready,
    output logic [15:0] rd_data,

    input  logic wr_valid,
    input  logic wr_bank,
    input  logic [ADDR_W-1:0] wr_addr,
    input  logic [15:0] wr_data,
    output logic wr_ready
);

    localparam int READ_COUNT_W = (READ_LATENCY > 1) ? $clog2(READ_LATENCY) : 1;
    localparam int WRITE_COUNT_W = (WRITE_LATENCY > 1) ? $clog2(WRITE_LATENCY) : 1;

    logic [15:0] mem [0:1][0:WORDS-1];

    logic read_pending;
    logic read_bank_pending;
    logic [ADDR_W-1:0] read_addr_pending;
    logic [READ_COUNT_W-1:0] read_count;

    logic write_pending;
    logic write_bank_pending;
    logic [ADDR_W-1:0] write_addr_pending;
    logic [15:0] write_data_pending;
    logic [WRITE_COUNT_W-1:0] write_count;

    always_ff @(posedge clk) begin
        if (reset) begin
            rd_ready <= 1'b0;
            rd_data <= 16'd0;
            wr_ready <= 1'b0;
            read_pending <= 1'b0;
            read_bank_pending <= 1'b0;
            read_addr_pending <= '0;
            read_count <= '0;
            write_pending <= 1'b0;
            write_bank_pending <= 1'b0;
            write_addr_pending <= '0;
            write_data_pending <= 16'd0;
            write_count <= '0;
        end else begin
            rd_ready <= 1'b0;
            wr_ready <= 1'b0;

            if (host_we) begin
                mem[host_bank][host_addr] <= host_wdata;
            end

            if (read_pending) begin
                if (read_count == '0) begin
                    rd_data <= mem[read_bank_pending][read_addr_pending];
                    rd_ready <= 1'b1;
                    read_pending <= 1'b0;
                end else begin
                    read_count <= read_count - 1'b1;
                end
            end else if (rd_valid && !rd_ready) begin
                read_pending <= 1'b1;
                read_bank_pending <= rd_bank;
                read_addr_pending <= rd_addr;
                read_count <= READ_COUNT_W'(READ_LATENCY - 1);
            end

            if (write_pending) begin
                if (write_count == '0) begin
                    mem[write_bank_pending][write_addr_pending] <= write_data_pending;
                    wr_ready <= 1'b1;
                    write_pending <= 1'b0;
                end else begin
                    write_count <= write_count - 1'b1;
                end
            end else if (wr_valid && !wr_ready) begin
                write_pending <= 1'b1;
                write_bank_pending <= wr_bank;
                write_addr_pending <= wr_addr;
                write_data_pending <= wr_data;
                write_count <= WRITE_COUNT_W'(WRITE_LATENCY - 1);
            end
        end
    end

    assign host_rdata = mem[host_bank][host_addr];

endmodule
