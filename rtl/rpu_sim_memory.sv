// Simulation model of the milestone-2 BSRAM store: BYTES of memory in 8*N-bit beats.
// Reads are pipelined: one request per cycle, data READ_LATENCY cycles later with
// rd_resp_valid. A read returns LOAD_BEATS beats from rd_addr rounded down to a multiple
// of LOAD_BEATS, the lowest beat first. Writes take one beat per cycle and never stall;
// rpu_top keeps host and DMA writes out of the same cycle, as the board's one write port
// needs; a cycle with both stops the simulation.
// The host port reads 64-bit words and writes HOST_WORDS of them from host_addr, a
// multiple of HOST_WORDS. A beat is N/8 words rounded up, lowest word first. When N is
// not a multiple of 8, the top bytes of a beat's last word are padding: reads drop them
// and DMA writes store zeros there.
module rpu_sim_memory #(
    parameter int N = 8,
    parameter int BYTES = 1 << 20,
    parameter int READ_LATENCY = 1,
    parameter int LOAD_BEATS = 1,
    parameter int HOST_WORDS = 1,
    parameter int BEAT_ADDR_W = $clog2(BYTES / N),
    parameter int HOST_ADDR_W = $clog2(BYTES / 8)
) (
    input  logic clk,
    input  logic reset,

    input  logic host_we,
    input  logic [HOST_ADDR_W-1:0] host_addr,
    input  logic [64*HOST_WORDS-1:0] host_wdata,
    output logic [63:0] host_rdata,

    input  logic rd_valid,
    input  logic [BEAT_ADDR_W-1:0] rd_addr,
    output logic rd_resp_valid,
    output logic [LOAD_BEATS*8*N-1:0] rd_data,

    input  logic wr_valid,
    input  logic [BEAT_ADDR_W-1:0] wr_addr,
    input  logic [8*N-1:0] wr_data
);

    localparam int BEAT_WORDS = (N + 7) / 8;

    logic [63:0] mem [0:BYTES/8-1];
    logic [READ_LATENCY-1:0] valid_pipe;
    logic [LOAD_BEATS*8*N-1:0] data_pipe [0:READ_LATENCY-1];
    /* verilator lint_off UNUSEDSIGNAL */
    logic [64*BEAT_WORDS-1:0] rd_words [LOAD_BEATS];  // the padding bytes above 8*N are dropped
    /* verilator lint_on UNUSEDSIGNAL */
    logic [LOAD_BEATS*8*N-1:0] rd_beats;
    logic [64*BEAT_WORDS-1:0] wr_words;

    always_comb begin
        for (int b = 0; b < LOAD_BEATS; b++) begin
            for (int w = 0; w < BEAT_WORDS; w++) begin
                rd_words[b][w*64 +: 64] =
                    mem[(int'(rd_addr) / LOAD_BEATS * LOAD_BEATS + b) * BEAT_WORDS + w];
            end
            rd_beats[b*8*N +: 8*N] = rd_words[b][8*N-1:0];
        end
    end
    assign wr_words = (64*BEAT_WORDS)'(wr_data);

    always_ff @(posedge clk) begin
        if (reset) begin
            valid_pipe <= '0;
        end else begin
            valid_pipe[0] <= rd_valid;
            for (int s = 1; s < READ_LATENCY; s++) valid_pipe[s] <= valid_pipe[s-1];
        end

        data_pipe[0] <= rd_beats;
        for (int s = 1; s < READ_LATENCY; s++) data_pipe[s] <= data_pipe[s-1];

`ifndef SYNTHESIS
        if (host_we && wr_valid) begin
            $fatal(1, "host and DMA write in one cycle: the board's memory has one write port");
        end
`endif
        if (host_we) begin
            for (int w = 0; w < HOST_WORDS; w++) begin
                mem[int'(host_addr) + w] <= host_wdata[w*64 +: 64];
            end
        end
        if (wr_valid) begin
            for (int w = 0; w < BEAT_WORDS; w++) begin
                mem[int'(wr_addr) * BEAT_WORDS + w] <= wr_words[w*64 +: 64];
            end
        end
    end

    assign rd_resp_valid = valid_pipe[READ_LATENCY-1];
    assign rd_data = data_pipe[READ_LATENCY-1];
    assign host_rdata = mem[host_addr];

endmodule
