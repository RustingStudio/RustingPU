module cpu (
    input  logic clk,
    input  logic reset,
    output logic [3:0] cpu_out
);

    logic wire_acc_reset;
    logic wire_sub_mode;
    logic wire_op_select;
    logic [3:0] wire_data;

    control_unit brain (
        .clk(clk),
        .cpu_reset(reset),
        .acc_reset(wire_acc_reset),
        .sub_mode(wire_sub_mode),
        .op_select(wire_op_select),
        .data_out(wire_data)
    );

    datapath muscles (
        .clk(clk),
        .reset(wire_acc_reset | reset),
        .data_in(wire_data),
        .sub_mode(wire_sub_mode),
        .op_select(wire_op_select),
        .out(cpu_out)
    );

endmodule
