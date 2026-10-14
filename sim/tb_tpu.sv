`timescale 1ns / 1ps

// Smoke test of the raw int8 systolic array (no registers, no memory path).
// Streams one N x N NT tile, shifts C out one column per cycle, and compares
// it with a behavioural reference.
module tb_tpu;
    parameter int N = 4;
    logic clk, reset;
    logic [N-1:0][7:0] a_flat;
    logic [N-1:0][7:0] b_flat;
    logic drain;
    logic [N-1:0][31:0] c_col;

    logic signed [7:0] a [0:N-1][0:N-1];
    logic signed [7:0] b [0:N-1][0:N-1];
    int errors;
    logic signed [31:0] c [0:N-1][0:N-1];
    // Icarus cannot index a multi-dimensional packed array with variables.
    wire [N*32-1:0] c_bits = c_col;

    rpu_array #(.N(N)) uut (.*);

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        for (int i = 0; i < N; i++) begin
            for (int k = 0; k < N; k++) begin
                a[i][k] = 8'((i * 37 + k * 11) % 255 - 127);
                b[i][k] = 8'((i * 53 + k * 29 + 5) % 255 - 127);
            end
            a_flat[i] = 0;
            b_flat[i] = 0;
        end
        a[0][0] = -127;
        b[0][0] = -127;

        drain = 0;
        reset = 1;
        @(negedge clk);
        reset = 0;

        for (int k = 0; k < N; k++) begin
            for (int i = 0; i < N; i++) begin
                a_flat[i] = a[i][k];
                b_flat[i] = b[i][k];
            end
            @(negedge clk);
        end
        for (int i = 0; i < N; i++) begin
            a_flat[i] = 0;
            b_flat[i] = 0;
        end
        repeat (2 * N) @(negedge clk);

        // Column N-1 is on c_col; each drain cycle shifts the next column in.
        drain = 1;
        for (int t = 0; t < N; t++) begin
            for (int i = 0; i < N; i++) c[i][N-1-t] = c_bits[i * 32 +: 32];
            @(negedge clk);
        end
        drain = 0;

        errors = 0;
        for (int i = 0; i < N; i++) begin
            for (int j = 0; j < N; j++) begin
                int want;
                logic signed [31:0] got;
                got = c[i][j];
                want = 0;
                for (int k = 0; k < N; k++) want += int'(a[i][k]) * int'(b[j][k]);
                if (got !== want) begin
                    $display("MISMATCH c[%0d][%0d] = %0d, want %0d", i, j, got, want);
                    errors++;
                end
            end
        end
        if (errors == 0) $display("PASS: %0dx%0d int8 tile bit-exact", N, N);
        else $fatal(1, "FAIL: %0d mismatches", errors);
        $finish;
    end
endmodule
