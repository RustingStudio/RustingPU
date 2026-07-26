`timescale 1ns / 1ps

module tb_cpu;
    logic clk, reset;
    logic [3:0] cpu_out;

    cpu uut (.clk(clk), .reset(reset), .cpu_out(cpu_out));

    // Генератор часов
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Запуск компьютера
    initial begin
        $monitor("Time: %0t | PC (Clock Cycle) | CPU_OUT (Accumulator): %d", $time, cpu_out);

        // Включаем компьютер, зажимаем Reset на один такт
        reset = 1;
        #10;

        // Отпускаем Reset, процессор начинает сам читать программу!
        reset = 0;

        // Ждем 70 наносекунд (пока процессор выполнит все 6 строк кода)
        #70;

        $finish;
    end
endmodule
