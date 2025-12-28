// import pack::*;
package pack;

  parameter logic [31:0] resetVector = 32'h00000000;
  parameter logic [31:0] trapVector = 32'h00000000;

  typedef enum logic [2:0] {
    BR_NONE = 3'd0,
    BR_EQ = 3'd1,
    BR_NE = 3'd2,
    BR_LT = 3'd3,
    BR_GE = 3'd4,
    BR_LTU = 3'd5,
    BR_GEU = 3'd6
  } branchType; // Parallel comparator setting. evaluates to 1

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
    OPCODE_SYSTEM = 7'b1110011  // I-type (CSR, ECALL, EBREAK) DO LATER
  } opcode;

  typedef enum logic [2:0] {
    WB_NONE = 3'b000,  // no writeback (or bubble/illegal)
    WB_ALU = 3'b001,  // write ALU result
    WB_MEM = 3'b010,  // write load data
    WB_PC4 = 3'b011   // write PC+4 (JAL/JALR)
  } writebackType;

  typedef enum logic [1:0] {
    JUMP_NONE = 2'b00,
    JUMP_JAL = 2'b01,
    JUMP_JALR = 2'b10
  } jumpType;
  
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
  } aluOperation;

  typedef enum logic [1:0] {
    ALU_RS1_RS2 = 2'b00, // normal R-type, branches
    ALU_RS1_IMM = 2'b01, // I-type, load/store, JALR
    ALU_PC_IMM = 2'b10, // AUIPC, JAL, branch target
    ALU_ZERO_IMM = 2'b11 // LUI
  } aluSource;

  typedef struct packed {
    logic [31:0] instruction;
    logic [31:0] programCounter;
    logic [31:0] programCounterPlus4;
    logic valid;
  } fetchDecodePayload;

  typedef struct packed {
    logic stall;
    logic flush;
  } control;

  typedef struct packed {
    logic [31:0] programCounter;
    logic [31:0] programCounterPlus4;
    logic [31:0] registerData1;
    logic [31:0] registerData2;
    logic [4:0] destinationRegister;
    logic [31:0] immediate;
    aluSource aluSource;
    logic memoryReadEnable;
    logic memoryWriteEnable;
    logic [1:0] memoryWidth;
    logic memorySigned;
    branchType branchType; 
    aluOperation aluOperation;
    jumpType jumpType;
    writebackType writebackType;
    logic illegal;
    logic valid;
  } decodeExecutePayload;

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
      writebackType writebackType;
      logic illegal;
      logic valid;
    } executeMemoryPayload;
    
    typedef struct packed {
      logic [31:0] programCounter;
      logic [4:0] destinationRegister;
      logic [31:0] data;
      logic writebackEnable;
      logic illegal;
      logic valid;
    } memoryWritebackPayload;
    
endpackage 
