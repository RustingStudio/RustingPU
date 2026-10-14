// Simulation model of the milestone-2 BSRAM store: BYTES of memory in 8*N-bit beats.
// Reads are pipelined: one request per cycle, data READ_LATENCY cycles later with
// rd_resp_valid. Writes take one beat per cycle and never stall. The host port reads
// and writes 64-bit words; a beat is N/8 words, lowest word first.
module rpu_sim_memory #(
    parameter int N = 8,
    parameter int BYTES = 1 << 20,
    parameter int READ_LATENCY = 1,
    parameter int BEAT_ADDR_W = $clog2(BYTES / N),
    parameter int HOST_ADDR_W = $clog2(BYTES / 8)
) (
    input  logic clk,
    input  logic reset,

    input  logic host_we,
    input  logic [HOST_ADDR_W-1:0] host_addr,
    input  logic [63:0] host_wdata,
    output logic [63:0] host_rdata,

    input  logic rd_valid,
    input  logic [BEAT_ADDR_W-1:0] rd_addr,
    output logic rd_resp_valid,
    output logic [8*N-1:0] rd_data,

    input  logic wr_valid,
    input  logic [BEAT_ADDR_W-1:0] wr_addr,
    input  logic [8*N-1:0] wr_data
);

    localparam int BEAT_WORDS = N / 8;

    logic [63:0] mem [0:BYTES/8-1];
    logic [READ_LATENCY-1:0] valid_pipe;
    logic [8*N-1:0] data_pipe [0:READ_LATENCY-1];

    initial begin
        if (N % 8 != 0) $fatal(1, "rpu_sim_memory: N must be a multiple of 8");
    end

    always_ff @(posedge clk) begin
        if (reset) begin
            valid_pipe <= '0;
        end else begin
            valid_pipe[0] <= rd_valid;
            for (int s = 1; s < READ_LATENCY; s++) valid_pipe[s] <= valid_pipe[s-1];
        end

        for (int w = 0; w < BEAT_WORDS; w++) begin
            data_pipe[0][w*64 +: 64] <= mem[int'(rd_addr) * BEAT_WORDS + w];
        end
        for (int s = 1; s < READ_LATENCY; s++) data_pipe[s] <= data_pipe[s-1];

        if (host_we) mem[host_addr] <= host_wdata;
        if (wr_valid) begin
            for (int w = 0; w < BEAT_WORDS; w++) begin
                mem[int'(wr_addr) * BEAT_WORDS + w] <= wr_data[w*64 +: 64];
            end
        end
    end

    assign rd_resp_valid = valid_pipe[READ_LATENCY-1];
    assign rd_data = data_pipe[READ_LATENCY-1];
    assign host_rdata = mem[host_addr];

endmodule
