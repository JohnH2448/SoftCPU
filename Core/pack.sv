// import pack::*;
package pack;

  parameter logic [31:0] resetVector = 32'h80000000;

  typedef enum logic [2:0] {
    BR_NONE = 3'd0,
    BR_EQ = 3'd1,
    BR_NE = 3'd2,
    BR_LT = 3'd3,
    BR_GE = 3'd4,
    BR_LTU = 3'd5,
    BR_GEU = 3'd6
  } branchType_; // Parallel comparator setting. evaluates to 1

  typedef enum logic [6:0] {
    OPCODE_ALU_REG = 7'b0110011, // R-type (reg-reg)
    OPCODE_MISC_MEM = 7'b0001111, // NOP (fence)
    OPCODE_ALU_IMM = 7'b0010011, // I-type (reg-imm)
    OPCODE_LOAD = 7'b0000011, // I-type
    OPCODE_STORE = 7'b0100011, // S-type
    OPCODE_BRANCH = 7'b1100011, // B-type
    OPCODE_LUI = 7'b0110111, // U-type
    OPCODE_AUIPC = 7'b0010111, // U-type
    OPCODE_JAL = 7'b1101111, // J-type
    OPCODE_JALR = 7'b1100111, // I-type
    OPCODE_SYSTEM = 7'b1110011 // I-type (CSR, ECALL, EBREAK) DO LATER
  } opcode_;

  typedef enum logic [2:0] {
    WB_NONE = 3'b000,  // no writeback (or bubble/illegal)
    WB_ALU = 3'b001,  // write ALU result
    WB_MEM = 3'b010,  // write load data
    WB_PC4 = 3'b011   // write PC+4 (JAL/JALR)
  } writebackType_;

  typedef enum logic [1:0] {
    JUMP_NONE = 2'b00,
    JUMP_JAL = 2'b01,
    JUMP_JALR = 2'b10
  } jumpType_;

  typedef enum logic [3:0] {
    ALU_ADD = 4'd0,
    ALU_SUB = 4'd1,
    ALU_AND = 4'd2,
    ALU_OR = 4'd3,
    ALU_XOR = 4'd4,
    ALU_SLL = 4'd5,
    ALU_SRL = 4'd6,
    ALU_SRA = 4'd7,
    ALU_SLT = 4'd8,
    ALU_SLTU = 4'd9
  } aluOperation_;

  typedef enum logic [1:0] {
    ALU_RS1_RS2 = 2'b00, // normal R-type, branches
    ALU_RS1_IMM = 2'b01, // I-type, load/store, JALR
    ALU_PC_IMM = 2'b10, // AUIPC, JAL, branch target
    ALU_ZERO_IMM = 2'b11 // LUI
  } aluSource_;

  typedef struct packed {
    logic [31:0] instruction;
    logic [31:0] programCounter;
    logic [31:0] programCounterPlus4;
    logic valid;
  } fetchDecodePayload_;

  typedef struct packed {
    logic stall;
    logic flush;
  } control;

  typedef enum logic [3:0] {
    MSTATUS = 4'b0000, // MRET sets this, Trap sets this, 
    MEPC = 4'b0001, // DONE
    MCAUSE = 4'b0010, // DONE
    MTVAL = 4'b0011, // DONE
    MIE = 4'b0100, // DONE
    MTVEC = 4'b0110, // DONE
    MSCRATCH = 4'b0111, // DONE
    MISA = 4'b1000, // DONE
    MVENDORID = 4'b1001, // DONE
    MARCHID = 4'b1010, // DONE
    MIMPID = 4'b1011, // DONE
    MHARTID = 4'b1100, // DONE
    MIP = 4'b1101, // DONE
    MCYCLE = 4'b1110, // DONE
    MINSTRET = 4'b1111 // DONE
  } destinationCSR_;

  typedef enum logic [1:0] {
    CSR_NONE = 2'b00,
    CSR_RW = 2'b01,
    CSR_RS = 2'b10,
    CSR_RC = 2'b11
  } CSROp_;

  typedef struct packed {
    CSROp_ CSROp; // default none
    destinationCSR_ destinationCSR;
    logic CSRSrc; // 0 = immediate, 1 = register
    logic [4:0] CSRImmediate; // zero extend in ex
    logic CSRWriteIntent; // indicates if instruction intends to write CSR
  } decodeExecuteCSR_;

  typedef struct packed {
    logic [31:0] programCounter;
    logic [31:0] programCounterPlus4;
    logic [31:0] registerData1;
    logic [31:0] registerData2;
    logic [4:0] readAddress1;
    logic [4:0] readAddress2;
    logic [4:0] destinationRegister;
    logic [31:0] immediate;
    aluSource_ aluSource;
    logic memoryReadEnable;
    logic memoryWriteEnable;
    logic [1:0] memoryWidth;
    logic memorySigned;
    branchType_ branchType; 
    aluOperation_ aluOperation;
    jumpType_ jumpType;
    writebackType_ writebackType;
    decodeExecuteCSR_ decodeExecuteCSR;
    logic ecall;
    logic ebreak;
    logic isMRET;
    logic illegal;
    logic valid;
  } decodeExecutePayload_;

  typedef struct packed {
    logic [31:0] programCounter;
    logic [31:0] programCounterPlus4;
    logic [4:0] destinationRegister;
    logic memoryReadEnable;
    logic memoryWriteEnable;
    logic [1:0] memoryWidth;
    logic memorySigned;
    logic [31:0] result;
    logic [31:0] storeData;
    writebackType_ writebackType;
    logic illegal;
    logic valid;
    // csr
    destinationCSR_ destinationCSR;
    logic [31:0] oldCSRValue;
    CSROp_ CSROp;
    logic CSRWriteIntent;
  } executeMemoryPayload_;

  typedef struct packed {
    logic [31:0] programCounter;
    logic [4:0] destinationRegister;
    logic [31:0] data;
    logic memoryReadEnable;
    logic memoryWriteEnable;
    logic writebackEnable;
    logic illegal;
    logic valid;
    // csr
    destinationCSR_ destinationCSR;
    logic [31:0] oldCSRValue;
    CSROp_ CSROp;
    logic CSRWriteIntent;
  } memoryWritebackPayload_;

endpackage
