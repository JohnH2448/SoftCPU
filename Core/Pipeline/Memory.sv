import StaticPack::*;
import ConfigPack::*;

module Memory (
    input logic clock,
    input logic reset,
    input logic interrupt,
    input executeMemoryPayload_ executeMemoryPayload,
    input control memoryWritebackControl,
    input logic [31:0] loadData,
    input logic loadDataValid,
    output logic storeValid, // clocked for mem
    output logic stallControl,
    input logic storeComplete,
    output memoryWritebackPayload_ memoryWritebackPayload,
    output logic [31:0] addressRegister,
    output logic [31:0] storeData,
    output logic [3:0] realStoreByteEnable
);

    logic illegal;
    logic accessFault;
    logic storeConfirm;
    logic storeReq;
    logic [4:0] shamt;
    logic [3:0] storeByteEnable;
    logic [31:0] limit;

    assign shamt = {addressRegister[1:0], 3'b000};
    assign storeData = executeMemoryPayload.storeData << shamt;

    assign storeReq = storeConfirm && !storeValid;
    assign stallControl = (executeMemoryPayload.valid && executeMemoryPayload.memoryReadEnable && !illegal && !accessFault && !memoryWritebackControl.flush) ? !loadDataValid : (storeReq || (storeValid && !storeComplete));
    assign addressRegister = executeMemoryPayload.result;
    assign realStoreByteEnable = storeByteEnable << addressRegister[1:0];

    always_comb begin
        accessFault = 1'b0;
        illegal = 1'b0;
        storeConfirm = 1'b0;
        storeByteEnable = 4'b0000;
        unique case (executeMemoryPayload.memoryWidth) // fake hardware
            2'b00: limit = memoryBytes - 32'd1;
            2'b01: limit = memoryBytes - 32'd2;
            2'b11: limit = memoryBytes - 32'd4;
            default: limit = 32'd0; 
        endcase
        if (executeMemoryPayload.valid && !memoryWritebackControl.flush && (executeMemoryPayload.trapPayload.trapType == NONE)) begin
            if (executeMemoryPayload.memoryReadEnable) begin
                unique case (executeMemoryPayload.memoryWidth)
                    2'b00: begin 
                        if (addressRegister > limit) begin
                            accessFault = 1'b1;
                        end
                    end
                    2'b01: begin 
                        if (addressRegister > limit) begin
                            accessFault = 1'b1;
                        end else if (addressRegister[0] != 1'b0) begin
                            illegal = 1'b1;
                        end
                    end
                    2'b11: begin 
                        if (addressRegister > limit) begin
                            accessFault = 1'b1;
                        end else if (addressRegister[1:0] != 2'b00) begin
                            illegal = 1'b1;
                        end
                    end
                    default: begin
                        if (addressRegister > limit) begin
                            accessFault = 1'b1;
                        end else begin
                            illegal = 1'b1;
                        end
                    end
                endcase
            end
            if (executeMemoryPayload.memoryWriteEnable) begin
                unique case (executeMemoryPayload.memoryWidth)
                    2'b00: begin
                        if (addressRegister > limit) begin
                            accessFault = 1'b1;
                        end else begin 
                            storeConfirm = 1'b1; 
                            storeByteEnable = 4'b0001;
                        end
                    end
                    2'b01: begin 
                        if (addressRegister > limit) begin
                            accessFault = 1'b1;
                        end else if (addressRegister[0] != 1'b0) begin
                            illegal = 1'b1;
                        end else begin
                            storeConfirm = 1'b1;
                            storeByteEnable = 4'b0011;
                        end
                    end
                    2'b11: begin 
                        if (addressRegister > limit) begin
                            accessFault = 1'b1;
                        end else if (addressRegister[1:0] != 2'b00) begin 
                            illegal = 1'b1;
                        end else begin
                            storeConfirm = 1'b1;
                            storeByteEnable = 4'b1111;
                        end
                    end
                    default: begin
                        if (addressRegister > limit) begin
                            accessFault = 1'b1;
                        end else begin
                            illegal = 1'b1;
                        end
                    end
                endcase
            end
        end
    end

    always_ff @(posedge clock) begin
        if (reset) begin
            storeValid <= 1'b0;
        end else if (!storeValid && !illegal && !accessFault && !memoryWritebackControl.flush) begin
            storeValid <= storeReq;
        end else if (storeComplete) begin
            storeValid <= 1'b0;
        end
    end

    always_ff @(posedge clock) begin
        if (reset) begin
            memoryWritebackPayload <= '0;
        end else if (memoryWritebackControl.flush) begin
             memoryWritebackPayload.valid <= 1'b0;
        end else if (!memoryWritebackControl.stall) begin
            unique case (executeMemoryPayload.writebackType)
                WB_NONE: memoryWritebackPayload.writebackEnable <= 1'b0;
                WB_ALU: begin
                    memoryWritebackPayload.data <= executeMemoryPayload.result;
                    memoryWritebackPayload.writebackEnable <= 1'b1;
                end
                WB_MEM: begin
                    if (executeMemoryPayload.memoryReadEnable && loadDataValid) begin
                        logic [31:0] word;
                        logic [7:0]  b;
                        logic [15:0] h;
                        word = loadData;
                        unique case (executeMemoryPayload.memoryWidth)
                            2'b00: begin 
                                b = word >> {addressRegister[1:0], 3'b000};
                                memoryWritebackPayload.data <= executeMemoryPayload.memorySigned
                                    ? {{24{b[7]}}, b}
                                    : {24'b0, b};
                            end
                            2'b01: begin 
                                h = word >> {addressRegister[1], 4'b0000}; 
                                memoryWritebackPayload.data <= executeMemoryPayload.memorySigned
                                    ? {{16{h[15]}}, h}
                                    : {16'b0, h};
                            end
                            2'b11: begin 
                                memoryWritebackPayload.data <= word;
                            end
                            default: ;
                        endcase
                    end
                    memoryWritebackPayload.writebackEnable <= executeMemoryPayload.memoryReadEnable && loadDataValid;
                end
                WB_PC4: begin 
                    memoryWritebackPayload.data <= executeMemoryPayload.programCounterPlus4;
                    memoryWritebackPayload.writebackEnable <= 1'b1;
                end
                default: memoryWritebackPayload.writebackEnable <= 1'b0;
            endcase
            memoryWritebackPayload.valid <= executeMemoryPayload.valid;
            memoryWritebackPayload.programCounter <= executeMemoryPayload.programCounter;
            memoryWritebackPayload.destinationRegister <= executeMemoryPayload.destinationRegister;
            memoryWritebackPayload.destinationCSR <= executeMemoryPayload.destinationCSR;
            memoryWritebackPayload.oldCSRValue <= executeMemoryPayload.oldCSRValue;
            memoryWritebackPayload.CSROp <= executeMemoryPayload.CSROp;
            memoryWritebackPayload.CSRWriteIntent <= executeMemoryPayload.CSRWriteIntent;
            if (executeMemoryPayload.CSROp != CSR_NONE) begin
                memoryWritebackPayload.data <= executeMemoryPayload.result;
            end
            memoryWritebackPayload.trapPayload <= executeMemoryPayload.trapPayload;
            if (accessFault && executeMemoryPayload.valid) begin
                if (executeMemoryPayload.trapPayload.trapType == NONE) begin
                    if (executeMemoryPayload.memoryWriteEnable) begin
                        memoryWritebackPayload.trapPayload.trapType <= ACCESS_STORE;
                        memoryWritebackPayload.trapPayload.faultingAddress <= addressRegister;
                    end else if (executeMemoryPayload.memoryReadEnable) begin
                        memoryWritebackPayload.trapPayload.trapType <= ACCESS_LOAD;
                        memoryWritebackPayload.trapPayload.faultingAddress <= addressRegister;
                    end
                end
            end else if (illegal && executeMemoryPayload.valid) begin
                if (executeMemoryPayload.trapPayload.trapType == NONE) begin
                    if (executeMemoryPayload.memoryWriteEnable) begin
                        memoryWritebackPayload.trapPayload.trapType <= MIS_STORE;
                        memoryWritebackPayload.trapPayload.faultingAddress <= addressRegister;
                    end else if (executeMemoryPayload.memoryReadEnable) begin
                        memoryWritebackPayload.trapPayload.trapType <= MIS_LOAD;
                        memoryWritebackPayload.trapPayload.faultingAddress <= addressRegister;
                    end
                end
            end
        end
    end

endmodule



// Do store buffer and dependency checks on loads
