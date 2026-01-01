import pack::*;

module Top (
    input logic clock,
    input logic reset,
    input logic interrupt,

    // debug outputs
    output logic [1023:0] dbg_registers,
    output logic dbg_IF_ID_Valid,
    output logic dbg_ID_EX_Valid,
    output logic dbg_EX_MEM_Valid,
    output logic dbg_MEM_WB_Valid,
    output logic [31:0] dbg_IF_ID_programCounter,
    output logic [31:0] dbg_IF_ID_instruction,
    output logic [31:0] dbg_ID_EX_programCounter,
    output logic [31:0] dbg_EX_MEM_programCounter,
    output logic [31:0] dbg_MEM_WB_programCounter,
    output logic dbg_trap,
    output logic [31:0] dbg_IMEM_data,
    output logic dbg_IMEM_valid,
    output logic [31:0] dbg_pc,
    output logic [31:0] dbg_wb_value,

    output logic forwardEnable1,
    output logic forwardEnable2,
    output logic [31:0] forwardData1,
    output logic [31:0] forwardData2
);

    // Debug Assignments
    logic [1023:0] debug_regs_flat;
    assign dbg_registers = debug_regs_flat;
    assign dbg_IF_ID_Valid = fetchDecodePayload.valid;
    assign dbg_ID_EX_Valid = decodeExecutePayload.valid;
    assign dbg_EX_MEM_Valid = executeMemoryPayload.valid;
    assign dbg_MEM_WB_Valid = memoryWritebackPayload.valid;
    assign dbg_IF_ID_programCounter = fetchDecodePayload.programCounter;
    assign dbg_ID_EX_programCounter = decodeExecutePayload.programCounter;
    assign dbg_EX_MEM_programCounter = executeMemoryPayload.programCounter;
    assign dbg_MEM_WB_programCounter = memoryWritebackPayload.programCounter;
    assign dbg_trap = controlReset; 
    assign dbg_IF_ID_instruction = fetchDecodePayload.instruction;
    assign dbg_IMEM_data = instructionData;
    assign dbg_IMEM_valid = instructionDataValid;  
    assign dbg_pc = instructionAddress;
    assign dbg_wb_value = destinationEnable ? memoryWritebackPayload.data : 32'd0;

    // IMEM
    logic instructionDataValid;
    logic [31:0] instructionData;

    // DMEM
    logic [31:0] loadData;
    logic loadDataValid;
    logic storeComplete;

    // Branch Predictor
    logic [31:0] branchPredictData;
    logic branchPredictValid;

    // Hazard Unit
    control fetchDecodeControl;
    control decodeExecuteControl;
    control executeMemoryControl;
    control memoryWritebackControl;
    logic controlReset;

    // Register File
    logic [31:0] readData1;
    logic [31:0] readData2;

    // Fetch Stage
    logic [31:0] instructionAddress;
    fetchDecodePayload_ fetchDecodePayload;

    // Decode Stage
    decodeExecutePayload_ decodeExecutePayload;
    logic [4:0] readAddress1;
    logic [4:0] readAddress2;

    // Execute Stage
    logic branchValid;
    logic [31:0] branchData;
    executeMemoryPayload_ executeMemoryPayload;

    // Memory Stage
    memoryWritebackPayload_ memoryWritebackPayload;
    logic [31:0] addressRegister;
    logic [31:0] storeData;
    logic [3:0] realStoreByteEnable;
    logic storeValid;
    logic stallControl;

    // Writeback Stage
    logic destinationEnable;
    logic [4:0] writeAddress;
    logic [31:0] writeData;

    // Forewarding Unit


    Forward forward (
        .decodeExecuteRegister1(decodeExecutePayload.readAddress1),
        .decodeExecuteRegister2(decodeExecutePayload.readAddress2),
        .executeMemoryDestinationRegister(executeMemoryPayload.destinationRegister),
        .executeMemoryData(executeMemoryPayload.result),
        .executeMemoryPC4(executeMemoryPayload.programCounterPlus4),
        .executeMemoryValid(executeMemoryPayload.valid),
        .executeMemoryWritebackType(executeMemoryPayload.writebackType),
        .memoryWritebackDestinationRegister(memoryWritebackPayload.destinationRegister),
        .memoryWritebackData(memoryWritebackPayload.data),
        .memoryWritebackValid(memoryWritebackPayload.valid),
        .memoryWritebackWritebackEnable(memoryWritebackPayload.writebackEnable),
        .forwardEnable1(forwardEnable1),
        .forwardEnable2(forwardEnable2),
        .forwardData1(forwardData1),
        .forwardData2(forwardData2)
    );

    BranchPredictor branchPredictor (
        .clock(clock),
        .reset(reset),
        .branchPredictData(branchPredictData),
        .branchPredictValid(branchPredictValid)
    );

    Hazard hazard (
        .clock(clock),
        .reset(reset),
        .decodeExecuteValid(decodeExecutePayload.valid),
        .decodeExecuteIllegal(decodeExecutePayload.illegal),
        .memoryWritebackValid(memoryWritebackPayload.valid),
        .memoryWritebackIllegal(memoryWritebackPayload.illegal),
        .branchValid(branchValid),
        .stallControl(stallControl),
        .fetchDecodeControl(fetchDecodeControl),
        .decodeExecuteControl(decodeExecuteControl),
        .executeMemoryControl(executeMemoryControl),
        .memoryWritebackControl(memoryWritebackControl),
        .controlReset(controlReset)
    );

    Fetch fetch (
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt),
        .instructionDataValid(instructionDataValid),
        .instructionData(instructionData),
        .branchValid(branchValid),
        .branchData(branchData),
        .fetchDecodeControl(fetchDecodeControl),
        .branchPredictData(branchPredictData),
        .branchPredictValid(branchPredictValid),
        .instructionAddress(instructionAddress),
        .fetchDecodePayload(fetchDecodePayload),
        .controlReset(controlReset)
    );

    Decode decode (
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt),
        .fetchDecodePayload(fetchDecodePayload),
        .decodeExecuteControl(decodeExecuteControl),
        .decodeExecutePayload(decodeExecutePayload),
        .readAddress1(readAddress1),
        .readAddress2(readAddress2),
        .readData1(readData1),
        .readData2(readData2)
    );

    RegisterFile registerFile (
        .clock(clock),
        .readAddress1(readAddress1),
        .readAddress2(readAddress2),
        .destinationEnable(destinationEnable),
        .writeAddress(writeAddress),
        .writeData(writeData),
        .readData1(readData1),
        .readData2(readData2),
        .debug_regs_flat(debug_regs_flat)
    );

    Execute execute (
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt),
        .decodeExecutePayload(decodeExecutePayload),
        .executeMemoryControl(executeMemoryControl),
        .executeMemoryPayload(executeMemoryPayload),
        .branchValid(branchValid),
        .branchData(branchData),
        .forwardEnable1(forwardEnable1),
        .forwardEnable2(forwardEnable2),
        .forwardData1(forwardData1),
        .forwardData2(forwardData2)
    );

    Memory memory (
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt),
        .executeMemoryPayload(executeMemoryPayload),
        .memoryWritebackControl(memoryWritebackControl),
        .loadData(loadData),
        .loadDataValid(loadDataValid),
        .storeValid(storeValid),
        .stallControl(stallControl),
        .storeComplete(storeComplete),
        .memoryWritebackPayload(memoryWritebackPayload),
        .addressRegister(addressRegister),
        .storeData(storeData),
        .realStoreByteEnable(realStoreByteEnable)
    );

    Writeback writeback (
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt),
        .memoryWritebackPayload(memoryWritebackPayload),
        .destinationEnable(destinationEnable),
        .writeAddress(writeAddress),
        .writeData(writeData)
    );

    Imem #(.DEPTH_WORDS(1024)) imem_inst (
        .clock   (clock),
        .reset   (reset),
        .address (instructionAddress),    // from Fetch
        .data    (instructionData),       // to Fetch
        .valid   (instructionDataValid)   // to Fetch
    );

    Dmem #(.DEPTH_WORDS(1024)) dmem_inst (
        .clock          (clock),
        .reset          (reset),
        .address        (addressRegister),       // from Memory
        .storeData      (storeData),             // from Memory
        .byteEnable     (realStoreByteEnable),   // from Memory
        .storeValid     (storeValid),            // from Memory
        .loadData       (loadData),              // to Memory
        .loadDataValid  (loadDataValid),         // to Memory
        .storeComplete  (storeComplete)          // to Memory
    );

endmodule
