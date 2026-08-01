module rpu_bf16_soc #(
    parameter int N = 8,
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

    localparam int EXT_WORDS = 4096;
    localparam int TILE_WORDS = N * N;
    localparam int STREAM_STEPS = N;
    localparam int DRAIN_STEPS = 2 * N;
    localparam int STREAM_W = (N > 1) ? $clog2(N) : 1;
    localparam int DRAIN_W = (DRAIN_STEPS > 1) ? $clog2(DRAIN_STEPS + 1) : 1;
    localparam int DMA_W = (TILE_WORDS > 1) ? $clog2(TILE_WORDS) : 1;
    localparam int EXT_ADDR_W = (EXT_WORDS > 1) ? $clog2(EXT_WORDS) : 1;
    localparam logic [STREAM_W-1:0] STREAM_LAST = STREAM_W'(N - 1);
    localparam logic [DRAIN_W-1:0] DRAIN_LAST = DRAIN_W'(DRAIN_STEPS - 1);
    localparam logic [DMA_W-1:0] DMA_LAST = DMA_W'(TILE_WORDS - 1);
    localparam int unsigned REG_CONTROL_ADDR = 0;
    localparam int unsigned REG_STATUS_ADDR = 1;
    localparam int unsigned REG_A_BASE_ADDR = 2;
    localparam int unsigned REG_B_BASE_ADDR = 3;
    localparam int unsigned REG_C_BASE_ADDR = 4;
    localparam int unsigned EXT_BASE_ADDR = 4096;

    logic [15:0] mem_a [0:1][0:TILE_WORDS-1];
    logic [15:0] mem_b [0:1][0:TILE_WORDS-1];
    logic [15:0] mem_c [0:TILE_WORDS-1];

    logic [15:0] reg_a_base;
    logic [15:0] reg_b_base;
    logic [15:0] reg_c_base;
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
        COMPUTE_DRAIN,
        COMPUTE_STORE_C,
        COMPUTE_FINISH
    } compute_state_t;

    load_state_t load_state;
    compute_state_t compute_state;

    logic [DMA_W-1:0] load_idx;
    logic [DMA_W-1:0] store_idx;
    logic [STREAM_W-1:0] stream_idx;
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

    logic [15:0] a_flat [0:N-1];
    logic [15:0] b_flat [0:N-1];
    logic [15:0] c [0:N-1][0:N-1];
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
                          (compute_state == COMPUTE_DRAIN) ||
                          (compute_state == COMPUTE_STORE_C);
    assign busy = load_busy || compute_busy;
    assign done = (compute_state == COMPUTE_FINISH);
    assign core_reset = reset || (compute_state == COMPUTE_CLEAR);

    genvar i;
    generate
        for (i = 0; i < N; i++) begin : input_flatten
            assign a_flat[i] = (compute_state == COMPUTE_STREAM)
                ? mem_a[compute_local_bank][i * N + int'(stream_idx)]
                : 16'd0;
            assign b_flat[i] = (compute_state == COMPUTE_STREAM)
                ? mem_b[compute_local_bank][int'(stream_idx) * N + i]
                : 16'd0;
        end
    endgenerate

    rpu_orchestrator_bf16 #(.N(N)) math_core (
        .clk(clk),
        .reset(core_reset),
        .a_flat(a_flat),
        .b_flat(b_flat),
        .c(c)
    );

    assign dma_rd_valid = (load_state == LOAD_A) || (load_state == LOAD_B);
    assign dma_rd_bank = load_ext_bank;
    assign dma_rd_addr = (load_state == LOAD_A)
        ? EXT_ADDR_W'(int'(load_a_base) + int'(load_idx))
        : EXT_ADDR_W'(int'(load_b_base) + int'(load_idx));

    assign dma_wr_valid = (compute_state == COMPUTE_STORE_C);
    assign dma_wr_bank = compute_ext_bank;
    assign dma_wr_addr = EXT_ADDR_W'(int'(compute_c_base) + int'(store_idx));
    assign dma_wr_data = mem_c[store_idx];

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
            load_idx <= '0;
            store_idx <= '0;
            stream_idx <= '0;
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
        end else begin
            if (busy) begin
                cycles <= cycles + 32'd1;
            end

            if (preload_request && load_state == LOAD_IDLE) begin
                load_state <= LOAD_A;
                load_idx <= '0;
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
                stream_idx <= '0;
                drain_count <= '0;
                store_idx <= '0;

                if (local_valid[control_bank]) begin
                    compute_state <= COMPUTE_CLEAR;
                    compute_local_bank <= control_bank;
                    compute_ext_bank <= control_bank;
                    compute_c_base <= reg_c_base;
                    local_valid[control_bank] <= 1'b0;
                end else if (load_state == LOAD_IDLE) begin
                    load_state <= LOAD_A;
                    load_idx <= '0;
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
                LOAD_A: begin
                    if (dma_rd_ready) begin
                        mem_a[load_local_bank][load_idx] <= dma_rd_data;

                        if (load_idx == DMA_LAST) begin
                            load_idx <= '0;
                            load_state <= LOAD_B;
                        end else begin
                            load_idx <= load_idx + 1'b1;
                        end
                    end
                end
                LOAD_B: begin
                    if (dma_rd_ready) begin
                        mem_b[load_local_bank][load_idx] <= dma_rd_data;

                        if (load_idx == DMA_LAST) begin
                            load_idx <= '0;
                            load_state <= LOAD_IDLE;

                            if (load_then_compute &&
                                (compute_state == COMPUTE_IDLE || compute_state == COMPUTE_FINISH)) begin
                                compute_state <= COMPUTE_CLEAR;
                                compute_local_bank <= load_local_bank;
                                compute_ext_bank <= load_ext_bank;
                                compute_c_base <= load_c_base;
                                stream_idx <= '0;
                                drain_count <= '0;
                                store_idx <= '0;
                                local_valid[load_local_bank] <= 1'b0;
                            end else begin
                                local_valid[load_local_bank] <= 1'b1;
                            end
                        end else begin
                            load_idx <= load_idx + 1'b1;
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
                    stream_idx <= '0;
                    drain_count <= '0;
                    compute_state <= COMPUTE_STREAM;
                end
                COMPUTE_STREAM: begin
                    if (stream_idx == STREAM_LAST) begin
                        stream_idx <= '0;
                        drain_count <= '0;
                        compute_state <= COMPUTE_DRAIN;
                    end else begin
                        stream_idx <= stream_idx + 1'b1;
                    end
                end
                COMPUTE_DRAIN: begin
                    if (drain_count == DRAIN_LAST) begin
                        for (int row = 0; row < N; row++) begin
                            for (int col = 0; col < N; col++) begin
                                mem_c[row * N + col] <= c[row][col];
                            end
                        end
                        store_idx <= '0;
                        compute_state <= COMPUTE_STORE_C;
                    end else begin
                        drain_count <= drain_count + 1'b1;
                    end
                end
                COMPUTE_STORE_C: begin
                    if (dma_wr_ready) begin
                        if (store_idx == DMA_LAST) begin
                            store_idx <= '0;
                            compute_state <= COMPUTE_FINISH;
                        end else begin
                            store_idx <= store_idx + 1'b1;
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
