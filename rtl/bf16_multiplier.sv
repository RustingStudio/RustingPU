module bf16_multiplier (
    input  logic [15:0] a,
    input  logic [15:0] b,
    output logic [15:0] result
);

    logic sign_c;
    logic [8:0] exp_c;
    logic [15:0] fract_mult;
    logic [7:0] final_exp;
    logic [6:0] final_fract;

    always @* begin
        sign_c = 1'b0;
        exp_c = 9'd0;
        fract_mult = 16'd0;
        final_exp = 8'd0;
        final_fract = 7'd0;
        result = 16'd0;

        if (a[14:0] == 15'd0 || b[14:0] == 15'd0) begin
            result = 16'd0;
        end else begin
            sign_c = a[15] ^ b[15];
            exp_c = {1'b0, a[14:7]} + {1'b0, b[14:7]} - 9'd127;
            fract_mult = {1'b1, a[6:0]} * {1'b1, b[6:0]};

            if (fract_mult[15] == 1'b1) begin
                final_exp = exp_c[7:0] + 8'd1;
                final_fract = fract_mult[14:8];
            end else begin
                final_exp = exp_c[7:0];
                final_fract = fract_mult[13:7];
            end

            result = {sign_c, final_exp, final_fract};
        end
    end

endmodule
