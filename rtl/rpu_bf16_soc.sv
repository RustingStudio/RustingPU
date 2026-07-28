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

    logic [15:0] mem_a [0:N*N-1];
    logic [15:0] mem_b [0:N*N-1];
    logic [15:0] mem_c [0:N*N-1];

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

    logic [15:0] ext_mem [0:EXT_WORDS-1];

    logic [15:0] reg_a_base;
    logic [15:0] reg_b_base;
    logic [15:0] reg_c_base;
    logic start_request;
    logic [DMA_W-1:0] dma_idx;

    typedef enum logic [3:0] {
        IDLE,
        DMA_LOAD_A,
        DMA_LOAD_B,
        CLEAR,
        STREAM,
        DRAIN,
        DMA_STORE_C,
        FINISH
    } state_t;

    state_t state;
    logic [STREAM_W-1:0] stream_idx;
    logic [DRAIN_W-1:0] drain_count;
    logic [15:0] a_flat [0:N-1];
    logic [15:0] b_flat [0:N-1];
    logic [15:0] c [0:N-1][0:N-1];
    logic core_reset;

    assign core_reset = reset || (state == CLEAR);
    assign busy = (state == DMA_LOAD_A) || (state == DMA_LOAD_B) ||
                  (state == CLEAR) || (state == STREAM) || (state == DRAIN) ||
                  (state == DMA_STORE_C);
    assign done = (state == FINISH);

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin : input_flatten
            assign a_flat[i] = (state == STREAM) ? mem_a[i * N + int'(stream_idx)] : 16'd0;
            assign b_flat[i] = (state == STREAM) ? mem_b[int'(stream_idx) * N + i] : 16'd0;
        end

    endgenerate

    rpu_orchestrator_bf16 #(.N(N)) math_core (
        .clk(clk),
        .reset(core_reset),
        .a_flat(a_flat),
        .b_flat(b_flat),
        .c(c)
    );

    always_ff @(posedge clk) begin
        if (reset) begin
            reg_a_base <= 16'd0;
            reg_b_base <= 16'd0;
            reg_c_base <= 16'd0;
            start_request <= 1'b0;
        end else begin
            start_request <= 1'b0;

            if (mem_we) begin
                case (mem_addr)
                    REG_CONTROL_ADDR[ADDR_W-1:0]: start_request <= mem_wdata[0];
                    REG_A_BASE_ADDR[ADDR_W-1:0]: reg_a_base <= mem_wdata;
                    REG_B_BASE_ADDR[ADDR_W-1:0]: reg_b_base <= mem_wdata;
                    REG_C_BASE_ADDR[ADDR_W-1:0]: reg_c_base <= mem_wdata;

                    default: begin
                        if (int'(mem_addr) >= EXT_BASE_ADDR &&
                            int'(mem_addr) < EXT_BASE_ADDR + EXT_WORDS) begin
                            ext_mem[EXT_ADDR_W'(int'(mem_addr) - EXT_BASE_ADDR)] <= mem_wdata;
                        end
                    end
                endcase
            end
        end
    end

    always_ff @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
            cycles <= 32'd0;
            stream_idx <= '0;
            drain_count <= '0;
            dma_idx <= '0;
        end else begin
            if (busy) begin
                cycles <= cycles + 32'd1;
            end

            case (state)
                IDLE, FINISH: begin
                    if (start_request || start) begin
                        cycles <= 32'd0;
                        stream_idx <= '0;
                        drain_count <= '0;
                        dma_idx <= '0;
                        state <= DMA_LOAD_A;
                    end
                end
                DMA_LOAD_A: begin
                    mem_a[dma_idx] <= ext_mem[EXT_ADDR_W'(int'(reg_a_base) + int'(dma_idx))];

                    if (dma_idx == DMA_LAST) begin
                        dma_idx <= '0;
                        state <= DMA_LOAD_B;
                    end else begin
                        dma_idx <= dma_idx + 1'b1;
                    end
                end

                DMA_LOAD_B: begin
                    mem_b[dma_idx] <= ext_mem[EXT_ADDR_W'(int'(reg_b_base) + int'(dma_idx))];

                    if (dma_idx == DMA_LAST) begin
                        dma_idx <= '0;
                        state <= CLEAR;
                    end else begin
                        dma_idx <= dma_idx + 1'b1;
                    end
                end
                CLEAR: begin
                    stream_idx <= '0;
                    drain_count <= '0;
                    state <= STREAM;
                end

                STREAM: begin
                    if (stream_idx == STREAM_LAST) begin
                        stream_idx <= '0;
                        drain_count <= '0;
                        state <= DRAIN;
                    end else begin
                        stream_idx <= stream_idx + 1'b1;
                    end
                end
                DMA_STORE_C: begin
                    ext_mem[EXT_ADDR_W'(int'(reg_c_base) + int'(dma_idx))] <= mem_c[dma_idx];

                    if (dma_idx == DMA_LAST) begin
                        dma_idx <= '0;
                        state <= FINISH;
                    end else begin
                        dma_idx <= dma_idx + 1'b1;
                    end
                end
                DRAIN: begin
                    if (drain_count == DRAIN_LAST) begin
                        for (int row = 0; row < N; row++) begin
                            for (int col = 0; col < N; col++) begin
                                mem_c[row * N + col] <= c[row][col];
                            end
                        end
                        dma_idx <= '0;
                        state <= DMA_STORE_C;
                    end else begin
                        drain_count <= drain_count + 1'b1;
                    end
                end

                default: begin
                    state <= IDLE;
                end
            endcase
        end
    end

    always_comb begin
        int unsigned addr;
        addr = int'(mem_addr);

        if (addr == REG_CONTROL_ADDR) begin
            mem_rdata = 16'd0;
        end else if (addr == REG_STATUS_ADDR) begin
            mem_rdata = {14'd0, done, busy};
        end else if (addr == REG_A_BASE_ADDR) begin
            mem_rdata = reg_a_base;
        end else if (addr == REG_B_BASE_ADDR) begin
            mem_rdata = reg_b_base;
        end else if (addr == REG_C_BASE_ADDR) begin
            mem_rdata = reg_c_base;
        end else if (addr >= EXT_BASE_ADDR && addr < EXT_BASE_ADDR + EXT_WORDS) begin
            mem_rdata = ext_mem[EXT_ADDR_W'(addr - EXT_BASE_ADDR)];
        end else begin
            mem_rdata = 16'd0;
        end
    end

endmodule
