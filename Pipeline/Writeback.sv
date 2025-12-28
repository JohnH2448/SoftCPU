import pack::*;

module Writeback (
    input logic clock,
    input logic reset,
    input logic interrupt,
    input memoryWritebackPayload memoryWritebackPayload,
    output logic destinationEnable,
    output logic [4:0] writeAddress,
    output logic [31:0] writeData
);

    assign writeAddress = memoryWritebackPayload.destinationRegister;
    assign writeData = memoryWritebackPayload.data;
    assign destinationEnable =
           memoryWritebackPayload.valid &&
           memoryWritebackPayload.writebackEnable &&
           !memoryWritebackPayload.illegal;

endmodule
