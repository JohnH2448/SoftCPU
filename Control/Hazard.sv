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
    output logic controlReset
);
    // Trap Handler
    always_comb begin
        fetchDecodeControl = '0;
        decodeExecuteControl = '0;
        executeMemoryControl = '0;
        memoryWritebackControl = '0;
        controlReset = 1'b0;
        if (!reset) begin
            if (decodeExecuteValid && decodeExecuteIllegal) begin
                // Trap from Decode stage
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                controlReset = 1'b1;
            end else if (memoryWritebackValid && memoryWritebackIllegal) begin
                // Trap from Memory stage
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                memoryWritebackControl.flush = 1'b1;
                controlReset = 1'b1;
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
            end
        end
    end
    // almost done but add RAW

endmodule

