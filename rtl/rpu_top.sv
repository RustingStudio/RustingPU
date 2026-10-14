// RPU top: register file, int8 panel buffers, DMA FSMs and the systolic array.
// C = A * B^T (NT GEMM) with A and B both N x K_LEN, 1 <= K_LEN <= KMAX.
// Bus words are 16 bits. A and B rows hold two int8 per word (even k in the low
// byte), each row padded to an even length. C holds each int32 as two words, low
// half first.
module rpu_top #(
    parameter int N = 8,
    parameter int KMAX = 1024,
    parameter int ADDR_W = 16
) (
    input  logic clk,
    input  logic reset,
    input  logic start,

    input  logic mem_we,
    input  logic [ADDR_W-1:0] mem_addr,
    input  logic [15:0] mem_wdata,
    output logic [15:0] mem_rdata,

    output logic [31:0] cycles,
    output logic busy,
    output logic done
);

    localparam int ROW_WORDS = KMAX / 2;       // two int8 per word; KMAX must be even
    localparam int PANEL_WORDS = N * ROW_WORDS;
    localparam int C_WORDS = N * N * 2;        // one int32 is two words
    // Each external bank holds an A panel, a B panel and a C tile.
    localparam int EXT_WORDS = 2 * PANEL_WORDS + C_WORDS;
    localparam int PE_LATENCY = 2;             // product register + accumulator
    // Last product reaches PE (N-1, N-1) after 2N-2 skew cycles, then PE_LATENCY.
    localparam int SETTLE_STEPS = 2 * N - 2 + PE_LATENCY;
    localparam int COL_W = (N > 1) ? $clog2(N) : 1;
    localparam int K_W = $clog2(KMAX + 1);     // holds K_LEN up to KMAX
    localparam int WORD_W = (ROW_WORDS > 1) ? $clog2(ROW_WORDS) : 1;
    localparam int DRAIN_W = $clog2(SETTLE_STEPS + 1);
    localparam int LOAD_W = $clog2(PANEL_WORDS + 1);
    localparam int DMA_W = $clog2(C_WORDS);
    localparam int EXT_ADDR_W = $clog2(EXT_WORDS);
    localparam logic [COL_W-1:0] COL_LAST = COL_W'(N - 1);
    localparam logic [DRAIN_W-1:0] SETTLE_LAST = DRAIN_W'(SETTLE_STEPS - 1);
    localparam logic [DRAIN_W-1:0] DRAIN_LAST = DRAIN_W'(N - 1);
    localparam logic [DMA_W-1:0] STORE_LAST = DMA_W'(C_WORDS - 1);
    localparam int unsigned REG_CONTROL_ADDR = 0;
    localparam int unsigned REG_STATUS_ADDR = 1;
    localparam int unsigned REG_A_BASE_ADDR = 2;
    localparam int unsigned REG_B_BASE_ADDR = 3;
    localparam int unsigned REG_C_BASE_ADDR = 4;
    localparam int unsigned REG_K_LEN_ADDR = 5;
    localparam int unsigned REG_ACTIVE_LO_ADDR = 6;
    localparam int unsigned REG_ACTIVE_HI_ADDR = 7;
    localparam int unsigned REG_BUSY_LO_ADDR = 8;
    localparam int unsigned REG_BUSY_HI_ADDR = 9;
    localparam int unsigned EXT_BASE_ADDR = 4096;

    // C buffer: one wide word per array column, written by the shift drain one
    // column per cycle (one write port, so it can map to BSRAM).
    logic [N-1:0][31:0] mem_c [0:N-1];

    logic [15:0] reg_a_base;
    logic [15:0] reg_b_base;
    logic [15:0] reg_c_base;
    logic [K_W-1:0] reg_k_len;
    // Free-running since reset: cycles the array streams, and cycles busy.
    logic [31:0] active_cycles;
    logic [31:0] busy_cycles;
    logic start_request;
    logic preload_request;
    logic control_bank;

    typedef enum logic [1:0] {
        LOAD_IDLE,
        LOAD_A,
        LOAD_B
    } load_state_t;

    typedef enum logic [2:0] {
        COMPUTE_IDLE,
        COMPUTE_CLEAR,
        COMPUTE_STREAM,
        COMPUTE_SETTLE,
        COMPUTE_DRAIN,
        COMPUTE_STORE_C,
        COMPUTE_FINISH
    } compute_state_t;

    load_state_t load_state;
    compute_state_t compute_state;

    logic [LOAD_W-1:0] load_idx;
    logic [COL_W-1:0] load_row;
    logic [WORD_W-1:0] load_word;
    logic [WORD_W-1:0] load_word_last;
    logic [DMA_W-1:0] store_idx;
    logic [COL_W-1:0] store_row;
    logic [COL_W-1:0] store_col;
    logic [K_W-1:0] stream_k;
    logic [K_W-1:0] stream_last;
    logic [DRAIN_W-1:0] drain_count;

    logic load_local_bank;
    logic load_ext_bank;
    logic load_then_compute;
    logic [15:0] load_a_base;
    logic [15:0] load_b_base;
    logic [15:0] load_c_base;

    logic compute_local_bank;
    logic compute_ext_bank;
    logic [15:0] compute_c_base;
    logic local_valid [0:1];
    logic [K_W-1:0] local_k_len [0:1];
    logic [K_W-1:0] load_k_len;

    logic [N-1:0][7:0] a_flat;
    logic [N-1:0][7:0] b_flat;
    logic [N-1:0][31:0] c_col;
    logic core_reset;
    logic load_busy;
    logic compute_busy;
    logic host_ext_we;
    logic host_ext_bank;
    logic [EXT_ADDR_W-1:0] host_ext_addr;
    logic [15:0] host_ext_rdata;
    logic dma_rd_valid;
    logic dma_rd_bank;
    logic [EXT_ADDR_W-1:0] dma_rd_addr;
    logic dma_rd_ready;
    logic [15:0] dma_rd_data;
    logic dma_wr_valid;
    logic dma_wr_bank;
    logic [EXT_ADDR_W-1:0] dma_wr_addr;
    logic [15:0] dma_wr_data;
    logic dma_wr_ready;

    assign load_busy = (load_state != LOAD_IDLE);
    assign compute_busy = (compute_state == COMPUTE_CLEAR) ||
                          (compute_state == COMPUTE_STREAM) ||
                          (compute_state == COMPUTE_SETTLE) ||
                          (compute_state == COMPUTE_DRAIN) ||
                          (compute_state == COMPUTE_STORE_C);
    assign busy = load_busy || compute_busy;
    assign done = (compute_state == COMPUTE_FINISH);
    assign core_reset = reset || (compute_state == COMPUTE_CLEAR);

    // Panel buffers: one memory per array row, so each has one write and one read port.
    genvar i;
    generate
        for (i = 0; i < N; i++) begin : panel_row
            logic [15:0] row_a [0:1][0:ROW_WORDS-1];
            logic [15:0] row_b [0:1][0:ROW_WORDS-1];
            logic [15:0] word_a;
            logic [15:0] word_b;

            always_ff @(posedge clk) begin
                if (dma_rd_ready && load_row == COL_W'(i)) begin
                    if (load_state == LOAD_A) row_a[load_local_bank][load_word] <= dma_rd_data;
                    if (load_state == LOAD_B) row_b[load_local_bank][load_word] <= dma_rd_data;
                end
            end

            assign word_a = row_a[compute_local_bank][stream_k[WORD_W:1]];
            assign word_b = row_b[compute_local_bank][stream_k[WORD_W:1]];
            assign a_flat[i] = (compute_state != COMPUTE_STREAM) ? 8'd0
                : stream_k[0] ? word_a[15:8] : word_a[7:0];
            assign b_flat[i] = (compute_state != COMPUTE_STREAM) ? 8'd0
                : stream_k[0] ? word_b[15:8] : word_b[7:0];
        end
    endgenerate

    rpu_array #(.N(N)) math_core (
        .clk(clk),
        .reset(core_reset),
        .a_flat(a_flat),
        .b_flat(b_flat),
        .drain(compute_state == COMPUTE_DRAIN),
        .c_col(c_col)
    );

    assign dma_rd_valid = (load_state == LOAD_A) || (load_state == LOAD_B);
    assign dma_rd_bank = load_ext_bank;
    assign dma_rd_addr = (load_state == LOAD_A)
        ? EXT_ADDR_W'(int'(load_a_base) + int'(load_idx))
        : EXT_ADDR_W'(int'(load_b_base) + int'(load_idx));

    assign dma_wr_valid = (compute_state == COMPUTE_STORE_C);
    assign dma_wr_bank = compute_ext_bank;
    assign dma_wr_addr = EXT_ADDR_W'(int'(compute_c_base) + int'(store_idx));
    assign dma_wr_data = store_idx[0] ? mem_c[store_col][store_row][31:16]
                                      : mem_c[store_col][store_row][15:0];

    rpu_sim_memory #(
        .WORDS(EXT_WORDS),
        .ADDR_W(EXT_ADDR_W),
        .READ_LATENCY(1),
        .WRITE_LATENCY(1)
    ) external_memory (
        .clk(clk),
        .reset(reset),
        .host_we(host_ext_we),
        .host_bank(host_ext_bank),
        .host_addr(host_ext_addr),
        .host_wdata(mem_wdata),
        .host_rdata(host_ext_rdata),
        .rd_valid(dma_rd_valid),
        .rd_bank(dma_rd_bank),
        .rd_addr(dma_rd_addr),
        .rd_ready(dma_rd_ready),
        .rd_data(dma_rd_data),
        .wr_valid(dma_wr_valid),
        .wr_bank(dma_wr_bank),
        .wr_addr(dma_wr_addr),
        .wr_data(dma_wr_data),
        .wr_ready(dma_wr_ready)
    );

    always_ff @(posedge clk) begin
        if (reset) begin
            reg_a_base <= 16'd0;
            reg_b_base <= 16'd0;
            reg_c_base <= 16'd0;
            reg_k_len <= K_W'(N);
            start_request <= 1'b0;
            preload_request <= 1'b0;
            control_bank <= 1'b0;
        end else begin
            start_request <= 1'b0;
            preload_request <= 1'b0;

            if (mem_we) begin
                case (mem_addr)
                    REG_CONTROL_ADDR[ADDR_W-1:0]: begin
                        start_request <= mem_wdata[0];
                        control_bank <= mem_wdata[1];
                        preload_request <= mem_wdata[2];
                    end
                    REG_A_BASE_ADDR[ADDR_W-1:0]: reg_a_base <= mem_wdata;
                    REG_B_BASE_ADDR[ADDR_W-1:0]: reg_b_base <= mem_wdata;
                    REG_C_BASE_ADDR[ADDR_W-1:0]: reg_c_base <= mem_wdata;
                    REG_K_LEN_ADDR[ADDR_W-1:0]: reg_k_len <= K_W'(mem_wdata);
                    default: begin
                    end
                endcase
            end
        end
    end

    always_ff @(posedge clk) begin
        if (reset) begin
            load_state <= LOAD_IDLE;
            compute_state <= COMPUTE_IDLE;
            cycles <= 32'd0;
            active_cycles <= 32'd0;
            busy_cycles <= 32'd0;
            load_idx <= '0;
            load_row <= '0;
            load_word <= '0;
            load_word_last <= '0;
            load_k_len <= '0;
            store_idx <= '0;
            store_row <= '0;
            store_col <= '0;
            stream_k <= '0;
            stream_last <= '0;
            drain_count <= '0;
            load_local_bank <= 1'b0;
            load_ext_bank <= 1'b0;
            load_then_compute <= 1'b0;
            load_a_base <= 16'd0;
            load_b_base <= 16'd0;
            load_c_base <= 16'd0;
            compute_local_bank <= 1'b0;
            compute_ext_bank <= 1'b0;
            compute_c_base <= 16'd0;
            local_valid[0] <= 1'b0;
            local_valid[1] <= 1'b0;
            local_k_len[0] <= '0;
            local_k_len[1] <= '0;
        end else begin
            if (busy) begin
                cycles <= cycles + 32'd1;
                busy_cycles <= busy_cycles + 32'd1;
            end
            if (compute_state == COMPUTE_STREAM) begin
                active_cycles <= active_cycles + 32'd1;
            end

            if (preload_request && load_state == LOAD_IDLE) begin
                load_state <= LOAD_A;
                load_idx <= '0;
                load_row <= '0;
                load_word <= '0;
                load_word_last <= WORD_W'((int'(reg_k_len) + 1) / 2 - 1);
                load_k_len <= reg_k_len;
                load_local_bank <= control_bank;
                load_ext_bank <= control_bank;
                load_then_compute <= 1'b0;
                load_a_base <= reg_a_base;
                load_b_base <= reg_b_base;
                load_c_base <= reg_c_base;
                local_valid[control_bank] <= 1'b0;
            end else if ((start_request || start) &&
                         (compute_state == COMPUTE_IDLE || compute_state == COMPUTE_FINISH)) begin
                cycles <= 32'd0;
                stream_k <= '0;
                drain_count <= '0;
                store_idx <= '0;

                if (local_valid[control_bank]) begin
                    compute_state <= COMPUTE_CLEAR;
                    stream_last <= local_k_len[control_bank] - 1'b1;
                    compute_local_bank <= control_bank;
                    compute_ext_bank <= control_bank;
                    compute_c_base <= reg_c_base;
                    local_valid[control_bank] <= 1'b0;
                end else if (load_state == LOAD_IDLE) begin
                    load_state <= LOAD_A;
                    load_idx <= '0;
                    load_row <= '0;
                    load_word <= '0;
                    load_word_last <= WORD_W'((int'(reg_k_len) + 1) / 2 - 1);
                    load_k_len <= reg_k_len;
                    load_local_bank <= control_bank;
                    load_ext_bank <= control_bank;
                    load_then_compute <= 1'b1;
                    load_a_base <= reg_a_base;
                    load_b_base <= reg_b_base;
                    load_c_base <= reg_c_base;
                    local_valid[control_bank] <= 1'b0;
                    compute_state <= COMPUTE_IDLE;
                end
            end

            case (load_state)
                LOAD_IDLE: begin
                end
                LOAD_A, LOAD_B: begin
                    if (dma_rd_ready) begin
                        // The row buffers in panel_row take dma_rd_data at (load_row, load_word).
                        load_idx <= load_idx + 1'b1;
                        if (load_word != load_word_last) begin
                            load_word <= load_word + 1'b1;
                        end else if (load_row != COL_LAST) begin
                            load_word <= '0;
                            load_row <= load_row + 1'b1;
                        end else if (load_state == LOAD_A) begin
                            load_idx <= '0;
                            load_word <= '0;
                            load_row <= '0;
                            load_state <= LOAD_B;
                        end else begin
                            load_idx <= '0;
                            load_word <= '0;
                            load_row <= '0;
                            load_state <= LOAD_IDLE;
                            local_k_len[load_local_bank] <= load_k_len;

                            if (load_then_compute &&
                                (compute_state == COMPUTE_IDLE || compute_state == COMPUTE_FINISH)) begin
                                compute_state <= COMPUTE_CLEAR;
                                compute_local_bank <= load_local_bank;
                                compute_ext_bank <= load_ext_bank;
                                compute_c_base <= load_c_base;
                                stream_k <= '0;
                                stream_last <= load_k_len - 1'b1;
                                drain_count <= '0;
                                store_idx <= '0;
                                local_valid[load_local_bank] <= 1'b0;
                            end else begin
                                local_valid[load_local_bank] <= 1'b1;
                            end
                        end
                    end
                end
                default: begin
                    load_state <= LOAD_IDLE;
                end
            endcase

            case (compute_state)
                COMPUTE_IDLE, COMPUTE_FINISH: begin
                end
                COMPUTE_CLEAR: begin
                    stream_k <= '0;
                    drain_count <= '0;
                    compute_state <= COMPUTE_STREAM;
                end
                COMPUTE_STREAM: begin
                    if (stream_k == stream_last) begin
                        stream_k <= '0;
                        drain_count <= '0;
                        compute_state <= COMPUTE_SETTLE;
                    end else begin
                        stream_k <= stream_k + 1'b1;
                    end
                end
                COMPUTE_SETTLE: begin
                    if (drain_count == SETTLE_LAST) begin
                        drain_count <= '0;
                        compute_state <= COMPUTE_DRAIN;
                    end else begin
                        drain_count <= drain_count + 1'b1;
                    end
                end
                COMPUTE_DRAIN: begin
                    // The array shifts right each cycle; c_col is column N-1-drain_count.
                    mem_c[COL_LAST - drain_count[COL_W-1:0]] <= c_col;
                    if (drain_count == DRAIN_LAST) begin
                        store_idx <= '0;
                        store_row <= '0;
                        store_col <= '0;
                        compute_state <= COMPUTE_STORE_C;
                    end else begin
                        drain_count <= drain_count + 1'b1;
                    end
                end
                COMPUTE_STORE_C: begin
                    if (dma_wr_ready) begin
                        if (store_idx == STORE_LAST) begin
                            store_idx <= '0;
                            compute_state <= COMPUTE_FINISH;
                        end else begin
                            store_idx <= store_idx + 1'b1;
                        end
                        if (store_idx[0]) begin
                            if (store_col == COL_LAST) begin
                                store_col <= '0;
                                store_row <= store_row + 1'b1;
                            end else begin
                                store_col <= store_col + 1'b1;
                            end
                        end
                    end
                end
                default: begin
                    compute_state <= COMPUTE_IDLE;
                end
            endcase
        end
    end

    always_comb begin
        int unsigned addr;
        addr = int'(mem_addr);
        host_ext_we = 1'b0;
        host_ext_bank = 1'b0;
        host_ext_addr = '0;

        if (addr >= EXT_BASE_ADDR && addr < EXT_BASE_ADDR + EXT_WORDS) begin
            host_ext_we = mem_we;
            host_ext_bank = 1'b0;
            host_ext_addr = EXT_ADDR_W'(addr - EXT_BASE_ADDR);
        end else if (addr >= EXT_BASE_ADDR + EXT_WORDS &&
                     addr < EXT_BASE_ADDR + 2 * EXT_WORDS) begin
            host_ext_we = mem_we;
            host_ext_bank = 1'b1;
            host_ext_addr = EXT_ADDR_W'(addr - (EXT_BASE_ADDR + EXT_WORDS));
        end

    end

    always_comb begin
        int unsigned addr;
        addr = int'(mem_addr);

        if (addr == REG_CONTROL_ADDR) begin
            mem_rdata = 16'd0;
        end else if (addr == REG_STATUS_ADDR) begin
            mem_rdata = {10'd0, local_valid[1], local_valid[0], compute_busy, load_busy, done, busy};
        end else if (addr == REG_A_BASE_ADDR) begin
            mem_rdata = reg_a_base;
        end else if (addr == REG_B_BASE_ADDR) begin
            mem_rdata = reg_b_base;
        end else if (addr == REG_C_BASE_ADDR) begin
            mem_rdata = reg_c_base;
        end else if (addr == REG_K_LEN_ADDR) begin
            mem_rdata = 16'(reg_k_len);
        end else if (addr == REG_ACTIVE_LO_ADDR) begin
            mem_rdata = active_cycles[15:0];
        end else if (addr == REG_ACTIVE_HI_ADDR) begin
            mem_rdata = active_cycles[31:16];
        end else if (addr == REG_BUSY_LO_ADDR) begin
            mem_rdata = busy_cycles[15:0];
        end else if (addr == REG_BUSY_HI_ADDR) begin
            mem_rdata = busy_cycles[31:16];
        end else if (addr >= EXT_BASE_ADDR && addr < EXT_BASE_ADDR + EXT_WORDS) begin
            mem_rdata = host_ext_rdata;
        end else if (addr >= EXT_BASE_ADDR + EXT_WORDS &&
                     addr < EXT_BASE_ADDR + 2 * EXT_WORDS) begin
            mem_rdata = host_ext_rdata;
        end else begin
            mem_rdata = 16'd0;
        end
    end

endmodule
