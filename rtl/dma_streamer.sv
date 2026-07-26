module dma_streamer (
    input  logic clk,
    input  logic reset,
    input  logic start,
    output logic [3:0] sram_addr,
    output logic rpu_valid
);

    typedef enum logic [1:0] {IDLE, STREAMING, DONE} state_t;
    state_t state, next_state;

    always_ff @(posedge clk) begin
        if (reset)
            state <= IDLE;
        else
            state <= next_state;
    end

    always_comb begin
        next_state = state;
        case (state)
            IDLE:      if (start) next_state = STREAMING;
            STREAMING: if (sram_addr == 4'd2) next_state = DONE;
            DONE:      if (start) next_state = IDLE;
        endcase
    end

    always_ff @(negedge clk) begin
        if (state == IDLE) begin
            sram_addr <= 4'd0;
            rpu_valid <= 1'b0;
        end
        else if (state == STREAMING) begin
            sram_addr <= sram_addr + 1;
            rpu_valid <= 1'b1;
        end
        else begin
            rpu_valid <= 1'b0;
        end
    end

endmodule
