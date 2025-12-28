import pack::*;

module Top (
    input logic clock,
    input logic reset
);

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

    // Branch Predictor
    logic [31:0] branchPredictData;
    logic branchPredictValid;

    // Register File
    logic [31:0] readData1;
    logic [31:0] readData2;

    // Fetch Stage
    logic [31:0] instructionAddress;
    fetchDecodePayload fetchDecodePayload;
    
    // Decode Stage
    decodeExecutePayload decodeExecutePayload;
    logic [4:0] readAddress1;
    logic [4:0] readAddress2;

    // Execute Stage
    logic branchValid;
    logic [31:0] branchData;
    executeMemoryPayload executeMemoryPayload;

    // Memory Stage
    memoryWritebackPayload memoryWritebackPayload;
    logic [31:0] addressRegister;
    logic [31:0] storeData;
    logic [3:0] realStoreByteEnable;
    logic storeValid;
    logic stallControl;

    // Writeback Stage
    logic destinationEnable;
    logic [4:0] writeAddress;
    logic [31:0] writeData;

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
        .readData2(readData2)
    );

    Execute execute (
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt),
        .decodeExecutePayload(decodeExecutePayload),
        .executeMemoryControl(executeMemoryControl),
        .executeMemoryPayload(executeMemoryPayload),
        .branchValid(branchValid),
        .branchData(branchData)
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