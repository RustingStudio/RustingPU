module datapath (
    input  logic clk,
    input  logic reset,
    input  logic [3:0] data_in,
    input  logic sub_mode,
    input  logic op_select,
    output logic [3:0] out
);

    logic [3:0] alu_to_reg;

    mini_alu core_alu (
        .a(out),
        .b(data_in),
        .sub_mode(sub_mode),
        .op_select(op_select),
        .result(alu_to_reg)
    );

    register_4bit accumulator (
        .clk(clk),
        .reset(reset),
        .d(alu_to_reg),
        .q(out)
    );

endmodule
