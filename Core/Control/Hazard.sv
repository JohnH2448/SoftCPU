import pack::*;

module Hazard (
    input logic clock,
    input logic reset,
    input logic decodeExecuteValid,
    input logic memoryWritebackValid,
    input logic branchValid,
    input logic stallControl,
    output control fetchDecodeControl,
    output control decodeExecuteControl,
    output control executeMemoryControl,
    output control memoryWritebackControl,
    output logic controlReset,
    // for load-use
    output logic [3:0] mcause,
    output logic [31:0] mtval,
    input logic mretSignal,
    input logic [4:0] readAddress1,
    input logic [4:0] readAddress2,
    input logic fetchDecodeValid,
    input writebackType_ decodeExecuteWBType,
    input logic [4:0] decodeExecuteDestinationRegister,
    input trapPayload_ trapData
);
    // Trap Handler
    always_comb begin
        fetchDecodeControl = '0;
        decodeExecuteControl = '0;
        executeMemoryControl = '0;
        memoryWritebackControl = '0;
        controlReset = 1'b0;
        mcause = '0;
        mtval = 32'd0;
        if (!reset) begin
            if ((trapData.trapType != NONE) && memoryWritebackValid) begin
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                memoryWritebackControl.flush = 1'b1;
                controlReset = 1'b1;
                mtval = trapData.faultingAddress;
                case (trapData.trapType)
                    ILLEGAL: begin
                        mcause = 4'h2;
                    end
                    MIS_STORE: begin
                        mcause = 4'h6;
                    end
                    MIS_LOAD: begin
                        mcause = 4'h4;
                    end
                    MIS_INST: begin
                        mcause = 4'h0;
                    end
                    ECALL: begin
                        mcause = 4'hB;
                    end
                    EBREAK: begin
                        mcause = 4'h3;
                    end
                    ACCESS_STORE: begin
                        mcause = 4'h7;
                    end
                    ACCESS_LOAD: begin
                        mcause = 4'h5;
                    end
                    ACCESS_INST: begin
                        mcause = 4'h1;
                    end
                    default: ;
                endcase
            end else if (mretSignal || branchValid) begin
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
            end
            if (stallControl) begin
                fetchDecodeControl.stall = 1'b1;
                decodeExecuteControl.stall = 1'b1;
                executeMemoryControl.stall = 1'b1;
                memoryWritebackControl.stall = 1'b1;
            end else begin
                // Load-Use Hazard
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

// need to alter mstatus


