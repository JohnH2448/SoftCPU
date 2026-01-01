#include "obj_dir/VTop.h"
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
    for (int i = 0; i < 100; i++) {
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

        if (top.dbg_trap) {
            printf("TRAP encountered! Halting simulation.\n");
            break;
        }
        if (top.forwardEnable1) {
            printf("Foreward Event: Data=%08x\n", top.forwardData1);
        }
        if (top.forwardEnable2) {
            printf("Foreward Event: Data=%08x\n", top.forwardData2);
        }
        printf("\nRegisters:");
        for (int i = 0; i < 32; i++) {
            if (i % 8 == 0) printf("\n");
            printf("x%02d=%08x ", i, top.dbg_registers[i]);
        }
        if (top.dbg_wb_value) {
            printf("\n\nWB Event: Value=%08x", top.dbg_wb_value);
        }
    }
    printf("\n\n");
}

