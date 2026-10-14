// RPU top: register file, int8 panel buffers, DMA FSMs and the systolic array.
// C = A * B^T (NT GEMM) with A and B both N x K_LEN, 1 <= K_LEN <= KMAX.
// Memory moves 8*N-bit beats (N int8). A and B rows are stored one after the other,
// each padded to a whole number of beats, k = 0 in the lowest byte. C is stored
// row-major as int32, 4 beats per row. Base registers hold beat addresses.
// The host bus has 32-bit addresses and 64-bit data words.
// There are two A panel buffers (CONTROL A bank bit) and two B panel buffers (CONTROL
// bank bit). A load with KEEP_A loads only B, so A stays valid across output tiles; a load
// with KEEP_B loads only A, so a B bank serves the first tile of the next row block. The
// C store runs on its own, overlapping the next compute. The host must not load A into
// the A bank of a running compute.
// Each PE keeps its finished sum in a shadow register, so the settle and drain of a tile
// overlap the stream of the next one. A compute is busy only while it streams.
module rpu_top #(
    parameter int N = 8,
    parameter int KMAX = 1024,
    parameter int READ_LATENCY = 1,
    parameter int MEM_BYTES = 1 << 20
) (
    input  logic clk,
    input  logic reset,
    input  logic start,

    input  logic mem_we,
    input  logic [31:0] mem_addr,
    input  logic [63:0] mem_wdata,
    output logic [63:0] mem_rdata,

    output logic [31:0] cycles,
    output logic busy,
    output logic done
);

    localparam int BEAT_W = 8 * N;
    localparam int ROW_BEATS = (KMAX + N - 1) / N;  // beats per panel row
    localparam int C_ROW_BEATS = 4;                  // N int32 = 4 beats of N bytes
    localparam int C_BEATS = C_ROW_BEATS * N;
    localparam int PE_LATENCY = 2;                   // product register + accumulator
    // Operand register between the panel read and the array, so that the edge PEs'
    // multipliers start from a flip-flop and not from the panel read multiplexer.
    localparam int OPERAND_STAGES = 1;
    // The last k reaches PE (N-1, N-1) after the operand register and 2N-2 skew cycles;
    // the shadow takes the sum with the last product, PE_LATENCY - 1 cycles later.
    localparam int SETTLE_STEPS = OPERAND_STAGES + 2 * N - 2 + PE_LATENCY - 1;
    // A stream may start during the drain of the tile before only if it is long enough:
    // the drain must end before PE (0, 0) takes the new sum, K cycles after the start.
    localparam int OVERLAP_K_MIN = SETTLE_STEPS + N;
    localparam int BEAT_ADDR_W = $clog2(MEM_BYTES / N);
    localparam int HOST_ADDR_W = $clog2(MEM_BYTES / 8);
    localparam int COL_W = (N > 1) ? $clog2(N) : 1;
    localparam int K_W = $clog2(KMAX + N + 1);       // holds K_LEN and a beat's k + N
    localparam int RB_W = (ROW_BEATS > 1) ? $clog2(ROW_BEATS) : 1;
    localparam int RA_W = $clog2(2 * ROW_BEATS);    // both A banks in one row memory
    localparam logic [RA_W-1:0] A_BANK1_BEAT = RA_W'(ROW_BEATS);
    localparam int DRAIN_W = $clog2(SETTLE_STEPS + 1);
    localparam int STORE_W = $clog2(C_BEATS);
    localparam logic [COL_W-1:0] COL_LAST = COL_W'(N - 1);
    localparam logic [DRAIN_W-1:0] SETTLE_LAST = DRAIN_W'(SETTLE_STEPS - 1);
    localparam logic [DRAIN_W-1:0] DRAIN_LAST = DRAIN_W'(N - 1);
    localparam logic [STORE_W-1:0] STORE_LAST = STORE_W'(C_BEATS - 1);
    localparam logic [1:0] C_ROW_LAST = 2'(C_ROW_BEATS - 1);
    localparam int unsigned REG_CONTROL_ADDR = 0;
    localparam int unsigned REG_STATUS_ADDR = 1;
    localparam int unsigned REG_A_BASE_ADDR = 2;
    localparam int unsigned REG_B_BASE_ADDR = 3;
    localparam int unsigned REG_C_BASE_ADDR = 4;
    localparam int unsigned REG_K_LEN_ADDR = 5;
    localparam int unsigned REG_ACTIVE_ADDR = 6;
    localparam int unsigned REG_BUSY_ADDR = 7;
    localparam int unsigned MEM_BASE_ADDR = 32'h1000_0000;  // in 64-bit words
    localparam int unsigned MEM_WORDS = MEM_BYTES / 8;

    // C buffer: one wide word per array row, written by the shift drain one row per
    // cycle (one write port, so it can map to BSRAM).
    logic [N-1:0][31:0] mem_c [0:N-1];

    logic [BEAT_ADDR_W-1:0] reg_a_base;
    logic [BEAT_ADDR_W-1:0] reg_b_base;
    logic [BEAT_ADDR_W-1:0] reg_c_base;
    logic [K_W-1:0] reg_k_len;
    // Free-running since reset: cycles the array streams, and cycles busy.
    logic [31:0] active_cycles;
    logic [31:0] busy_cycles;
    logic start_request;
    logic preload_request;
    logic control_bank;
    logic control_keep_a;
    logic control_keep_b;
    logic control_a_bank;

    typedef enum logic [1:0] {
        COMPUTE_IDLE,
        COMPUTE_CLEAR,   // set up the stream; waits while the drain before needs the array
        COMPUTE_STREAM,
        COMPUTE_FINISH
    } compute_state_t;

    // Settle and drain of the tile that last streamed, from the shadow registers.
    typedef enum logic [1:0] {
        DRAIN_IDLE,
        DRAIN_SETTLE,
        DRAIN_SHIFT
    } drain_state_t;

    compute_state_t compute_state;
    drain_state_t drain_state;

    // Load: the issue side requests one beat per cycle, the receive side writes each
    // response into the panel buffers. Both walk A rows, then B rows.
    logic load_busy;
    logic issue_active;
    logic issue_panel;  // 0: A, 1: B
    logic [COL_W-1:0] issue_row;
    logic [K_W-1:0] issue_k;  // k of the beat's first value
    logic [BEAT_ADDR_W-1:0] issue_addr;
    logic recv_panel;
    logic [COL_W-1:0] recv_row;
    logic [RB_W-1:0] recv_beat;
    logic [K_W-1:0] recv_k;
    logic issue_row_end;
    logic recv_row_end;

    logic load_local_bank;
    logic load_a_bank;
    logic load_then_compute;
    logic load_keep_b;
    logic [K_W-1:0] load_k_len;
    logic [BEAT_ADDR_W-1:0] load_b_base;
    logic [BEAT_ADDR_W-1:0] load_c_base;

    logic [K_W-1:0] stream_k;
    logic [K_W-1:0] stream_last;
    logic [RB_W-1:0] stream_beat;
    // A read address, bank included. One register (not {bank, beat}) so that synthesis
    // folds it into a synchronous BSRAM read port.
    logic [RA_W-1:0] stream_a_addr;
    logic [COL_W-1:0] stream_lane;
    logic [DRAIN_W-1:0] drain_count;
    logic [BEAT_ADDR_W-1:0] drain_c_base;
    logic drain_busy;
    logic stream_last_k;
    logic store_busy;
    logic [BEAT_ADDR_W-1:0] store_c_base;
    logic [STORE_W-1:0] store_idx;
    logic [COL_W-1:0] store_row;
    logic [1:0] store_part;

    logic compute_local_bank;
    logic compute_a_bank;
    logic [BEAT_ADDR_W-1:0] compute_c_base;
    logic local_valid [0:1];
    logic [K_W-1:0] local_k_len [0:1];

    logic [N-1:0][7:0] a_flat;
    logic [N-1:0][7:0] b_flat;
    logic [N-1:0][7:0] a_operand;
    logic [N-1:0][7:0] b_operand;
    logic last_operand;
    logic [N-1:0][31:0] c_row;
    logic compute_busy;
    logic host_mem_we;
    logic [HOST_ADDR_W-1:0] host_mem_addr;
    logic [63:0] host_mem_rdata;
    logic dma_rd_resp_valid;
    logic [BEAT_W-1:0] dma_rd_data;
    logic dma_wr_valid;
    logic [BEAT_ADDR_W-1:0] dma_wr_addr;
    logic [BEAT_W-1:0] dma_wr_data;
    logic [32*N-1:0] c_store_row;

    assign compute_busy = (compute_state == COMPUTE_CLEAR) ||
                          (compute_state == COMPUTE_STREAM);
    assign drain_busy = drain_state != DRAIN_IDLE;
    assign busy = load_busy || compute_busy || drain_busy || store_busy;
    assign done = (compute_state == COMPUTE_FINISH) && !drain_busy && !store_busy;
    assign stream_last_k = (compute_state == COMPUTE_STREAM) && (stream_k == stream_last);
    assign issue_row_end = int'(issue_k) + N >= int'(load_k_len);
    assign recv_row_end = int'(recv_k) + N >= int'(load_k_len);

    // Panel buffers: one memory per array row, so each has one write and one read port.
    genvar i;
    generate
        for (i = 0; i < N; i++) begin : panel_row
            logic [BEAT_W-1:0] row_a [0:2*ROW_BEATS-1];
            logic [BEAT_W-1:0] row_b [0:1][0:ROW_BEATS-1];
            logic [BEAT_W-1:0] beat_a;
            logic [BEAT_W-1:0] beat_b;

            always_ff @(posedge clk) begin
                if (load_busy && dma_rd_resp_valid && recv_row == COL_W'(i)) begin
                    if (!recv_panel) row_a[(load_a_bank ? A_BANK1_BEAT : '0) + RA_W'(recv_beat)] <= dma_rd_data;
                    else row_b[load_local_bank][recv_beat] <= dma_rd_data;
                end
            end

            assign beat_a = row_a[stream_a_addr];
            assign beat_b = row_b[compute_local_bank][stream_beat];
            assign a_flat[i] = (compute_state == COMPUTE_STREAM) ? beat_a[int'(stream_lane)*8 +: 8] : 8'd0;
            assign b_flat[i] = (compute_state == COMPUTE_STREAM) ? beat_b[int'(stream_lane)*8 +: 8] : 8'd0;
        end
    endgenerate

    always_ff @(posedge clk) begin
        if (reset) begin
            a_operand <= '0;
            b_operand <= '0;
            last_operand <= 1'b0;
        end else begin
            a_operand <= a_flat;
            b_operand <= b_flat;
            last_operand <= stream_last_k;
        end
    end

    rpu_array #(.N(N)) math_core (
        .clk(clk),
        .reset(reset),
        .a_flat(a_operand),
        .b_flat(b_operand),
        .last(last_operand),
        .drain(drain_state == DRAIN_SHIFT),
        .c_row(c_row)
    );

    assign dma_wr_valid = store_busy;
    assign dma_wr_addr = store_c_base + BEAT_ADDR_W'(store_idx);
    assign c_store_row = mem_c[store_row];
    assign dma_wr_data = c_store_row[int'(store_part)*BEAT_W +: BEAT_W];

    rpu_sim_memory #(
        .N(N),
        .BYTES(MEM_BYTES),
        .READ_LATENCY(READ_LATENCY)
    ) external_memory (
        .clk(clk),
        .reset(reset),
        .host_we(host_mem_we),
        .host_addr(host_mem_addr),
        .host_wdata(mem_wdata),
        .host_rdata(host_mem_rdata),
        .rd_valid(issue_active),
        .rd_addr(issue_addr),
        .rd_resp_valid(dma_rd_resp_valid),
        .rd_data(dma_rd_data),
        .wr_valid(dma_wr_valid),
        .wr_addr(dma_wr_addr),
        .wr_data(dma_wr_data)
    );

    always_ff @(posedge clk) begin
        if (reset) begin
            reg_a_base <= '0;
            reg_b_base <= '0;
            reg_c_base <= '0;
            reg_k_len <= K_W'(N);
            start_request <= 1'b0;
            preload_request <= 1'b0;
            control_bank <= 1'b0;
            control_keep_a <= 1'b0;
            control_keep_b <= 1'b0;
            control_a_bank <= 1'b0;
        end else begin
            start_request <= 1'b0;
            preload_request <= 1'b0;

            if (mem_we) begin
                case (mem_addr)
                    REG_CONTROL_ADDR: begin
                        start_request <= mem_wdata[0];
                        control_bank <= mem_wdata[1];
                        preload_request <= mem_wdata[2];
                        control_keep_a <= mem_wdata[3];
                        control_a_bank <= mem_wdata[4];
                        control_keep_b <= mem_wdata[5];
                    end
                    REG_A_BASE_ADDR: reg_a_base <= BEAT_ADDR_W'(mem_wdata);
                    REG_B_BASE_ADDR: reg_b_base <= BEAT_ADDR_W'(mem_wdata);
                    REG_C_BASE_ADDR: reg_c_base <= BEAT_ADDR_W'(mem_wdata);
                    REG_K_LEN_ADDR: reg_k_len <= K_W'(mem_wdata);
                    default: begin
                    end
                endcase
            end
        end
    end

    always_ff @(posedge clk) begin
        if (reset) begin
            compute_state <= COMPUTE_IDLE;
            drain_state <= DRAIN_IDLE;
            drain_c_base <= '0;
            cycles <= 32'd0;
            active_cycles <= 32'd0;
            busy_cycles <= 32'd0;
            load_busy <= 1'b0;
            issue_active <= 1'b0;
            issue_panel <= 1'b0;
            issue_row <= '0;
            issue_k <= '0;
            issue_addr <= '0;
            recv_panel <= 1'b0;
            recv_row <= '0;
            recv_beat <= '0;
            recv_k <= '0;
            load_local_bank <= 1'b0;
            load_a_bank <= 1'b0;
            load_then_compute <= 1'b0;
            load_keep_b <= 1'b0;
            load_k_len <= '0;
            load_b_base <= '0;
            load_c_base <= '0;
            stream_k <= '0;
            stream_last <= '0;
            stream_beat <= '0;
            stream_a_addr <= '0;
            stream_lane <= '0;
            drain_count <= '0;
            store_busy <= 1'b0;
            store_c_base <= '0;
            store_idx <= '0;
            store_row <= '0;
            store_part <= '0;
            compute_local_bank <= 1'b0;
            compute_a_bank <= 1'b0;
            compute_c_base <= '0;
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

            if ((preload_request || start_request || start) && !load_busy &&
                (preload_request || !local_valid[control_bank]) &&
                (preload_request || compute_state == COMPUTE_IDLE || compute_state == COMPUTE_FINISH)) begin
                // Preload, or START on a bank that is not loaded yet: load first.
                load_busy <= 1'b1;
                issue_active <= 1'b1;
                issue_panel <= control_keep_a;
                issue_row <= '0;
                issue_k <= '0;
                issue_addr <= control_keep_a ? reg_b_base : reg_a_base;
                recv_panel <= control_keep_a;
                recv_row <= '0;
                recv_beat <= '0;
                recv_k <= '0;
                load_local_bank <= control_bank;
                load_a_bank <= control_a_bank;
                load_then_compute <= !preload_request;
                load_keep_b <= control_keep_b;
                load_k_len <= reg_k_len;
                load_b_base <= reg_b_base;
                load_c_base <= reg_c_base;
                local_valid[control_bank] <= 1'b0;
                if (!preload_request) begin
                    cycles <= 32'd0;
                    compute_state <= COMPUTE_IDLE;
                end
            end else if ((start_request || start) && local_valid[control_bank] &&
                         (compute_state == COMPUTE_IDLE || compute_state == COMPUTE_FINISH)) begin
                cycles <= 32'd0;
                compute_state <= COMPUTE_CLEAR;
                stream_last <= local_k_len[control_bank] - 1'b1;
                compute_local_bank <= control_bank;
                compute_a_bank <= control_a_bank;
                compute_c_base <= reg_c_base;
                local_valid[control_bank] <= 1'b0;
            end

            if (issue_active) begin
                issue_addr <= issue_addr + 1'b1;
                if (!issue_row_end) begin
                    issue_k <= issue_k + K_W'(N);
                end else begin
                    issue_k <= '0;
                    if (issue_row != COL_LAST) begin
                        issue_row <= issue_row + 1'b1;
                    end else if (!issue_panel && !load_keep_b) begin
                        issue_row <= '0;
                        issue_panel <= 1'b1;
                        issue_addr <= load_b_base;
                    end else begin
                        issue_active <= 1'b0;
                    end
                end
            end

            if (load_busy && dma_rd_resp_valid) begin
                // The row buffers in panel_row take dma_rd_data at (recv_row, recv_beat).
                if (!recv_row_end) begin
                    recv_k <= recv_k + K_W'(N);
                    recv_beat <= recv_beat + 1'b1;
                end else begin
                    recv_k <= '0;
                    recv_beat <= '0;
                    if (recv_row != COL_LAST) begin
                        recv_row <= recv_row + 1'b1;
                    end else if (!recv_panel && !load_keep_b) begin
                        recv_row <= '0;
                        recv_panel <= 1'b1;
                    end else begin
                        load_busy <= 1'b0;
                        local_k_len[load_local_bank] <= load_k_len;
                        if (load_then_compute &&
                            (compute_state == COMPUTE_IDLE || compute_state == COMPUTE_FINISH)) begin
                            compute_state <= COMPUTE_CLEAR;
                            stream_last <= load_k_len - 1'b1;
                            compute_local_bank <= load_local_bank;
                            compute_a_bank <= load_a_bank;
                            compute_c_base <= load_c_base;
                            local_valid[load_local_bank] <= 1'b0;
                        end else begin
                            local_valid[load_local_bank] <= 1'b1;
                        end
                    end
                end
            end

            // Before the compute FSM: a stream that ends while the last drain step runs
            // starts the next settle.
            case (drain_state)
                DRAIN_IDLE: begin
                end
                DRAIN_SETTLE: begin
                    // Wait for the store of the previous tile: the drain overwrites mem_c.
                    if (drain_count == SETTLE_LAST && !store_busy) begin
                        drain_count <= '0;
                        drain_state <= DRAIN_SHIFT;
                    end else if (drain_count != SETTLE_LAST) begin
                        drain_count <= drain_count + 1'b1;
                    end
                end
                DRAIN_SHIFT: begin
                    // The shadows shift down each cycle; c_row is row N-1-drain_count.
                    mem_c[COL_LAST - drain_count[COL_W-1:0]] <= c_row;
                    if (drain_count == DRAIN_LAST) begin
                        store_busy <= 1'b1;
                        store_c_base <= drain_c_base;
                        store_idx <= '0;
                        store_row <= '0;
                        store_part <= '0;
                        drain_state <= DRAIN_IDLE;
                    end else begin
                        drain_count <= drain_count + 1'b1;
                    end
                end
                default: begin
                    drain_state <= DRAIN_IDLE;
                end
            endcase

            case (compute_state)
                COMPUTE_IDLE, COMPUTE_FINISH: begin
                end
                COMPUTE_CLEAR: begin
                    stream_k <= '0;
                    stream_beat <= '0;
                    stream_a_addr <= compute_a_bank ? A_BANK1_BEAT : '0;
                    stream_lane <= '0;
                    // While a drain is pending, a store still busy could delay it.
                    if (!drain_busy ||
                        (!store_busy && stream_last >= K_W'(OVERLAP_K_MIN - 1))) begin
                        compute_state <= COMPUTE_STREAM;
                    end
                end
                COMPUTE_STREAM: begin
                    if (stream_k == stream_last) begin
                        compute_state <= COMPUTE_FINISH;
                        drain_state <= DRAIN_SETTLE;
                        drain_count <= '0;
                        drain_c_base <= compute_c_base;
                    end else begin
                        stream_k <= stream_k + 1'b1;
                        if (stream_lane == COL_LAST) begin
                            stream_lane <= '0;
                            stream_beat <= stream_beat + 1'b1;
                            stream_a_addr <= stream_a_addr + 1'b1;
                        end else begin
                            stream_lane <= stream_lane + 1'b1;
                        end
                    end
                end
                default: begin
                    compute_state <= COMPUTE_IDLE;
                end
            endcase

            // C store, one beat per cycle: the memory never stalls a write.
            if (store_busy) begin
                if (store_idx == STORE_LAST) begin
                    store_busy <= 1'b0;
                end
                store_idx <= store_idx + 1'b1;
                if (store_part == C_ROW_LAST) begin
                    store_part <= '0;
                    store_row <= store_row + 1'b1;
                end else begin
                    store_part <= store_part + 1'b1;
                end
            end
        end
    end

    always_comb begin
        host_mem_we = 1'b0;
        host_mem_addr = HOST_ADDR_W'(mem_addr - MEM_BASE_ADDR);
        if (mem_addr >= MEM_BASE_ADDR && mem_addr < MEM_BASE_ADDR + MEM_WORDS) begin
            host_mem_we = mem_we;
        end
    end

    always_comb begin
        case (mem_addr)
            REG_STATUS_ADDR: mem_rdata = 64'({store_busy, local_valid[1], local_valid[0],
                                              compute_busy, load_busy, done, busy});
            REG_A_BASE_ADDR: mem_rdata = 64'(reg_a_base);
            REG_B_BASE_ADDR: mem_rdata = 64'(reg_b_base);
            REG_C_BASE_ADDR: mem_rdata = 64'(reg_c_base);
            REG_K_LEN_ADDR: mem_rdata = 64'(reg_k_len);
            REG_ACTIVE_ADDR: mem_rdata = 64'(active_cycles);
            REG_BUSY_ADDR: mem_rdata = 64'(busy_cycles);
            default: mem_rdata = (mem_addr >= MEM_BASE_ADDR && mem_addr < MEM_BASE_ADDR + MEM_WORDS)
                ? host_mem_rdata : 64'd0;
        endcase
    end

endmodule
