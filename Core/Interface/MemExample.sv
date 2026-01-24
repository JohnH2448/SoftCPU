import StaticPack::*;
import ConfigPack::*;

module MemExample (
    input  logic        clock,
    input  logic        reset,

    // Instruction fetch port (same behavior as Imem)
    input  logic [31:0] i_address,
    output logic [31:0] i_data,
    output logic        i_valid,

    // Data port (same behavior as Dmem)
    input  logic [31:0] d_address,
    input  logic [31:0] storeData,
    input  logic [3:0]  byteEnable,
    input  logic        storeValid,
    output logic [31:0] loadData,
    output logic        loadDataValid,
    output logic        storeComplete
);

    // One shared address space
    logic [31:0] mem [0:16383];
    logic        storeValid_q;

    initial begin
        integer i;
        for (i = 0; i < 16384; i = i + 1) begin
            mem[i] = 32'h00000000;
        end

        $display("Loading mem.hex...");
        $readmemh("mem.hex", mem);

    end

    // ===== Instruction fetch (Imem behavior) =====
    always_comb begin
        i_data  = 32'h00000013; // default NOP
        i_valid = 1'b0;
        if (!reset) begin
            if (i_address[1:0] == 2'b00) begin
                i_data  = mem[i_address[15:2]];
                i_valid = 1'b1;
            end
        end
    end

    // ===== Data load (Dmem behavior) =====
    always_comb begin
        if (reset) begin
            loadData      = 32'b0;
            loadDataValid = 1'b0;
        end else begin
            loadData      = mem[d_address[15:2]];
            loadDataValid = 1'b1;
        end
    end

    // ===== Data store (Dmem behavior) =====
    always_ff @(posedge clock) begin
        if (reset) begin
            storeValid_q   <= 1'b0;
            storeComplete  <= 1'b0;
        end else begin
            storeComplete <= 1'b0;

            if (storeValid && !storeValid_q) begin
                logic [31:0] word;
                word = mem[d_address[15:2]];

                if (byteEnable[0]) word[7:0]   = storeData[7:0];
                if (byteEnable[1]) word[15:8]  = storeData[15:8];
                if (byteEnable[2]) word[23:16] = storeData[23:16];
                if (byteEnable[3]) word[31:24] = storeData[31:24];

                // kept indexing behavior consistent with your original store path
                mem[d_address[31:2]] <= word;

                $display("\n\nStored %08h at address %08h", word, {d_address[31:2], 2'b00}, "\n\n");
                storeComplete <= 1'b1;
            end

            storeValid_q <= storeValid;
        end
    end

endmodule
