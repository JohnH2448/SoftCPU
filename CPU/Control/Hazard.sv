import pack::*;

module Hazard (
    input logic clock,
    input logic reset,
    input logic decodeExecuteValid,
    input logic decodeExecuteIllegal,
    input logic memoryWritebackValid,
    input logic memoryWritebackIllegal,
    input logic branchValid,
    input logic stallControl,
    output control fetchDecodeControl,
    output control decodeExecuteControl,
    output control executeMemoryControl,
    output control memoryWritebackControl,
    output logic controlReset,
    // for load-use
    input logic [4:0] decodeExecuteRegister1,
    input logic [4:0] decodeExecuteRegister2,
    input logic [4:0] executeMemoryDestinationRegister,
    input logic executeMemoryValid,
    input writebackType_ executeMemoryWritebackType,
    input logic loadDataValid,
    input logic executeMemoryIllegal,
    output logic [3:0] mcause,
    input logic ebreak,
    input logic ecall,
    input logic memoryReadEnable,
    input logic memoryWriteEnable,
    input logic mretSignal,
    input logic readAddress1,
    input logic readAddress2,
    input logic decodeCombIllegal,
    input logic fetchDecodeValid,
    input writebackType_ decodeExecuteWBType,
    input logic [4:0] decodeExecuteDestinationRegister
);
    // Trap Handler
    always_comb begin
        fetchDecodeControl = '0;
        decodeExecuteControl = '0;
        executeMemoryControl = '0;
        memoryWritebackControl = '0;
        controlReset = 1'b0;
        mcause = '0;
        if (!reset) begin
            if (memoryWritebackValid && memoryWritebackIllegal) begin
                // Misalignment from Memory Stage
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                memoryWritebackControl.flush = 1'b1;
                controlReset = 1'b1;
                if (memoryReadEnable) begin
                    mcause = 4'h4;
                end else if (memoryWriteEnable) begin
                    mcause = 4'h6;
                end
            end else if (executeMemoryValid && executeMemoryIllegal) begin
                // Branch Misalignment from Execute Stage
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                memoryWritebackControl.flush = 1'b1;
                controlReset = 1'b1;
                mcause = 4'h0;
            end else if (mretSignal) begin
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
            end else if (decodeExecuteValid && decodeExecuteIllegal) begin
                // Illegal Instruction from Decode Stage
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                controlReset = 1'b1;
                mcause = 4'h2;
            end else if (decodeExecuteValid && ecall) begin
                // ECALL
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                controlReset = 1'b1;
                mcause = 4'hB;
            end else if (decodeExecuteValid && ebreak) begin
                // EBREAK
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                controlReset = 1'b1;
                mcause = 4'h3;
            end else if (branchValid) begin
                // PC Redirect Flush
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
            end
            if (stallControl) begin
                fetchDecodeControl.stall = 1'b1;
                decodeExecuteControl.stall = 1'b1;
                executeMemoryControl.stall = 1'b1;
                memoryWritebackControl.stall = 1'b1;
            end else begin
                // Load-Use Hazard 2
                if ((decodeExecuteDestinationRegister != 5'd0) && (readAddress1 != 5'd0) && decodeExecuteValid && fetchDecodeValid && !decodeCombIllegal && (decodeExecuteDestinationRegister == readAddress1) && (decodeExecuteWBType == WB_MEM)) begin
                    fetchDecodeControl.stall = 1'b1;
                    decodeExecuteControl.flush = 1'b1;
                end
                if ((decodeExecuteDestinationRegister != 5'd0) && (readAddress2 != 5'd0) && decodeExecuteValid && fetchDecodeValid && !decodeCombIllegal && (decodeExecuteDestinationRegister == readAddress2) && (decodeExecuteWBType == WB_MEM)) begin
                    fetchDecodeControl.stall = 1'b1;
                    decodeExecuteControl.flush = 1'b1;
                end
            end
        end
    end
endmodule

// Trap Handler will redirect to 0 by default unless set