import pack::*;

module Fetch (
    input logic clock,
    input logic reset,
    input logic interrupt,
    input logic instructionDataValid,
    input logic [31:0] instructionData,
    input logic branchValid,
    input logic [31:0] branchData,
    input control fetchDecodeControl,
    input logic [31:0] branchPredictData,
    input logic branchPredictValid,
    input logic controlReset,
    input logic [31:0] trapVector,
    output logic [31:0] instructionAddress,
    output fetchDecodePayload_ fetchDecodePayload,
    input logic mretSignal
);

    logic [31:0] programCounter;
    assign instructionAddress = programCounter;

    always_ff @(posedge clock) begin
        if (reset) begin
            programCounter <= resetVector;
        end else if (controlReset) begin
            programCounter <= trapVector;
        end else if (mretSignal) begin
            programCounter <= branchData;
        end else begin
            if (branchValid) begin
                programCounter <= branchData;
            end else if (!fetchDecodeControl.stall) begin
                if (branchPredictValid) begin
                    programCounter <= branchPredictData;
                end else if (instructionDataValid) begin
                    programCounter <= programCounter + 32'd4;
                end
            end 
        end
    end
    always_ff @(posedge clock) begin
        if (!reset && !controlReset) begin
            if (fetchDecodeControl.flush) begin
                fetchDecodePayload.valid <= 1'b0;
            end else if (!fetchDecodeControl.stall && instructionDataValid) begin
                fetchDecodePayload.valid <= 1'b1;
                fetchDecodePayload.instruction <= instructionData;
                fetchDecodePayload.programCounter <= programCounter;
                fetchDecodePayload.programCounterPlus4 <= programCounter + 32'd4;
            end else if (!fetchDecodeControl.stall && !instructionDataValid) begin
                fetchDecodePayload.valid <= 1'b0;
            end
        end else begin
            fetchDecodePayload <= '0;
        end
    end

endmodule

// CONTROL FLUSH OVERWRITES BOUNDRY REG UNIVERSALLY
// COMBINATIONAL INVALIDS DO NOT AND ARE SUPERCEEDED BY STALL

// ALL INVALID INSTRUCTIONS FLOW THROUGH THE PIPELINE AND FALL OFF AT WB

// STALLS MUST BE GLOBAL AND NOT JUST BACKSTALL

// ADD INTERUPS. FINISH MEM AND WB DISCARD ELSE
