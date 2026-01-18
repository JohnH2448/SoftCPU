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
    output logic [31:0] forwardData2,
    //csrs
    input CSROp_ executeMemoryCSROp,
    input logic [31:0] oldCSRData,
    input logic [31:0] memoryWritebackCSRData,
    input destinationCSR_ executeMemoryDestinationCSR,
    input logic executeMemoryCSRWriteIntent,
    input logic [31:0] executeMemoryCSRData,
    input destinationCSR_ memoryWritebackDestinationCSR,
    input logic memoryWritebackCSRWriteIntent,
    input destinationCSR_ decodeExecuteDestinationCSR,
    output logic [31:0] csrForwardData,
    output logic csrForwardEnable
);

    always_comb begin
        forwardEnable1 = 1'b0;
        forwardEnable2 = 1'b0;
        forwardData1 = 32'd0;
        forwardData2 = 32'd0;
        csrForwardEnable = 1'd0;
        csrForwardData = 32'd0;
        if (decodeExecuteRegister1 != 5'd0) begin
            if (executeMemoryValid &&
                ((executeMemoryWritebackType != WB_NONE && executeMemoryWritebackType != WB_MEM) || executeMemoryCSROp != CSR_NONE) &&
                (executeMemoryDestinationRegister != 5'd0) &&
                (decodeExecuteRegister1 == executeMemoryDestinationRegister)) begin
                forwardEnable1 = 1'b1;
                case (executeMemoryWritebackType)
                    WB_ALU: forwardData1 = executeMemoryData;
                    WB_PC4: forwardData1 = executeMemoryPC4;
                    default: begin
                        if (executeMemoryCSROp != CSR_NONE) forwardData1 = oldCSRData;
                        else forwardData1 = 32'd0;
                    end
                endcase
                $display("Forward Rs1 from EX/MEM. Value: ", forwardData1);
            end else if (memoryWritebackValid &&
                        memoryWritebackWritebackEnable &&
                        (memoryWritebackDestinationRegister != 5'd0) &&
                        (decodeExecuteRegister1 == memoryWritebackDestinationRegister)) begin
                forwardEnable1 = 1'b1;
                forwardData1 = memoryWritebackData;
                $display("Forward Rs1 from MEM/WB. Value: ", forwardData1);
            end
        end
        if (decodeExecuteRegister2 != 5'd0) begin
            if (executeMemoryValid &&
                ((executeMemoryWritebackType != WB_NONE && executeMemoryWritebackType != WB_MEM) || executeMemoryCSROp != CSR_NONE) &&
                (executeMemoryDestinationRegister != 5'd0) &&
                (decodeExecuteRegister2 == executeMemoryDestinationRegister)) begin
                forwardEnable2 = 1'b1;
                case (executeMemoryWritebackType)
                    WB_ALU: forwardData2 = executeMemoryData;
                    WB_PC4: forwardData2 = executeMemoryPC4;
                    default: begin
                        if (executeMemoryCSROp != CSR_NONE) forwardData2 = oldCSRData;
                        else forwardData2 = 32'd0;
                    end
                endcase
                $display("Forward Rs2 from EX/MEM. Value: ", forwardData2);
            end else if (memoryWritebackValid &&
                        memoryWritebackWritebackEnable &&
                        (memoryWritebackDestinationRegister != 5'd0) &&
                        (decodeExecuteRegister2 == memoryWritebackDestinationRegister)) begin
                forwardEnable2 = 1'b1;
                forwardData2 = memoryWritebackData;
                $display("Forward Rs2 from MEM/WB. Value: ", forwardData2);
            end
        end
        if ((decodeExecuteDestinationCSR == executeMemoryDestinationCSR) && executeMemoryCSRWriteIntent && executeMemoryValid) begin
            csrForwardData = executeMemoryCSRData;
            csrForwardEnable = 1'b1;
        end else if ((decodeExecuteDestinationCSR == memoryWritebackDestinationCSR) && memoryWritebackCSRWriteIntent && memoryWritebackValid) begin
            csrForwardData = memoryWritebackCSRData;
            csrForwardEnable = 1'b1;
        end
    end
endmodule
