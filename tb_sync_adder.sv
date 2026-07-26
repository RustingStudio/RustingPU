module tb_sync_adder;
    reg clk, a, b, cin;
    wire sum_out, cout_out;

    sync_adder uut (
        .clk(clk),
        .a(a),
        .b(b),
        .cin(cin),
        .sum_out(sum_out),
        .cout_out(cout_out)
    );

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, tb_sync_adder);

        clk = 0;
        a = 0; b = 0; cin = 0;
        #10 a = 1;
        #10 b = 1;
        #10 cin = 1;
        #10 a = 0; b = 1;
        #10 $finish;
    end

    always #5 clk = ~clk;
endmodule
