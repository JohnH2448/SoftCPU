import pack::*;

module Decode (
    input logic clock,
    input logic reset,
    input logic interrupt,
    input fetchDecodePayload_ fetchDecodePayload,
    input control decodeExecuteControl,
    output decodeExecutePayload_ decodeExecutePayload,
    output logic [4:0] readAddress1,
    output logic [4:0] readAddress2,
    input [31:0] readData1,
    input [31:0] readData2
);

    opcode_ opcode;
    decodeExecutePayload_ decodeExecuteCandidate;
    assign opcode = opcode_'(fetchDecodePayload.instruction[6:0]);

    always_comb begin
        decodeExecuteCandidate = '0;
        readAddress1 = 5'd0;
        readAddress2 = 5'd0;
        decodeExecuteCandidate.registerData1 = readData1;
        decodeExecuteCandidate.registerData2 = readData2;
        decodeExecuteCandidate.programCounter = fetchDecodePayload.programCounter;
        decodeExecuteCandidate.programCounterPlus4 = fetchDecodePayload.programCounterPlus4;
        unique case (opcode)
            OPCODE_ALU_REG: begin 
                decodeExecuteCandidate.destinationRegister = fetchDecodePayload.instruction[11:7];
                readAddress1 = fetchDecodePayload.instruction[19:15];
                readAddress2 = fetchDecodePayload.instruction[24:20];
                decodeExecuteCandidate.aluSource = ALU_RS1_RS2;
                decodeExecuteCandidate.writebackType = WB_ALU;
                unique case ({fetchDecodePayload.instruction[31:25], fetchDecodePayload.instruction[14:12]})
                    10'b0000000000: decodeExecuteCandidate.aluOperation = ALU_ADD;
                    10'b0100000000: decodeExecuteCandidate.aluOperation = ALU_SUB;
                    10'b0000000111: decodeExecuteCandidate.aluOperation = ALU_AND;
                    10'b0000000110: decodeExecuteCandidate.aluOperation = ALU_OR;
                    10'b0000000100: decodeExecuteCandidate.aluOperation = ALU_XOR;
                    10'b0000000001: decodeExecuteCandidate.aluOperation = ALU_SLL;
                    10'b0000000101: decodeExecuteCandidate.aluOperation = ALU_SRL;
                    10'b0100000101: decodeExecuteCandidate.aluOperation = ALU_SRA;
                    10'b0000000010: decodeExecuteCandidate.aluOperation = ALU_SLT;
                    10'b0000000011: decodeExecuteCandidate.aluOperation = ALU_SLTU;
                    default: decodeExecuteCandidate.illegal = 1'b1;
                endcase
            end // R-type   (reg–reg ALU)
            OPCODE_MISC_MEM: begin 
                // NOP for in order pipeliens
            end // I-type   (FENCE / FENCE.I)
            OPCODE_ALU_IMM: begin 
                decodeExecuteCandidate.destinationRegister = fetchDecodePayload.instruction[11:7];
                readAddress1 = fetchDecodePayload.instruction[19:15];
                decodeExecuteCandidate.aluSource = ALU_RS1_IMM;
                decodeExecuteCandidate.writebackType = WB_ALU;
                decodeExecuteCandidate.immediate = {{20{fetchDecodePayload.instruction[31]}}, fetchDecodePayload.instruction[31:20]};
                unique case (fetchDecodePayload.instruction[14:12]) // funct3
                    3'b000: decodeExecuteCandidate.aluOperation = ALU_ADD;   // ADDI
                    3'b010: decodeExecuteCandidate.aluOperation = ALU_SLT;   // SLTI
                    3'b011: decodeExecuteCandidate.aluOperation = ALU_SLTU;  // SLTIU
                    3'b100: decodeExecuteCandidate.aluOperation = ALU_XOR;   // XORI
                    3'b110: decodeExecuteCandidate.aluOperation = ALU_OR;    // ORI
                    3'b111: decodeExecuteCandidate.aluOperation = ALU_AND;   // ANDI
                    3'b001: begin // SLLI
                        if (fetchDecodePayload.instruction[31:25] == 7'b0000000)
                            decodeExecuteCandidate.aluOperation = ALU_SLL;
                        else
                            decodeExecuteCandidate.illegal = 1'b1;
                    end
                    3'b101: begin // SRLI SRAI
                        if (fetchDecodePayload.instruction[31:25] == 7'b0000000)
                            decodeExecuteCandidate.aluOperation = ALU_SRL;
                        else if (fetchDecodePayload.instruction[31:25] == 7'b0100000)
                            decodeExecuteCandidate.aluOperation = ALU_SRA;
                        else
                            decodeExecuteCandidate.illegal = 1'b1;
                    end
                    default: decodeExecuteCandidate.illegal = 1'b1;
                endcase
            end // I-type   (reg–imm ALU)
            OPCODE_LOAD: begin 
                decodeExecuteCandidate.destinationRegister = fetchDecodePayload.instruction[11:7];
                decodeExecuteCandidate.aluSource = ALU_RS1_IMM;
                decodeExecuteCandidate.writebackType = WB_MEM;
                readAddress1 = fetchDecodePayload.instruction[19:15];
                decodeExecuteCandidate.immediate = {{20{fetchDecodePayload.instruction[31]}}, fetchDecodePayload.instruction[31:20]};
                decodeExecuteCandidate.memoryReadEnable = 1'b1;
                unique case (fetchDecodePayload.instruction[14:12]) // funct3
                    3'b000: begin
                        decodeExecuteCandidate.memoryWidth = 2'b00;
                        decodeExecuteCandidate.memorySigned = 1'b1;
                    end
                    3'b001: begin
                        decodeExecuteCandidate.memoryWidth = 2'b01;
                        decodeExecuteCandidate.memorySigned = 1'b1;
                    end
                    3'b010: begin
                        decodeExecuteCandidate.memoryWidth = 2'b11;
                        decodeExecuteCandidate.memorySigned = 1'b1;
                    end
                    3'b100: begin
                        decodeExecuteCandidate.memoryWidth = 2'b00;
                        decodeExecuteCandidate.memorySigned = 1'b0;
                    end
                    3'b101: begin
                        decodeExecuteCandidate.memoryWidth = 2'b01;
                        decodeExecuteCandidate.memorySigned = 1'b0;
                    end
                    default: decodeExecuteCandidate.illegal = 1'b1;
                endcase
            end // I-type   (loads)
            OPCODE_STORE: begin 
                decodeExecuteCandidate.aluSource = ALU_RS1_IMM;
                readAddress1 = fetchDecodePayload.instruction[19:15];
                readAddress2 = fetchDecodePayload.instruction[24:20];
                decodeExecuteCandidate.immediate = {{20{fetchDecodePayload.instruction[31]}}, fetchDecodePayload.instruction[31:25], fetchDecodePayload.instruction[11:7]};
                decodeExecuteCandidate.memoryWriteEnable = 1'b1;
                unique case (fetchDecodePayload.instruction[14:12]) // funct3
                    3'b000: decodeExecuteCandidate.memoryWidth = 2'b00; // SB
                    3'b001: decodeExecuteCandidate.memoryWidth = 2'b01; // SH
                    3'b010: decodeExecuteCandidate.memoryWidth = 2'b11; // SW
                    default: decodeExecuteCandidate.illegal = 1'b1;
                endcase
            end // S-type   (stores)
            OPCODE_BRANCH: begin 
                readAddress1 = fetchDecodePayload.instruction[19:15];
                readAddress2 = fetchDecodePayload.instruction[24:20];
                decodeExecuteCandidate.aluSource = ALU_PC_IMM;
                decodeExecuteCandidate.immediate = {{19{fetchDecodePayload.instruction[31]}},fetchDecodePayload.instruction[31],fetchDecodePayload.instruction[7],fetchDecodePayload.instruction[30:25],fetchDecodePayload.instruction[11:8],1'b0};
                unique case (fetchDecodePayload.instruction[14:12]) // funct3
                    3'b000: decodeExecuteCandidate.branchType = BR_EQ;   // BEQ
                    3'b001: decodeExecuteCandidate.branchType = BR_NE;   // BNE
                    3'b100: decodeExecuteCandidate.branchType = BR_LT;   // BLT
                    3'b101: decodeExecuteCandidate.branchType = BR_GE;   // BGE
                    3'b110: decodeExecuteCandidate.branchType = BR_LTU;  // BLTU
                    3'b111: decodeExecuteCandidate.branchType = BR_GEU;  // BGEU
                    default: decodeExecuteCandidate.illegal = 1'b1;
                endcase
            end // B-type   (conditional branches)
            OPCODE_LUI: begin 
                decodeExecuteCandidate.destinationRegister = fetchDecodePayload.instruction[11:7];
                decodeExecuteCandidate.aluSource = ALU_ZERO_IMM;
                decodeExecuteCandidate.writebackType = WB_ALU;
                decodeExecuteCandidate.immediate = {fetchDecodePayload.instruction[31:12], 12'd0};
            end // U-type   (load upper immediate)
            OPCODE_AUIPC: begin 
                decodeExecuteCandidate.destinationRegister = fetchDecodePayload.instruction[11:7];
                decodeExecuteCandidate.aluSource = ALU_PC_IMM;
                decodeExecuteCandidate.writebackType = WB_ALU;
                decodeExecuteCandidate.immediate = {fetchDecodePayload.instruction[31:12], 12'd0};
            end // U-type   (add upper immediate to PC)
            OPCODE_JAL: begin 
                decodeExecuteCandidate.destinationRegister = fetchDecodePayload.instruction[11:7];
                decodeExecuteCandidate.aluSource = ALU_PC_IMM;
                decodeExecuteCandidate.writebackType = WB_PC4;
                decodeExecuteCandidate.jumpType = JUMP_JAL;
                decodeExecuteCandidate.immediate = {{11{fetchDecodePayload.instruction[31]}},fetchDecodePayload.instruction[31],fetchDecodePayload.instruction[19:12],fetchDecodePayload.instruction[20],fetchDecodePayload.instruction[30:21],1'b0};
            end // J-type   (jump and link)
            OPCODE_JALR: begin 
                readAddress1 = fetchDecodePayload.instruction[19:15];
                decodeExecuteCandidate.destinationRegister = fetchDecodePayload.instruction[11:7];
                decodeExecuteCandidate.aluSource = ALU_RS1_IMM;
                decodeExecuteCandidate.writebackType = WB_PC4;
                decodeExecuteCandidate.jumpType = JUMP_JALR;
                decodeExecuteCandidate.immediate = {{20{fetchDecodePayload.instruction[31]}},fetchDecodePayload.instruction[31:20]};
                if (fetchDecodePayload.instruction[14:12] != 3'b000)
                    decodeExecuteCandidate.illegal = 1'b1;
            end // I-type   (jump and link register)
            OPCODE_SYSTEM: begin 
                decodeExecuteCandidate.illegal = 1'b1;
            end // I-type   (CSR / ECALL / EBREAK)
            default: begin
                decodeExecuteCandidate.illegal = 1'b1;
            end
        endcase
        decodeExecuteCandidate.readAddress1 = readAddress1;
        decodeExecuteCandidate.readAddress2 = readAddress2;
    end
    always_ff @(posedge clock) begin
        if (reset) begin
            decodeExecutePayload <= '0;
        end else if (decodeExecuteControl.flush) begin
            decodeExecutePayload.valid <= 1'b0;
        end else if (!decodeExecuteControl.stall) begin
            if (fetchDecodePayload.instruction == '0) begin
                decodeExecutePayload.valid <= 1'b0;
                decodeExecutePayload <= '0;
            end else begin
                decodeExecutePayload <= decodeExecuteCandidate;
                decodeExecutePayload.valid <= fetchDecodePayload.valid;
            end
        end
    end
endmodule
