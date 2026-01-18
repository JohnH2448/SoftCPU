// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___eval_static__TOP(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_static(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static\n"); );
    // Body
    VTop___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void VTop___024root___eval_static__TOP(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->Top__DOT__execute__DOT__redirectAsserted = 0U;
}

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    VTop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readCSR__0 
        = vlSelf->Top__DOT__readCSR;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__mretSignal__0 
        = vlSelf->Top__DOT__mretSignal;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__stallControl__0 
        = vlSelf->Top__DOT__stallControl;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress1__0 
        = vlSelf->Top__DOT__readAddress1;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress2__0 
        = vlSelf->Top__DOT__readAddress2;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__mretSignal__1 
        = vlSelf->Top__DOT__mretSignal;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__stallControl__1 
        = vlSelf->Top__DOT__stallControl;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readCSR__1 
        = vlSelf->Top__DOT__readCSR;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__mretSignal__2 
        = vlSelf->Top__DOT__mretSignal;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__stallControl__2 
        = vlSelf->Top__DOT__stallControl;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress1__1 
        = vlSelf->Top__DOT__readAddress1;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress2__1 
        = vlSelf->Top__DOT__readAddress2;
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = vlSelf->clock;
}

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ Top__DOT__imem_inst__DOT__unnamedblk1__DOT__i;
    Top__DOT__imem_inst__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelf->Top__DOT__registerFile__DOT__registers[0U] = 0U;
    Top__DOT__imem_inst__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x4000U, Top__DOT__imem_inst__DOT__unnamedblk1__DOT__i)) {
        vlSelf->Top__DOT__imem_inst__DOT__mem[(0x3fffU 
                                               & Top__DOT__imem_inst__DOT__unnamedblk1__DOT__i)] = 0x13U;
        Top__DOT__imem_inst__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + Top__DOT__imem_inst__DOT__unnamedblk1__DOT__i);
    }
    VL_WRITEF("IMEM: loading imem.hex\n");
    VL_READMEM_N(true, 32, 16384, 0, std::string{"imem.hex"}
                 ,  &(vlSelf->Top__DOT__imem_inst__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void VTop___024root___eval_final(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VTop___024root___eval_phase__stl(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("CPU/Top.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VTop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] Top.readCSR)\n");
    }
    if ((4ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] Top.mretSignal or [hybrid] Top.stallControl)\n");
    }
    if ((8ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 3 is active: @([hybrid] Top.stallControl)\n");
    }
    if ((0x10ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 4 is active: @([hybrid] Top.readAddress1)\n");
    }
    if ((0x20ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 5 is active: @([hybrid] Top.readAddress2)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->dbg_IF_ID_programCounter = ((vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                         << 0x1fU) 
                                        | (vlSelf->Top__DOT__fetchDecodePayload[1U] 
                                           >> 1U));
    vlSelf->dbg_IF_ID_instruction = ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                      << 0x1fU) | (
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                   >> 1U));
    vlSelf->dbg_ID_EX_programCounter = ((vlSelf->Top__DOT__decodeExecutePayload[6U] 
                                         << 0xcU) | 
                                        (vlSelf->Top__DOT__decodeExecutePayload[5U] 
                                         >> 0x14U));
    vlSelf->dbg_EX_MEM_programCounter = ((vlSelf->Top__DOT__executeMemoryPayload[5U] 
                                          << 0xaU) 
                                         | (vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                            >> 0x16U));
    vlSelf->Top__DOT__storeData = (((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                     << 0x14U) | (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                  >> 0xcU)) 
                                   << (0x18U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                >> 9U)));
    vlSelf->dbg_MEM_WB_programCounter = ((vlSelf->Top__DOT__memoryWritebackPayload[3U] 
                                          << 0xfU) 
                                         | (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                            >> 0x11U));
    vlSelf->Top__DOT__debug_regs_flat[0U] = vlSelf->Top__DOT__registerFile__DOT__registers
        [0U];
    vlSelf->Top__DOT__debug_regs_flat[1U] = (IData)(
                                                    (((QData)((IData)(
                                                                      vlSelf->Top__DOT__registerFile__DOT__registers
                                                                      [2U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->Top__DOT__registerFile__DOT__registers
                                                                       [1U]))));
    vlSelf->Top__DOT__debug_regs_flat[2U] = (IData)(
                                                    ((((QData)((IData)(
                                                                       vlSelf->Top__DOT__registerFile__DOT__registers
                                                                       [2U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->Top__DOT__registerFile__DOT__registers
                                                                        [1U]))) 
                                                     >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[3U] = vlSelf->Top__DOT__registerFile__DOT__registers
        [3U];
    vlSelf->Top__DOT__debug_regs_flat[4U] = (IData)(
                                                    (((QData)((IData)(
                                                                      vlSelf->Top__DOT__registerFile__DOT__registers
                                                                      [5U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->Top__DOT__registerFile__DOT__registers
                                                                       [4U]))));
    vlSelf->Top__DOT__debug_regs_flat[5U] = (IData)(
                                                    ((((QData)((IData)(
                                                                       vlSelf->Top__DOT__registerFile__DOT__registers
                                                                       [5U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->Top__DOT__registerFile__DOT__registers
                                                                        [4U]))) 
                                                     >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[6U] = vlSelf->Top__DOT__registerFile__DOT__registers
        [6U];
    vlSelf->Top__DOT__debug_regs_flat[7U] = (IData)(
                                                    (((QData)((IData)(
                                                                      vlSelf->Top__DOT__registerFile__DOT__registers
                                                                      [8U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlSelf->Top__DOT__registerFile__DOT__registers
                                                                       [7U]))));
    vlSelf->Top__DOT__debug_regs_flat[8U] = (IData)(
                                                    ((((QData)((IData)(
                                                                       vlSelf->Top__DOT__registerFile__DOT__registers
                                                                       [8U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->Top__DOT__registerFile__DOT__registers
                                                                        [7U]))) 
                                                     >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[9U] = vlSelf->Top__DOT__registerFile__DOT__registers
        [9U];
    vlSelf->Top__DOT__debug_regs_flat[0xaU] = (IData)(
                                                      (((QData)((IData)(
                                                                        vlSelf->Top__DOT__registerFile__DOT__registers
                                                                        [0xbU])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0xaU]))));
    vlSelf->Top__DOT__debug_regs_flat[0xbU] = (IData)(
                                                      ((((QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0xbU])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0xaU]))) 
                                                       >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[0xcU] = vlSelf->Top__DOT__registerFile__DOT__registers
        [0xcU];
    vlSelf->Top__DOT__debug_regs_flat[0xdU] = (IData)(
                                                      (((QData)((IData)(
                                                                        vlSelf->Top__DOT__registerFile__DOT__registers
                                                                        [0xeU])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0xdU]))));
    vlSelf->Top__DOT__debug_regs_flat[0xeU] = (IData)(
                                                      ((((QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0xeU])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0xdU]))) 
                                                       >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[0xfU] = vlSelf->Top__DOT__registerFile__DOT__registers
        [0xfU];
    vlSelf->Top__DOT__debug_regs_flat[0x10U] = (IData)(
                                                       (((QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0x11U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x10U]))));
    vlSelf->Top__DOT__debug_regs_flat[0x11U] = (IData)(
                                                       ((((QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x11U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->Top__DOT__registerFile__DOT__registers
                                                                           [0x10U]))) 
                                                        >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[0x12U] = vlSelf->Top__DOT__registerFile__DOT__registers
        [0x12U];
    vlSelf->Top__DOT__debug_regs_flat[0x13U] = (IData)(
                                                       (((QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0x14U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x13U]))));
    vlSelf->Top__DOT__debug_regs_flat[0x14U] = (IData)(
                                                       ((((QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x14U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->Top__DOT__registerFile__DOT__registers
                                                                           [0x13U]))) 
                                                        >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[0x15U] = vlSelf->Top__DOT__registerFile__DOT__registers
        [0x15U];
    vlSelf->Top__DOT__debug_regs_flat[0x16U] = (IData)(
                                                       (((QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0x17U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x16U]))));
    vlSelf->Top__DOT__debug_regs_flat[0x17U] = (IData)(
                                                       ((((QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x17U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->Top__DOT__registerFile__DOT__registers
                                                                           [0x16U]))) 
                                                        >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[0x18U] = vlSelf->Top__DOT__registerFile__DOT__registers
        [0x18U];
    vlSelf->Top__DOT__debug_regs_flat[0x19U] = (IData)(
                                                       (((QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0x1aU])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x19U]))));
    vlSelf->Top__DOT__debug_regs_flat[0x1aU] = (IData)(
                                                       ((((QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x1aU])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->Top__DOT__registerFile__DOT__registers
                                                                           [0x19U]))) 
                                                        >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[0x1bU] = vlSelf->Top__DOT__registerFile__DOT__registers
        [0x1bU];
    vlSelf->Top__DOT__debug_regs_flat[0x1cU] = (IData)(
                                                       (((QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0x1dU])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x1cU]))));
    vlSelf->Top__DOT__debug_regs_flat[0x1dU] = (IData)(
                                                       ((((QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x1dU])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->Top__DOT__registerFile__DOT__registers
                                                                           [0x1cU]))) 
                                                        >> 0x20U));
    vlSelf->Top__DOT__debug_regs_flat[0x1eU] = (IData)(
                                                       (((QData)((IData)(
                                                                         vlSelf->Top__DOT__registerFile__DOT__registers
                                                                         [0x1fU])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x1eU]))));
    vlSelf->Top__DOT__debug_regs_flat[0x1fU] = (IData)(
                                                       ((((QData)((IData)(
                                                                          vlSelf->Top__DOT__registerFile__DOT__registers
                                                                          [0x1fU])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->Top__DOT__registerFile__DOT__registers
                                                                           [0x1eU]))) 
                                                        >> 0x20U));
    vlSelf->dbg_pc = vlSelf->Top__DOT__fetch__DOT__programCounter;
    vlSelf->dbg_IF_ID_Valid = (1U & vlSelf->Top__DOT__fetchDecodePayload[0U]);
    vlSelf->Top__DOT__loadDataValid = (1U & (~ (IData)(vlSelf->reset)));
    vlSelf->dbg_ID_EX_Valid = (1U & vlSelf->Top__DOT__decodeExecutePayload[0U]);
    vlSelf->dbg_EX_MEM_Valid = (1U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                      >> 7U));
    vlSelf->dbg_MEM_WB_Valid = (1U & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                      >> 7U));
    vlSelf->dbg_registers[0U] = vlSelf->Top__DOT__debug_regs_flat[0U];
    vlSelf->dbg_registers[1U] = vlSelf->Top__DOT__debug_regs_flat[1U];
    vlSelf->dbg_registers[2U] = vlSelf->Top__DOT__debug_regs_flat[2U];
    vlSelf->dbg_registers[3U] = vlSelf->Top__DOT__debug_regs_flat[3U];
    vlSelf->dbg_registers[4U] = vlSelf->Top__DOT__debug_regs_flat[4U];
    vlSelf->dbg_registers[5U] = vlSelf->Top__DOT__debug_regs_flat[5U];
    vlSelf->dbg_registers[6U] = vlSelf->Top__DOT__debug_regs_flat[6U];
    vlSelf->dbg_registers[7U] = vlSelf->Top__DOT__debug_regs_flat[7U];
    vlSelf->dbg_registers[8U] = vlSelf->Top__DOT__debug_regs_flat[8U];
    vlSelf->dbg_registers[9U] = vlSelf->Top__DOT__debug_regs_flat[9U];
    vlSelf->dbg_registers[0xaU] = vlSelf->Top__DOT__debug_regs_flat[0xaU];
    vlSelf->dbg_registers[0xbU] = vlSelf->Top__DOT__debug_regs_flat[0xbU];
    vlSelf->dbg_registers[0xcU] = vlSelf->Top__DOT__debug_regs_flat[0xcU];
    vlSelf->dbg_registers[0xdU] = vlSelf->Top__DOT__debug_regs_flat[0xdU];
    vlSelf->dbg_registers[0xeU] = vlSelf->Top__DOT__debug_regs_flat[0xeU];
    vlSelf->dbg_registers[0xfU] = vlSelf->Top__DOT__debug_regs_flat[0xfU];
    vlSelf->dbg_registers[0x10U] = vlSelf->Top__DOT__debug_regs_flat[0x10U];
    vlSelf->dbg_registers[0x11U] = vlSelf->Top__DOT__debug_regs_flat[0x11U];
    vlSelf->dbg_registers[0x12U] = vlSelf->Top__DOT__debug_regs_flat[0x12U];
    vlSelf->dbg_registers[0x13U] = vlSelf->Top__DOT__debug_regs_flat[0x13U];
    vlSelf->dbg_registers[0x14U] = vlSelf->Top__DOT__debug_regs_flat[0x14U];
    vlSelf->dbg_registers[0x15U] = vlSelf->Top__DOT__debug_regs_flat[0x15U];
    vlSelf->dbg_registers[0x16U] = vlSelf->Top__DOT__debug_regs_flat[0x16U];
    vlSelf->dbg_registers[0x17U] = vlSelf->Top__DOT__debug_regs_flat[0x17U];
    vlSelf->dbg_registers[0x18U] = vlSelf->Top__DOT__debug_regs_flat[0x18U];
    vlSelf->dbg_registers[0x19U] = vlSelf->Top__DOT__debug_regs_flat[0x19U];
    vlSelf->dbg_registers[0x1aU] = vlSelf->Top__DOT__debug_regs_flat[0x1aU];
    vlSelf->dbg_registers[0x1bU] = vlSelf->Top__DOT__debug_regs_flat[0x1bU];
    vlSelf->dbg_registers[0x1cU] = vlSelf->Top__DOT__debug_regs_flat[0x1cU];
    vlSelf->dbg_registers[0x1dU] = vlSelf->Top__DOT__debug_regs_flat[0x1dU];
    vlSelf->dbg_registers[0x1eU] = vlSelf->Top__DOT__debug_regs_flat[0x1eU];
    vlSelf->dbg_registers[0x1fU] = vlSelf->Top__DOT__debug_regs_flat[0x1fU];
    vlSelf->Top__DOT__instructionDataValid = 0U;
    vlSelf->Top__DOT__instructionData = 0x13U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if ((0U == (3U & vlSelf->dbg_pc))) {
            vlSelf->Top__DOT__instructionDataValid = 1U;
            vlSelf->Top__DOT__instructionData = vlSelf->Top__DOT__imem_inst__DOT__mem
                [(0x3fffU & (vlSelf->dbg_pc >> 2U))];
        }
    }
    vlSelf->Top__DOT__csrForwardEnable = 0U;
    vlSelf->Top__DOT__csrForwardData = 0U;
    if (((((0xfU & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                    >> 0xcU)) == (0xfU & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                          >> 3U))) 
          & vlSelf->Top__DOT__executeMemoryPayload[0U]) 
         & (IData)(vlSelf->dbg_EX_MEM_Valid))) {
        vlSelf->Top__DOT__csrForwardEnable = 1U;
        vlSelf->Top__DOT__csrForwardData = ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                             << 0x14U) 
                                            | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                               >> 0xcU));
    } else if (((((0xfU & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 0xcU)) == (0xfU & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                 >> 3U))) 
                 & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                & (IData)(vlSelf->dbg_MEM_WB_Valid))) {
        vlSelf->Top__DOT__csrForwardEnable = 1U;
        vlSelf->Top__DOT__csrForwardData = ((vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                             << 0x14U) 
                                            | (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                               >> 0xcU));
    }
    vlSelf->Top__DOT__dualValid = ((~ (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                       >> 8U)) & (IData)(vlSelf->dbg_MEM_WB_Valid));
    if ((0U != (3U & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                      >> 1U)))) {
        vlSelf->Top__DOT__writeData = ((vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                        << 0x1dU) | 
                                       (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                        >> 3U));
        vlSelf->Top__DOT__destinationEnable = vlSelf->Top__DOT__dualValid;
        vlSelf->dbg_IMEM_valid = vlSelf->Top__DOT__instructionDataValid;
        vlSelf->dbg_IMEM_data = vlSelf->Top__DOT__instructionData;
        vlSelf->Top__DOT__csrDestinationEnable = ((IData)(vlSelf->Top__DOT__dualValid) 
                                                  & vlSelf->Top__DOT__memoryWritebackPayload[0U]);
    } else {
        vlSelf->Top__DOT__writeData = ((vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                        << 0x14U) | 
                                       (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                        >> 0xcU));
        vlSelf->Top__DOT__destinationEnable = ((IData)(vlSelf->dbg_MEM_WB_Valid) 
                                               & (IData)(
                                                         (0x200U 
                                                          == 
                                                          (0x300U 
                                                           & vlSelf->Top__DOT__memoryWritebackPayload[1U]))));
        vlSelf->dbg_IMEM_valid = vlSelf->Top__DOT__instructionDataValid;
        vlSelf->dbg_IMEM_data = vlSelf->Top__DOT__instructionData;
        vlSelf->Top__DOT__csrDestinationEnable = 0U;
    }
    vlSelf->dbg_wb_value = ((IData)(vlSelf->Top__DOT__destinationEnable)
                             ? ((vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                 << 0x14U) | (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                              >> 0xcU))
                             : 0U);
    vlSelf->forwardEnable1 = 0U;
    vlSelf->forwardEnable2 = 0U;
    vlSelf->forwardData1 = 0U;
    vlSelf->forwardData2 = 0U;
    VL_WRITEF("FWD_IN: rs1=%0# rs2=%0# | EXMEM: v=%0b wbtype=%0# rd=%0# | MEMWB: v=%0b we=%0b rd=%0#\n",
              5,(0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                          >> 0xfU)),5,(0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                >> 0xaU)),
              1,(IData)(vlSelf->dbg_EX_MEM_Valid),3,
              (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                     >> 9U)),5,(0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                         >> 0x11U)),
              1,(IData)(vlSelf->dbg_MEM_WB_Valid),1,
              vlSelf->Top__DOT__destinationEnable,5,
              (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                        >> 0xcU)));
    if ((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                         >> 0xfU)))) {
        if (VL_UNLIKELY(((((IData)(vlSelf->dbg_EX_MEM_Valid) 
                           & (((0U != (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                             >> 9U))) 
                               & (2U != (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                               >> 9U)))) 
                              | (0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                              >> 1U))))) 
                          & (0U != (0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                             >> 0x11U)))) 
                         & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                      >> 0xfU)) == 
                            (0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                      >> 0x11U)))))) {
            vlSelf->forwardData1 = ((1U == (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                  >> 9U)))
                                     ? ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                         << 0x14U) 
                                        | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                           >> 0xcU))
                                     : ((3U == (7U 
                                                & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                   >> 9U)))
                                         ? ((vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                             << 0xaU) 
                                            | (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                               >> 0x16U))
                                         : ((0U != 
                                             (3U & 
                                              (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                               >> 1U)))
                                             ? ((vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                 << 0x1dU) 
                                                | (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                   >> 3U))
                                             : 0U)));
            vlSelf->forwardEnable1 = 1U;
            VL_WRITEF("Forward Rs1 from EX/MEM. Value: %10#\n",
                      32,vlSelf->forwardData1);
        } else if (VL_UNLIKELY(((((IData)(vlSelf->dbg_MEM_WB_Valid) 
                                  & (IData)(vlSelf->Top__DOT__destinationEnable)) 
                                 & (0U != (0x1fU & 
                                           (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                            >> 0xcU)))) 
                                & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                             >> 0xfU)) 
                                   == (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                                >> 0xcU)))))) {
            vlSelf->forwardData1 = vlSelf->Top__DOT__writeData;
            vlSelf->forwardEnable1 = 1U;
            VL_WRITEF("Forward Rs1 from MEM/WB. Value: %10#\n",
                      32,vlSelf->forwardData1);
        }
    }
    if ((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                         >> 0xaU)))) {
        if (VL_UNLIKELY(((((IData)(vlSelf->dbg_EX_MEM_Valid) 
                           & (((0U != (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                             >> 9U))) 
                               & (2U != (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                               >> 9U)))) 
                              | (0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                              >> 1U))))) 
                          & (0U != (0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                             >> 0x11U)))) 
                         & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                      >> 0xaU)) == 
                            (0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                      >> 0x11U)))))) {
            vlSelf->forwardData2 = ((1U == (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                  >> 9U)))
                                     ? ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                         << 0x14U) 
                                        | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                           >> 0xcU))
                                     : ((3U == (7U 
                                                & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                   >> 9U)))
                                         ? ((vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                             << 0xaU) 
                                            | (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                               >> 0x16U))
                                         : ((0U != 
                                             (3U & 
                                              (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                               >> 1U)))
                                             ? ((vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                 << 0x1dU) 
                                                | (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                   >> 3U))
                                             : 0U)));
            vlSelf->forwardEnable2 = 1U;
            VL_WRITEF("Forward Rs2 from EX/MEM. Value: %10#\n",
                      32,vlSelf->forwardData2);
        } else if (VL_UNLIKELY(((((IData)(vlSelf->dbg_MEM_WB_Valid) 
                                  & (IData)(vlSelf->Top__DOT__destinationEnable)) 
                                 & (0U != (0x1fU & 
                                           (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                            >> 0xcU)))) 
                                & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                             >> 0xaU)) 
                                   == (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                                >> 0xcU)))))) {
            vlSelf->forwardData2 = vlSelf->Top__DOT__writeData;
            vlSelf->forwardEnable2 = 1U;
            VL_WRITEF("Forward Rs2 from MEM/WB. Value: %10#\n",
                      32,vlSelf->forwardData2);
        }
    }
    VL_WRITEF("FWD_OUT: en1=%0b data1=%08x | en2=%0b data2=%08x\n",
              1,vlSelf->forwardEnable1,32,vlSelf->forwardData1,
              1,(IData)(vlSelf->forwardEnable2),32,
              vlSelf->forwardData2);
}

void VTop___024root___act_sequent__TOP__0(VTop___024root* vlSelf);
void VTop___024root___ico_comb__TOP__0(VTop___024root* vlSelf);
void VTop___024root___act_sequent__TOP__2(VTop___024root* vlSelf);
void VTop___024root___act_sequent__TOP__3(VTop___024root* vlSelf);
void VTop___024root___act_sequent__TOP__4(VTop___024root* vlSelf);
void VTop___024root___act_comb__TOP__0(VTop___024root* vlSelf);
void VTop___024root___act_comb__TOP__1(VTop___024root* vlSelf);
void VTop___024root___ico_comb__TOP__2(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((9ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___ico_comb__TOP__0(vlSelf);
    }
    if ((5ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0x11ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((0x21ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__4(vlSelf);
    }
    if ((7ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0x31ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0x3fULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___ico_comb__TOP__2(vlSelf);
    }
}

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf);

VL_ATTR_COLD bool VTop___024root___eval_phase__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VTop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VTop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 1 is active: @([hybrid] Top.mretSignal or [hybrid] Top.stallControl)\n");
    }
    if ((4ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 2 is active: @([hybrid] Top.stallControl)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] Top.readCSR)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] Top.mretSignal or [hybrid] Top.stallControl)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([hybrid] Top.stallControl)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([hybrid] Top.readAddress1)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([hybrid] Top.readAddress2)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] Top.readCSR)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] Top.mretSignal or [hybrid] Top.stallControl)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([hybrid] Top.stallControl)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([hybrid] Top.readAddress1)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([hybrid] Top.readAddress2)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___eval_postponed__TOP(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_postponed(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_postponed\n"); );
    // Body
    VTop___024root___eval_postponed__TOP(vlSelf);
}

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->__SYM__interrupt = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(1024, vlSelf->dbg_registers);
    vlSelf->dbg_IF_ID_Valid = VL_RAND_RESET_I(1);
    vlSelf->dbg_ID_EX_Valid = VL_RAND_RESET_I(1);
    vlSelf->dbg_EX_MEM_Valid = VL_RAND_RESET_I(1);
    vlSelf->dbg_MEM_WB_Valid = VL_RAND_RESET_I(1);
    vlSelf->dbg_IF_ID_programCounter = VL_RAND_RESET_I(32);
    vlSelf->dbg_IF_ID_instruction = VL_RAND_RESET_I(32);
    vlSelf->dbg_ID_EX_programCounter = VL_RAND_RESET_I(32);
    vlSelf->dbg_EX_MEM_programCounter = VL_RAND_RESET_I(32);
    vlSelf->dbg_MEM_WB_programCounter = VL_RAND_RESET_I(32);
    vlSelf->dbg_trap = VL_RAND_RESET_I(1);
    vlSelf->dbg_IMEM_data = VL_RAND_RESET_I(32);
    vlSelf->dbg_IMEM_valid = VL_RAND_RESET_I(1);
    vlSelf->dbg_pc = VL_RAND_RESET_I(32);
    vlSelf->dbg_wb_value = VL_RAND_RESET_I(32);
    vlSelf->forwardEnable1 = VL_RAND_RESET_I(1);
    vlSelf->forwardEnable2 = VL_RAND_RESET_I(1);
    vlSelf->forwardData1 = VL_RAND_RESET_I(32);
    vlSelf->forwardData2 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(1024, vlSelf->Top__DOT__debug_regs_flat);
    vlSelf->Top__DOT__instructionDataValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instructionData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__loadDataValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__storeComplete = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__fetchDecodeControl = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__decodeExecuteControl = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__executeMemoryControl = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__memoryWritebackControl = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__controlReset = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__mcause = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__readData1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__readData2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__csrReadData = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(97, vlSelf->Top__DOT__fetchDecodePayload);
    VL_RAND_RESET_W(212, vlSelf->Top__DOT__decodeExecutePayload);
    vlSelf->Top__DOT__readAddress1 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__readAddress2 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__decodeCombIllegal = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__branchValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__branchData = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(182, vlSelf->Top__DOT__executeMemoryPayload);
    vlSelf->Top__DOT__readCSR = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__mretSignal = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(113, vlSelf->Top__DOT__memoryWritebackPayload);
    vlSelf->Top__DOT__storeData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__realStoreByteEnable = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__storeValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__stallControl = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__destinationEnable = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__writeData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__csrDestinationEnable = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__dualValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__csrForwardData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__csrForwardEnable = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__csrFile__DOT____Vstrobe0 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__fetch__DOT__programCounter = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(212, vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__registerFile__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__execute__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__redirectAsserted = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__illegal = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__execute__DOT__branchValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__memory__DOT__illegal = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__memory__DOT__storeReq = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->Top__DOT__imem_inst__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->Top__DOT__dmem_inst__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__dmem_inst__DOT__storeValid_q = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk1__DOT__word = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readCSR__0 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__mretSignal__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__stallControl__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress1__0 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress2__0 = VL_RAND_RESET_I(5);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__mretSignal__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__stallControl__1 = VL_RAND_RESET_I(1);
    vlSelf->__VicoDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readCSR__1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__mretSignal__2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__stallControl__2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress1__1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress2__1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
