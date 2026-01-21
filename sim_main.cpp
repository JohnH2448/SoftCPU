#include "Verilator/VTop.h"
#include "verilated.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    VTop top;

    top.__SYM__interrupt = 0;

    // reset
    top.reset = 1;
    for (int i = 0; i < 5; i++) {
        top.clock = 0; top.eval();
        top.clock = 1; top.eval();
    }
    top.reset = 0;
    
    printf("SIM: starting execution\n");

    // run
    int count = 0;
    for (int i = 1; i < 5000; i++) {
        top.clock = 0; top.eval();
        top.clock = 1; top.eval();
        printf("\n\n");
        printf("Cycle %d:\n\n", i);
        printf("Fetch Input: pc=%08x data=%08x, valid=%d\n", top.dbg_pc, top.dbg_IMEM_data, top.dbg_IMEM_valid);
        printf("IF/ID  PC=%08x v=%d instr=%08x\n",
            top.dbg_IF_ID_programCounter,
            top.dbg_IF_ID_Valid,
            top.dbg_IF_ID_instruction);
        printf("ID/EX  PC=%08x v=%d\n",
            top.dbg_ID_EX_programCounter,
            top.dbg_ID_EX_Valid);
        printf("EX/MEM PC=%08x v=%d\n",
            top.dbg_EX_MEM_programCounter,
            top.dbg_EX_MEM_Valid);
        printf("MEM/WB PC=%08x v=%d\n",
            top.dbg_MEM_WB_programCounter,
            top.dbg_MEM_WB_Valid);
        printf("\nRegisters:");
        for (int i = 0; i < 32; i++) {
            if (i % 8 == 0) printf("\n");
            printf("x%02d=%08x ", i, top.dbg_registers[i]);
        }
    }
    printf("\n\n");
}

