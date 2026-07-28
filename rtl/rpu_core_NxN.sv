module rpu_core_NxN #(
    parameter N = 4
)(
    input logic clk, reset,
    input logic [3:0] a_in [N],
    input logic [3:0] b_in [N],
    output logic [7:0] c_out [N][N]
);

    logic [3:0] wire_a [N][N+1];
    logic [3:0] wire_b [N+1][N];

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin : row
            for (j = 0; j < N; j++) begin : col
                systolic_cell cell (
                    .clk(clk), .reset(reset),
                    .a_in( (j==0) ? a_in[i] : wire_a[i][j] ),
                    .b_in( (i==0) ? b_in[j] : wire_b[i][j] ),
                    .a_out( wire_a[i][j+1] ),
                    .b_out( wire_b[i+1][j] ),
                    .accumulator( c_out[i][j] )
                );
            end
        end
    endgenerate

endmodule
