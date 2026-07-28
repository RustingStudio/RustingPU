module bf16_adder (
    input  logic [15:0] a,
    input  logic [15:0] b,
    output logic [15:0] result
);

    logic [7:0] exp_a;
    logic [7:0] exp_b;
    logic [7:0] max_exp;
    logic [7:0] exp_diff;
    logic [7:0] mant_a;
    logic [7:0] mant_b;
    logic [7:0] shifted_mant_a;
    logic [7:0] shifted_mant_b;
    logic [8:0] mant_sum;
    logic [7:0] mant_diff;
    logic [7:0] norm_mant;
    logic [7:0] norm_exp;
    logic sign_c;
    logic a_bigger;
    integer shift_idx;

    always @* begin
        exp_a = a[14:7];
        exp_b = b[14:7];
        mant_a = {1'b1, a[6:0]};
        mant_b = {1'b1, b[6:0]};

        max_exp = 8'd0;
        exp_diff = 8'd0;
        shifted_mant_a = 8'd0;
        shifted_mant_b = 8'd0;
        mant_sum = 9'd0;
        mant_diff = 8'd0;
        norm_mant = 8'd0;
        norm_exp = 8'd0;
        sign_c = 1'b0;
        a_bigger = 1'b0;
        result = 16'd0;

        if (a[14:0] == 15'd0) begin
            result = b;
        end else if (b[14:0] == 15'd0) begin
            result = a;
        end else begin
            if (exp_a > exp_b) begin
                max_exp = exp_a;
                exp_diff = exp_a - exp_b;
                shifted_mant_a = mant_a;
                shifted_mant_b = (exp_diff >= 8) ? 8'd0 : (mant_b >> exp_diff);
            end else begin
                max_exp = exp_b;
                exp_diff = exp_b - exp_a;
                shifted_mant_a = (exp_diff >= 8) ? 8'd0 : (mant_a >> exp_diff);
                shifted_mant_b = mant_b;
            end

            if (a[15] == b[15]) begin
                mant_sum = {1'b0, shifted_mant_a} + {1'b0, shifted_mant_b};
                sign_c = a[15];

                if (mant_sum[8]) begin
                    result = {sign_c, max_exp + 8'd1, mant_sum[7:1]};
                end else begin
                    result = {sign_c, max_exp, mant_sum[6:0]};
                end
            end else begin
                a_bigger = ({exp_a, mant_a} >= {exp_b, mant_b});
                sign_c = a_bigger ? a[15] : b[15];

                if (shifted_mant_a >= shifted_mant_b) begin
                    mant_diff = shifted_mant_a - shifted_mant_b;
                end else begin
                    mant_diff = shifted_mant_b - shifted_mant_a;
                end

                norm_mant = mant_diff;
                norm_exp = max_exp;

                for (shift_idx = 0; shift_idx < 8; shift_idx = shift_idx + 1) begin
                    if (norm_mant != 8'd0 && norm_mant[7] == 1'b0 && norm_exp != 8'd0) begin
                        norm_mant = norm_mant << 1;
                        norm_exp = norm_exp - 8'd1;
                    end
                end

                if (norm_mant == 8'd0) begin
                    result = 16'd0;
                end else begin
                    result = {sign_c, norm_exp, norm_mant[6:0]};
                end
            end
        end
    end

endmodule
