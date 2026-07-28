module rpu_orchestrator_NxN #(
    parameter N = 4
) (
    input  logic clk, reset,
    input  logic [3:0] a_flat [0:N-1],
    input  logic [3:0] b_flat [0:N-1],
    output logic [7:0] c [0:N-1][0:N-1]
);

    logic [3:0] a_skewed [0:N-1];
    logic [3:0] b_skewed [0:N-1];

    logic [3:0] a_delay_chain [0:N-1][0:N];

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin : skew_a
            assign a_delay_chain[i][0] = a_flat[i];

            for (j = 0; j < i; j++) begin : delays
                delay_cell d (
                    .clk(clk), .reset(reset),
                    .data_in(a_delay_chain[i][j]),
                    .data_out(a_delay_chain[i][j+1])
                );
            end

            assign a_skewed[i] = a_delay_chain[i][i];
        end

    logic [3:0] b_delay_chain [0:N-1][0:N];

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin : skew_b
            assign b_delay_chain[i][0] = b_flat[i];

            for (j = 0; j < i; j++) begin : delays
                delay_cell d (
                    .clk(clk), .reset(reset),
                    .data_in(b_delay_chain[i][j]),
                    .data_out(b_delay_chain[i][j+1])
                );
            end

            assign b_skewed[i] = b_delay_chain[i][i];
        end

endgenerate
