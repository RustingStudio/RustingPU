// RPU top: register file, int8 panel buffers, DMA FSMs and the systolic array.
// C = A * B^T (NT GEMM) with A and B both N x K_LEN, 1 <= K_LEN <= KMAX.
// Memory moves 8*N-bit beats (N int8). The load reads LOAD_BEATS beats per request, so
// A and B base addresses must be multiples of LOAD_BEATS; LOAD_BEATS = 2 loads A and B
// as fast as the stream reads them. An A or B panel is stored column by column: beat
// column c of rows 0..N-1, then column c + 1; a beat holds k = c*N.. c*N + N-1 of one row,
// k = c*N in the lowest byte, zero padded past K. C is stored
// row-major as int32, 4 beats per row. Base registers hold beat addresses.
// The host bus has 32-bit addresses and 64-bit data words.
// There are two A panel buffers (CONTROL A bank bit) and two B panel buffers (CONTROL
// bank bit). A load with KEEP_A loads only B, so A stays valid across output tiles; a load
// with KEEP_B loads only A, so a B bank serves the first tile of the next row block. The
// C store runs on its own, overlapping the next compute. The host must not load A into
// the A bank of a running compute.
// A load walks the columns, so a START that loads its operands begins to stream before
// the load ends, once the beats it has still to wait for cannot fall behind the stream.
// CONTROL GEMM runs a whole tiled GEMM: the sequencer issues a START for every tile
// (serpentine B tiles, alternating banks), each loading what its tile does not share.
// Each PE keeps its finished sum in a shadow register, so the settle and drain of a tile
// overlap the stream of the next one. A compute is busy only while it streams.
// CONTROL GEMM with QUANT stores each C row as N int8 instead of N int32: per column j,
// y = clamp(round((acc + bias[j]) * mult[j] / 2^shift[j]), relu[j] ? 0 : -127, 127), from
// a parameter memory that the host writes. Row i of tile (r, j) goes to beat
// C_BASE + r * n_tiles * N + j * N + i, which is the column-major A panel of the next layer.
module rpu_top #(
    parameter int N = 8,
    parameter int KMAX = 1024,
    parameter int READ_LATENCY = 1,
    // Beats per load request: 1 for the board, 2 or more for a wider read port. Must
    // divide N.
    parameter int LOAD_BEATS = 1,
    // 64K beats from N = 16 on, so a bigger array gets a bigger memory.
    parameter int MEM_BYTES = (1 << 20) * ((N > 16) ? N / 16 : 1)
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
    localparam logic [COL_W-1:0] LOAD_LAST = COL_W'(N - LOAD_BEATS);  // last request of a column
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
    localparam int unsigned REG_PANEL_ADDR = 8;
    localparam int unsigned REG_TILES_ADDR = 9;
    localparam int unsigned MEM_BASE_ADDR = 32'h1000_0000;  // in 64-bit words
    // Requantization: each store cycle (4 per C row) takes L columns of the row.
    localparam int L = (N + 3) / 4;
    localparam int LANE_W = (L > 1) ? $clog2(L) : 1;
    localparam int QP_DEPTH = 4 * ROW_BEATS;  // (tile column, store part) per lane
    localparam int QP_AW = $clog2(QP_DEPTH);
    // Parameter word: bias [31:0] (int32), mult [47:32], shift [53:48], relu [54].
    localparam int QP_W = 55;
    // Host word QPARAM_BASE + ((j * 4 + part) << LANE_W) + lane holds column
    // j * N + part * L + lane.
    localparam int unsigned QPARAM_BASE_ADDR = 32'h0800_0000;
    localparam int unsigned QPARAM_WORDS = QP_DEPTH << LANE_W;
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
    logic control_quant;
    // GEMM sequencer. A blocks at A_BASE + r * PANEL, B tiles at B_BASE + j * PANEL, C tile
    // (r, j) at C_BASE + (r * n_tiles + j) * C_BEATS. The base registers move with it.
    typedef enum logic [1:0] {
        SEQ_IDLE,
        SEQ_START,       // START the current tile
        SEQ_STARTED,     // START is taken this cycle
        SEQ_WAIT         // wait until its load is done and its compute has begun
    } seq_state_t;
    seq_state_t seq_state;
    logic [BEAT_ADDR_W-1:0] reg_panel;
    logic [15:0] reg_m_blocks;
    logic [15:0] reg_n_tiles;
    logic [15:0] seq_r;
    logic [15:0] seq_j;
    logic seq_back;  // j runs backwards in this row block
    logic seq_bank;
    logic seq_block_end;
    logic seq_last;
    logic [BEAT_ADDR_W-1:0] c_stride;  // beats between the C tiles of one row block

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
    // response into the panel buffers. Both walk the beat columns; in each column the A
    // rows, then the B rows.
    logic load_busy;
    logic issue_active;
    logic issue_panel;  // 0: A, 1: B
    logic [COL_W-1:0] issue_row;
    logic [K_W-1:0] issue_k;  // k of the beat's first value
    logic [BEAT_ADDR_W-1:0] issue_a_addr;
    logic [BEAT_ADDR_W-1:0] issue_b_addr;
    logic recv_panel;
    logic [COL_W-1:0] recv_row;
    logic [RB_W-1:0] recv_beat;
    logic [K_W-1:0] recv_k;
    logic issue_row_end;
    logic recv_row_end;

    logic load_local_bank;
    logic load_a_bank;
    logic load_then_compute;
    logic load_keep_a;
    logic load_both;  // A and B
    logic [K_W-1:0] load_k_len;
    // A START waits here for the compute: it may stream once launch_ready is set, either
    // at the end of its load or once launch_wait beats are left to receive before it.
    logic launch_valid;
    logic launch_ready;
    logic [K_W:0] launch_wait;
    logic launch_bank;
    logic launch_a_bank;
    logic [K_W-1:0] launch_k_len;
    logic [BEAT_ADDR_W-1:0] launch_c_base;
    logic launch_quant;
    logic [RB_W-1:0] launch_j;  // tile column, for the requantization parameters

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
    logic compute_quant;
    logic drain_quant;
    logic store_quant;
    logic [RB_W-1:0] compute_j;
    logic [RB_W-1:0] drain_j;
    logic [RB_W-1:0] store_j;
    // Requantized store: stage 1 holds L int32 of the row and their parameters, stage 2
    // the products, stage 3 the rounded products, stage 4 the shifted ones, stage 5 writes
    // the row's N int8 once its last part is done.
    logic q1_valid;
    logic [1:0] q1_part;
    logic [BEAT_ADDR_W-1:0] q1_addr;
    logic [L-1:0][31:0] q1_acc;
    logic [L-1:0][QP_W-1:0] q1_par;
    logic q2_valid;
    logic [1:0] q2_part;
    logic [BEAT_ADDR_W-1:0] q2_addr;
    logic signed [49:0] q2_prod [L];
    logic [L-1:0][5:0] q2_shift;
    logic [L-1:0] q2_relu;
    logic q3_valid;
    logic [1:0] q3_part;
    logic [BEAT_ADDR_W-1:0] q3_addr;
    logic signed [49:0] q3_rnd [L];
    logic [L-1:0][5:0] q3_shift;
    logic [L-1:0] q3_relu;
    logic q4_valid;
    logic [1:0] q4_part;
    logic [BEAT_ADDR_W-1:0] q4_addr;
    logic signed [49:0] q4_val [L];
    logic [L-1:0] q4_relu;
    logic [N-1:0][7:0] q_bytes;
    logic [N-1:0][7:0] q_next;
    logic q_wr_valid;
    logic [BEAT_ADDR_W-1:0] q_wr_addr;
    logic [BEAT_W-1:0] q_wr_data;
    logic [QP_AW-1:0] qp_read_addr;

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
    logic [LOAD_BEATS*BEAT_W-1:0] dma_rd_data;
    logic dma_wr_valid;
    logic [BEAT_ADDR_W-1:0] dma_wr_addr;
    logic [BEAT_W-1:0] dma_wr_data;
    logic [32*N-1:0] c_store_row;

    assign compute_busy = (compute_state == COMPUTE_CLEAR) ||
                          (compute_state == COMPUTE_STREAM);
    assign drain_busy = drain_state != DRAIN_IDLE;
    assign busy = load_busy || launch_valid || compute_busy || drain_busy || store_busy ||
                  q1_valid || q2_valid || q3_valid || q4_valid || q_wr_valid || seq_state != SEQ_IDLE;
    assign done = (compute_state == COMPUTE_FINISH) && !drain_busy && !store_busy &&
                  !q1_valid && !q2_valid && !q3_valid && !q4_valid && !q_wr_valid && !launch_valid && seq_state == SEQ_IDLE;
    assign seq_block_end = seq_back ? (seq_j == 16'd0) : (seq_j == reg_n_tiles - 16'd1);
    assign seq_last = seq_block_end && (seq_r == reg_m_blocks - 16'd1);
    assign c_stride = control_quant ? BEAT_ADDR_W'(N) : BEAT_ADDR_W'(C_BEATS);
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
            logic [BEAT_W-1:0] load_beat;

            // A response holds rows recv_row .. recv_row + LOAD_BEATS - 1 of one column.
            assign load_beat = dma_rd_data[(i % LOAD_BEATS)*BEAT_W +: BEAT_W];
            always_ff @(posedge clk) begin
                if (load_busy && dma_rd_resp_valid && recv_row == COL_W'(i - i % LOAD_BEATS)) begin
                    if (!recv_panel) row_a[(load_a_bank ? A_BANK1_BEAT : '0) + RA_W'(recv_beat)] <= load_beat;
                    else row_b[load_local_bank][recv_beat] <= load_beat;
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

    assign c_store_row = mem_c[store_row];
    // A raw store writes one beat per cycle; a requantized one, one beat per row.
    assign dma_wr_valid = (store_busy && !store_quant) || q_wr_valid;
    assign dma_wr_addr = q_wr_valid ? q_wr_addr : store_c_base + BEAT_ADDR_W'(store_idx);
    assign dma_wr_data = q_wr_valid ? q_wr_data : c_store_row[int'(store_part)*BEAT_W +: BEAT_W];

    // Requantization parameters: one memory per lane, one read port each.
    assign qp_read_addr = QP_AW'({store_j, store_part});
    generate
        for (i = 0; i < L; i++) begin : qparam_lane
            logic [QP_W-1:0] qp_mem [0:QP_DEPTH-1];
            always_ff @(posedge clk) begin
                if (mem_we && mem_addr >= QPARAM_BASE_ADDR &&
                    mem_addr < QPARAM_BASE_ADDR + QPARAM_WORDS &&
                    (L == 1 || int'(mem_addr[LANE_W-1:0]) == i)) begin
                    qp_mem[QP_AW'((mem_addr - QPARAM_BASE_ADDR) >> LANE_W)] <= mem_wdata[QP_W-1:0];
                end
                q1_par[i] <= qp_mem[qp_read_addr];
                q1_acc[i] <= (int'(store_part) * L + i < N)
                    ? c_store_row[(int'(store_part) * L + i) * 32 +: 32] : 32'd0;
                // |acc + bias| < 2^32 and mult < 2^16, so the product fits 49 bits.
                q2_prod[i] <= 50'(33'(signed'(q1_acc[i])) + 33'(signed'(q1_par[i][31:0]))) *
                              50'(signed'({1'b0, q1_par[i][47:32]}));
                q2_shift[i] <= q1_par[i][53:48];
                q2_relu[i] <= q1_par[i][54];
                // Round half up; shift <= 48.
                q3_rnd[i] <= (q2_shift[i] == 6'd0) ? q2_prod[i]
                    : q2_prod[i] + (50'sd1 <<< (q2_shift[i] - 6'd1));
                q3_shift[i] <= q2_shift[i];
                q3_relu[i] <= q2_relu[i];
                q4_val[i] <= q3_rnd[i] >>> q3_shift[i];
                q4_relu[i] <= q3_relu[i];
            end
        end
    endgenerate

    // y = clamp(round((acc + bias) * mult / 2^shift), relu ? 0 : -127, 127) per lane.
    always_comb begin
        q_next = q_bytes;
        for (int l = 0; l < L; l++) begin
            if (int'(q4_part) * L + l < N) begin
                if (q4_val[l] > 50'sd127) q_next[int'(q4_part) * L + l] = 8'd127;
                else if (q4_relu[l] && q4_val[l] < 50'sd0) q_next[int'(q4_part) * L + l] = 8'd0;
                else if (q4_val[l] < -50'sd127) q_next[int'(q4_part) * L + l] = 8'h81;
                else q_next[int'(q4_part) * L + l] = q4_val[l][7:0];
            end
        end
    end

    rpu_sim_memory #(
        .N(N),
        .BYTES(MEM_BYTES),
        .READ_LATENCY(READ_LATENCY),
        .LOAD_BEATS(LOAD_BEATS)
    ) external_memory (
        .clk(clk),
        .reset(reset),
        .host_we(host_mem_we),
        .host_addr(host_mem_addr),
        .host_wdata(mem_wdata),
        .host_rdata(host_mem_rdata),
        .rd_valid(issue_active),
        .rd_addr(issue_panel ? issue_b_addr : issue_a_addr),
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
            control_quant <= 1'b0;
            seq_state <= SEQ_IDLE;
            reg_panel <= '0;
            reg_m_blocks <= '0;
            reg_n_tiles <= '0;
            seq_r <= '0;
            seq_j <= '0;
            seq_back <= 1'b0;
            seq_bank <= 1'b0;
        end else begin
            start_request <= 1'b0;
            preload_request <= 1'b0;

            case (seq_state)
                SEQ_IDLE: begin
                end
                SEQ_START: begin
                    start_request <= 1'b1;
                    seq_state <= SEQ_STARTED;
                end
                SEQ_STARTED: seq_state <= SEQ_WAIT;
                SEQ_WAIT: begin
                    // The next load may start once this one is done and the compute has
                    // taken this tile: the B bank and A bank it fills are then free.
                    if (!load_busy && !launch_valid) begin
                        if (seq_last) begin
                            seq_state <= SEQ_IDLE;
                        end else begin
                            seq_state <= SEQ_START;
                            if (seq_block_end) begin
                                // Next row block, same B tile and B bank: load only A.
                                seq_r <= seq_r + 16'd1;
                                seq_back <= !seq_back;
                                reg_a_base <= reg_a_base + reg_panel;
                                reg_c_base <= reg_c_base + BEAT_ADDR_W'(reg_n_tiles) * c_stride;
                                control_a_bank <= !seq_r[0];
                                control_keep_a <= 1'b0;
                                control_keep_b <= 1'b1;
                            end else begin
                                // Next B tile into the other B bank: load only B.
                                seq_j <= seq_back ? seq_j - 16'd1 : seq_j + 16'd1;
                                seq_bank <= !seq_bank;
                                control_bank <= !seq_bank;
                                reg_b_base <= seq_back ? reg_b_base - reg_panel : reg_b_base + reg_panel;
                                reg_c_base <= seq_back ? reg_c_base - c_stride : reg_c_base + c_stride;
                                control_keep_a <= 1'b1;
                                control_keep_b <= 1'b0;
                            end
                        end
                    end
                end
                default: seq_state <= SEQ_IDLE;
            endcase

            if (mem_we) begin
                case (mem_addr)
                    REG_CONTROL_ADDR: begin
                        start_request <= mem_wdata[0];
                        control_bank <= mem_wdata[1];
                        preload_request <= mem_wdata[2];
                        control_keep_a <= mem_wdata[3];
                        control_a_bank <= mem_wdata[4];
                        control_keep_b <= mem_wdata[5];
                        control_quant <= mem_wdata[7];
                        if (mem_wdata[6]) begin
                            // Tile 0 loads A and B into bank 0.
                            control_bank <= 1'b0;
                            control_a_bank <= 1'b0;
                            control_keep_a <= 1'b0;
                            control_keep_b <= 1'b0;
                            seq_state <= SEQ_START;
                            seq_r <= '0;
                            seq_j <= '0;
                            seq_back <= 1'b0;
                            seq_bank <= 1'b0;
                        end
                    end
                    REG_PANEL_ADDR: reg_panel <= BEAT_ADDR_W'(mem_wdata);
                    REG_TILES_ADDR: begin
                        reg_m_blocks <= mem_wdata[15:0];
                        reg_n_tiles <= mem_wdata[31:16];
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
            issue_a_addr <= '0;
            issue_b_addr <= '0;
            recv_panel <= 1'b0;
            recv_row <= '0;
            recv_beat <= '0;
            recv_k <= '0;
            load_local_bank <= 1'b0;
            load_a_bank <= 1'b0;
            load_then_compute <= 1'b0;
            load_keep_a <= 1'b0;
            load_both <= 1'b0;
            load_k_len <= '0;
            launch_valid <= 1'b0;
            launch_ready <= 1'b0;
            launch_wait <= '0;
            launch_bank <= 1'b0;
            launch_a_bank <= 1'b0;
            launch_k_len <= '0;
            launch_c_base <= '0;
            launch_quant <= 1'b0;
            launch_j <= '0;
            compute_quant <= 1'b0;
            drain_quant <= 1'b0;
            store_quant <= 1'b0;
            compute_j <= '0;
            drain_j <= '0;
            store_j <= '0;
            q1_valid <= 1'b0;
            q1_part <= '0;
            q1_addr <= '0;
            q2_valid <= 1'b0;
            q2_part <= '0;
            q2_addr <= '0;
            q3_valid <= 1'b0;
            q3_part <= '0;
            q3_addr <= '0;
            q4_valid <= 1'b0;
            q4_part <= '0;
            q4_addr <= '0;
            q_bytes <= '0;
            q_wr_valid <= 1'b0;
            q_wr_addr <= '0;
            q_wr_data <= '0;
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

            if ((preload_request || ((start_request || start) && !launch_valid)) && !load_busy &&
                (preload_request || !local_valid[control_bank])) begin
                // Preload, or START on a bank that is not loaded yet: load first.
                load_busy <= 1'b1;
                issue_active <= 1'b1;
                issue_panel <= control_keep_a;
                issue_row <= '0;
                issue_k <= '0;
                issue_a_addr <= reg_a_base;
                issue_b_addr <= reg_b_base;
                recv_panel <= control_keep_a;
                recv_row <= '0;
                recv_beat <= '0;
                recv_k <= '0;
                load_local_bank <= control_bank;
                load_a_bank <= control_a_bank;
                load_then_compute <= !preload_request;
                load_keep_a <= control_keep_a;
                load_both <= !control_keep_a && !control_keep_b;
                load_k_len <= reg_k_len;
                local_valid[control_bank] <= 1'b0;
                if (!preload_request) begin
                    cycles <= 32'd0;
                    launch_valid <= 1'b1;
                    launch_ready <= 1'b0;
                    // Response r of the load lands at most one cycle after response r - 1,
                    // and the stream reads column c from N*c cycles after it starts.
                    // Column c is complete at response R*(c+1), R = P*N/LOAD_BEATS for P
                    // panels, so the stream may start once R*(c+1) - N*c - 2 responses
                    // are in, for every column c. With R > N (LOAD_BEATS = 1, A and B)
                    // the last column c = ceil(K/N) - 1 decides: K + 2N - 3. Otherwise
                    // column 0 does: R - 2. The thresholds below leave 3 responses more.
                    launch_wait <= (!control_keep_a && !control_keep_b)
                        ? ((LOAD_BEATS == 1) ? (K_W + 1)'(reg_k_len) + (K_W + 1)'(2 * N)
                                             : (K_W + 1)'(2 * N / LOAD_BEATS + 1))
                        : (K_W + 1)'(N / LOAD_BEATS + 1);
                    launch_bank <= control_bank;
                    launch_a_bank <= control_a_bank;
                    launch_k_len <= reg_k_len;
                    launch_c_base <= reg_c_base;
                    launch_quant <= control_quant;
                    launch_j <= RB_W'(seq_j);
                end
            end else if ((start_request || start) && !launch_valid && local_valid[control_bank]) begin
                cycles <= 32'd0;
                local_valid[control_bank] <= 1'b0;
                if (compute_state == COMPUTE_IDLE || compute_state == COMPUTE_FINISH) begin
                    compute_state <= COMPUTE_CLEAR;
                    stream_last <= local_k_len[control_bank] - 1'b1;
                    compute_local_bank <= control_bank;
                    compute_a_bank <= control_a_bank;
                    compute_c_base <= reg_c_base;
                    compute_quant <= control_quant;
                    compute_j <= RB_W'(seq_j);
                end else begin
                    launch_valid <= 1'b1;
                    launch_ready <= 1'b1;
                    launch_bank <= control_bank;
                    launch_a_bank <= control_a_bank;
                    launch_k_len <= local_k_len[control_bank];
                    launch_c_base <= reg_c_base;
                    launch_quant <= control_quant;
                    launch_j <= RB_W'(seq_j);
                end
            end

            if (launch_valid && launch_ready &&
                (compute_state == COMPUTE_IDLE || compute_state == COMPUTE_FINISH)) begin
                launch_valid <= 1'b0;
                compute_state <= COMPUTE_CLEAR;
                stream_last <= launch_k_len - 1'b1;
                compute_local_bank <= launch_bank;
                compute_a_bank <= launch_a_bank;
                compute_c_base <= launch_c_base;
                compute_quant <= launch_quant;
                compute_j <= launch_j;
            end

            if (issue_active) begin
                if (issue_panel) issue_b_addr <= issue_b_addr + BEAT_ADDR_W'(LOAD_BEATS);
                else issue_a_addr <= issue_a_addr + BEAT_ADDR_W'(LOAD_BEATS);
                if (issue_row != LOAD_LAST) begin
                    issue_row <= issue_row + COL_W'(LOAD_BEATS);
                end else begin
                    issue_row <= '0;
                    if (load_both && !issue_panel) begin
                        issue_panel <= 1'b1;
                    end else if (issue_row_end) begin
                        issue_active <= 1'b0;
                    end else begin
                        issue_panel <= load_keep_a;
                        issue_k <= issue_k + K_W'(N);
                    end
                end
            end

            if (load_busy && dma_rd_resp_valid) begin
                // The row buffers in panel_row take dma_rd_data at (recv_row, recv_beat).
                if (load_then_compute && launch_wait != '0) begin
                    launch_wait <= launch_wait - 1'b1;
                    if (launch_wait == (K_W + 1)'(1)) launch_ready <= 1'b1;
                end
                if (recv_row != LOAD_LAST) begin
                    recv_row <= recv_row + COL_W'(LOAD_BEATS);
                end else begin
                    recv_row <= '0;
                    if (load_both && !recv_panel) begin
                        recv_panel <= 1'b1;
                    end else if (recv_row_end) begin
                        load_busy <= 1'b0;
                        local_k_len[load_local_bank] <= load_k_len;
                        if (load_then_compute) begin
                            launch_ready <= 1'b1;
                        end else begin
                            local_valid[load_local_bank] <= 1'b1;
                        end
                    end else begin
                        recv_panel <= load_keep_a;
                        recv_beat <= recv_beat + 1'b1;
                        recv_k <= recv_k + K_W'(N);
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
                        store_quant <= drain_quant;
                        store_j <= drain_j;
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
                        drain_quant <= compute_quant;
                        drain_j <= compute_j;
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

            // Requantized store: stages 1 to 4 are in q1_* to q4_*, stage 5 builds the row
            // in q_bytes.
            q1_valid <= store_busy && store_quant;
            q1_part <= store_part;
            q1_addr <= store_c_base + BEAT_ADDR_W'(store_row);
            q2_valid <= q1_valid;
            q2_part <= q1_part;
            q2_addr <= q1_addr;
            q3_valid <= q2_valid;
            q3_part <= q2_part;
            q3_addr <= q2_addr;
            q4_valid <= q3_valid;
            q4_part <= q3_part;
            q4_addr <= q3_addr;
            q_wr_valid <= 1'b0;
            if (q4_valid) begin
                q_bytes <= q_next;
                if (q4_part == C_ROW_LAST) begin
                    q_wr_valid <= 1'b1;
                    q_wr_addr <= q4_addr;
                    q_wr_data <= q_next;
                end
            end

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
