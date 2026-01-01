import pack::*;

module Forward (
    input logic [4:0] decodeExecuteRegister1,
    input logic [4:0] decodeExecuteRegister2,
    input logic [4:0] executeMemoryDestinationRegister,
    input logic [31:0] executeMemoryData,
    input logic [31:0] executeMemoryPC4,
    input logic executeMemoryValid,
    input writebackType_ executeMemoryWritebackType, // functionally used as "executeMemoryWritebackEnable" 
    input logic [4:0] memoryWritebackDestinationRegister,
    input logic [31:0] memoryWritebackData,
    input logic memoryWritebackValid,
    input logic memoryWritebackWritebackEnable,
    output logic forwardEnable1,
    output logic forwardEnable2,
    output logic [31:0] forwardData1,
    output logic [31:0] forwardData2
);

    always_comb begin
        forwardEnable1 = 1'b0;
        forwardEnable2 = 1'b0;
        forwardData1 = 32'd0;
        forwardData2 = 32'd0;
        if (decodeExecuteRegister1 != 5'd0) begin
            if (executeMemoryValid &&
                (executeMemoryWritebackType != WB_NONE && executeMemoryWritebackType != WB_MEM) &&
                (executeMemoryDestinationRegister != 5'd0) &&
                (decodeExecuteRegister1 == executeMemoryDestinationRegister)) begin
                forwardEnable1 = 1'b1;
                case (executeMemoryWritebackType)
                    WB_ALU: forwardData1 = executeMemoryData;
                    WB_PC4: forwardData1 = executeMemoryPC4;
                    default: forwardData1 = 32'd0;
                endcase
            end else if (memoryWritebackValid &&
                        memoryWritebackWritebackEnable &&
                        (memoryWritebackDestinationRegister != 5'd0) &&
                        (decodeExecuteRegister1 == memoryWritebackDestinationRegister)) begin
                forwardEnable1 = 1'b1;
                forwardData1 = memoryWritebackData;
            end
        end
        if (decodeExecuteRegister2 != 5'd0) begin
            if (executeMemoryValid &&
                (executeMemoryWritebackType != WB_NONE && executeMemoryWritebackType != WB_MEM) &&
                (executeMemoryDestinationRegister != 5'd0) &&
                (decodeExecuteRegister2 == executeMemoryDestinationRegister)) begin
                forwardEnable2 = 1'b1;
                case (executeMemoryWritebackType)
                    WB_ALU: forwardData2 = executeMemoryData;
                    WB_PC4: forwardData2 = executeMemoryPC4;
                    default: forwardData2 = 32'd0;
                endcase
            end else if (memoryWritebackValid &&
                        memoryWritebackWritebackEnable &&
                        (memoryWritebackDestinationRegister != 5'd0) &&
                        (decodeExecuteRegister2 == memoryWritebackDestinationRegister)) begin
                forwardEnable2 = 1'b1;
                forwardData2 = memoryWritebackData;
            end
        end
    end

endmodule
// MUST DO FOREWARDING FOR BRANCH CHECKS IN EXECUTE STAGE