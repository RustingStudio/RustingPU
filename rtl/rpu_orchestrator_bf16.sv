module rpu_orchestrator_bf16 #(
    parameter N = 2
)(
    input  logic clk, reset,
    input  logic [15:0] a_flat [0:N-1],
    input  logic [15:0] b_flat [0:N-1],
    output logic [15:0] c [0:N-1][0:N-1]
);

    logic [15:0] a_delay_chain [0:N-1][0:N];
    logic [15:0] b_delay_chain [0:N-1][0:N];

    logic [15:0] wire_a [0:N-1][0:N];
    logic [15:0] wire_b [0:N][0:N-1];

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin : delays
            assign a_delay_chain[i][0] = a_flat[i];
            assign b_delay_chain[i][0] = b_flat[i];

            for (j = 0; j < i; j++) begin : chain
                delay_cell d_a (.clk(clk), .reset(reset), .data_in(a_delay_chain[i][j]), .data_out(a_delay_chain[i][j+1]));
                delay_cell d_b (.clk(clk), .reset(reset), .data_in(b_delay_chain[i][j]), .data_out(b_delay_chain[i][j+1]));
            end

            assign wire_a[i][0] = a_delay_chain[i][i];
            assign wire_b[0][i] = b_delay_chain[i][i];
        end

        for (i = 0; i < N; i++) begin : row
            for (j = 0; j < N; j++) begin : col
                bf16_systolic_cell pe_cell (
                    .clk(clk), .reset(reset),
                    .a_in(wire_a[i][j]),
                    .b_in(wire_b[i][j]),
                    .a_out(wire_a[i][j+1]),
                    .b_out(wire_b[i+1][j]),
                    .accumulator(c[i][j])
                );
            end
        end
    endgenerate
endmodule
