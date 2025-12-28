import pack::*;

module Memory (
    input logic clock,
    input logic reset,
    input logic interrupt,
    input executeMemoryPayload executeMemoryPayload,
    input control memoryWritebackControl,
    input logic [31:0] loadData,
    input logic loadDataValid,
    output logic storeValid, // clocked for mem
    output logic stallControl,
    input logic storeComplete,
    output memoryWritebackPayload memoryWritebackPayload,
    output logic [31:0] addressRegister,
    output logic [31:0] storeData,
    output logic [3:0] realStoreByteEnable
);

    logic illegal;
    logic storeConfirm;
    logic storeReq;
    logic [4:0] shamt;

    assign shamt = {addressRegister[1:0], 3'b000};
    assign storeData = executeMemoryPayload.storeData << shamt;

    assign storeReq = storeConfirm && !storeValid;
    assign stallControl = (executeMemoryPayload.valid && executeMemoryPayload.memoryReadEnable && !illegal && !memoryWritebackControl.flush) ? !loadDataValid : (storeReq || (storeValid && !storeComplete));
    assign addressRegister = executeMemoryPayload.result;
    assign realStoreByteEnable = storeByteEnable << addressRegister[1:0];

    always_comb begin
        illegal = 1'b0;
        storeConfirm = 1'b0;
        storeByteEnable = 4'b0000;
        if (executeMemoryPayload.valid && !memoryWritebackControl.flush && !executeMemoryPayload.illegal) begin
            if (executeMemoryPayload.memoryReadEnable) begin
                unique case (executeMemoryPayload.memoryWidth)
                    2'b00: begin end
                    2'b01: begin 
                        if (addressRegister[0] != 1'b0) begin
                            illegal = 1'b1;
                        end
                    end
                    2'b11: begin 
                        if (addressRegister[1:0] != 2'b00) begin
                            illegal = 1'b1;
                        end
                    end
                    default: illegal = 1'b1;
                endcase
            end
            if (executeMemoryPayload.memoryWriteEnable) begin
                unique case (executeMemoryPayload.memoryWidth)
                    2'b00: begin 
                        storeConfirm = 1'b1; 
                        storeByteEnable = 4'b0001;
                    end
                    2'b01: begin 
                        if (addressRegister[0] != 1'b0) begin
                            illegal = 1'b1;
                        end else begin
                            storeConfirm = 1'b1;
                            storeByteEnable = 4'b0011;
                        end
                    end
                    2'b11: begin 
                        if (addressRegister[1:0] != 2'b00) begin 
                            illegal = 1'b1;
                        end else begin
                            storeConfirm = 1'b1;
                            storeByteEnable = 4'b1111;
                        end
                    end
                    default: illegal = 1'b1;
                endcase
            end
        end
    end

    always_ff @(posedge clock) begin
        if (reset) begin
            storeValid <= 1'b0;
        end else if (!storeValid && !illegal && !memoryWritebackControl.flush) begin
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
                            2'b00: begin // byte (LB/LBU)
                                b = word >> {addressRegister[1:0], 3'b000};
                                memoryWritebackPayload.data <= executeMemoryPayload.memorySigned
                                    ? {{24{b[7]}}, b}
                                    : {24'b0, b};
                            end
                            2'b01: begin // half (LH/LHU)  (assumes misalign already trapped)
                                h = word >> {addressRegister[1], 4'b0000}; // shift by 0 or 16
                                memoryWritebackPayload.data <= executeMemoryPayload.memorySigned
                                    ? {{16{h[15]}}, h}
                                    : {16'b0, h};
                            end
                            2'b11: begin // word (LW) (assumes aligned)
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
            memoryWritebackPayload.illegal <= illegal || executeMemoryPayload.illegal;
            memoryWritebackPayload.valid <= executeMemoryPayload.valid;
            memoryWritebackPayload.programCounter <= executeMemoryPayload.programCounter;
            memoryWritebackPayload.destinationRegister <= executeMemoryPayload.destinationRegister;
        end
    end

endmodule

// Do store buffer and dependency checks on loads
