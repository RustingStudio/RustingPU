// N x N output-stationary systolic array of int8_cell PEs.
// Row i of A enters from the left delayed by i cycles; column j of B enters
// from the top delayed by j cycles, so A[i][k] and B[j][k] meet in PE (i, j).
module rpu_array #(
    parameter int N = 8
)(
    input  logic clk,
    input  logic reset,
    input  logic [N-1:0][7:0] a_flat,
    input  logic [N-1:0][7:0] b_flat,
    output logic [N-1:0][N-1:0][31:0] c
);

    // Packed arrays throughout: Yosys does not take unpacked array ports.
    logic [N-1:0][N:0][7:0] a_delay_chain;
    logic [N-1:0][N:0][7:0] b_delay_chain;

    logic [N-1:0][N:0][7:0] wire_a;
    logic [N:0][N-1:0][7:0] wire_b;

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin : delays
            assign a_delay_chain[i][0] = a_flat[i];
            assign b_delay_chain[i][0] = b_flat[i];

            for (j = 0; j < i; j++) begin : chain
                delay_cell #(.W(8)) d_a (.clk(clk), .reset(reset), .data_in(a_delay_chain[i][j]), .data_out(a_delay_chain[i][j+1]));
                delay_cell #(.W(8)) d_b (.clk(clk), .reset(reset), .data_in(b_delay_chain[i][j]), .data_out(b_delay_chain[i][j+1]));
            end

            assign wire_a[i][0] = a_delay_chain[i][i];
            assign wire_b[0][i] = b_delay_chain[i][i];
        end

        for (i = 0; i < N; i++) begin : row
            for (j = 0; j < N; j++) begin : col
                int8_cell pe_cell (
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
