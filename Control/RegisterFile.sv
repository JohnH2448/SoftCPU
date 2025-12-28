import pack::*;

module RegisterFile (
    input logic clock,
    input logic [4:0] readAddress1,
    input logic [4:0] readAddress2,
    input logic destinationEnable,
    input logic [4:0] writeAddress,
    input logic [31:0] writeData,
    output logic [31:0] readData1,
    output logic [31:0] readData2
);
    logic [31:0] registers [31:0];

    initial begin
        registers[0] = 32'd0;
    end

    always_comb begin
        if (readAddress1 == 5'd0) begin
            readData1 = 32'd0;
        end else begin
            readData1 = registers[readAddress1];
        end
        if (readAddress2 == 5'd0) begin
            readData2 = 32'd0;
        end else begin
            readData2 = registers[readAddress2];
        end
    end
    
    always_ff @(posedge clock) begin

        if (destinationEnable) begin
            if (writeAddress != 5'd0) begin
                registers[writeAddress] <= writeData;
            end
        end



    end

endmodule