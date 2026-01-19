import pack::*;

module Imem (
    input logic clock,
    input logic reset,
    input logic [31:0] address,
    output logic [31:0] data,
    output logic valid
);

    logic [31:0] mem [0:16383];

    initial begin
        integer i;
        for (i = 0; i < 16384; i = i + 1) begin
            mem[i] = 32'h00000013;
        end
        $display("IMEM: loading imem.hex");
        $readmemh("imem.hex", mem);
    end

    always_comb begin
        data = 32'h00000013; // default NOP
        valid = 1'b0;
        if (!reset) begin
            if (address[1:0] == 2'b00) begin
                data = mem[address[15:2]];
                valid = 1'b1;
            end
        end
    end

endmodule
