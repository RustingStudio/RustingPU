module mini_alu (
    input  logic [3:0] a,
    input  logic [3:0] b,
    input  logic sub_mode,
    input  logic op_select,
    output logic [3:0] result
);

    logic [3:0] add_answer;
    logic [3:0] and_answer;
    logic ignore_cout;

    add_sub_4bit my_adder (
        .a(a),
        .b(b),
        .sub_mode(sub_mode),
        .result(add_answer),
        .cout(ignore_cout)
    );

    assign and_answer = a & b;


    mux_2to1 my_mux (
        .d0(add_answer),
        .d1(and_answer),
        .sel(op_select),
        .y(result)
    );

endmodule
