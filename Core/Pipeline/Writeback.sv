import pack::*;

module Writeback (
    input logic clock,
    input logic reset,
    input logic interrupt,
    input memoryWritebackPayload_ memoryWritebackPayload,
    output logic destinationEnable,
    output logic [4:0] writeAddress,
    output logic [31:0] writeData,
    output logic memoryWritebackValid,
    // csrs
    output destinationCSR_ destinationCSR,
    output logic csrDestinationEnable,
    output logic [31:0] csrWriteData,
    output logic dualValid,
    output trapPayload_ trapData
);
    assign trapData = memoryWritebackPayload.trapPayload;
    assign memoryWritebackValid = memoryWritebackPayload.valid;
    assign dualValid = memoryWritebackPayload.valid && memoryWritebackPayload.trapPayload.trapType == NONE;
    // reg file
    assign writeAddress = memoryWritebackPayload.destinationRegister;
    assign writeData = (memoryWritebackPayload.CSROp != CSR_NONE) ? memoryWritebackPayload.oldCSRValue : memoryWritebackPayload.data;
    assign destinationEnable = (memoryWritebackPayload.CSROp != CSR_NONE) ? (dualValid) :
        (memoryWritebackPayload.valid &&
        memoryWritebackPayload.writebackEnable &&
        memoryWritebackPayload.trapPayload.trapType == NONE);
    // csr file
    assign destinationCSR = memoryWritebackPayload.destinationCSR;
    assign csrWriteData = memoryWritebackPayload.data;
    assign csrDestinationEnable = (memoryWritebackPayload.CSROp != CSR_NONE) ? (dualValid && memoryWritebackPayload.CSRWriteIntent) : 1'b0;

endmodule
