package ConfigPack;

    parameter logic [31:0] resetVector = 32'h00000000; // PC Reset Point
    parameter logic [31:0] memoryBytes = 32'h0000_FFFF; // Word Aligned Supported Memory Bytes

endpackage