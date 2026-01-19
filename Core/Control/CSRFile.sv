import pack::*;

module CSRFile (
    input logic clock,
    input logic reset,
    input logic interrupt,
    input destinationCSR_ destinationCSR,
    input destinationCSR_ readCSR,
    input logic [31:0] csrWriteData,
    output logic [31:0] csrReadData,
    input logic csrDestinationEnable,
    input logic dualValid,
    output logic [31:0] trapVector,
    input logic controlReset,
    input logic [3:0] mcause,
    input logic [31:0] decodeExecutePC,
    input logic [31:0] executeMemoryPC,
    input logic [31:0] memoryWritebackPC
);
    logic [31:0] csrs [0:15];

    always_comb begin
        csrReadData = csrs[readCSR];
        trapVector = csrs[MTVEC];
    end

    integer i;
    always_ff @(posedge clock) begin
        if (reset) begin
            for (i = 0; i < 16; i++) begin
                csrs[i] <= 32'b0;
            end
            csrs[MISA] <= 32'h40000100;
            csrs[MSTATUS] <= 32'h00001800;
        end else begin
            if (csrDestinationEnable) begin
                csrs[destinationCSR] <= csrWriteData;
            end
            if (!(csrDestinationEnable && (destinationCSR == MCYCLE))) begin
                csrs[MCYCLE] <= csrs[MCYCLE] + 32'd1;
            end
            if (dualValid && !(csrDestinationEnable && (destinationCSR == MINSTRET))) begin
                csrs[MINSTRET] <= csrs[MINSTRET] + 32'd1;
            end
            if (controlReset) begin
                csrs[MTVAL] <= 32'd0;
                csrs[MCAUSE] <= {28'd0, mcause};
                unique case (mcause)
                    4'h6: csrs[MEPC] <= memoryWritebackPC;
                    4'h4: csrs[MEPC] <= memoryWritebackPC;
                    4'h0: csrs[MEPC] <= executeMemoryPC;
                    4'h2: csrs[MEPC] <= decodeExecutePC;
                    4'hB: csrs[MEPC] <= decodeExecutePC;
                    4'h3: csrs[MEPC] <= decodeExecutePC;
                endcase
                $strobe("\n\nException: MEPC=%08h MCAUSE=%08h MTVEC=%08h", csrs[MEPC], csrs[MCAUSE], csrs[MTVEC],"\n");
            end
        end
    end
endmodule
