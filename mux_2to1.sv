module mux_2to1 (
    input  logic [3:0] d0,
    input  logic [3:0] d1,
    input  logic sel,
    output logic [3:0] y
);

    assign y = sel ? d1 : d0;

endmodule
