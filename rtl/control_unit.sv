module control_unit (
    input  logic clk,
    input  logic cpu_reset,
    output logic acc_reset,
    output logic sub_mode,
    output logic op_select,
    output logic [3:0] data_out
);

    logic [2:0] pc;
    always_ff @(posedge clk) begin
        if (cpu_reset)
            pc <= 3'b000;
        else
            pc <= pc + 1;
    end

    logic [7:0] instruction;
    always_comb begin
        case (pc)
            3'd0: instruction = 8'b11_00_0000;
            3'd1: instruction = 8'b00_00_0101;
            3'd2: instruction = 8'b00_00_0011;
            3'd3: instruction = 8'b01_00_0010;
            3'd4: instruction = 8'b10_00_0111;
            3'd5: instruction = 8'b01_00_0101;
            default: instruction = 8'b00_00_0000;
        endcase
    end

    logic [1:0] opcode;
    assign opcode = instruction[7:6];
    assign data_out = instruction[3:0];

    always_comb begin
        sub_mode = 0; op_select = 0; acc_reset = 0;

        case (opcode)
            2'b00: begin sub_mode = 0; op_select = 0; end
            2'b01: begin sub_mode = 1; op_select = 0; end
            2'b10: begin sub_mode = 0; op_select = 1; end
            2'b11: begin acc_reset = 1;               end
        endcase
    end

endmodule
