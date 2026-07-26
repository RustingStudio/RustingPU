module add_sub_4bit (
    input  logic [3:0] a,
    input  logic [3:0] b,
    input  logic sub_mode,
    output logic [3:0] result,
    output logic cout
);

    logic wire_c1, wire_c2, wire_c3;
    logic [3:0] b_modified;

    assign b_modified[0] = b[0] ^ sub_mode;
    assign b_modified[1] = b[1] ^ sub_mode;
    assign b_modified[2] = b[2] ^ sub_mode;
    assign b_modified[3] = b[3] ^ sub_mode;

    full_adder bit0 (
        .a(a[0]),
        .b(b_modified[0]),
        .cin(sub_mode),
        .sum(result[0]),
        .cout(wire_c1)
    );

    full_adder bit1 (
        .a(a[1]),
        .b(b_modified[1]),
        .cin(wire_c1),
        .sum(result[1]),
        .cout(wire_c2)
    );

    full_adder bit2 (
        .a(a[2]),
        .b(b_modified[2]),
        .cin(wire_c2),
        .sum(result[2]),
        .cout(wire_c3)
    );

    full_adder bit3 (
        .a(a[3]),
        .b(b_modified[3]),
        .cin(wire_c3),
        .sum(result[3]),
        .cout(cout)
    );

endmodule
