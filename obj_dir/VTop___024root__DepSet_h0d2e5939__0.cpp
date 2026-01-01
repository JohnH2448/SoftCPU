// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->Top__DOT__instructionDataValid = (1U & 
                                              (~ (IData)(vlSelf->reset)));
    vlSelf->Top__DOT__instructionData = ((IData)(vlSelf->reset)
                                          ? 0x13U : 
                                         vlSelf->Top__DOT__imem_inst__DOT__mem
                                         [(0x3ffU & 
                                           (vlSelf->dbg_pc 
                                            >> 2U))]);
    vlSelf->Top__DOT__controlReset = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_ID_EX_Valid) & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 1U))) {
            vlSelf->Top__DOT__controlReset = 1U;
        } else if (((IData)(vlSelf->dbg_MEM_WB_Valid) 
                    & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                       >> 1U))) {
            vlSelf->Top__DOT__controlReset = 1U;
        }
        vlSelf->Top__DOT__loadDataValid = 1U;
    } else {
        vlSelf->Top__DOT__loadDataValid = 0U;
    }
    vlSelf->dbg_IMEM_valid = vlSelf->Top__DOT__instructionDataValid;
    vlSelf->dbg_IMEM_data = vlSelf->Top__DOT__instructionData;
    vlSelf->dbg_trap = vlSelf->Top__DOT__controlReset;
}

VL_INLINE_OPT void VTop___024root___ico_comb__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_comb__TOP__0\n"); );
    // Init
    CData/*0:0*/ Top__DOT__stallControl;
    Top__DOT__stallControl = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__operand1;
    Top__DOT__execute__DOT__operand1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__operand2;
    Top__DOT__execute__DOT__operand2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__brOp1;
    Top__DOT__execute__DOT__brOp1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__brOp2;
    Top__DOT__execute__DOT__brOp2 = 0;
    CData/*3:0*/ Top__DOT__memory__DOT__storeByteEnable;
    Top__DOT__memory__DOT__storeByteEnable = 0;
    // Body
    Top__DOT__stallControl = (1U & (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                                     & ((~ ((IData)(vlSelf->Top__DOT__memory__DOT__illegal) 
                                            | (IData)(vlSelf->Top__DOT__memoryWritebackControl))) 
                                        & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                           >> 9U)))
                                     ? (~ (IData)(vlSelf->Top__DOT__loadDataValid))
                                     : ((IData)(vlSelf->Top__DOT__memory__DOT__storeReq) 
                                        | ((~ (IData)(vlSelf->Top__DOT__storeComplete)) 
                                           & (IData)(vlSelf->Top__DOT__storeValid)))));
    vlSelf->Top__DOT__memoryWritebackControl = 0U;
    vlSelf->Top__DOT__executeMemoryControl = 0U;
    Top__DOT__memory__DOT__storeByteEnable = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if ((1U & (~ ((IData)(vlSelf->dbg_ID_EX_Valid) 
                      & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                         >> 1U))))) {
            if (((IData)(vlSelf->dbg_MEM_WB_Valid) 
                 & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                    >> 1U))) {
                vlSelf->Top__DOT__memoryWritebackControl 
                    = (1U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
            }
        }
        if (Top__DOT__stallControl) {
            vlSelf->Top__DOT__memoryWritebackControl 
                = (2U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
        }
    }
    if ((1U & (IData)(((1U == (3U & vlSelf->Top__DOT__executeMemoryPayload[0U])) 
                       & (~ (IData)(vlSelf->Top__DOT__memoryWritebackControl)))))) {
        if ((0x100U & vlSelf->Top__DOT__executeMemoryPayload[2U])) {
            if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 6U)))) {
                Top__DOT__memory__DOT__storeByteEnable = 1U;
            } else if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                     >> 6U)))) {
                if ((1U & (~ (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                              >> 5U)))) {
                    Top__DOT__memory__DOT__storeByteEnable = 3U;
                }
            } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                     >> 6U)))) {
                if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                  >> 5U)))) {
                    Top__DOT__memory__DOT__storeByteEnable = 0xfU;
                }
            }
        }
    }
    Top__DOT__execute__DOT__operand1 = 0U;
    Top__DOT__execute__DOT__operand2 = 0U;
    vlSelf->Top__DOT__execute__DOT__result = 0U;
    vlSelf->Top__DOT__branchData = 0U;
    if ((0x100000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
        if ((0x80000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            Top__DOT__execute__DOT__operand1 = 0U;
            Top__DOT__execute__DOT__operand2 = ((vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                                 << 0xbU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                   >> 0x15U));
        } else {
            Top__DOT__execute__DOT__operand1 = ((vlSelf->Top__DOT__decodeExecutePayload[6U] 
                                                 << 0x1cU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[5U] 
                                                   >> 4U));
            Top__DOT__execute__DOT__operand2 = ((vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                                 << 0xbU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                   >> 0x15U));
        }
    } else if ((0x80000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
        Top__DOT__execute__DOT__operand1 = ((IData)(vlSelf->forwardEnable1)
                                             ? vlSelf->forwardData1
                                             : ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                                 << 0x1cU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                   >> 4U)));
        Top__DOT__execute__DOT__operand2 = ((vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                             << 0xbU) 
                                            | (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                               >> 0x15U));
    } else {
        Top__DOT__execute__DOT__operand1 = ((IData)(vlSelf->forwardEnable1)
                                             ? vlSelf->forwardData1
                                             : ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                                 << 0x1cU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                   >> 4U)));
        Top__DOT__execute__DOT__operand2 = ((IData)(vlSelf->forwardEnable2)
                                             ? vlSelf->forwardData2
                                             : ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                 << 0x1cU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                   >> 4U)));
    }
    if ((0x400U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
        if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                      >> 9U)))) {
            if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 8U)))) {
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((0x80U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                        ? ((Top__DOT__execute__DOT__operand1 
                            < Top__DOT__execute__DOT__operand2)
                            ? 1U : 0U) : (VL_LTS_III(32, Top__DOT__execute__DOT__operand1, Top__DOT__execute__DOT__operand2)
                                           ? 1U : 0U));
            }
        }
    } else {
        vlSelf->Top__DOT__execute__DOT__result = ((0x200U 
                                                   & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                   ? 
                                                  ((0x100U 
                                                    & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                    ? 
                                                   ((0x80U 
                                                     & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, Top__DOT__execute__DOT__operand1, 
                                                                   (0x1fU 
                                                                    & Top__DOT__execute__DOT__operand2))
                                                     : 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     >> 
                                                     (0x1fU 
                                                      & Top__DOT__execute__DOT__operand2)))
                                                    : 
                                                   ((0x80U 
                                                     & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                     ? 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     << 
                                                     (0x1fU 
                                                      & Top__DOT__execute__DOT__operand2))
                                                     : 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     ^ Top__DOT__execute__DOT__operand2)))
                                                   : 
                                                  ((0x100U 
                                                    & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                    ? 
                                                   ((0x80U 
                                                     & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                     ? 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     | Top__DOT__execute__DOT__operand2)
                                                     : 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     & Top__DOT__execute__DOT__operand2))
                                                    : 
                                                   ((0x80U 
                                                     & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                     ? 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     - Top__DOT__execute__DOT__operand2)
                                                     : 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     + Top__DOT__execute__DOT__operand2))));
    }
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_ID_EX_Valid) & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 1U))) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        } else if (((IData)(vlSelf->dbg_MEM_WB_Valid) 
                    & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                       >> 1U))) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        }
        if (Top__DOT__stallControl) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (2U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        }
    }
    if ((1U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
               & (~ (IData)(vlSelf->Top__DOT__executeMemoryControl))))) {
        if ((1U != (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 5U)))) {
            if ((2U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                              >> 5U)))) {
                vlSelf->Top__DOT__branchData = (0xfffffffeU 
                                                & vlSelf->Top__DOT__execute__DOT__result);
            }
        }
    }
    if ((2U != (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                      >> 5U)))) {
        vlSelf->Top__DOT__branchData = vlSelf->Top__DOT__execute__DOT__result;
    }
    vlSelf->Top__DOT__branchValid = 0U;
    Top__DOT__execute__DOT__brOp1 = ((IData)(vlSelf->forwardEnable1)
                                      ? vlSelf->forwardData1
                                      : ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                          << 0x1cU) 
                                         | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                            >> 4U)));
    Top__DOT__execute__DOT__brOp2 = ((IData)(vlSelf->forwardEnable2)
                                      ? vlSelf->forwardData2
                                      : ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                          << 0x1cU) 
                                         | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                            >> 4U)));
    if ((1U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
               & (~ (IData)(vlSelf->Top__DOT__executeMemoryControl))))) {
        if ((0x2000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            if ((0x1000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                              >> 0xbU)))) {
                    vlSelf->Top__DOT__branchValid = 
                        (Top__DOT__execute__DOT__brOp1 
                         >= Top__DOT__execute__DOT__brOp2);
                }
            } else {
                vlSelf->Top__DOT__branchValid = ((0x800U 
                                                  & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                  ? 
                                                 (Top__DOT__execute__DOT__brOp1 
                                                  < Top__DOT__execute__DOT__brOp2)
                                                  : 
                                                 VL_GTES_III(32, Top__DOT__execute__DOT__brOp1, Top__DOT__execute__DOT__brOp2));
            }
        } else if ((0x1000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            vlSelf->Top__DOT__branchValid = ((0x800U 
                                              & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                              ? VL_LTS_III(32, Top__DOT__execute__DOT__brOp1, Top__DOT__execute__DOT__brOp2)
                                              : (Top__DOT__execute__DOT__brOp1 
                                                 != Top__DOT__execute__DOT__brOp2));
        } else if ((0x800U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            vlSelf->Top__DOT__branchValid = (Top__DOT__execute__DOT__brOp1 
                                             == Top__DOT__execute__DOT__brOp2);
        }
        if ((1U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 5U)))) {
            vlSelf->Top__DOT__branchValid = 1U;
        } else if ((2U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                 >> 5U)))) {
            vlSelf->Top__DOT__branchValid = 1U;
        }
    } else {
        vlSelf->Top__DOT__branchValid = 0U;
    }
    if (vlSelf->Top__DOT__execute__DOT__redirectAsserted) {
        vlSelf->Top__DOT__branchValid = 0U;
    }
    vlSelf->Top__DOT__realStoreByteEnable = (0xfU & 
                                             ((IData)(Top__DOT__memory__DOT__storeByteEnable) 
                                              << (3U 
                                                  & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                     >> 5U))));
    vlSelf->Top__DOT__fetchDecodeControl = 0U;
    vlSelf->Top__DOT__decodeExecuteControl = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_ID_EX_Valid) & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 1U))) {
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
        } else if (((IData)(vlSelf->dbg_MEM_WB_Valid) 
                    & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                       >> 1U))) {
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
        } else if (vlSelf->Top__DOT__branchValid) {
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
        }
        if (Top__DOT__stallControl) {
            vlSelf->Top__DOT__fetchDecodeControl = 
                (2U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            vlSelf->Top__DOT__decodeExecuteControl 
                = (2U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
        }
    }
}

void VTop___024root___eval_ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VTop___024root___ico_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VicoTriggered.word(0U))) {
        VTop___024root___ico_comb__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_triggers__ico(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VTop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VTop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

VL_INLINE_OPT void VTop___024root___act_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->Top__DOT__readData1 = ((0U == (IData)(vlSelf->Top__DOT__readAddress1))
                                    ? 0U : vlSelf->Top__DOT__registerFile__DOT__registers
                                   [vlSelf->Top__DOT__readAddress1]);
}

VL_INLINE_OPT void VTop___024root___act_sequent__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_sequent__TOP__1\n"); );
    // Body
    vlSelf->Top__DOT__readData2 = ((0U == (IData)(vlSelf->Top__DOT__readAddress2))
                                    ? 0U : vlSelf->Top__DOT__registerFile__DOT__registers
                                   [vlSelf->Top__DOT__readAddress2]);
}

VL_INLINE_OPT void VTop___024root___act_sequent__TOP__2(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_sequent__TOP__2\n"); );
    // Init
    CData/*0:0*/ Top__DOT__stallControl;
    Top__DOT__stallControl = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__operand1;
    Top__DOT__execute__DOT__operand1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__operand2;
    Top__DOT__execute__DOT__operand2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__brOp1;
    Top__DOT__execute__DOT__brOp1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__brOp2;
    Top__DOT__execute__DOT__brOp2 = 0;
    CData/*0:0*/ Top__DOT__memory__DOT__storeConfirm;
    Top__DOT__memory__DOT__storeConfirm = 0;
    CData/*3:0*/ Top__DOT__memory__DOT__storeByteEnable;
    Top__DOT__memory__DOT__storeByteEnable = 0;
    // Body
    vlSelf->Top__DOT__memory__DOT__illegal = 0U;
    Top__DOT__memory__DOT__storeConfirm = 0U;
    if ((1U & (IData)(((1U == (3U & vlSelf->Top__DOT__executeMemoryPayload[0U])) 
                       & (~ (IData)(vlSelf->Top__DOT__memoryWritebackControl)))))) {
        if ((0x200U & vlSelf->Top__DOT__executeMemoryPayload[2U])) {
            if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 6U)))) {
                if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                  >> 6U)))) {
                    if ((0x20U & vlSelf->Top__DOT__executeMemoryPayload[1U])) {
                        vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                    }
                } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                         >> 6U)))) {
                    if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                      >> 5U)))) {
                        vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                }
            }
        }
        if ((0x100U & vlSelf->Top__DOT__executeMemoryPayload[2U])) {
            if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 6U)))) {
                if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                  >> 6U)))) {
                    if ((0x20U & vlSelf->Top__DOT__executeMemoryPayload[1U])) {
                        vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                    }
                } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                         >> 6U)))) {
                    if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                      >> 5U)))) {
                        vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                }
            }
            if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 6U)))) {
                Top__DOT__memory__DOT__storeConfirm = 1U;
            } else if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                     >> 6U)))) {
                if ((1U & (~ (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                              >> 5U)))) {
                    Top__DOT__memory__DOT__storeConfirm = 1U;
                }
            } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                     >> 6U)))) {
                if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                  >> 5U)))) {
                    Top__DOT__memory__DOT__storeConfirm = 1U;
                }
            }
        }
    }
    vlSelf->Top__DOT__memory__DOT__storeReq = ((~ (IData)(vlSelf->Top__DOT__storeValid)) 
                                               & (IData)(Top__DOT__memory__DOT__storeConfirm));
    Top__DOT__stallControl = (1U & (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                                     & ((~ ((IData)(vlSelf->Top__DOT__memory__DOT__illegal) 
                                            | (IData)(vlSelf->Top__DOT__memoryWritebackControl))) 
                                        & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                           >> 9U)))
                                     ? (~ (IData)(vlSelf->Top__DOT__loadDataValid))
                                     : ((IData)(vlSelf->Top__DOT__memory__DOT__storeReq) 
                                        | ((~ (IData)(vlSelf->Top__DOT__storeComplete)) 
                                           & (IData)(vlSelf->Top__DOT__storeValid)))));
    vlSelf->Top__DOT__memoryWritebackControl = 0U;
    vlSelf->Top__DOT__executeMemoryControl = 0U;
    Top__DOT__memory__DOT__storeByteEnable = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if ((1U & (~ ((IData)(vlSelf->dbg_ID_EX_Valid) 
                      & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                         >> 1U))))) {
            if (((IData)(vlSelf->dbg_MEM_WB_Valid) 
                 & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                    >> 1U))) {
                vlSelf->Top__DOT__memoryWritebackControl 
                    = (1U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
            }
        }
        if (Top__DOT__stallControl) {
            vlSelf->Top__DOT__memoryWritebackControl 
                = (2U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
        }
    }
    if ((1U & (IData)(((1U == (3U & vlSelf->Top__DOT__executeMemoryPayload[0U])) 
                       & (~ (IData)(vlSelf->Top__DOT__memoryWritebackControl)))))) {
        if ((0x100U & vlSelf->Top__DOT__executeMemoryPayload[2U])) {
            if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 6U)))) {
                Top__DOT__memory__DOT__storeByteEnable = 1U;
            } else if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                     >> 6U)))) {
                if ((1U & (~ (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                              >> 5U)))) {
                    Top__DOT__memory__DOT__storeByteEnable = 3U;
                }
            } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                     >> 6U)))) {
                if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                  >> 5U)))) {
                    Top__DOT__memory__DOT__storeByteEnable = 0xfU;
                }
            }
        }
    }
    Top__DOT__execute__DOT__operand1 = 0U;
    Top__DOT__execute__DOT__operand2 = 0U;
    vlSelf->Top__DOT__execute__DOT__result = 0U;
    vlSelf->Top__DOT__branchData = 0U;
    if ((0x100000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
        if ((0x80000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            Top__DOT__execute__DOT__operand1 = 0U;
            Top__DOT__execute__DOT__operand2 = ((vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                                 << 0xbU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                   >> 0x15U));
        } else {
            Top__DOT__execute__DOT__operand1 = ((vlSelf->Top__DOT__decodeExecutePayload[6U] 
                                                 << 0x1cU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[5U] 
                                                   >> 4U));
            Top__DOT__execute__DOT__operand2 = ((vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                                 << 0xbU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                   >> 0x15U));
        }
    } else if ((0x80000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
        Top__DOT__execute__DOT__operand1 = ((IData)(vlSelf->forwardEnable1)
                                             ? vlSelf->forwardData1
                                             : ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                                 << 0x1cU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                   >> 4U)));
        Top__DOT__execute__DOT__operand2 = ((vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                             << 0xbU) 
                                            | (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                               >> 0x15U));
    } else {
        Top__DOT__execute__DOT__operand1 = ((IData)(vlSelf->forwardEnable1)
                                             ? vlSelf->forwardData1
                                             : ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                                 << 0x1cU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                   >> 4U)));
        Top__DOT__execute__DOT__operand2 = ((IData)(vlSelf->forwardEnable2)
                                             ? vlSelf->forwardData2
                                             : ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                 << 0x1cU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                   >> 4U)));
    }
    if ((0x400U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
        if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                      >> 9U)))) {
            if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 8U)))) {
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((0x80U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                        ? ((Top__DOT__execute__DOT__operand1 
                            < Top__DOT__execute__DOT__operand2)
                            ? 1U : 0U) : (VL_LTS_III(32, Top__DOT__execute__DOT__operand1, Top__DOT__execute__DOT__operand2)
                                           ? 1U : 0U));
            }
        }
    } else {
        vlSelf->Top__DOT__execute__DOT__result = ((0x200U 
                                                   & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                   ? 
                                                  ((0x100U 
                                                    & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                    ? 
                                                   ((0x80U 
                                                     & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, Top__DOT__execute__DOT__operand1, 
                                                                   (0x1fU 
                                                                    & Top__DOT__execute__DOT__operand2))
                                                     : 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     >> 
                                                     (0x1fU 
                                                      & Top__DOT__execute__DOT__operand2)))
                                                    : 
                                                   ((0x80U 
                                                     & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                     ? 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     << 
                                                     (0x1fU 
                                                      & Top__DOT__execute__DOT__operand2))
                                                     : 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     ^ Top__DOT__execute__DOT__operand2)))
                                                   : 
                                                  ((0x100U 
                                                    & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                    ? 
                                                   ((0x80U 
                                                     & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                     ? 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     | Top__DOT__execute__DOT__operand2)
                                                     : 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     & Top__DOT__execute__DOT__operand2))
                                                    : 
                                                   ((0x80U 
                                                     & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                     ? 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     - Top__DOT__execute__DOT__operand2)
                                                     : 
                                                    (Top__DOT__execute__DOT__operand1 
                                                     + Top__DOT__execute__DOT__operand2))));
    }
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_ID_EX_Valid) & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 1U))) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        } else if (((IData)(vlSelf->dbg_MEM_WB_Valid) 
                    & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                       >> 1U))) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        }
        if (Top__DOT__stallControl) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (2U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        }
    }
    if ((1U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
               & (~ (IData)(vlSelf->Top__DOT__executeMemoryControl))))) {
        if ((1U != (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 5U)))) {
            if ((2U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                              >> 5U)))) {
                vlSelf->Top__DOT__branchData = (0xfffffffeU 
                                                & vlSelf->Top__DOT__execute__DOT__result);
            }
        }
    }
    if ((2U != (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                      >> 5U)))) {
        vlSelf->Top__DOT__branchData = vlSelf->Top__DOT__execute__DOT__result;
    }
    vlSelf->Top__DOT__branchValid = 0U;
    Top__DOT__execute__DOT__brOp1 = ((IData)(vlSelf->forwardEnable1)
                                      ? vlSelf->forwardData1
                                      : ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                          << 0x1cU) 
                                         | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                            >> 4U)));
    Top__DOT__execute__DOT__brOp2 = ((IData)(vlSelf->forwardEnable2)
                                      ? vlSelf->forwardData2
                                      : ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                          << 0x1cU) 
                                         | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                            >> 4U)));
    if ((1U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
               & (~ (IData)(vlSelf->Top__DOT__executeMemoryControl))))) {
        if ((0x2000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            if ((0x1000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                              >> 0xbU)))) {
                    vlSelf->Top__DOT__branchValid = 
                        (Top__DOT__execute__DOT__brOp1 
                         >= Top__DOT__execute__DOT__brOp2);
                }
            } else {
                vlSelf->Top__DOT__branchValid = ((0x800U 
                                                  & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                  ? 
                                                 (Top__DOT__execute__DOT__brOp1 
                                                  < Top__DOT__execute__DOT__brOp2)
                                                  : 
                                                 VL_GTES_III(32, Top__DOT__execute__DOT__brOp1, Top__DOT__execute__DOT__brOp2));
            }
        } else if ((0x1000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            vlSelf->Top__DOT__branchValid = ((0x800U 
                                              & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                              ? VL_LTS_III(32, Top__DOT__execute__DOT__brOp1, Top__DOT__execute__DOT__brOp2)
                                              : (Top__DOT__execute__DOT__brOp1 
                                                 != Top__DOT__execute__DOT__brOp2));
        } else if ((0x800U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            vlSelf->Top__DOT__branchValid = (Top__DOT__execute__DOT__brOp1 
                                             == Top__DOT__execute__DOT__brOp2);
        }
        if ((1U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 5U)))) {
            vlSelf->Top__DOT__branchValid = 1U;
        } else if ((2U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                 >> 5U)))) {
            vlSelf->Top__DOT__branchValid = 1U;
        }
    } else {
        vlSelf->Top__DOT__branchValid = 0U;
    }
    if (vlSelf->Top__DOT__execute__DOT__redirectAsserted) {
        vlSelf->Top__DOT__branchValid = 0U;
    }
    vlSelf->Top__DOT__realStoreByteEnable = (0xfU & 
                                             ((IData)(Top__DOT__memory__DOT__storeByteEnable) 
                                              << (3U 
                                                  & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                     >> 5U))));
    vlSelf->Top__DOT__fetchDecodeControl = 0U;
    vlSelf->Top__DOT__decodeExecuteControl = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_ID_EX_Valid) & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 1U))) {
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
        } else if (((IData)(vlSelf->dbg_MEM_WB_Valid) 
                    & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                       >> 1U))) {
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
        } else if (vlSelf->Top__DOT__branchValid) {
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
        }
        if (Top__DOT__stallControl) {
            vlSelf->Top__DOT__fetchDecodeControl = 
                (2U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            vlSelf->Top__DOT__decodeExecuteControl 
                = (2U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
        }
    }
}

VL_INLINE_OPT void VTop___024root___act_comb__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[3U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[4U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[5U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[6U] = 0U;
    vlSelf->Top__DOT__readAddress1 = 0U;
    vlSelf->Top__DOT__readAddress2 = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
        = ((0xfU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
           | (vlSelf->Top__DOT__readData2 << 4U));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[3U] 
        = ((vlSelf->Top__DOT__readData2 >> 0x1cU) | 
           (vlSelf->Top__DOT__readData1 << 4U));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[4U] 
        = ((vlSelf->Top__DOT__readData1 >> 0x1cU) | 
           ((IData)((((QData)((IData)(vlSelf->Top__DOT__fetchDecodePayload[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelf->Top__DOT__fetchDecodePayload[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelf->Top__DOT__fetchDecodePayload[0U])) 
                                                 >> 1U)))) 
            << 4U));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[5U] 
        = (((IData)((((QData)((IData)(vlSelf->Top__DOT__fetchDecodePayload[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelf->Top__DOT__fetchDecodePayload[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelf->Top__DOT__fetchDecodePayload[0U])) 
                                                 >> 1U)))) 
            >> 0x1cU) | ((IData)(((((QData)((IData)(
                                                    vlSelf->Top__DOT__fetchDecodePayload[2U])) 
                                    << 0x3fU) | (((QData)((IData)(
                                                                  vlSelf->Top__DOT__fetchDecodePayload[1U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->Top__DOT__fetchDecodePayload[0U])) 
                                                    >> 1U))) 
                                  >> 0x20U)) << 4U));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[6U] 
        = ((IData)(((((QData)((IData)(vlSelf->Top__DOT__fetchDecodePayload[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelf->Top__DOT__fetchDecodePayload[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelf->Top__DOT__fetchDecodePayload[0U])) 
                                                 >> 1U))) 
                    >> 0x20U)) >> 0x1cU);
    if ((0x80U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        if ((0x40U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            if ((0x20U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            } else if ((0x10U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                        if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                                = ((0xfc1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                                   | (0x3e00000U & 
                                      (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                       << 0xdU)));
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (0x100000U | (0xffe7ffffU 
                                                & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (0x2cU | (0xffffff83U 
                                            & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = ((0x1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                   | (0xffc00000U & 
                                      vlSelf->Top__DOT__fetchDecodePayload[2U]));
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                                = ((0xffe00000U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                                   | (0x1fffffU & (
                                                   (0x1ffc00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                                       << 0xaU)) 
                                                   | ((0x200U 
                                                       & (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                          << 9U)) 
                                                      | ((0x1feU 
                                                          & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                             >> 0xcU)) 
                                                         | (1U 
                                                            & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                               >> 0x15U)))))));
                        } else {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                        }
                    } else {
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                    }
                } else {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                }
            } else if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                        vlSelf->Top__DOT__readAddress1 
                            = (0x1fU & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                        >> 0x10U));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                            = ((0xfc1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                               | (0x3e00000U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                << 0xdU)));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (0x80000U | (0xffe7ffffU 
                                           & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (0x4cU | (0xffffff83U 
                                        & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = ((0x1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                               | (0xffe00000U & vlSelf->Top__DOT__fetchDecodePayload[2U]));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                            = ((0xffe00000U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                               | (0x1fffffU & ((0x1ffffeU 
                                                & ((- (IData)(
                                                              (1U 
                                                               & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                                   << 1U)) 
                                               | (1U 
                                                  & vlSelf->Top__DOT__fetchDecodePayload[3U]))));
                        if ((0U != (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                          >> 0xdU)))) {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                        }
                    } else {
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                    }
                } else {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                }
            } else if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    vlSelf->Top__DOT__readAddress1 
                        = (0x1fU & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                    >> 0x10U));
                    vlSelf->Top__DOT__readAddress2 
                        = (0x1fU & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                    >> 0x15U));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0x100000U | (0xffe7ffffU 
                                        & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = ((0x1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                           | (0xffe00000U & ((0xfc000000U 
                                              & vlSelf->Top__DOT__fetchDecodePayload[2U]) 
                                             | (0x3c00000U 
                                                & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                   << 0xdU)))));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = ((0xffe00000U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                           | (0x1fffffU & ((0x1ffffcU 
                                            & ((- (IData)(
                                                          (1U 
                                                           & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                               << 2U)) 
                                           | ((2U & 
                                               (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                << 1U)) 
                                              | (1U 
                                                 & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                    >> 8U))))));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = ((0x8000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? ((0xffffc7ffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                               | (((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                    ? ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                        ? 6U : 5U) : 
                                   ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                     ? 4U : 3U)) << 0xbU))
                            : ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                : ((0xffffc7ffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                   | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                        ? 2U : 1U) 
                                      << 0xbU))));
                } else {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                }
            } else {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            }
        } else {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        }
    } else if ((0x40U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        if ((0x20U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            if ((0x10U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            } else if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                            = ((0xfc1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                               | (0x3e00000U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                << 0xdU)));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (0x180000U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (4U | (0xffffffe3U & 
                                     vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (0x1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                            = ((0xffe00000U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                               | (0x1ffffeU & ((0x100000U 
                                                & (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                   << 0x14U)) 
                                               | (0xffffeU 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0xcU)))));
                    } else {
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                    }
                } else {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                }
            } else if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = ((0xfc1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                           | (0x3e00000U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                            << 0xdU)));
                    vlSelf->Top__DOT__readAddress1 
                        = (0x1fU & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                    >> 0x10U));
                    vlSelf->Top__DOT__readAddress2 
                        = (0x1fU & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                    >> 0x15U));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0xffe7ffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (4U | (0xffffffe3U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (((((((((0U == ((0x3f8U & 
                                           ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                             << 9U) 
                                            | (0x1f8U 
                                               & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                  >> 0x17U)))) 
                                          | (7U & (
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                   >> 0xdU)))) 
                                  | (0x100U == ((0x3f8U 
                                                 & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                     << 9U) 
                                                    | (0x1f8U 
                                                       & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                          >> 0x17U)))) 
                                                | (7U 
                                                   & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                      >> 0xdU))))) 
                                 | (7U == ((0x3f8U 
                                            & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                << 9U) 
                                               | (0x1f8U 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x17U)))) 
                                           | (7U & 
                                              (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                               >> 0xdU))))) 
                                | (6U == ((0x3f8U & 
                                           ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                             << 9U) 
                                            | (0x1f8U 
                                               & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                  >> 0x17U)))) 
                                          | (7U & (
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                   >> 0xdU))))) 
                               | (4U == ((0x3f8U & 
                                          ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                            << 9U) 
                                           | (0x1f8U 
                                              & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 >> 0x17U)))) 
                                         | (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                  >> 0xdU))))) 
                              | (1U == ((0x3f8U & (
                                                   (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                    << 9U) 
                                                   | (0x1f8U 
                                                      & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                         >> 0x17U)))) 
                                        | (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 >> 0xdU))))) 
                             | (5U == ((0x3f8U & ((
                                                   vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                   << 9U) 
                                                  | (0x1f8U 
                                                     & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                        >> 0x17U)))) 
                                       | (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                >> 0xdU))))) 
                            | (0x105U == ((0x3f8U & 
                                           ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                             << 9U) 
                                            | (0x1f8U 
                                               & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                  >> 0x17U)))) 
                                          | (7U & (
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                   >> 0xdU)))))
                            ? ((0xfffff87fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                               | (((0U == ((0x3f8U 
                                            & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                << 9U) 
                                               | (0x1f8U 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x17U)))) 
                                           | (7U & 
                                              (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                               >> 0xdU))))
                                    ? 0U : ((0x100U 
                                             == ((0x3f8U 
                                                  & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                      << 9U) 
                                                     | (0x1f8U 
                                                        & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                           >> 0x17U)))) 
                                                 | (7U 
                                                    & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                       >> 0xdU))))
                                             ? 1U : 
                                            ((7U == 
                                              ((0x3f8U 
                                                & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                    << 9U) 
                                                   | (0x1f8U 
                                                      & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                         >> 0x17U)))) 
                                               | (7U 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0xdU))))
                                              ? 2U : 
                                             ((6U == 
                                               ((0x3f8U 
                                                 & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                     << 9U) 
                                                    | (0x1f8U 
                                                       & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                          >> 0x17U)))) 
                                                | (7U 
                                                   & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                      >> 0xdU))))
                                               ? 3U
                                               : ((4U 
                                                   == 
                                                   ((0x3f8U 
                                                     & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                         << 9U) 
                                                        | (0x1f8U 
                                                           & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                              >> 0x17U)))) 
                                                    | (7U 
                                                       & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                          >> 0xdU))))
                                                   ? 4U
                                                   : 
                                                  ((1U 
                                                    == 
                                                    ((0x3f8U 
                                                      & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                          << 9U) 
                                                         | (0x1f8U 
                                                            & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                               >> 0x17U)))) 
                                                     | (7U 
                                                        & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                           >> 0xdU))))
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     ((0x3f8U 
                                                       & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                           << 9U) 
                                                          | (0x1f8U 
                                                             & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                                >> 0x17U)))) 
                                                      | (7U 
                                                         & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                            >> 0xdU))))
                                                     ? 6U
                                                     : 7U))))))) 
                                  << 7U)) : ((2U == 
                                              ((0x3f8U 
                                                & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                    << 9U) 
                                                   | (0x1f8U 
                                                      & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                         >> 0x17U)))) 
                                               | (7U 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0xdU))))
                                              ? (0x400U 
                                                 | (0xfffff87fU 
                                                    & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                              : ((3U 
                                                  == 
                                                  ((0x3f8U 
                                                    & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                        << 9U) 
                                                       | (0x1f8U 
                                                          & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                             >> 0x17U)))) 
                                                   | (7U 
                                                      & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                         >> 0xdU))))
                                                  ? 
                                                 (0x480U 
                                                  | (0xfffff87fU 
                                                     & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                                  : 
                                                 (2U 
                                                  | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))));
                } else {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                }
            } else {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            }
        } else if ((0x10U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        } else if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        } else if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (0x80000U | (0xffe7ffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                vlSelf->Top__DOT__readAddress1 = (0x1fU 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x10U));
                vlSelf->Top__DOT__readAddress2 = (0x1fU 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x15U));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = ((0x1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                       | (0xffe00000U & ((0xfc000000U 
                                          & vlSelf->Top__DOT__fetchDecodePayload[2U]) 
                                         | (0x3e00000U 
                                            & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                               << 0xdU)))));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = ((0xffe00000U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                       | (0x1fffffU & ((0x1ffffeU & 
                                        ((- (IData)(
                                                    (1U 
                                                     & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                         << 1U)) | 
                                       (1U & vlSelf->Top__DOT__fetchDecodePayload[3U]))));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (0x20000U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = ((0U == (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                     >> 0xdU))) ? (0xfffe7fffU 
                                                   & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                        : ((1U == (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                         >> 0xdU)))
                            ? (0x8000U | (0xfffe7fffU 
                                          & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                            : ((2U == (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                             >> 0xdU)))
                                ? (0x18000U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                : (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))));
            } else {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            }
        } else {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        }
    } else if ((0x20U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        if ((0x10U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        } else if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = ((0xfc1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                           | (0x3e00000U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                            << 0xdU)));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0x100000U | (0xffe7ffffU 
                                        & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (4U | (0xffffffe3U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0x1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = ((0xffe00000U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                           | (0x1ffffeU & ((0x100000U 
                                            & (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                               << 0x14U)) 
                                           | (0xffffeU 
                                              & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 >> 0xcU)))));
                } else {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                }
            } else {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            }
        } else if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = ((0xfc1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                       | (0x3e00000U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                        << 0xdU)));
                vlSelf->Top__DOT__readAddress1 = (0x1fU 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x10U));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (0x80000U | (0xffe7ffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (4U | (0xffffffe3U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = ((0x1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                       | (0xffe00000U & vlSelf->Top__DOT__fetchDecodePayload[2U]));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = ((0xffe00000U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                       | (0x1fffffU & ((0x1ffffeU & 
                                        ((- (IData)(
                                                    (1U 
                                                     & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                         << 1U)) | 
                                       (1U & vlSelf->Top__DOT__fetchDecodePayload[3U]))));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = ((0x8000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                        ? ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? ((0xfffff87fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                               | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                    ? 2U : 3U) << 7U))
                            : ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? ((0U == (0x7fU & 
                                           ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                             << 6U) 
                                            | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                               >> 0x1aU))))
                                    ? (0x300U | (0xfffff87fU 
                                                 & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                    : ((0x20U == (0x7fU 
                                                  & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                      << 6U) 
                                                     | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                        >> 0x1aU))))
                                        ? (0x380U | 
                                           (0xfffff87fU 
                                            & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                        : (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])))
                                : (0x200U | (0xfffff87fU 
                                             & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))))
                        : ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? ((0xfffff87fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                               | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                    ? 9U : 8U) << 7U))
                            : ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? ((0U == (0x7fU & 
                                           ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                             << 6U) 
                                            | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                               >> 0x1aU))))
                                    ? (0x280U | (0xfffff87fU 
                                                 & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                    : (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                : (0xfffff87fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))));
            } else {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            }
        } else {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        }
    } else if ((0x10U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((1U & (~ (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                              >> 1U)))) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                }
            } else {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            }
        } else {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        }
    } else if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
            = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
    } else if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                = ((0xfc1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                   | (0x3e00000U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                    << 0xdU)));
            vlSelf->Top__DOT__readAddress1 = (0x1fU 
                                              & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 >> 0x10U));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (0x80000U | (0xffe7ffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (8U | (0xffffffe3U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = ((0x1fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                   | (0xffe00000U & vlSelf->Top__DOT__fetchDecodePayload[2U]));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                = ((0xffe00000U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                   | (0x1fffffU & ((0x1ffffeU & ((- (IData)(
                                                            (1U 
                                                             & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                                 << 1U)) 
                                   | (1U & vlSelf->Top__DOT__fetchDecodePayload[3U]))));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (0x40000U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = ((0x8000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                    ? ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                        ? (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                        : ((0xfffe3fffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                           | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? 2U : 0U) << 0xeU)))
                    : ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                        ? ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                            : (0x1c000U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                        : ((0xfffe3fffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                           | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? 3U : 1U) << 0xeU))));
        } else {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        }
    } else {
        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
            = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
    }
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
        = ((0x3ffffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
           | (0xfc000000U & (((IData)(vlSelf->Top__DOT__readAddress1) 
                              << 0x1fU) | ((IData)(vlSelf->Top__DOT__readAddress2) 
                                           << 0x1aU))));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
        = ((0xfffffff0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
           | (0x3ffffffU & ((0x3ffffffU & ((IData)(vlSelf->Top__DOT__readAddress1) 
                                           >> 1U)) 
                            | ((IData)(vlSelf->Top__DOT__readAddress2) 
                               >> 6U))));
}

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((6ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__Top__DOT__fetch__DOT__programCounter;
    __Vdly__Top__DOT__fetch__DOT__programCounter = 0;
    CData/*4:0*/ __Vdlyvdim0__Top__DOT__registerFile__DOT__registers__v0;
    __Vdlyvdim0__Top__DOT__registerFile__DOT__registers__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__registerFile__DOT__registers__v0;
    __Vdlyvval__Top__DOT__registerFile__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__registerFile__DOT__registers__v0;
    __Vdlyvset__Top__DOT__registerFile__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdly__Top__DOT__execute__DOT__redirectAsserted;
    __Vdly__Top__DOT__execute__DOT__redirectAsserted = 0;
    CData/*0:0*/ __Vdly__Top__DOT__storeValid;
    __Vdly__Top__DOT__storeValid = 0;
    SData/*9:0*/ __Vdlyvdim0__Top__DOT__dmem_inst__DOT__mem__v0;
    __Vdlyvdim0__Top__DOT__dmem_inst__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__dmem_inst__DOT__mem__v0;
    __Vdlyvval__Top__DOT__dmem_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0;
    __Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0 = 0;
    // Body
    __Vdly__Top__DOT__fetch__DOT__programCounter = vlSelf->Top__DOT__fetch__DOT__programCounter;
    __Vdly__Top__DOT__execute__DOT__redirectAsserted 
        = vlSelf->Top__DOT__execute__DOT__redirectAsserted;
    __Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0 = 0U;
    __Vdly__Top__DOT__storeValid = vlSelf->Top__DOT__storeValid;
    __Vdlyvset__Top__DOT__registerFile__DOT__registers__v0 = 0U;
    if (vlSelf->Top__DOT__destinationEnable) {
        if ((0U != (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                             >> 3U)))) {
            __Vdlyvval__Top__DOT__registerFile__DOT__registers__v0 
                = ((vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                    << 0x1dU) | (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                 >> 3U));
            __Vdlyvset__Top__DOT__registerFile__DOT__registers__v0 = 1U;
            __Vdlyvdim0__Top__DOT__registerFile__DOT__registers__v0 
                = (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                            >> 3U));
        }
    }
    if (vlSelf->reset) {
        __Vdly__Top__DOT__fetch__DOT__programCounter = 0U;
        __Vdly__Top__DOT__execute__DOT__redirectAsserted = 0U;
    } else {
        if (vlSelf->Top__DOT__controlReset) {
            __Vdly__Top__DOT__fetch__DOT__programCounter = 0U;
        } else if (vlSelf->Top__DOT__branchValid) {
            __Vdly__Top__DOT__fetch__DOT__programCounter 
                = vlSelf->Top__DOT__branchData;
        } else if ((1U & (~ ((IData)(vlSelf->Top__DOT__fetchDecodeControl) 
                             >> 1U)))) {
            if (vlSelf->Top__DOT__instructionDataValid) {
                __Vdly__Top__DOT__fetch__DOT__programCounter 
                    = ((IData)(4U) + vlSelf->Top__DOT__fetch__DOT__programCounter);
            }
        }
        if ((((IData)(vlSelf->Top__DOT__branchValid) 
              & ((IData)(vlSelf->Top__DOT__executeMemoryControl) 
                 >> 1U)) & (~ (IData)(vlSelf->Top__DOT__execute__DOT__redirectAsserted)))) {
            __Vdly__Top__DOT__execute__DOT__redirectAsserted = 1U;
        }
        if ((IData)((2U != (IData)(vlSelf->Top__DOT__executeMemoryControl)))) {
            __Vdly__Top__DOT__execute__DOT__redirectAsserted = 0U;
        }
    }
    vlSelf->Top__DOT__execute__DOT__redirectAsserted 
        = __Vdly__Top__DOT__execute__DOT__redirectAsserted;
    if (__Vdlyvset__Top__DOT__registerFile__DOT__registers__v0) {
        vlSelf->Top__DOT__registerFile__DOT__registers[__Vdlyvdim0__Top__DOT__registerFile__DOT__registers__v0] 
            = __Vdlyvval__Top__DOT__registerFile__DOT__registers__v0;
    }
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
    if (vlSelf->reset) {
        __Vdly__Top__DOT__storeValid = 0U;
        vlSelf->Top__DOT__storeComplete = 0U;
        vlSelf->Top__DOT__memoryWritebackPayload[0U] = 0U;
        vlSelf->Top__DOT__memoryWritebackPayload[1U] = 0U;
        vlSelf->Top__DOT__memoryWritebackPayload[2U] = 0U;
    } else {
        if ((1U & (((~ (IData)(vlSelf->Top__DOT__storeValid)) 
                    & (~ (IData)(vlSelf->Top__DOT__memory__DOT__illegal))) 
                   & (~ (IData)(vlSelf->Top__DOT__memoryWritebackControl))))) {
            __Vdly__Top__DOT__storeValid = vlSelf->Top__DOT__memory__DOT__storeReq;
        } else if (vlSelf->Top__DOT__storeComplete) {
            __Vdly__Top__DOT__storeValid = 0U;
        }
        vlSelf->Top__DOT__storeComplete = 0U;
        if (((IData)(vlSelf->Top__DOT__storeValid) 
             & (~ (IData)(vlSelf->Top__DOT__dmem_inst__DOT__storeValid_q)))) {
            vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__idx 
                = (0x3ffU & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                             >> 7U));
            vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word 
                = vlSelf->Top__DOT__dmem_inst__DOT__mem
                [(0x3ffU & vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__idx)];
            vlSelf->Top__DOT__storeComplete = 1U;
            if ((1U & (IData)(vlSelf->Top__DOT__realStoreByteEnable))) {
                vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word 
                    = ((0xffffff00U & vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word) 
                       | (0xffU & vlSelf->Top__DOT__storeData));
            }
            if ((2U & (IData)(vlSelf->Top__DOT__realStoreByteEnable))) {
                vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word 
                    = ((0xffff00ffU & vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word) 
                       | (0xff00U & vlSelf->Top__DOT__storeData));
            }
            if ((4U & (IData)(vlSelf->Top__DOT__realStoreByteEnable))) {
                vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word 
                    = ((0xff00ffffU & vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word) 
                       | (0xff0000U & vlSelf->Top__DOT__storeData));
            }
            if ((8U & (IData)(vlSelf->Top__DOT__realStoreByteEnable))) {
                vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word 
                    = ((0xffffffU & vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word) 
                       | (0xff000000U & vlSelf->Top__DOT__storeData));
            }
            __Vdlyvval__Top__DOT__dmem_inst__DOT__mem__v0 
                = vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word;
            __Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0 = 1U;
            __Vdlyvdim0__Top__DOT__dmem_inst__DOT__mem__v0 
                = (0x3ffU & vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__idx);
        }
        if ((1U & (IData)(vlSelf->Top__DOT__memoryWritebackControl))) {
            vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                = (0xfffffffeU & vlSelf->Top__DOT__memoryWritebackPayload[0U]);
        } else if ((1U & (~ ((IData)(vlSelf->Top__DOT__memoryWritebackControl) 
                             >> 1U)))) {
            if ((0x10U & vlSelf->Top__DOT__executeMemoryPayload[0U])) {
                vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                    = (0xfffffffbU & vlSelf->Top__DOT__memoryWritebackPayload[0U]);
            } else if ((8U & vlSelf->Top__DOT__executeMemoryPayload[0U])) {
                if ((4U & vlSelf->Top__DOT__executeMemoryPayload[0U])) {
                    vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                        = ((3U & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                           | ((IData)((1ULL | ((QData)((IData)(
                                                               ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                                 << 0x11U) 
                                                                | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                                   >> 0xfU)))) 
                                               << 1U))) 
                              << 2U));
                    vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                        = ((0xfffffff8U & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                           | (((IData)((1ULL | ((QData)((IData)(
                                                                ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                                  << 0x11U) 
                                                                 | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                                    >> 0xfU)))) 
                                                << 1U))) 
                               >> 0x1eU) | ((IData)(
                                                    ((1ULL 
                                                      | ((QData)((IData)(
                                                                         ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                                           << 0x11U) 
                                                                          | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                                             >> 0xfU)))) 
                                                         << 1U)) 
                                                     >> 0x20U)) 
                                            << 2U)));
                } else {
                    if (((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                          >> 9U) & (IData)(vlSelf->Top__DOT__loadDataValid))) {
                        vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                            = ((IData)(vlSelf->reset)
                                ? 0U : vlSelf->Top__DOT__dmem_inst__DOT__mem
                               [(0x3ffU & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                           >> 7U))]);
                        if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                          >> 6U)))) {
                            vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b 
                                = (0xffU & (vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                                            >> (0x18U 
                                                & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                   >> 2U))));
                            vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                = ((7U & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                                   | (((0x20U & vlSelf->Top__DOT__executeMemoryPayload[2U])
                                        ? (((- (IData)(
                                                       (1U 
                                                        & ((IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b) 
                                                           >> 7U)))) 
                                            << 8U) 
                                           | (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b))
                                        : (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b)) 
                                      << 3U));
                            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                = ((0xfffffff8U & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                                   | (((0x20U & vlSelf->Top__DOT__executeMemoryPayload[2U])
                                        ? (((- (IData)(
                                                       (1U 
                                                        & ((IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b) 
                                                           >> 7U)))) 
                                            << 8U) 
                                           | (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b))
                                        : (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b)) 
                                      >> 0x1dU));
                        } else if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                 >> 6U)))) {
                            vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h 
                                = (0xffffU & (vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                                              >> (0x10U 
                                                  & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                     >> 2U))));
                            vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                = ((7U & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                                   | (((0x20U & vlSelf->Top__DOT__executeMemoryPayload[2U])
                                        ? (((- (IData)(
                                                       (1U 
                                                        & ((IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h) 
                                                           >> 0xfU)))) 
                                            << 0x10U) 
                                           | (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h))
                                        : (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h)) 
                                      << 3U));
                            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                = ((0xfffffff8U & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                                   | (((0x20U & vlSelf->Top__DOT__executeMemoryPayload[2U])
                                        ? (((- (IData)(
                                                       (1U 
                                                        & ((IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h) 
                                                           >> 0xfU)))) 
                                            << 0x10U) 
                                           | (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h))
                                        : (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h)) 
                                      >> 0x1dU));
                        } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                 >> 6U)))) {
                            vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                = ((7U & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                                   | (vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                                      << 3U));
                            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                = ((0xfffffff8U & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                                   | (vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                                      >> 0x1dU));
                        }
                    }
                    vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                        = ((0xfffffffbU & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                           | (0x1fffffcU & ((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                             >> 7U) 
                                            & ((IData)(vlSelf->Top__DOT__loadDataValid) 
                                               << 2U))));
                }
            } else if ((4U & vlSelf->Top__DOT__executeMemoryPayload[0U])) {
                vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                    = ((3U & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                       | ((IData)((1ULL | ((QData)((IData)(
                                                           ((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                             << 0x1bU) 
                                                            | (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                               >> 5U)))) 
                                           << 1U))) 
                          << 2U));
                vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                    = ((0xfffffff8U & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                       | (((IData)((1ULL | ((QData)((IData)(
                                                            ((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                              << 0x1bU) 
                                                             | (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                                >> 5U)))) 
                                            << 1U))) 
                           >> 0x1eU) | ((IData)(((1ULL 
                                                  | ((QData)((IData)(
                                                                     ((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                                       << 0x1bU) 
                                                                      | (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                                         >> 5U)))) 
                                                     << 1U)) 
                                                 >> 0x20U)) 
                                        << 2U)));
            } else {
                vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                    = (0xfffffffbU & vlSelf->Top__DOT__memoryWritebackPayload[0U]);
            }
            vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                = ((0xfffffffcU & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                   | ((2U & (((IData)(vlSelf->Top__DOT__memory__DOT__illegal) 
                              << 1U) | (0xfffffffeU 
                                        & vlSelf->Top__DOT__executeMemoryPayload[0U]))) 
                      | (1U & vlSelf->Top__DOT__executeMemoryPayload[0U])));
            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                = ((7U & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                   | ((IData)((((QData)((IData)(((vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                                  << 0x11U) 
                                                 | (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                    >> 0xfU)))) 
                                << 5U) | (QData)((IData)(
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                             >> 0xaU)))))) 
                      << 3U));
            vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                = (0xffU & (((IData)((((QData)((IData)(
                                                       ((vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                                         << 0x11U) 
                                                        | (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                           >> 0xfU)))) 
                                       << 5U) | (QData)((IData)(
                                                                (0x1fU 
                                                                 & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                                    >> 0xaU)))))) 
                             >> 0x1dU) | ((IData)((
                                                   (((QData)((IData)(
                                                                     ((vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                                                       << 0x11U) 
                                                                      | (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                                         >> 0xfU)))) 
                                                     << 5U) 
                                                    | (QData)((IData)(
                                                                      (0x1fU 
                                                                       & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                                          >> 0xaU))))) 
                                                   >> 0x20U)) 
                                          << 3U)));
        }
    }
    if (__Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0) {
        vlSelf->Top__DOT__dmem_inst__DOT__mem[__Vdlyvdim0__Top__DOT__dmem_inst__DOT__mem__v0] 
            = __Vdlyvval__Top__DOT__dmem_inst__DOT__mem__v0;
    }
    vlSelf->Top__DOT__dmem_inst__DOT__storeValid_q 
        = ((1U & (~ (IData)(vlSelf->reset))) && (IData)(vlSelf->Top__DOT__storeValid));
    vlSelf->dbg_MEM_WB_programCounter = ((vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                          << 0x18U) 
                                         | (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                            >> 8U));
    vlSelf->dbg_MEM_WB_Valid = (1U & vlSelf->Top__DOT__memoryWritebackPayload[0U]);
    vlSelf->Top__DOT__storeValid = __Vdly__Top__DOT__storeValid;
    vlSelf->Top__DOT__destinationEnable = ((IData)(vlSelf->dbg_MEM_WB_Valid) 
                                           & (IData)(
                                                     (4U 
                                                      == 
                                                      (6U 
                                                       & vlSelf->Top__DOT__memoryWritebackPayload[0U]))));
    vlSelf->dbg_wb_value = ((IData)(vlSelf->Top__DOT__destinationEnable)
                             ? ((vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                 << 0x1dU) | (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                              >> 3U))
                             : 0U);
    if (vlSelf->reset) {
        vlSelf->Top__DOT__executeMemoryPayload[0U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[1U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[2U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[3U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[4U] = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__executeMemoryControl))) {
        vlSelf->Top__DOT__executeMemoryPayload[0U] 
            = (0xfffffffeU & vlSelf->Top__DOT__executeMemoryPayload[0U]);
    } else if ((1U & (~ ((IData)(vlSelf->Top__DOT__executeMemoryControl) 
                         >> 1U)))) {
        vlSelf->Top__DOT__executeMemoryPayload[2U] 
            = ((0x1ffU & vlSelf->Top__DOT__executeMemoryPayload[2U]) 
               | (((IData)((((QData)((IData)(vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                             << 0x3cU) | (((QData)((IData)(
                                                           vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                           << 0x1cU) 
                                          | ((QData)((IData)(
                                                             vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                             >> 4U)))) 
                   << 0xfU) | ((0x7c00U & (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                           >> 0xbU)) 
                               | (0x200U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                            >> 9U)))));
        vlSelf->Top__DOT__executeMemoryPayload[3U] 
            = ((0x1ffU & ((IData)((((QData)((IData)(
                                                    vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                    << 0x3cU) | (((QData)((IData)(
                                                                  vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                  << 0x1cU) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                    >> 4U)))) 
                          >> 0x11U)) | ((0x7e00U & 
                                         ((IData)((
                                                   ((QData)((IData)(
                                                                    vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                                    << 0x3cU) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                       << 0x1cU) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                         >> 4U)))) 
                                          >> 0x11U)) 
                                        | ((IData)(
                                                   ((((QData)((IData)(
                                                                      vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                                      << 0x3cU) 
                                                     | (((QData)((IData)(
                                                                         vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                         << 0x1cU) 
                                                        | ((QData)((IData)(
                                                                           vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                           >> 4U))) 
                                                    >> 0x20U)) 
                                           << 0xfU)));
        vlSelf->Top__DOT__executeMemoryPayload[4U] 
            = (0x7fffU & ((0x1ffU & ((IData)(((((QData)((IData)(
                                                                vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                                << 0x3cU) 
                                               | (((QData)((IData)(
                                                                   vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                   << 0x1cU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                     >> 4U))) 
                                              >> 0x20U)) 
                                     >> 0x11U)) | (0x7e00U 
                                                   & ((IData)(
                                                              ((((QData)((IData)(
                                                                                vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                                                 << 0x3cU) 
                                                                | (((QData)((IData)(
                                                                                vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                                    << 0x1cU) 
                                                                   | ((QData)((IData)(
                                                                                vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                                      >> 4U))) 
                                                               >> 0x20U)) 
                                                      >> 0x11U))));
        vlSelf->Top__DOT__executeMemoryPayload[0U] 
            = ((0x1fU & vlSelf->Top__DOT__executeMemoryPayload[0U]) 
               | ((IData)((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result)) 
                            << 0x20U) | (QData)((IData)(
                                                        ((IData)(vlSelf->forwardEnable2)
                                                          ? vlSelf->forwardData2
                                                          : 
                                                         ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                           << 0x1cU) 
                                                          | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                             >> 4U))))))) 
                  << 5U));
        vlSelf->Top__DOT__executeMemoryPayload[1U] 
            = (((IData)((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result)) 
                          << 0x20U) | (QData)((IData)(
                                                      ((IData)(vlSelf->forwardEnable2)
                                                        ? vlSelf->forwardData2
                                                        : 
                                                       ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                         << 0x1cU) 
                                                        | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                           >> 4U))))))) 
                >> 0x1bU) | ((IData)(((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result)) 
                                        << 0x20U) | (QData)((IData)(
                                                                    ((IData)(vlSelf->forwardEnable2)
                                                                      ? vlSelf->forwardData2
                                                                      : 
                                                                     ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                                       << 0x1cU) 
                                                                      | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                                         >> 4U)))))) 
                                      >> 0x20U)) << 5U));
        vlSelf->Top__DOT__executeMemoryPayload[2U] 
            = ((0xfffffe00U & vlSelf->Top__DOT__executeMemoryPayload[2U]) 
               | (((IData)(((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((IData)(vlSelf->forwardEnable2)
                                                            ? vlSelf->forwardData2
                                                            : 
                                                           ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                             << 0x1cU) 
                                                            | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                               >> 4U)))))) 
                            >> 0x20U)) >> 0x1bU) | 
                  (0x1e0U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                             >> 9U))));
        vlSelf->Top__DOT__executeMemoryPayload[0U] 
            = ((0xffffffe0U & vlSelf->Top__DOT__executeMemoryPayload[0U]) 
               | (0x1fU & vlSelf->Top__DOT__decodeExecutePayload[0U]));
    }
    vlSelf->dbg_EX_MEM_programCounter = ((vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                          << 0x11U) 
                                         | (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                            >> 0xfU));
    vlSelf->Top__DOT__storeData = (((vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                     << 0x1bU) | (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                  >> 5U)) 
                                   << (0x18U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                >> 2U)));
    vlSelf->dbg_EX_MEM_Valid = (1U & vlSelf->Top__DOT__executeMemoryPayload[0U]);
    if (vlSelf->reset) {
        vlSelf->Top__DOT__decodeExecutePayload[0U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[1U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[2U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[3U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[4U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[5U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[6U] = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__decodeExecuteControl))) {
        vlSelf->Top__DOT__decodeExecutePayload[0U] 
            = (0xfffffffeU & vlSelf->Top__DOT__decodeExecutePayload[0U]);
    } else if ((1U & (~ ((IData)(vlSelf->Top__DOT__decodeExecuteControl) 
                         >> 1U)))) {
        if ((0U == ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                     << 0x1fU) | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                  >> 1U)))) {
            vlSelf->Top__DOT__decodeExecutePayload[0U] 
                = (0xfffffffeU & vlSelf->Top__DOT__decodeExecutePayload[0U]);
            vlSelf->Top__DOT__decodeExecutePayload[0U] = 0U;
            vlSelf->Top__DOT__decodeExecutePayload[1U] = 0U;
            vlSelf->Top__DOT__decodeExecutePayload[2U] = 0U;
            vlSelf->Top__DOT__decodeExecutePayload[3U] = 0U;
            vlSelf->Top__DOT__decodeExecutePayload[4U] = 0U;
            vlSelf->Top__DOT__decodeExecutePayload[5U] = 0U;
            vlSelf->Top__DOT__decodeExecutePayload[6U] = 0U;
        } else {
            vlSelf->Top__DOT__decodeExecutePayload[0U] 
                = vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U];
            vlSelf->Top__DOT__decodeExecutePayload[1U] 
                = vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U];
            vlSelf->Top__DOT__decodeExecutePayload[2U] 
                = vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U];
            vlSelf->Top__DOT__decodeExecutePayload[3U] 
                = vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[3U];
            vlSelf->Top__DOT__decodeExecutePayload[4U] 
                = vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[4U];
            vlSelf->Top__DOT__decodeExecutePayload[5U] 
                = vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[5U];
            vlSelf->Top__DOT__decodeExecutePayload[6U] 
                = vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[6U];
            vlSelf->Top__DOT__decodeExecutePayload[0U] 
                = ((0xfffffffeU & vlSelf->Top__DOT__decodeExecutePayload[0U]) 
                   | (1U & vlSelf->Top__DOT__fetchDecodePayload[0U]));
        }
    }
    if ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__controlReset))))) {
        if ((1U & (IData)(vlSelf->Top__DOT__fetchDecodeControl))) {
            vlSelf->Top__DOT__fetchDecodePayload[0U] 
                = (0xfffffffeU & vlSelf->Top__DOT__fetchDecodePayload[0U]);
        } else if (((~ ((IData)(vlSelf->Top__DOT__fetchDecodeControl) 
                        >> 1U)) & (IData)(vlSelf->Top__DOT__instructionDataValid))) {
            vlSelf->Top__DOT__fetchDecodePayload[0U] 
                = (1U | (((IData)(4U) + vlSelf->Top__DOT__fetch__DOT__programCounter) 
                         << 1U));
            vlSelf->Top__DOT__fetchDecodePayload[1U] 
                = ((((IData)(4U) + vlSelf->Top__DOT__fetch__DOT__programCounter) 
                    >> 0x1fU) | ((IData)((((QData)((IData)(vlSelf->Top__DOT__instructionData)) 
                                           << 0x20U) 
                                          | (QData)((IData)(vlSelf->Top__DOT__fetch__DOT__programCounter)))) 
                                 << 1U));
            vlSelf->Top__DOT__fetchDecodePayload[2U] 
                = (((IData)((((QData)((IData)(vlSelf->Top__DOT__instructionData)) 
                              << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__fetch__DOT__programCounter)))) 
                    >> 0x1fU) | ((IData)(((((QData)((IData)(vlSelf->Top__DOT__instructionData)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelf->Top__DOT__fetch__DOT__programCounter))) 
                                          >> 0x20U)) 
                                 << 1U));
            vlSelf->Top__DOT__fetchDecodePayload[3U] 
                = ((IData)(((((QData)((IData)(vlSelf->Top__DOT__instructionData)) 
                              << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__fetch__DOT__programCounter))) 
                            >> 0x20U)) >> 0x1fU);
        } else if ((1U & ((~ ((IData)(vlSelf->Top__DOT__fetchDecodeControl) 
                              >> 1U)) & (~ (IData)(vlSelf->Top__DOT__instructionDataValid))))) {
            vlSelf->Top__DOT__fetchDecodePayload[0U] 
                = (0xfffffffeU & vlSelf->Top__DOT__fetchDecodePayload[0U]);
        }
    } else {
        vlSelf->Top__DOT__fetchDecodePayload[0U] = 0U;
        vlSelf->Top__DOT__fetchDecodePayload[1U] = 0U;
        vlSelf->Top__DOT__fetchDecodePayload[2U] = 0U;
        vlSelf->Top__DOT__fetchDecodePayload[3U] = 0U;
    }
    vlSelf->dbg_ID_EX_programCounter = ((vlSelf->Top__DOT__decodeExecutePayload[6U] 
                                         << 0x1cU) 
                                        | (vlSelf->Top__DOT__decodeExecutePayload[5U] 
                                           >> 4U));
    vlSelf->forwardEnable1 = 0U;
    vlSelf->forwardEnable2 = 0U;
    vlSelf->forwardData1 = 0U;
    if ((0U != (0x1fU & ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                          << 1U) | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                    >> 0x1fU))))) {
        if (((((IData)(vlSelf->dbg_EX_MEM_Valid) & 
               ((0U != (7U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                              >> 2U))) & (2U != (7U 
                                                 & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                    >> 2U))))) 
              & (0U != (0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                 >> 0xaU)))) & ((0x1fU 
                                                 & ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                     << 1U) 
                                                    | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                                       >> 0x1fU))) 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                    >> 0xaU))))) {
            vlSelf->forwardEnable1 = 1U;
            vlSelf->forwardData1 = ((1U == (7U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                  >> 2U)))
                                     ? ((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                         << 0x1bU) 
                                        | (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                           >> 5U)) : 
                                    ((3U == (7U & (
                                                   vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                   >> 2U)))
                                      ? ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                          << 0x11U) 
                                         | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                            >> 0xfU))
                                      : 0U));
        } else if (((((IData)(vlSelf->dbg_MEM_WB_Valid) 
                      & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                         >> 2U)) & (0U != (0x1fU & 
                                           (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                            >> 3U)))) 
                    & ((0x1fU & ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                  << 1U) | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                            >> 0x1fU))) 
                       == (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                    >> 3U))))) {
            vlSelf->forwardEnable1 = 1U;
            vlSelf->forwardData1 = ((vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                     << 0x1dU) | (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                                  >> 3U));
        }
    }
    vlSelf->forwardData2 = 0U;
    if ((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                         >> 0x1aU)))) {
        if (((((IData)(vlSelf->dbg_EX_MEM_Valid) & 
               ((0U != (7U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                              >> 2U))) & (2U != (7U 
                                                 & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                    >> 2U))))) 
              & (0U != (0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                 >> 0xaU)))) & ((0x1fU 
                                                 & (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                                    >> 0x1aU)) 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                    >> 0xaU))))) {
            vlSelf->forwardEnable2 = 1U;
            vlSelf->forwardData2 = ((1U == (7U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                  >> 2U)))
                                     ? ((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                         << 0x1bU) 
                                        | (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                           >> 5U)) : 
                                    ((3U == (7U & (
                                                   vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                                   >> 2U)))
                                      ? ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                          << 0x11U) 
                                         | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                            >> 0xfU))
                                      : 0U));
        } else if (((((IData)(vlSelf->dbg_MEM_WB_Valid) 
                      & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                         >> 2U)) & (0U != (0x1fU & 
                                           (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                            >> 3U)))) 
                    & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                 >> 0x1aU)) == (0x1fU 
                                                & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                   >> 3U))))) {
            vlSelf->forwardEnable2 = 1U;
            vlSelf->forwardData2 = ((vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                     << 0x1dU) | (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                                  >> 3U));
        }
    }
    vlSelf->dbg_ID_EX_Valid = (1U & vlSelf->Top__DOT__decodeExecutePayload[0U]);
    vlSelf->Top__DOT__fetch__DOT__programCounter = __Vdly__Top__DOT__fetch__DOT__programCounter;
    vlSelf->Top__DOT__controlReset = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_ID_EX_Valid) & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 1U))) {
            vlSelf->Top__DOT__controlReset = 1U;
        } else if (((IData)(vlSelf->dbg_MEM_WB_Valid) 
                    & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                       >> 1U))) {
            vlSelf->Top__DOT__controlReset = 1U;
        }
    }
    vlSelf->dbg_pc = vlSelf->Top__DOT__fetch__DOT__programCounter;
    vlSelf->Top__DOT__instructionData = ((IData)(vlSelf->reset)
                                          ? 0x13U : 
                                         vlSelf->Top__DOT__imem_inst__DOT__mem
                                         [(0x3ffU & 
                                           (vlSelf->dbg_pc 
                                            >> 2U))]);
    vlSelf->dbg_IF_ID_Valid = (1U & vlSelf->Top__DOT__fetchDecodePayload[0U]);
    vlSelf->dbg_IF_ID_programCounter = ((vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                         << 0x1fU) 
                                        | (vlSelf->Top__DOT__fetchDecodePayload[1U] 
                                           >> 1U));
    vlSelf->dbg_IF_ID_instruction = ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                      << 0x1fU) | (
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                   >> 1U));
    vlSelf->dbg_trap = vlSelf->Top__DOT__controlReset;
    vlSelf->dbg_IMEM_data = vlSelf->Top__DOT__instructionData;
}

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0xaULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((0xcULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((9ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0xeULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VTop___024root___eval_phase__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VTop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("Top.sv", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VTop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("Top.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("Top.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VTop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->__SYM__interrupt & 0xfeU))) {
        Verilated::overWidthError("__SYM__interrupt");}
}
#endif  // VL_DEBUG
