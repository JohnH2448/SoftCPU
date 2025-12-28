import pack::*;

module Execute (
    input logic clock,
    input logic reset,
    input logic interrupt,
    input decodeExecutePayload decodeExecutePayload,
    input control executeMemoryControl,
    output executeMemoryPayload executeMemoryPayload,
    output logic branchValid,
    output logic [31:0] branchData
);

    logic [31:0] operand1;
    logic [31:0] operand2;
    logic [31:0] result;
    logic redirectAsserted = 1'd0; // IMEM Latency Optimization

    always_comb begin
        branchValid = '0;
        operand1 = 32'd0;
        operand2 = 32'd0;
        result = 32'd0;
        branchData = 32'd0;
        unique case (decodeExecutePayload.aluSource)
            default:;
            ALU_RS1_RS2: begin
                operand1 = decodeExecutePayload.registerData1;
                operand2 = decodeExecutePayload.registerData2;
            end
            ALU_RS1_IMM: begin
                operand1 = decodeExecutePayload.registerData1;
                operand2 = decodeExecutePayload.immediate;
            end
            ALU_PC_IMM: begin
                operand1 = decodeExecutePayload.programCounter;
                operand2 = decodeExecutePayload.immediate;
            end
            ALU_ZERO_IMM: begin
                operand1 = 32'd0;
                operand2 = decodeExecutePayload.immediate;
            end
        endcase
        unique case (decodeExecutePayload.aluOperation)
            default:;
            ALU_ADD: result = operand1 + operand2;
            ALU_SUB: result = operand1 - operand2;
            ALU_AND: result = operand1 & operand2;
            ALU_OR: result = operand1 | operand2;
            ALU_XOR: result = operand1 ^ operand2;
            ALU_SLL: result = operand1 << operand2[4:0];
            ALU_SRL: result = operand1 >> operand2[4:0];
            ALU_SRA: result = $signed(operand1) >>> operand2[4:0];
            ALU_SLT: result = ($signed(operand1) < $signed(operand2)) ? 32'd1 : 32'd0;
            ALU_SLTU: result = (operand1 < operand2) ? 32'd1 : 32'd0;
        endcase
        if (decodeExecutePayload.valid && !executeMemoryControl.flush) begin
            unique case (decodeExecutePayload.branchType)
                default:;
                BR_EQ: branchValid = (decodeExecutePayload.registerData1 == decodeExecutePayload.registerData2);
                BR_NE: branchValid = (decodeExecutePayload.registerData1 != decodeExecutePayload.registerData2);
                BR_LT: branchValid = ($signed(decodeExecutePayload.registerData1) < $signed(decodeExecutePayload.registerData2));
                BR_GE: branchValid = ($signed(decodeExecutePayload.registerData1) >= $signed(decodeExecutePayload.registerData2));
                BR_LTU: branchValid = (decodeExecutePayload.registerData1 < decodeExecutePayload.registerData2);
                BR_GEU: branchValid = (decodeExecutePayload.registerData1 >= decodeExecutePayload.registerData2);
            endcase
            unique case (decodeExecutePayload.jumpType)
                default:;
                JUMP_JAL: branchValid = 1'd1;
                JUMP_JALR: begin
                    branchValid = 1'd1;
                    branchData = {result[31:1], 1'b0};
                end
            endcase
        end else begin
            branchValid = 1'd0;
        end
        if (decodeExecutePayload.jumpType != JUMP_JALR) begin
            branchData = result;
        end
        if (redirectAsserted) begin
            branchValid = 1'd0;
        end
    end
    always_ff @(posedge clock) begin
        if (reset) begin // synth will reduce this, broken up for clarity
            redirectAsserted <= 1'd0;
        end else begin
            if (branchValid && executeMemoryControl.stall && !redirectAsserted) begin
                redirectAsserted <= 1'd1;
            end
            if (!executeMemoryControl.stall || executeMemoryControl.flush) begin
                redirectAsserted <= 1'd0;
            end
        end
        if (reset) begin
            executeMemoryPayload <= '0;
        end else if (executeMemoryControl.flush) begin
            executeMemoryPayload.valid <= 1'd0;
        end else if (!executeMemoryControl.stall) begin
            executeMemoryPayload.programCounter <= decodeExecutePayload.programCounter;
            executeMemoryPayload.programCounterPlus4 <= decodeExecutePayload.programCounterPlus4;
            executeMemoryPayload.destinationRegister <= decodeExecutePayload.destinationRegister;
            executeMemoryPayload.memoryReadEnable <= decodeExecutePayload.memoryReadEnable;
            executeMemoryPayload.memoryWriteEnable <= decodeExecutePayload.memoryWriteEnable;
            executeMemoryPayload.memoryWidth <= decodeExecutePayload.memoryWidth;
            executeMemoryPayload.memorySigned <= decodeExecutePayload.memorySigned;
            executeMemoryPayload.result <= result;
            executeMemoryPayload.storeData <= decodeExecutePayload.registerData2;
            executeMemoryPayload.writebackType <= decodeExecutePayload.writebackType;
            executeMemoryPayload.valid <= decodeExecutePayload.valid;
            executeMemoryPayload.illegal <= decodeExecutePayload.illegal;
        end
    end

endmodule