module mul_4bit (
    input  logic [3:0] a,
    input  logic [3:0] b,
    output logic [3:0] result,
    output logic cout
);

    logic [3:0] pp0, pp1, pp2, pp3;
    logic [7:0] product;

    assign pp0 = {4{a[0]}} & b;
    assign pp1 = {4{a[1]}} & b;
    assign pp2 = {4{a[2]}} & b;
    assign pp3 = {4{a[3]}} & b;

    assign product = pp0 + (pp1 << 1) + (pp2 << 2) + (pp3 << 3);

    assign result = product[3:0];
    assign cout = |product[7:4];

endmodule
