module sync_adder (
    input  logic clk,
    input  logic a,
    input  logic b,
    input  logic cin,
    output logic sum_out,
    output logic cout_out
);

    logic wire_sum;
    logic wire_cout;

    full_adder math_unit (
        .a(a),
        .b(b),
        .cin(cin),
        .sum(wire_sum),
        .cout(wire_cout)
    );

    always_ff @(posedge clk) begin
        sum_out  <= wire_sum;
        cout_out <= wire_cout;
    end

endmodule
