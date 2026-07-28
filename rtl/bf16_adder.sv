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
    logic [11:0] aligned_a;
    logic [11:0] aligned_b;
    logic [11:0] mant_sum;
    logic [11:0] norm_mant;
    logic [7:0] norm_exp;
    logic [8:0] rounded_mant;
    logic round_up;
    logic sign_c;
    logic a_bigger;
    integer shift_idx;

    function automatic [11:0] shift_right_sticky(
        input logic [11:0] value,
        input integer shift
    );
        logic sticky;
        integer bit_idx;
        begin
            if (shift <= 0) begin
                shift_right_sticky = value;
            end else if (shift >= 12) begin
                shift_right_sticky = (value != 12'd0) ? 12'd1 : 12'd0;
            end else begin
                sticky = 1'b0;
                for (bit_idx = 0; bit_idx < 12; bit_idx = bit_idx + 1) begin
                    if (bit_idx < shift) begin
                        sticky = sticky | value[bit_idx];
                    end
                end
                shift_right_sticky = value >> shift;
                shift_right_sticky[0] = shift_right_sticky[0] | sticky;
            end
        end
    endfunction

    always @* begin
        exp_a = a[14:7];
        exp_b = b[14:7];
        mant_a = {1'b1, a[6:0]};
        mant_b = {1'b1, b[6:0]};

        max_exp = 8'd0;
        exp_diff = 8'd0;
        aligned_a = 12'd0;
        aligned_b = 12'd0;
        mant_sum = 12'd0;
        norm_mant = 12'd0;
        norm_exp = 8'd0;
        rounded_mant = 9'd0;
        round_up = 1'b0;
        sign_c = 1'b0;
        a_bigger = 1'b0;
        result = 16'd0;

        if (a[14:0] == 15'd0) begin
            result = b;
        end else if (b[14:0] == 15'd0) begin
            result = a;
        end else begin
            aligned_a = {4'd0, mant_a};
            aligned_b = {4'd0, mant_b};

            if (exp_a > exp_b) begin
                max_exp = exp_a;
                exp_diff = exp_a - exp_b;
                aligned_a = aligned_a << 3;
                aligned_b = shift_right_sticky(aligned_b << 3, int'(exp_diff));
            end else begin
                max_exp = exp_b;
                exp_diff = exp_b - exp_a;
                aligned_a = shift_right_sticky(aligned_a << 3, int'(exp_diff));
                aligned_b = aligned_b << 3;
            end

            if (a[15] == b[15]) begin
                mant_sum = aligned_a + aligned_b;
                sign_c = a[15];
                norm_mant = mant_sum;
                norm_exp = max_exp;
                if (norm_mant[11]) begin
                    norm_mant = norm_mant >> 1;
                    norm_exp = norm_exp + 8'd1;
                end
            end else begin
                a_bigger = (aligned_a >= aligned_b);
                sign_c = a_bigger ? a[15] : b[15];

                if (a_bigger) begin
                    norm_mant = aligned_a - aligned_b;
                end else begin
                    norm_mant = aligned_b - aligned_a;
                end
                norm_exp = max_exp;

                for (shift_idx = 0; shift_idx < 11; shift_idx = shift_idx + 1) begin
                    if (norm_mant != 12'd0 && norm_mant[10] == 1'b0 && norm_exp != 8'd0) begin
                        norm_mant = norm_mant << 1;
                        norm_exp = norm_exp - 8'd1;
                    end
                end
            end

            if (norm_mant == 12'd0) begin
                result = 16'd0;
            end else begin
                if (norm_mant[2] && (|norm_mant[1:0] || norm_mant[3])) begin
                    rounded_mant = {1'b0, norm_mant[10:3]} + 9'd1;
                end else begin
                    rounded_mant = {1'b0, norm_mant[10:3]};
                end

                if (rounded_mant[8]) begin
                    result = {sign_c, norm_exp + 8'd1, rounded_mant[7:1]};
                end else begin
                    result = {sign_c, norm_exp, rounded_mant[6:0]};
                end
            end
        end
    end

endmodule
