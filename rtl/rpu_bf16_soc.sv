module rpu_bf16_soc (
    input  logic clk,
    input  logic reset,
    input  logic start,
    output logic [31:0] cycles,

    input  logic [15:0] a00,
    input  logic [15:0] a01,
    input  logic [15:0] a10,
    input  logic [15:0] a11,
    input  logic [15:0] b00,
    input  logic [15:0] b01,
    input  logic [15:0] b10,
    input  logic [15:0] b11,

    output logic busy,
    output logic done,
    output logic [15:0] c00,
    output logic [15:0] c01,
    output logic [15:0] c10,
    output logic [15:0] c11
);

    localparam int N = 2;
    localparam logic STREAM_LAST = 1'b1;
    localparam logic [2:0] DRAIN_LAST = 3'd3;

    typedef enum logic [2:0] {
        IDLE,
        CLEAR,
        STREAM,
        DRAIN,
        DONE
    } state_t;

    state_t state;
    logic stream_idx;
    logic [2:0] drain_count;
    logic core_reset;

    logic [15:0] a_reg [0:N-1][0:N-1];
    logic [15:0] b_reg [0:N-1][0:N-1];
    logic [15:0] a_flat [0:N-1];
    logic [15:0] b_flat [0:N-1];
    logic [15:0] c [0:N-1][0:N-1];

    assign core_reset = reset || state == CLEAR;
    assign busy = state == CLEAR || state == STREAM || state == DRAIN;

    assign a_flat[0] = (state == STREAM) ? a_reg[0][stream_idx] : 16'd0;
    assign a_flat[1] = (state == STREAM) ? a_reg[1][stream_idx] : 16'd0;
    assign b_flat[0] = (state == STREAM) ? b_reg[stream_idx][0] : 16'd0;
    assign b_flat[1] = (state == STREAM) ? b_reg[stream_idx][1] : 16'd0;

    assign c00 = c[0][0];
    assign c01 = c[0][1];
    assign c10 = c[1][0];
    assign c11 = c[1][1];

    rpu_orchestrator_bf16 #(.N(N)) math_core (
        .clk(clk),
        .reset(core_reset),
        .a_flat(a_flat),
        .b_flat(b_flat),
        .c(c)
    );

    always_ff @(posedge clk) begin
        if (reset) begin
            cycles <= 32'd0;
        end else if (start) begin
            cycles <= 32'd0;
        end else if (busy) begin
            cycles <= cycles + 32'd1;
        end
    end

    always_ff @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
            done <= 1'b0;
            stream_idx <= 1'b0;
            drain_count <= 3'd0;

        end else begin
            case (state)
                IDLE, DONE: begin
                    if (start) begin
                        a_reg[0][0] <= a00;
                        a_reg[0][1] <= a01;
                        a_reg[1][0] <= a10;
                        a_reg[1][1] <= a11;
                        b_reg[0][0] <= b00;
                        b_reg[0][1] <= b01;
                        b_reg[1][0] <= b10;
                        b_reg[1][1] <= b11;

                        done <= 1'b0;
                        stream_idx <= 1'b0;
                        drain_count <= 3'd0;
                        state <= CLEAR;
                    end else if (state == DONE) begin
                        done <= 1'b1;
                    end
                end

                CLEAR: begin
                    stream_idx <= 1'b0;
                    drain_count <= 3'd0;
                    state <= STREAM;
                end

                STREAM: begin
                    if (stream_idx == STREAM_LAST) begin
                        stream_idx <= 1'b0;
                        drain_count <= 3'd0;
                        state <= DRAIN;
                    end else begin
                        stream_idx <= 1'b1;
                    end
                end

                DRAIN: begin
                    if (drain_count == DRAIN_LAST) begin
                        done <= 1'b1;
                        state <= DONE;
                    end else begin
                        drain_count <= drain_count + 3'd1;
                    end
                end

                default: begin
                    state <= IDLE;
                    done <= 1'b0;
                end
            endcase
        end
    end

endmodule
