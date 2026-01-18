// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(__SYM__interrupt,0,0);
        VL_OUT8(dbg_IF_ID_Valid,0,0);
        VL_OUT8(dbg_ID_EX_Valid,0,0);
        VL_OUT8(dbg_EX_MEM_Valid,0,0);
        VL_OUT8(dbg_MEM_WB_Valid,0,0);
        VL_OUT8(dbg_trap,0,0);
        VL_OUT8(dbg_IMEM_valid,0,0);
        VL_OUT8(forwardEnable1,0,0);
        VL_OUT8(forwardEnable2,0,0);
        CData/*0:0*/ Top__DOT__instructionDataValid;
        CData/*0:0*/ Top__DOT__loadDataValid;
        CData/*0:0*/ Top__DOT__storeComplete;
        CData/*1:0*/ Top__DOT__fetchDecodeControl;
        CData/*1:0*/ Top__DOT__decodeExecuteControl;
        CData/*1:0*/ Top__DOT__executeMemoryControl;
        CData/*1:0*/ Top__DOT__memoryWritebackControl;
        CData/*0:0*/ Top__DOT__controlReset;
        CData/*3:0*/ Top__DOT__mcause;
        CData/*4:0*/ Top__DOT__readAddress1;
        CData/*4:0*/ Top__DOT__readAddress2;
        CData/*0:0*/ Top__DOT__branchValid;
        CData/*3:0*/ Top__DOT__readCSR;
        CData/*0:0*/ Top__DOT__mretSignal;
        CData/*3:0*/ Top__DOT__realStoreByteEnable;
        CData/*0:0*/ Top__DOT__storeValid;
        CData/*0:0*/ Top__DOT__stallControl;
        CData/*0:0*/ Top__DOT__destinationEnable;
        CData/*0:0*/ Top__DOT__csrDestinationEnable;
        CData/*0:0*/ Top__DOT__dualValid;
        CData/*0:0*/ Top__DOT__csrForwardEnable;
        CData/*0:0*/ Top__DOT__csrFile__DOT____Vstrobe0;
        CData/*0:0*/ Top__DOT__execute__DOT__redirectAsserted;
        CData/*0:0*/ Top__DOT__execute__DOT__illegal;
        CData/*0:0*/ Top__DOT__execute__DOT__branchValid;
        CData/*0:0*/ Top__DOT__memory__DOT__illegal;
        CData/*0:0*/ Top__DOT__memory__DOT__storeReq;
        CData/*7:0*/ Top__DOT__memory__DOT__unnamedblk1__DOT__b;
        CData/*0:0*/ Top__DOT__dmem_inst__DOT__storeValid_q;
        CData/*3:0*/ __Vtrigprevexpr___TOP__Top__DOT__readCSR__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__mretSignal__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__stallControl__0;
        CData/*4:0*/ __Vtrigprevexpr___TOP__Top__DOT__readAddress1__0;
        CData/*4:0*/ __Vtrigprevexpr___TOP__Top__DOT__readAddress2__0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__mretSignal__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__stallControl__1;
        CData/*0:0*/ __VicoDidInit;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*3:0*/ __Vtrigprevexpr___TOP__Top__DOT__readCSR__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__mretSignal__2;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__stallControl__2;
        CData/*4:0*/ __Vtrigprevexpr___TOP__Top__DOT__readAddress1__1;
        CData/*4:0*/ __Vtrigprevexpr___TOP__Top__DOT__readAddress2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ Top__DOT__memory__DOT__unnamedblk1__DOT__h;
        VL_OUTW(dbg_registers,1023,0,32);
        VL_OUT(dbg_IF_ID_programCounter,31,0);
        VL_OUT(dbg_IF_ID_instruction,31,0);
        VL_OUT(dbg_ID_EX_programCounter,31,0);
    };
    struct {
        VL_OUT(dbg_EX_MEM_programCounter,31,0);
        VL_OUT(dbg_MEM_WB_programCounter,31,0);
        VL_OUT(dbg_IMEM_data,31,0);
        VL_OUT(dbg_pc,31,0);
        VL_OUT(dbg_wb_value,31,0);
        VL_OUT(forwardData1,31,0);
        VL_OUT(forwardData2,31,0);
        VlWide<32>/*1023:0*/ Top__DOT__debug_regs_flat;
        IData/*31:0*/ Top__DOT__instructionData;
        IData/*31:0*/ Top__DOT__readData1;
        IData/*31:0*/ Top__DOT__readData2;
        IData/*31:0*/ Top__DOT__csrReadData;
        IData/*31:0*/ Top__DOT__branchData;
        IData/*31:0*/ Top__DOT__storeData;
        IData/*31:0*/ Top__DOT__writeData;
        IData/*31:0*/ Top__DOT__csrForwardData;
        IData/*31:0*/ Top__DOT__fetch__DOT__programCounter;
        IData/*31:0*/ Top__DOT__execute__DOT__result;
        IData/*31:0*/ Top__DOT__execute__DOT__forwardCorrectedCSRReadData;
        IData/*31:0*/ Top__DOT__memory__DOT__unnamedblk1__DOT__word;
        IData/*31:0*/ Top__DOT__dmem_inst__DOT__unnamedblk1__DOT__word;
        IData/*31:0*/ __VactIterCount;
        VlWide<4>/*96:0*/ Top__DOT__fetchDecodePayload;
        VlWide<7>/*211:0*/ Top__DOT__decodeExecutePayload;
        VlWide<6>/*181:0*/ Top__DOT__executeMemoryPayload;
        VlWide<4>/*112:0*/ Top__DOT__memoryWritebackPayload;
        VlWide<7>/*211:0*/ Top__DOT__decode__DOT__decodeExecuteCandidate;
        VlUnpacked<IData/*31:0*/, 16> Top__DOT__csrFile__DOT__csrs;
        VlUnpacked<IData/*31:0*/, 32> Top__DOT__registerFile__DOT__registers;
        VlUnpacked<IData/*31:0*/, 16384> Top__DOT__imem_inst__DOT__mem;
        VlUnpacked<IData/*31:0*/, 16384> Top__DOT__dmem_inst__DOT__mem;
    };
    VlTriggerVec<6> __VstlTriggered;
    VlTriggerVec<3> __VicoTriggered;
    VlTriggerVec<6> __VactTriggered;
    VlTriggerVec<6> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* v__name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
