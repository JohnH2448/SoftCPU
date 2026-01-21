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
    vlSelf->Top__DOT__instructionDataValid = 0U;
    vlSelf->Top__DOT__instructionData = 0x13U;
    vlSelf->Top__DOT__mcause = 0U;
    vlSelf->Top__DOT__controlReset = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if ((0U == (3U & vlSelf->dbg_pc))) {
            vlSelf->Top__DOT__instructionDataValid = 1U;
            vlSelf->Top__DOT__instructionData = vlSelf->Top__DOT__imem_inst__DOT__mem
                [(0x3fffU & (vlSelf->dbg_pc >> 2U))];
        }
        if (((IData)(vlSelf->dbg_MEM_WB_Valid) & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                  >> 8U))) {
            if ((0x800U & vlSelf->Top__DOT__memoryWritebackPayload[1U])) {
                vlSelf->Top__DOT__mcause = 4U;
            } else if ((0x400U & vlSelf->Top__DOT__memoryWritebackPayload[1U])) {
                vlSelf->Top__DOT__mcause = 6U;
            }
            vlSelf->Top__DOT__controlReset = 1U;
        } else if (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                    & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                       >> 8U))) {
            vlSelf->Top__DOT__mcause = 0U;
            vlSelf->Top__DOT__controlReset = 1U;
        } else if ((1U & (~ (IData)(vlSelf->Top__DOT__mretSignal)))) {
            if (((IData)(vlSelf->dbg_ID_EX_Valid) & 
                 (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                  >> 1U))) {
                vlSelf->Top__DOT__mcause = 2U;
                vlSelf->Top__DOT__controlReset = 1U;
            } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                        & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 4U))) {
                vlSelf->Top__DOT__mcause = 0xbU;
                vlSelf->Top__DOT__controlReset = 1U;
            } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                        & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 3U))) {
                vlSelf->Top__DOT__mcause = 3U;
                vlSelf->Top__DOT__controlReset = 1U;
            }
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
    IData/*31:0*/ Top__DOT__execute__DOT__operand1;
    Top__DOT__execute__DOT__operand1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__operand2;
    Top__DOT__execute__DOT__operand2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__brOp1;
    Top__DOT__execute__DOT__brOp1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__brOp2;
    Top__DOT__execute__DOT__brOp2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__csrOperand;
    Top__DOT__execute__DOT__csrOperand = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__tempResult;
    Top__DOT__execute__DOT__tempResult = 0;
    CData/*3:0*/ Top__DOT__memory__DOT__storeByteEnable;
    Top__DOT__memory__DOT__storeByteEnable = 0;
    // Body
    vlSelf->Top__DOT__stallControl = (1U & (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                                             & ((~ 
                                                 ((IData)(vlSelf->Top__DOT__memory__DOT__illegal) 
                                                  | (IData)(vlSelf->Top__DOT__memoryWritebackControl))) 
                                                & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                   >> 0x10U)))
                                             ? (~ (IData)(vlSelf->Top__DOT__loadDataValid))
                                             : ((IData)(vlSelf->Top__DOT__memory__DOT__storeReq) 
                                                | ((~ (IData)(vlSelf->Top__DOT__storeComplete)) 
                                                   & (IData)(vlSelf->Top__DOT__storeValid)))));
    vlSelf->Top__DOT__memoryWritebackControl = 0U;
    vlSelf->Top__DOT__executeMemoryControl = 0U;
    Top__DOT__memory__DOT__storeByteEnable = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_MEM_WB_Valid) & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                  >> 8U))) {
            vlSelf->Top__DOT__memoryWritebackControl 
                = (1U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
        } else if (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                    & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                       >> 8U))) {
            vlSelf->Top__DOT__memoryWritebackControl 
                = (1U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
        }
        if (vlSelf->Top__DOT__stallControl) {
            vlSelf->Top__DOT__memoryWritebackControl 
                = (2U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
        }
    }
    if ((1U & (IData)(((0x80U == (0x180U & vlSelf->Top__DOT__executeMemoryPayload[1U])) 
                       & (~ (IData)(vlSelf->Top__DOT__memoryWritebackControl)))))) {
        if ((0x8000U & vlSelf->Top__DOT__executeMemoryPayload[3U])) {
            if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                              >> 0xdU)))) {
                Top__DOT__memory__DOT__storeByteEnable = 1U;
            } else if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                     >> 0xdU)))) {
                if ((1U & (~ (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 0xcU)))) {
                    Top__DOT__memory__DOT__storeByteEnable = 3U;
                }
            } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                     >> 0xdU)))) {
                if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                  >> 0xcU)))) {
                    Top__DOT__memory__DOT__storeByteEnable = 0xfU;
                }
            }
        }
    }
    vlSelf->Top__DOT__execute__DOT__illegal = 0U;
    vlSelf->Top__DOT__execute__DOT__branchValid = 0U;
    vlSelf->Top__DOT__readCSR = 0U;
    Top__DOT__execute__DOT__tempResult = 0U;
    Top__DOT__execute__DOT__operand1 = 0U;
    Top__DOT__execute__DOT__operand2 = 0U;
    vlSelf->Top__DOT__execute__DOT__result = 0U;
    vlSelf->Top__DOT__branchData = 0U;
    vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData 
        = ((IData)(vlSelf->Top__DOT__csrForwardEnable)
            ? vlSelf->Top__DOT__csrForwardData : vlSelf->Top__DOT__csrReadData);
    Top__DOT__execute__DOT__brOp1 = ((IData)(vlSelf->forwardEnable1)
                                      ? vlSelf->forwardData1
                                      : ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                          << 0xcU) 
                                         | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                            >> 0x14U)));
    Top__DOT__execute__DOT__brOp2 = ((IData)(vlSelf->forwardEnable2)
                                      ? vlSelf->forwardData2
                                      : ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                          << 0xcU) 
                                         | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                            >> 0x14U)));
    Top__DOT__execute__DOT__csrOperand = ((0x800U & 
                                           vlSelf->Top__DOT__decodeExecutePayload[0U])
                                           ? Top__DOT__execute__DOT__brOp1
                                           : (0x1fU 
                                              & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 6U)));
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_MEM_WB_Valid) & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                  >> 8U))) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        } else if (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                    & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                       >> 8U))) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        } else if ((1U & (~ (IData)(vlSelf->Top__DOT__mretSignal)))) {
            if (((IData)(vlSelf->dbg_ID_EX_Valid) & 
                 (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                  >> 1U))) {
                vlSelf->Top__DOT__executeMemoryControl 
                    = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
            } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                        & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 4U))) {
                vlSelf->Top__DOT__executeMemoryControl 
                    = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
            } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                        & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 3U))) {
                vlSelf->Top__DOT__executeMemoryControl 
                    = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
            }
        }
        if (vlSelf->Top__DOT__stallControl) {
            vlSelf->Top__DOT__executeMemoryControl 
                = (2U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        }
    }
    if ((IData)((5U == (7U & vlSelf->Top__DOT__decodeExecutePayload[0U])))) {
        vlSelf->Top__DOT__readCSR = 1U;
        vlSelf->Top__DOT__branchData = vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData;
    } else if ((0U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                             >> 0x10U)))) {
        if ((0x10U & vlSelf->Top__DOT__decodeExecutePayload[1U])) {
            if ((8U & vlSelf->Top__DOT__decodeExecutePayload[1U])) {
                Top__DOT__execute__DOT__operand1 = 0U;
                Top__DOT__execute__DOT__operand2 = 
                    ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                      << 0x1bU) | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                   >> 5U));
            } else {
                Top__DOT__execute__DOT__operand1 = 
                    ((vlSelf->Top__DOT__decodeExecutePayload[6U] 
                      << 0xcU) | (vlSelf->Top__DOT__decodeExecutePayload[5U] 
                                  >> 0x14U));
                Top__DOT__execute__DOT__operand2 = 
                    ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                      << 0x1bU) | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                   >> 5U));
            }
        } else if ((8U & vlSelf->Top__DOT__decodeExecutePayload[1U])) {
            Top__DOT__execute__DOT__operand1 = ((IData)(vlSelf->forwardEnable1)
                                                 ? vlSelf->forwardData1
                                                 : 
                                                ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                                  << 0xcU) 
                                                 | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                    >> 0x14U)));
            Top__DOT__execute__DOT__operand2 = ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                 << 0x1bU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                                   >> 5U));
        } else {
            Top__DOT__execute__DOT__operand1 = ((IData)(vlSelf->forwardEnable1)
                                                 ? vlSelf->forwardData1
                                                 : 
                                                ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                                  << 0xcU) 
                                                 | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                    >> 0x14U)));
            Top__DOT__execute__DOT__operand2 = ((IData)(vlSelf->forwardEnable2)
                                                 ? vlSelf->forwardData2
                                                 : 
                                                ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                  << 0xcU) 
                                                 | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                    >> 0x14U)));
        }
        if ((0x4000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 0x19U)))) {
                if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                              >> 0x18U)))) {
                    vlSelf->Top__DOT__execute__DOT__result 
                        = ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? ((Top__DOT__execute__DOT__operand1 
                                < Top__DOT__execute__DOT__operand2)
                                ? 1U : 0U) : (VL_LTS_III(32, Top__DOT__execute__DOT__operand1, Top__DOT__execute__DOT__operand2)
                                               ? 1U
                                               : 0U));
                }
            }
        } else {
            vlSelf->Top__DOT__execute__DOT__result 
                = ((0x2000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                    ? ((0x1000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                        ? ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? VL_SHIFTRS_III(32,32,5, Top__DOT__execute__DOT__operand1, 
                                             (0x1fU 
                                              & Top__DOT__execute__DOT__operand2))
                            : (Top__DOT__execute__DOT__operand1 
                               >> (0x1fU & Top__DOT__execute__DOT__operand2)))
                        : ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? (Top__DOT__execute__DOT__operand1 
                               << (0x1fU & Top__DOT__execute__DOT__operand2))
                            : (Top__DOT__execute__DOT__operand1 
                               ^ Top__DOT__execute__DOT__operand2)))
                    : ((0x1000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                        ? ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? (Top__DOT__execute__DOT__operand1 
                               | Top__DOT__execute__DOT__operand2)
                            : (Top__DOT__execute__DOT__operand1 
                               & Top__DOT__execute__DOT__operand2))
                        : ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? (Top__DOT__execute__DOT__operand1 
                               - Top__DOT__execute__DOT__operand2)
                            : (Top__DOT__execute__DOT__operand1 
                               + Top__DOT__execute__DOT__operand2))));
        }
        if ((1U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                   & (~ (IData)(vlSelf->Top__DOT__executeMemoryControl))))) {
            if ((0x20000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                if ((0x10000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                    if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                  >> 0x1bU)))) {
                        vlSelf->Top__DOT__execute__DOT__branchValid 
                            = (Top__DOT__execute__DOT__brOp1 
                               >= Top__DOT__execute__DOT__brOp2);
                    }
                } else {
                    vlSelf->Top__DOT__execute__DOT__branchValid 
                        = ((0x8000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? (Top__DOT__execute__DOT__brOp1 
                               < Top__DOT__execute__DOT__brOp2)
                            : VL_GTES_III(32, Top__DOT__execute__DOT__brOp1, Top__DOT__execute__DOT__brOp2));
                }
            } else if ((0x10000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                vlSelf->Top__DOT__execute__DOT__branchValid 
                    = ((0x8000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                        ? VL_LTS_III(32, Top__DOT__execute__DOT__brOp1, Top__DOT__execute__DOT__brOp2)
                        : (Top__DOT__execute__DOT__brOp1 
                           != Top__DOT__execute__DOT__brOp2));
            } else if ((0x8000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                vlSelf->Top__DOT__execute__DOT__branchValid 
                    = (Top__DOT__execute__DOT__brOp1 
                       == Top__DOT__execute__DOT__brOp2);
            }
            if ((1U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                              >> 0x15U)))) {
                vlSelf->Top__DOT__execute__DOT__branchValid = 1U;
            } else if ((2U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                     >> 0x15U)))) {
                vlSelf->Top__DOT__execute__DOT__branchValid = 1U;
            }
        } else {
            vlSelf->Top__DOT__execute__DOT__branchValid = 0U;
        }
        if ((IData)((((1U == (3U & vlSelf->Top__DOT__decodeExecutePayload[0U])) 
                      & (IData)(vlSelf->Top__DOT__execute__DOT__branchValid)) 
                     & (0U != (0x38600000U & vlSelf->Top__DOT__decodeExecutePayload[0U]))))) {
            vlSelf->Top__DOT__branchData = ((2U == 
                                             (3U & 
                                              (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                               >> 0x15U)))
                                             ? (0xfffffffeU 
                                                & vlSelf->Top__DOT__execute__DOT__result)
                                             : vlSelf->Top__DOT__execute__DOT__result);
            if ((0U != (3U & vlSelf->Top__DOT__branchData))) {
                vlSelf->Top__DOT__execute__DOT__illegal = 1U;
            }
        }
        if (vlSelf->Top__DOT__execute__DOT__redirectAsserted) {
            vlSelf->Top__DOT__execute__DOT__branchValid = 0U;
        }
    } else {
        vlSelf->Top__DOT__readCSR = (0xfU & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                             >> 0xcU));
        if ((1U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 0x10U)))) {
            Top__DOT__execute__DOT__tempResult = Top__DOT__execute__DOT__csrOperand;
        } else if ((2U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                 >> 0x10U)))) {
            Top__DOT__execute__DOT__tempResult = (vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData 
                                                  | Top__DOT__execute__DOT__csrOperand);
        } else if ((3U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                 >> 0x10U)))) {
            Top__DOT__execute__DOT__tempResult = (vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData 
                                                  & (~ Top__DOT__execute__DOT__csrOperand));
        }
        if ((8U & (IData)(vlSelf->Top__DOT__readCSR))) {
            vlSelf->Top__DOT__execute__DOT__result 
                = ((4U & (IData)(vlSelf->Top__DOT__readCSR))
                    ? ((2U & (IData)(vlSelf->Top__DOT__readCSR))
                        ? Top__DOT__execute__DOT__tempResult
                        : ((1U & (IData)(vlSelf->Top__DOT__readCSR))
                            ? vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData
                            : Top__DOT__execute__DOT__tempResult))
                    : Top__DOT__execute__DOT__tempResult);
        } else if ((4U & (IData)(vlSelf->Top__DOT__readCSR))) {
            if ((2U & (IData)(vlSelf->Top__DOT__readCSR))) {
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((1U & (IData)(vlSelf->Top__DOT__readCSR))
                        ? Top__DOT__execute__DOT__tempResult
                        : (0xfffffffcU & Top__DOT__execute__DOT__tempResult));
            } else if ((1U & (IData)(vlSelf->Top__DOT__readCSR))) {
                vlSelf->Top__DOT__execute__DOT__result 
                    = Top__DOT__execute__DOT__tempResult;
            } else {
                vlSelf->Top__DOT__execute__DOT__result = 0U;
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((0xfffffff7U & vlSelf->Top__DOT__execute__DOT__result) 
                       | (8U & Top__DOT__execute__DOT__tempResult));
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((0xffffff7fU & vlSelf->Top__DOT__execute__DOT__result) 
                       | (0x80U & Top__DOT__execute__DOT__tempResult));
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((0xfffff7ffU & vlSelf->Top__DOT__execute__DOT__result) 
                       | (0x800U & Top__DOT__execute__DOT__tempResult));
            }
        } else if ((2U & (IData)(vlSelf->Top__DOT__readCSR))) {
            vlSelf->Top__DOT__execute__DOT__result 
                = Top__DOT__execute__DOT__tempResult;
        } else if ((1U & (IData)(vlSelf->Top__DOT__readCSR))) {
            vlSelf->Top__DOT__execute__DOT__result 
                = (0xfffffffcU & Top__DOT__execute__DOT__tempResult);
        } else {
            vlSelf->Top__DOT__execute__DOT__result = 0U;
            vlSelf->Top__DOT__execute__DOT__result 
                = ((0xfffffff7U & vlSelf->Top__DOT__execute__DOT__result) 
                   | (8U & Top__DOT__execute__DOT__tempResult));
            vlSelf->Top__DOT__execute__DOT__result 
                = ((0xffffff7fU & vlSelf->Top__DOT__execute__DOT__result) 
                   | (0x80U & Top__DOT__execute__DOT__tempResult));
            vlSelf->Top__DOT__execute__DOT__result 
                = (0x1800U | vlSelf->Top__DOT__execute__DOT__result);
        }
    }
    vlSelf->Top__DOT__realStoreByteEnable = (0xfU & 
                                             ((IData)(Top__DOT__memory__DOT__storeByteEnable) 
                                              << (3U 
                                                  & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                     >> 0xcU))));
    vlSelf->Top__DOT__branchValid = ((~ (IData)(vlSelf->Top__DOT__execute__DOT__illegal)) 
                                     & (IData)(vlSelf->Top__DOT__execute__DOT__branchValid));
    vlSelf->Top__DOT__decodeExecuteControl = 0U;
    vlSelf->Top__DOT__fetchDecodeControl = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_MEM_WB_Valid) & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                  >> 8U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                    & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                       >> 8U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (vlSelf->Top__DOT__mretSignal) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                       >> 1U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                       >> 4U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                       >> 3U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (vlSelf->Top__DOT__branchValid) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        }
        if (vlSelf->Top__DOT__stallControl) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (2U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (2U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else {
            if ((((((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (IData)(vlSelf->dbg_IF_ID_Valid)) 
                   & (~ (IData)(vlSelf->Top__DOT__decodeCombIllegal))) 
                  & (0x80000U == (0x1c0000U & vlSelf->Top__DOT__decodeExecutePayload[0U]))) 
                 & (((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                      >> 5U))) & (0U 
                                                  != (IData)(vlSelf->Top__DOT__readAddress1))) 
                    & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                 >> 5U)) == (IData)(vlSelf->Top__DOT__readAddress1))))) {
                vlSelf->Top__DOT__decodeExecuteControl 
                    = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
                vlSelf->Top__DOT__fetchDecodeControl 
                    = (2U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            }
            if ((((((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (IData)(vlSelf->dbg_IF_ID_Valid)) 
                   & (~ (IData)(vlSelf->Top__DOT__decodeCombIllegal))) 
                  & (0x80000U == (0x1c0000U & vlSelf->Top__DOT__decodeExecutePayload[0U]))) 
                 & (((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                      >> 5U))) & (0U 
                                                  != (IData)(vlSelf->Top__DOT__readAddress2))) 
                    & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                 >> 5U)) == (IData)(vlSelf->Top__DOT__readAddress2))))) {
                vlSelf->Top__DOT__decodeExecuteControl 
                    = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
                vlSelf->Top__DOT__fetchDecodeControl 
                    = (2U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            }
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
    vlSelf->Top__DOT__csrReadData = vlSelf->Top__DOT__csrFile__DOT__csrs
        [vlSelf->Top__DOT__readCSR];
}

VL_INLINE_OPT void VTop___024root___act_sequent__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ Top__DOT__memory__DOT__storeConfirm;
    Top__DOT__memory__DOT__storeConfirm = 0;
    CData/*3:0*/ Top__DOT__memory__DOT__storeByteEnable;
    Top__DOT__memory__DOT__storeByteEnable = 0;
    // Body
    vlSelf->Top__DOT__memory__DOT__illegal = 0U;
    Top__DOT__memory__DOT__storeConfirm = 0U;
    if ((1U & (IData)(((0x80U == (0x180U & vlSelf->Top__DOT__executeMemoryPayload[1U])) 
                       & (~ (IData)(vlSelf->Top__DOT__memoryWritebackControl)))))) {
        if ((0x10000U & vlSelf->Top__DOT__executeMemoryPayload[3U])) {
            if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                              >> 0xdU)))) {
                if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                  >> 0xdU)))) {
                    if ((0x1000U & vlSelf->Top__DOT__executeMemoryPayload[2U])) {
                        vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                    }
                } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                         >> 0xdU)))) {
                    if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                      >> 0xcU)))) {
                        vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                }
            }
        }
        if ((0x8000U & vlSelf->Top__DOT__executeMemoryPayload[3U])) {
            if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                              >> 0xdU)))) {
                if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                  >> 0xdU)))) {
                    if ((0x1000U & vlSelf->Top__DOT__executeMemoryPayload[2U])) {
                        vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                    }
                } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                         >> 0xdU)))) {
                    if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                      >> 0xcU)))) {
                        vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__memory__DOT__illegal = 1U;
                }
            }
            if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                              >> 0xdU)))) {
                Top__DOT__memory__DOT__storeConfirm = 1U;
            } else if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                     >> 0xdU)))) {
                if ((1U & (~ (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 0xcU)))) {
                    Top__DOT__memory__DOT__storeConfirm = 1U;
                }
            } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                     >> 0xdU)))) {
                if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                  >> 0xcU)))) {
                    Top__DOT__memory__DOT__storeConfirm = 1U;
                }
            }
        }
    }
    vlSelf->Top__DOT__memory__DOT__storeReq = ((~ (IData)(vlSelf->Top__DOT__storeValid)) 
                                               & (IData)(Top__DOT__memory__DOT__storeConfirm));
    vlSelf->Top__DOT__stallControl = (1U & (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                                             & ((~ 
                                                 ((IData)(vlSelf->Top__DOT__memory__DOT__illegal) 
                                                  | (IData)(vlSelf->Top__DOT__memoryWritebackControl))) 
                                                & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                   >> 0x10U)))
                                             ? (~ (IData)(vlSelf->Top__DOT__loadDataValid))
                                             : ((IData)(vlSelf->Top__DOT__memory__DOT__storeReq) 
                                                | ((~ (IData)(vlSelf->Top__DOT__storeComplete)) 
                                                   & (IData)(vlSelf->Top__DOT__storeValid)))));
    vlSelf->Top__DOT__memoryWritebackControl = 0U;
    vlSelf->Top__DOT__executeMemoryControl = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_MEM_WB_Valid) & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                  >> 8U))) {
            vlSelf->Top__DOT__memoryWritebackControl 
                = (1U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
            vlSelf->Top__DOT__executeMemoryControl 
                = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        } else if (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                    & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                       >> 8U))) {
            vlSelf->Top__DOT__memoryWritebackControl 
                = (1U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
            vlSelf->Top__DOT__executeMemoryControl 
                = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        } else if ((1U & (~ (IData)(vlSelf->Top__DOT__mretSignal)))) {
            if (((IData)(vlSelf->dbg_ID_EX_Valid) & 
                 (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                  >> 1U))) {
                vlSelf->Top__DOT__executeMemoryControl 
                    = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
            } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                        & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 4U))) {
                vlSelf->Top__DOT__executeMemoryControl 
                    = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
            } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                        & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 3U))) {
                vlSelf->Top__DOT__executeMemoryControl 
                    = (1U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
            }
        }
        if (vlSelf->Top__DOT__stallControl) {
            vlSelf->Top__DOT__memoryWritebackControl 
                = (2U | (IData)(vlSelf->Top__DOT__memoryWritebackControl));
            vlSelf->Top__DOT__executeMemoryControl 
                = (2U | (IData)(vlSelf->Top__DOT__executeMemoryControl));
        }
    }
    Top__DOT__memory__DOT__storeByteEnable = 0U;
    if ((1U & (IData)(((0x80U == (0x180U & vlSelf->Top__DOT__executeMemoryPayload[1U])) 
                       & (~ (IData)(vlSelf->Top__DOT__memoryWritebackControl)))))) {
        if ((0x8000U & vlSelf->Top__DOT__executeMemoryPayload[3U])) {
            if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                              >> 0xdU)))) {
                Top__DOT__memory__DOT__storeByteEnable = 1U;
            } else if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                     >> 0xdU)))) {
                if ((1U & (~ (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 0xcU)))) {
                    Top__DOT__memory__DOT__storeByteEnable = 3U;
                }
            } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                     >> 0xdU)))) {
                if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                  >> 0xcU)))) {
                    Top__DOT__memory__DOT__storeByteEnable = 0xfU;
                }
            }
        }
    }
    vlSelf->Top__DOT__realStoreByteEnable = (0xfU & 
                                             ((IData)(Top__DOT__memory__DOT__storeByteEnable) 
                                              << (3U 
                                                  & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                     >> 0xcU))));
}

VL_INLINE_OPT void VTop___024root___act_sequent__TOP__2(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_sequent__TOP__2\n"); );
    // Body
    vlSelf->Top__DOT__readData1 = ((0U == (IData)(vlSelf->Top__DOT__readAddress1))
                                    ? 0U : (((((IData)(vlSelf->Top__DOT__destinationEnable) 
                                               & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                                      >> 0xcU)))) 
                                              & ((0x1fU 
                                                  & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                                     >> 0xcU)) 
                                                 == (IData)(vlSelf->Top__DOT__readAddress1))) 
                                             & (IData)(vlSelf->dbg_MEM_WB_Valid))
                                             ? vlSelf->Top__DOT__writeData
                                             : vlSelf->Top__DOT__registerFile__DOT__registers
                                            [vlSelf->Top__DOT__readAddress1]));
}

VL_INLINE_OPT void VTop___024root___act_sequent__TOP__3(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_sequent__TOP__3\n"); );
    // Body
    vlSelf->Top__DOT__readData2 = ((0U == (IData)(vlSelf->Top__DOT__readAddress2))
                                    ? 0U : (((((IData)(vlSelf->Top__DOT__destinationEnable) 
                                               & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                                      >> 0xcU)))) 
                                              & ((0x1fU 
                                                  & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                                     >> 0xcU)) 
                                                 == (IData)(vlSelf->Top__DOT__readAddress2))) 
                                             & (IData)(vlSelf->dbg_MEM_WB_Valid))
                                             ? vlSelf->Top__DOT__writeData
                                             : vlSelf->Top__DOT__registerFile__DOT__registers
                                            [vlSelf->Top__DOT__readAddress2]));
}

VL_INLINE_OPT void VTop___024root___act_comb__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_comb__TOP__0\n"); );
    // Init
    IData/*31:0*/ Top__DOT__execute__DOT__operand1;
    Top__DOT__execute__DOT__operand1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__operand2;
    Top__DOT__execute__DOT__operand2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__brOp1;
    Top__DOT__execute__DOT__brOp1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__brOp2;
    Top__DOT__execute__DOT__brOp2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__csrOperand;
    Top__DOT__execute__DOT__csrOperand = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__tempResult;
    Top__DOT__execute__DOT__tempResult = 0;
    // Body
    vlSelf->Top__DOT__execute__DOT__illegal = 0U;
    vlSelf->Top__DOT__execute__DOT__branchValid = 0U;
    vlSelf->Top__DOT__readCSR = 0U;
    Top__DOT__execute__DOT__tempResult = 0U;
    Top__DOT__execute__DOT__operand1 = 0U;
    Top__DOT__execute__DOT__operand2 = 0U;
    vlSelf->Top__DOT__execute__DOT__result = 0U;
    vlSelf->Top__DOT__branchData = 0U;
    vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData 
        = ((IData)(vlSelf->Top__DOT__csrForwardEnable)
            ? vlSelf->Top__DOT__csrForwardData : vlSelf->Top__DOT__csrReadData);
    Top__DOT__execute__DOT__brOp1 = ((IData)(vlSelf->forwardEnable1)
                                      ? vlSelf->forwardData1
                                      : ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                          << 0xcU) 
                                         | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                            >> 0x14U)));
    Top__DOT__execute__DOT__brOp2 = ((IData)(vlSelf->forwardEnable2)
                                      ? vlSelf->forwardData2
                                      : ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                          << 0xcU) 
                                         | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                            >> 0x14U)));
    Top__DOT__execute__DOT__csrOperand = ((0x800U & 
                                           vlSelf->Top__DOT__decodeExecutePayload[0U])
                                           ? Top__DOT__execute__DOT__brOp1
                                           : (0x1fU 
                                              & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 6U)));
    if ((IData)((5U == (7U & vlSelf->Top__DOT__decodeExecutePayload[0U])))) {
        vlSelf->Top__DOT__readCSR = 1U;
        vlSelf->Top__DOT__branchData = vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData;
    } else if ((0U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                             >> 0x10U)))) {
        if ((0x10U & vlSelf->Top__DOT__decodeExecutePayload[1U])) {
            if ((8U & vlSelf->Top__DOT__decodeExecutePayload[1U])) {
                Top__DOT__execute__DOT__operand1 = 0U;
                Top__DOT__execute__DOT__operand2 = 
                    ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                      << 0x1bU) | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                   >> 5U));
            } else {
                Top__DOT__execute__DOT__operand1 = 
                    ((vlSelf->Top__DOT__decodeExecutePayload[6U] 
                      << 0xcU) | (vlSelf->Top__DOT__decodeExecutePayload[5U] 
                                  >> 0x14U));
                Top__DOT__execute__DOT__operand2 = 
                    ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                      << 0x1bU) | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                   >> 5U));
            }
        } else if ((8U & vlSelf->Top__DOT__decodeExecutePayload[1U])) {
            Top__DOT__execute__DOT__operand1 = ((IData)(vlSelf->forwardEnable1)
                                                 ? vlSelf->forwardData1
                                                 : 
                                                ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                                  << 0xcU) 
                                                 | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                    >> 0x14U)));
            Top__DOT__execute__DOT__operand2 = ((vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                 << 0x1bU) 
                                                | (vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                                   >> 5U));
        } else {
            Top__DOT__execute__DOT__operand1 = ((IData)(vlSelf->forwardEnable1)
                                                 ? vlSelf->forwardData1
                                                 : 
                                                ((vlSelf->Top__DOT__decodeExecutePayload[4U] 
                                                  << 0xcU) 
                                                 | (vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                    >> 0x14U)));
            Top__DOT__execute__DOT__operand2 = ((IData)(vlSelf->forwardEnable2)
                                                 ? vlSelf->forwardData2
                                                 : 
                                                ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                  << 0xcU) 
                                                 | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                    >> 0x14U)));
        }
        if ((0x4000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
            if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 0x19U)))) {
                if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                              >> 0x18U)))) {
                    vlSelf->Top__DOT__execute__DOT__result 
                        = ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? ((Top__DOT__execute__DOT__operand1 
                                < Top__DOT__execute__DOT__operand2)
                                ? 1U : 0U) : (VL_LTS_III(32, Top__DOT__execute__DOT__operand1, Top__DOT__execute__DOT__operand2)
                                               ? 1U
                                               : 0U));
                }
            }
        } else {
            vlSelf->Top__DOT__execute__DOT__result 
                = ((0x2000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                    ? ((0x1000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                        ? ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? VL_SHIFTRS_III(32,32,5, Top__DOT__execute__DOT__operand1, 
                                             (0x1fU 
                                              & Top__DOT__execute__DOT__operand2))
                            : (Top__DOT__execute__DOT__operand1 
                               >> (0x1fU & Top__DOT__execute__DOT__operand2)))
                        : ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? (Top__DOT__execute__DOT__operand1 
                               << (0x1fU & Top__DOT__execute__DOT__operand2))
                            : (Top__DOT__execute__DOT__operand1 
                               ^ Top__DOT__execute__DOT__operand2)))
                    : ((0x1000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                        ? ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? (Top__DOT__execute__DOT__operand1 
                               | Top__DOT__execute__DOT__operand2)
                            : (Top__DOT__execute__DOT__operand1 
                               & Top__DOT__execute__DOT__operand2))
                        : ((0x800000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? (Top__DOT__execute__DOT__operand1 
                               - Top__DOT__execute__DOT__operand2)
                            : (Top__DOT__execute__DOT__operand1 
                               + Top__DOT__execute__DOT__operand2))));
        }
        if ((1U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                   & (~ (IData)(vlSelf->Top__DOT__executeMemoryControl))))) {
            if ((0x20000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                if ((0x10000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                    if ((1U & (~ (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                  >> 0x1bU)))) {
                        vlSelf->Top__DOT__execute__DOT__branchValid 
                            = (Top__DOT__execute__DOT__brOp1 
                               >= Top__DOT__execute__DOT__brOp2);
                    }
                } else {
                    vlSelf->Top__DOT__execute__DOT__branchValid 
                        = ((0x8000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                            ? (Top__DOT__execute__DOT__brOp1 
                               < Top__DOT__execute__DOT__brOp2)
                            : VL_GTES_III(32, Top__DOT__execute__DOT__brOp1, Top__DOT__execute__DOT__brOp2));
                }
            } else if ((0x10000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                vlSelf->Top__DOT__execute__DOT__branchValid 
                    = ((0x8000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                        ? VL_LTS_III(32, Top__DOT__execute__DOT__brOp1, Top__DOT__execute__DOT__brOp2)
                        : (Top__DOT__execute__DOT__brOp1 
                           != Top__DOT__execute__DOT__brOp2));
            } else if ((0x8000000U & vlSelf->Top__DOT__decodeExecutePayload[0U])) {
                vlSelf->Top__DOT__execute__DOT__branchValid 
                    = (Top__DOT__execute__DOT__brOp1 
                       == Top__DOT__execute__DOT__brOp2);
            }
            if ((1U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                              >> 0x15U)))) {
                vlSelf->Top__DOT__execute__DOT__branchValid = 1U;
            } else if ((2U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                     >> 0x15U)))) {
                vlSelf->Top__DOT__execute__DOT__branchValid = 1U;
            }
        } else {
            vlSelf->Top__DOT__execute__DOT__branchValid = 0U;
        }
        if ((IData)((((1U == (3U & vlSelf->Top__DOT__decodeExecutePayload[0U])) 
                      & (IData)(vlSelf->Top__DOT__execute__DOT__branchValid)) 
                     & (0U != (0x38600000U & vlSelf->Top__DOT__decodeExecutePayload[0U]))))) {
            vlSelf->Top__DOT__branchData = ((2U == 
                                             (3U & 
                                              (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                               >> 0x15U)))
                                             ? (0xfffffffeU 
                                                & vlSelf->Top__DOT__execute__DOT__result)
                                             : vlSelf->Top__DOT__execute__DOT__result);
            if ((0U != (3U & vlSelf->Top__DOT__branchData))) {
                vlSelf->Top__DOT__execute__DOT__illegal = 1U;
            }
        }
        if (vlSelf->Top__DOT__execute__DOT__redirectAsserted) {
            vlSelf->Top__DOT__execute__DOT__branchValid = 0U;
        }
    } else {
        vlSelf->Top__DOT__readCSR = (0xfU & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                             >> 0xcU));
        if ((1U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                          >> 0x10U)))) {
            Top__DOT__execute__DOT__tempResult = Top__DOT__execute__DOT__csrOperand;
        } else if ((2U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                 >> 0x10U)))) {
            Top__DOT__execute__DOT__tempResult = (vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData 
                                                  | Top__DOT__execute__DOT__csrOperand);
        } else if ((3U == (3U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                 >> 0x10U)))) {
            Top__DOT__execute__DOT__tempResult = (vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData 
                                                  & (~ Top__DOT__execute__DOT__csrOperand));
        }
        if ((8U & (IData)(vlSelf->Top__DOT__readCSR))) {
            vlSelf->Top__DOT__execute__DOT__result 
                = ((4U & (IData)(vlSelf->Top__DOT__readCSR))
                    ? ((2U & (IData)(vlSelf->Top__DOT__readCSR))
                        ? Top__DOT__execute__DOT__tempResult
                        : ((1U & (IData)(vlSelf->Top__DOT__readCSR))
                            ? vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData
                            : Top__DOT__execute__DOT__tempResult))
                    : Top__DOT__execute__DOT__tempResult);
        } else if ((4U & (IData)(vlSelf->Top__DOT__readCSR))) {
            if ((2U & (IData)(vlSelf->Top__DOT__readCSR))) {
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((1U & (IData)(vlSelf->Top__DOT__readCSR))
                        ? Top__DOT__execute__DOT__tempResult
                        : (0xfffffffcU & Top__DOT__execute__DOT__tempResult));
            } else if ((1U & (IData)(vlSelf->Top__DOT__readCSR))) {
                vlSelf->Top__DOT__execute__DOT__result 
                    = Top__DOT__execute__DOT__tempResult;
            } else {
                vlSelf->Top__DOT__execute__DOT__result = 0U;
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((0xfffffff7U & vlSelf->Top__DOT__execute__DOT__result) 
                       | (8U & Top__DOT__execute__DOT__tempResult));
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((0xffffff7fU & vlSelf->Top__DOT__execute__DOT__result) 
                       | (0x80U & Top__DOT__execute__DOT__tempResult));
                vlSelf->Top__DOT__execute__DOT__result 
                    = ((0xfffff7ffU & vlSelf->Top__DOT__execute__DOT__result) 
                       | (0x800U & Top__DOT__execute__DOT__tempResult));
            }
        } else if ((2U & (IData)(vlSelf->Top__DOT__readCSR))) {
            vlSelf->Top__DOT__execute__DOT__result 
                = Top__DOT__execute__DOT__tempResult;
        } else if ((1U & (IData)(vlSelf->Top__DOT__readCSR))) {
            vlSelf->Top__DOT__execute__DOT__result 
                = (0xfffffffcU & Top__DOT__execute__DOT__tempResult);
        } else {
            vlSelf->Top__DOT__execute__DOT__result = 0U;
            vlSelf->Top__DOT__execute__DOT__result 
                = ((0xfffffff7U & vlSelf->Top__DOT__execute__DOT__result) 
                   | (8U & Top__DOT__execute__DOT__tempResult));
            vlSelf->Top__DOT__execute__DOT__result 
                = ((0xffffff7fU & vlSelf->Top__DOT__execute__DOT__result) 
                   | (0x80U & Top__DOT__execute__DOT__tempResult));
            vlSelf->Top__DOT__execute__DOT__result 
                = (0x1800U | vlSelf->Top__DOT__execute__DOT__result);
        }
    }
    vlSelf->Top__DOT__branchValid = ((~ (IData)(vlSelf->Top__DOT__execute__DOT__illegal)) 
                                     & (IData)(vlSelf->Top__DOT__execute__DOT__branchValid));
}

VL_INLINE_OPT void VTop___024root___act_comb__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_comb__TOP__1\n"); );
    // Init
    CData/*0:0*/ Top__DOT__decode__DOT__ro;
    Top__DOT__decode__DOT__ro = 0;
    // Body
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[3U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[4U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[5U] = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[6U] = 0U;
    Top__DOT__decode__DOT__ro = 0U;
    vlSelf->Top__DOT__readAddress1 = 0U;
    vlSelf->Top__DOT__readAddress2 = 0U;
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
        = ((0xfffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
           | (vlSelf->Top__DOT__readData2 << 0x14U));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[3U] 
        = ((vlSelf->Top__DOT__readData2 >> 0xcU) | 
           (vlSelf->Top__DOT__readData1 << 0x14U));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[4U] 
        = ((vlSelf->Top__DOT__readData1 >> 0xcU) | 
           ((IData)((((QData)((IData)(vlSelf->Top__DOT__fetchDecodePayload[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelf->Top__DOT__fetchDecodePayload[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelf->Top__DOT__fetchDecodePayload[0U])) 
                                                 >> 1U)))) 
            << 0x14U));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[5U] 
        = (((IData)((((QData)((IData)(vlSelf->Top__DOT__fetchDecodePayload[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelf->Top__DOT__fetchDecodePayload[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelf->Top__DOT__fetchDecodePayload[0U])) 
                                                 >> 1U)))) 
            >> 0xcU) | ((IData)(((((QData)((IData)(
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U])) 
                                   << 0x3fU) | (((QData)((IData)(
                                                                 vlSelf->Top__DOT__fetchDecodePayload[1U])) 
                                                 << 0x1fU) 
                                                | ((QData)((IData)(
                                                                   vlSelf->Top__DOT__fetchDecodePayload[0U])) 
                                                   >> 1U))) 
                                 >> 0x20U)) << 0x14U));
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[6U] 
        = ((IData)(((((QData)((IData)(vlSelf->Top__DOT__fetchDecodePayload[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelf->Top__DOT__fetchDecodePayload[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelf->Top__DOT__fetchDecodePayload[0U])) 
                                                 >> 1U))) 
                    >> 0x20U)) >> 0xcU);
    vlSelf->Top__DOT__decodeCombIllegal = (1U & (vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                                 >> 1U));
    if ((0x80U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        if ((0x40U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            if ((0x20U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((0x10U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                } else if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                } else if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                        vlSelf->Top__DOT__readAddress1 
                            = (0x1fU & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                        >> 0x10U));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                            = ((0xfffffc1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                               | (0x3e0U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                            >> 3U)));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (0xffe3ffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                        if ((0U != (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                          >> 0xdU)))) {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = ((1U & vlSelf->Top__DOT__fetchDecodePayload[3U])
                                    ? ((vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                        >> 0x1fU) ? 
                                       ((0x40000000U 
                                         & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                         ? ((0x20000000U 
                                             & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                             ? ((0x10000000U 
                                                 & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                 ? 
                                                (2U 
                                                 | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                 : 
                                                ((0x8000000U 
                                                  & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                  ? 
                                                 (2U 
                                                  | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                  : 
                                                 ((0x4000000U 
                                                   & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                   ? 
                                                  (2U 
                                                   | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                   : 
                                                  ((0x2000000U 
                                                    & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                    ? 
                                                   ((0x1000000U 
                                                     & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                     ? 
                                                    (2U 
                                                     | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                     : 
                                                    ((0x800000U 
                                                      & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                      ? 
                                                     ((0x400000U 
                                                       & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                       ? 
                                                      (2U 
                                                       | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                       : 
                                                      ((0x200000U 
                                                        & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                        ? 
                                                       (2U 
                                                        | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                        : 
                                                       (0xc000U 
                                                        | (0xffff0fffU 
                                                           & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))))
                                                      : 
                                                     ((0x400000U 
                                                       & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                       ? 
                                                      ((0xffff0fffU 
                                                        & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                                       | (((0x200000U 
                                                            & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                            ? 0xbU
                                                            : 0xaU) 
                                                          << 0xcU))
                                                       : 
                                                      ((0x200000U 
                                                        & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                        ? 
                                                       (0x9000U 
                                                        | (0xffff0fffU 
                                                           & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                                        : 
                                                       (2U 
                                                        | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])))))
                                                    : 
                                                   (2U 
                                                    | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])))))
                                             : (2U 
                                                | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                         : (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                        : ((0x40000000U 
                                            & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                            ? ((0x20000000U 
                                                & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                ? (
                                                   (0x10000000U 
                                                    & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                    ? 
                                                   (2U 
                                                    | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                    : 
                                                   ((0x8000000U 
                                                     & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                     ? 
                                                    (2U 
                                                     | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                     : 
                                                    ((0x4000000U 
                                                      & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                      ? 
                                                     (2U 
                                                      | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                      : 
                                                     ((0x2000000U 
                                                       & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                       ? 
                                                      (2U 
                                                       | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                       : 
                                                      ((0x1000000U 
                                                        & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                        ? 
                                                       (2U 
                                                        | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                        : 
                                                       ((0x800000U 
                                                         & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                         ? 
                                                        (2U 
                                                         | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                         : 
                                                        ((0x400000U 
                                                          & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                          ? 
                                                         ((0x200000U 
                                                           & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                           ? 
                                                          (2U 
                                                           | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                           : 
                                                          (0xf000U 
                                                           | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                                          : 
                                                         ((0x200000U 
                                                           & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                           ? 
                                                          (2U 
                                                           | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                           : 
                                                          (0xe000U 
                                                           | (0xffff0fffU 
                                                              & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))))))))))
                                                : (2U 
                                                   | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                            : (2U | 
                                               vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])))
                                    : ((vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                        >> 0x1fU) ? 
                                       (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                        : ((0x40000000U 
                                            & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                            ? ((0x20000000U 
                                                & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                ? (
                                                   (0x10000000U 
                                                    & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                    ? 
                                                   (2U 
                                                    | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                    : 
                                                   ((0x8000000U 
                                                     & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                     ? 
                                                    ((0x4000000U 
                                                      & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                      ? 
                                                     (2U 
                                                      | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                      : 
                                                     ((0x2000000U 
                                                       & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                       ? 
                                                      (2U 
                                                       | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                       : 
                                                      ((0x1000000U 
                                                        & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                        ? 
                                                       (2U 
                                                        | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                        : 
                                                       ((0x800000U 
                                                         & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                         ? 
                                                        ((0x400000U 
                                                          & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                          ? 
                                                         (2U 
                                                          | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                          : 
                                                         ((0x200000U 
                                                           & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                           ? 
                                                          (2U 
                                                           | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                           : 
                                                          (0xd000U 
                                                           | (0xffff0fffU 
                                                              & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))))
                                                         : 
                                                        ((0xffff0fffU 
                                                          & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                                         | (((0x400000U 
                                                              & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                              ? 
                                                             ((0x200000U 
                                                               & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                               ? 3U
                                                               : 2U)
                                                              : 
                                                             ((0x200000U 
                                                               & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                               ? 1U
                                                               : 7U)) 
                                                            << 0xcU))))))
                                                     : 
                                                    ((0x4000000U 
                                                      & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                      ? 
                                                     (2U 
                                                      | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                      : 
                                                     ((0x2000000U 
                                                       & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                       ? 
                                                      (2U 
                                                       | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                       : 
                                                      ((0x1000000U 
                                                        & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                        ? 
                                                       (2U 
                                                        | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                        : 
                                                       ((0x800000U 
                                                         & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                         ? 
                                                        ((0x400000U 
                                                          & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                          ? 
                                                         (2U 
                                                          | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                          : 
                                                         ((0xffff0fffU 
                                                           & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                                          | (((0x200000U 
                                                               & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                               ? 6U
                                                               : 4U) 
                                                             << 0xcU)))
                                                         : 
                                                        ((0x400000U 
                                                          & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                          ? 
                                                         (2U 
                                                          | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                                          : 
                                                         ((0xffff0fffU 
                                                           & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                                          | (((0x200000U 
                                                               & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                                               ? 8U
                                                               : 0U) 
                                                             << 0xcU)))))))))
                                                : (2U 
                                                   | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                            : (2U | 
                                               vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))));
                            if ((0x8000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                                if ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                                    if ((0x2000U & 
                                         vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                            = (0x30000U 
                                               | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                            = ((0xfffff03fU 
                                                & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                               | (0x7c0U 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0xaU)));
                                        if ((0U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 >> 0x10U)))) {
                                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                                = (0x20U 
                                                   | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                        }
                                    } else {
                                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                            = (0x20000U 
                                               | (0xfffcffffU 
                                                  & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                            = ((0xfffff03fU 
                                                & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                               | (0x7c0U 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0xaU)));
                                        if ((0U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 >> 0x10U)))) {
                                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                                = (0x20U 
                                                   | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                        }
                                    }
                                } else if ((0x2000U 
                                            & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                        = (0x10000U 
                                           | (0xfffcffffU 
                                              & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                        = ((0xfffff01fU 
                                            & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                           | (0xffffffe0U 
                                              & (0x20U 
                                                 | (0x7c0U 
                                                    & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                       >> 0xaU)))));
                                } else {
                                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                }
                            } else if ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                                if ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                        = (0x30000U 
                                           | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                        = (0x800U | 
                                           vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                    if ((0U != (IData)(vlSelf->Top__DOT__readAddress1))) {
                                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                            = (0x20U 
                                               | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                    }
                                } else {
                                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                        = (0x20000U 
                                           | (0xfffcffffU 
                                              & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                        = (0x800U | 
                                           vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                    if ((0U != (IData)(vlSelf->Top__DOT__readAddress1))) {
                                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                            = (0x20U 
                                               | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                    }
                                }
                            } else if ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                    = (0x10000U | (0xfffcffffU 
                                                   & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                    = (0x800U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                    = (0x20U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                            } else {
                                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                            }
                            Top__DOT__decode__DOT__ro 
                                = (((((8U == (0xfU 
                                              & (vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                                 >> 0xcU))) 
                                      | (9U == (0xfU 
                                                & (vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                                   >> 0xcU)))) 
                                     | (0xaU == (0xfU 
                                                 & (vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                                    >> 0xcU)))) 
                                    | (0xbU == (0xfU 
                                                & (vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                                   >> 0xcU)))) 
                                   | (0xcU == (0xfU 
                                               & (vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                                  >> 0xcU))));
                            if (((vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                  >> 5U) & (IData)(Top__DOT__decode__DOT__ro))) {
                                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                            }
                        } else if ((0x73U == ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                               << 0x1fU) 
                                              | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 >> 1U)))) {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (0x10U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                        } else if ((0x100073U == ((
                                                   vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                   << 0x1fU) 
                                                  | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 1U)))) {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (8U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                        } else if ((0x30200073U == 
                                    ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                      << 0x1fU) | (
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                   >> 1U)))) {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (4U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (0x1000U | (0xffff0fffU 
                                              & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                        } else if ((0x10500073U != 
                                    ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                      << 0x1fU) | (
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U] 
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
            } else if ((0x10U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                        if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                                = ((0xfffffc1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                                   | (0x3e0U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                >> 3U)));
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                                = (0x10U | (0xffffffe7U 
                                            & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]));
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (0x2c0000U | (0xff83ffffU 
                                                & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                                = ((0x1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                                   | (0xffffffe0U & 
                                      (((- (IData)(
                                                   (1U 
                                                    & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                        << 0x1aU) | 
                                       ((0x2000000U 
                                         & (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                            << 0x19U)) 
                                        | ((0x1fe0000U 
                                            & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                               << 4U)) 
                                           | ((0x10000U 
                                               & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                  >> 5U)) 
                                              | (0xffc0U 
                                                 & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                    >> 0x10U))))))));
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                                = ((0xffffffe0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                                   | (0x1fU & ((- (IData)(
                                                          (1U 
                                                           & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                               >> 6U)));
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
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                            = ((0xfffffc1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                               | (0x3e0U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                            >> 3U)));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                            = (8U | (0xffffffe7U & 
                                     vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (0x4c0000U | (0xff83ffffU 
                                            & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                            = ((0x1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                               | (0xffffffe0U & (((- (IData)(
                                                             (1U 
                                                              & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                                  << 0x11U) 
                                                 | (0x1ffe0U 
                                                    & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                        << 0x10U) 
                                                       | (0xffe0U 
                                                          & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                             >> 0x10U)))))));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                            = ((0xffffffe0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                               | (0x1fU & ((- (IData)(
                                                      (1U 
                                                       & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                           >> 0xfU)));
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
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = (0x10U | (0xffffffe7U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = ((0x1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                           | (0xffffffe0U & (((- (IData)(
                                                         (1U 
                                                          & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                              << 0x12U) 
                                             | ((0x20000U 
                                                 & (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                    << 0x11U)) 
                                                | ((0x10000U 
                                                    & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                       << 8U)) 
                                                   | ((0xfc00U 
                                                       & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                          >> 0x10U)) 
                                                      | (0x3c0U 
                                                         & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                            >> 3U))))))));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                        = ((0xffffffe0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                           | (0x1fU & ((- (IData)((1U 
                                                   & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                       >> 0xeU)));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = ((0x8000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? ((0xc7ffffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                               | (((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                    ? ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                        ? 6U : 5U) : 
                                   ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                     ? 4U : 3U)) << 0x1bU))
                            : ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])
                                : ((0xc7ffffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                                   | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                        ? 2U : 1U) 
                                      << 0x1bU))));
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
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                            = ((0xfffffc1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                               | (0x3e0U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                            >> 3U)));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                            = (0x18U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]);
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                            = (0x40000U | (0xffe3ffffU 
                                           & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                            = ((0x1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                               | (0xfffe0000U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 << 4U)));
                        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                            = ((0xffffffe0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                               | (0x1fU & ((0x10U & 
                                            (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                             << 4U)) 
                                           | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                              >> 0x1cU))));
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
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                        = ((0xfffffc1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                           | (0x3e0U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                        >> 3U)));
                    vlSelf->Top__DOT__readAddress1 
                        = (0x1fU & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                    >> 0x10U));
                    vlSelf->Top__DOT__readAddress2 
                        = (0x1fU & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                    >> 0x15U));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = (0xffffffe7U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]);
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0x40000U | (0xffe3ffffU 
                                       & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
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
                            ? ((0xf87fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
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
                                  << 0x17U)) : ((2U 
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
                                                (0x4000000U 
                                                 | (0xf87fffffU 
                                                    & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                                 : 
                                                ((3U 
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
                                                 (0x4800000U 
                                                  | (0xf87fffffU 
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
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = (8U | (0xffffffe7U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]));
                vlSelf->Top__DOT__readAddress1 = (0x1fU 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x10U));
                vlSelf->Top__DOT__readAddress2 = (0x1fU 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x15U));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = ((0x1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                       | (0xffffffe0U & (((- (IData)(
                                                     (1U 
                                                      & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                          << 0x11U) 
                                         | ((0x1fc00U 
                                             & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                 << 0x10U) 
                                                | (0xfc00U 
                                                   & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                      >> 0x10U)))) 
                                            | (0x3e0U 
                                               & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                  >> 3U))))));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                    = ((0xffffffe0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                       | (0x1fU & ((- (IData)((1U & 
                                               vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                   >> 0xfU)));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]);
                if ((0U == (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                  >> 0xdU)))) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0x7fffffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = (0xfffffffeU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]);
                } else if ((1U == (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                         >> 0xdU)))) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0x80000000U | (0x7fffffffU 
                                          & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = (0xfffffffeU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]);
                } else if ((2U == (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                         >> 0xdU)))) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0x80000000U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = (1U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]);
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
    } else if ((0x20U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        if ((0x10U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        } else if ((8U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                        = ((0xfffffc1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                           | (0x3e0U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                        >> 3U)));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = (0x10U | (0xffffffe7U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0x40000U | (0xffe3ffffU 
                                       & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = ((0x1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                           | (0xfffe0000U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                             << 4U)));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                        = ((0xffffffe0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                           | (0x1fU & ((0x10U & (vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                 << 4U)) 
                                       | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                          >> 0x1cU))));
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
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                    = ((0xfffffc1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                       | (0x3e0U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                    >> 3U)));
                vlSelf->Top__DOT__readAddress1 = (0x1fU 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x10U));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = (8U | (0xffffffe7U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = (0x40000U | (0xffe3ffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = ((0x1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                       | (0xffffffe0U & (((- (IData)(
                                                     (1U 
                                                      & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                          << 0x11U) 
                                         | (0x1ffe0U 
                                            & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                << 0x10U) 
                                               | (0xffe0U 
                                                  & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                     >> 0x10U)))))));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                    = ((0xffffffe0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                       | (0x1fU & ((- (IData)((1U & 
                                               vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                   >> 0xfU)));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = ((0x8000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                        ? ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? ((0xf87fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                               | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                    ? 2U : 3U) << 0x17U))
                            : ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? ((0U == (0x7fU & 
                                           ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                             << 6U) 
                                            | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                               >> 0x1aU))))
                                    ? (0x3000000U | 
                                       (0xf87fffffU 
                                        & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                    : ((0x20U == (0x7fU 
                                                  & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                      << 6U) 
                                                     | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                        >> 0x1aU))))
                                        ? (0x3800000U 
                                           | (0xf87fffffU 
                                              & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                        : (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U])))
                                : (0x2000000U | (0xf87fffffU 
                                                 & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))))
                        : ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? ((0xf87fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                               | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                    ? 9U : 8U) << 0x17U))
                            : ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? ((0U == (0x7fU & 
                                           ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                             << 6U) 
                                            | (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                               >> 0x1aU))))
                                    ? (0x2800000U | 
                                       (0xf87fffffU 
                                        & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                    : (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))
                                : (0xf87fffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]))));
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
                if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    if ((0U != (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                      >> 0xdU)))) {
                        if ((1U != (7U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                          >> 0xdU)))) {
                            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                        }
                    }
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
        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
            = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
    } else if ((4U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
        if ((2U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                = ((0xfffffc1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                   | (0x3e0U & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                >> 3U)));
            vlSelf->Top__DOT__readAddress1 = (0x1fU 
                                              & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                 >> 0x10U));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                = (8U | (0xffffffe7U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (0x80000U | (0xffe3ffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                = ((0x1fU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                   | (0xffffffe0U & (((- (IData)((1U 
                                                  & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                                      << 0x11U) | (0x1ffe0U 
                                                   & ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                                       << 0x10U) 
                                                      | (0xffe0U 
                                                         & (vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                            >> 0x10U)))))));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
                = ((0xffffffe0U & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
                   | (0x1fU & ((- (IData)((1U & vlSelf->Top__DOT__fetchDecodePayload[3U]))) 
                               >> 0xfU)));
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                = (4U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]);
            if ((0x8000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                } else {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = ((0x3fffffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                           | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? 2U : 0U) << 0x1eU));
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = ((0xfffffffeU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                           | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                                ? 2U : 0U) >> 2U));
                }
            } else if ((0x4000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                if ((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])) {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                } else {
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                        = (0xc0000000U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
                    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                        = (1U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]);
                }
            } else {
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                    = ((0x3fffffffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]) 
                       | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? 3U : 1U) << 0x1eU));
                vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U] 
                    = ((0xfffffffeU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[1U]) 
                       | (((0x2000U & vlSelf->Top__DOT__fetchDecodePayload[2U])
                            ? 3U : 1U) >> 2U));
            }
        } else {
            vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
                = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
        }
    } else {
        vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U] 
            = (2U | vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[0U]);
    }
    vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U] 
        = ((0xfff003ffU & vlSelf->Top__DOT__decode__DOT__decodeExecuteCandidate[2U]) 
           | (0xfffffc00U & (((IData)(vlSelf->Top__DOT__readAddress1) 
                              << 0xfU) | ((IData)(vlSelf->Top__DOT__readAddress2) 
                                          << 0xaU))));
}

VL_INLINE_OPT void VTop___024root___act_comb__TOP__2(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___act_comb__TOP__2\n"); );
    // Body
    vlSelf->Top__DOT__decodeExecuteControl = 0U;
    vlSelf->Top__DOT__fetchDecodeControl = 0U;
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_MEM_WB_Valid) & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                  >> 8U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                    & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                       >> 8U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (vlSelf->Top__DOT__mretSignal) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                       >> 1U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                       >> 4U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                       >> 3U))) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else if (vlSelf->Top__DOT__branchValid) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (1U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        }
        if (vlSelf->Top__DOT__stallControl) {
            vlSelf->Top__DOT__decodeExecuteControl 
                = (2U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
            vlSelf->Top__DOT__fetchDecodeControl = 
                (2U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
        } else {
            if ((((((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (IData)(vlSelf->dbg_IF_ID_Valid)) 
                   & (~ (IData)(vlSelf->Top__DOT__decodeCombIllegal))) 
                  & (0x80000U == (0x1c0000U & vlSelf->Top__DOT__decodeExecutePayload[0U]))) 
                 & (((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                      >> 5U))) & (0U 
                                                  != (IData)(vlSelf->Top__DOT__readAddress1))) 
                    & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                 >> 5U)) == (IData)(vlSelf->Top__DOT__readAddress1))))) {
                vlSelf->Top__DOT__decodeExecuteControl 
                    = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
                vlSelf->Top__DOT__fetchDecodeControl 
                    = (2U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            }
            if ((((((IData)(vlSelf->dbg_ID_EX_Valid) 
                    & (IData)(vlSelf->dbg_IF_ID_Valid)) 
                   & (~ (IData)(vlSelf->Top__DOT__decodeCombIllegal))) 
                  & (0x80000U == (0x1c0000U & vlSelf->Top__DOT__decodeExecutePayload[0U]))) 
                 & (((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                      >> 5U))) & (0U 
                                                  != (IData)(vlSelf->Top__DOT__readAddress2))) 
                    & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                 >> 5U)) == (IData)(vlSelf->Top__DOT__readAddress2))))) {
                vlSelf->Top__DOT__decodeExecuteControl 
                    = (1U | (IData)(vlSelf->Top__DOT__decodeExecuteControl));
                vlSelf->Top__DOT__fetchDecodeControl 
                    = (2U | (IData)(vlSelf->Top__DOT__fetchDecodeControl));
            }
        }
    }
}

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((3ULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0xcULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0xfULL & vlSelf->__VactTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v0;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v0 = 0;
    CData/*3:0*/ __Vdlyvdim0__Top__DOT__csrFile__DOT__csrs__v18;
    __Vdlyvdim0__Top__DOT__csrFile__DOT__csrs__v18 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v18;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v18 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v18;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v18 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v19;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v19 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v19;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v19 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v20;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v20 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v20;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v20 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v21;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v21 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v22;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v22 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v23;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v23 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v23;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v23 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v24;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v24 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v24;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v24 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v25;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v25 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v25;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v25 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v26;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v26 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v26;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v26 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v27;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v27 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v27;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v27 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v28;
    __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v28 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v28;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v28 = 0;
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
    CData/*0:0*/ __Vdly__Top__DOT__dmem_inst__DOT__storeValid_q;
    __Vdly__Top__DOT__dmem_inst__DOT__storeValid_q = 0;
    SData/*13:0*/ __Vdlyvdim0__Top__DOT__dmem_inst__DOT__mem__v0;
    __Vdlyvdim0__Top__DOT__dmem_inst__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__dmem_inst__DOT__mem__v0;
    __Vdlyvval__Top__DOT__dmem_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0;
    __Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0 = 0;
    // Body
    __Vdly__Top__DOT__execute__DOT__redirectAsserted 
        = vlSelf->Top__DOT__execute__DOT__redirectAsserted;
    __Vdly__Top__DOT__fetch__DOT__programCounter = vlSelf->Top__DOT__fetch__DOT__programCounter;
    __Vdly__Top__DOT__dmem_inst__DOT__storeValid_q 
        = vlSelf->Top__DOT__dmem_inst__DOT__storeValid_q;
    __Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0 = 0U;
    __Vdly__Top__DOT__storeValid = vlSelf->Top__DOT__storeValid;
    __Vdlyvset__Top__DOT__registerFile__DOT__registers__v0 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v0 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v18 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v19 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v20 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v21 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v23 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v24 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v25 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v26 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v27 = 0U;
    __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v28 = 0U;
    if (vlSelf->reset) {
        __Vdly__Top__DOT__execute__DOT__redirectAsserted = 0U;
    } else {
        if ((((IData)(vlSelf->Top__DOT__execute__DOT__branchValid) 
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
    if (vlSelf->Top__DOT__destinationEnable) {
        if ((0U != (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                             >> 0xcU)))) {
            __Vdlyvval__Top__DOT__registerFile__DOT__registers__v0 
                = vlSelf->Top__DOT__writeData;
            __Vdlyvset__Top__DOT__registerFile__DOT__registers__v0 = 1U;
            __Vdlyvdim0__Top__DOT__registerFile__DOT__registers__v0 
                = (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                            >> 0xcU));
        }
    }
    if (__Vdlyvset__Top__DOT__registerFile__DOT__registers__v0) {
        vlSelf->Top__DOT__registerFile__DOT__registers[__Vdlyvdim0__Top__DOT__registerFile__DOT__registers__v0] 
            = __Vdlyvval__Top__DOT__registerFile__DOT__registers__v0;
    }
    if (vlSelf->reset) {
        __Vdly__Top__DOT__fetch__DOT__programCounter = 0x80000000U;
        __Vdly__Top__DOT__storeValid = 0U;
        __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v0 = 1U;
    } else {
        if (vlSelf->Top__DOT__controlReset) {
            __Vdly__Top__DOT__fetch__DOT__programCounter 
                = vlSelf->Top__DOT__csrFile__DOT__csrs
                [6U];
            __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v21 = 1U;
            __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v22 
                = vlSelf->Top__DOT__mcause;
            if ((6U == (IData)(vlSelf->Top__DOT__mcause))) {
                __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v23 
                    = vlSelf->dbg_MEM_WB_programCounter;
                __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v23 = 1U;
            } else if ((4U == (IData)(vlSelf->Top__DOT__mcause))) {
                __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v24 
                    = vlSelf->dbg_MEM_WB_programCounter;
                __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v24 = 1U;
            } else if ((0U == (IData)(vlSelf->Top__DOT__mcause))) {
                __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v25 
                    = vlSelf->dbg_EX_MEM_programCounter;
                __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v25 = 1U;
            } else if ((2U == (IData)(vlSelf->Top__DOT__mcause))) {
                __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v26 
                    = vlSelf->dbg_ID_EX_programCounter;
                __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v26 = 1U;
            } else if ((0xbU == (IData)(vlSelf->Top__DOT__mcause))) {
                __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v27 
                    = vlSelf->dbg_ID_EX_programCounter;
                __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v27 = 1U;
            } else if ((3U == (IData)(vlSelf->Top__DOT__mcause))) {
                __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v28 
                    = vlSelf->dbg_ID_EX_programCounter;
                __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v28 = 1U;
            }
        } else if (vlSelf->Top__DOT__mretSignal) {
            __Vdly__Top__DOT__fetch__DOT__programCounter 
                = vlSelf->Top__DOT__branchData;
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
        if ((1U & (((~ (IData)(vlSelf->Top__DOT__storeValid)) 
                    & (~ (IData)(vlSelf->Top__DOT__memory__DOT__illegal))) 
                   & (~ (IData)(vlSelf->Top__DOT__memoryWritebackControl))))) {
            __Vdly__Top__DOT__storeValid = vlSelf->Top__DOT__memory__DOT__storeReq;
        } else if (vlSelf->Top__DOT__storeComplete) {
            __Vdly__Top__DOT__storeValid = 0U;
        }
        if (vlSelf->Top__DOT__csrDestinationEnable) {
            __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v18 
                = ((vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                    << 0x14U) | (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                 >> 0xcU));
            __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v18 = 1U;
            __Vdlyvdim0__Top__DOT__csrFile__DOT__csrs__v18 
                = (0xfU & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                           >> 3U));
        }
        if ((1U & (~ ((IData)(vlSelf->Top__DOT__csrDestinationEnable) 
                      & (0x70U == (0x78U & vlSelf->Top__DOT__memoryWritebackPayload[1U])))))) {
            __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v19 
                = ((IData)(1U) + vlSelf->Top__DOT__csrFile__DOT__csrs
                   [0xeU]);
            __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v19 = 1U;
        }
        if (((IData)(vlSelf->Top__DOT__dualValid) & 
             (~ ((IData)(vlSelf->Top__DOT__csrDestinationEnable) 
                 & (0x78U == (0x78U & vlSelf->Top__DOT__memoryWritebackPayload[1U])))))) {
            __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v20 
                = ((IData)(1U) + vlSelf->Top__DOT__csrFile__DOT__csrs
                   [0xfU]);
            __Vdlyvset__Top__DOT__csrFile__DOT__csrs__v20 = 1U;
        }
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v0) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[0U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[1U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[2U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[3U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[4U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[5U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[6U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[7U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[8U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[9U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[0xaU] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[0xbU] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[0xcU] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[0xdU] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[0xeU] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[0xfU] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[8U] = 0x40000100U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[0U] = 0x1800U;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v18) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[__Vdlyvdim0__Top__DOT__csrFile__DOT__csrs__v18] 
            = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v18;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v19) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[0xeU] 
            = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v19;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v20) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[0xfU] 
            = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v20;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v21) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[3U] = 0U;
        vlSelf->Top__DOT__csrFile__DOT__csrs[2U] = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v22;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v23) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[1U] = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v23;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v24) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[1U] = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v24;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v25) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[1U] = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v25;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v26) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[1U] = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v26;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v27) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[1U] = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v27;
    }
    if (__Vdlyvset__Top__DOT__csrFile__DOT__csrs__v28) {
        vlSelf->Top__DOT__csrFile__DOT__csrs[1U] = __Vdlyvval__Top__DOT__csrFile__DOT__csrs__v28;
    }
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (vlSelf->Top__DOT__controlReset) {
            vlSelf->Top__DOT__csrFile__DOT____Vstrobe0 = 1U;
        }
    }
    if (vlSelf->reset) {
        __Vdly__Top__DOT__dmem_inst__DOT__storeValid_q = 0U;
        vlSelf->Top__DOT__storeComplete = 0U;
    } else {
        vlSelf->Top__DOT__storeComplete = 0U;
        if (VL_UNLIKELY(((IData)(vlSelf->Top__DOT__storeValid) 
                         & (~ (IData)(vlSelf->Top__DOT__dmem_inst__DOT__storeValid_q))))) {
            vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word 
                = vlSelf->Top__DOT__dmem_inst__DOT__mem
                [(0x3fffU & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                             >> 0xeU))];
            if ((1U & (IData)(vlSelf->Top__DOT__realStoreByteEnable))) {
                vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word 
                    = ((0xffffff00U & vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word) 
                       | (0xffU & vlSelf->Top__DOT__storeData));
            }
            vlSelf->Top__DOT__storeComplete = 1U;
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
                = (0x3fffU & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                              >> 0xeU));
            VL_WRITEF("\n\nStored %08x at address %08x\n\n\n",
                      32,vlSelf->Top__DOT__dmem_inst__DOT__unnamedblk2__DOT__word,
                      32,(0xfffffffcU & ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                          << 0x14U) 
                                         | (0xffffcU 
                                            & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                               >> 0xcU)))));
        }
        __Vdly__Top__DOT__dmem_inst__DOT__storeValid_q 
            = vlSelf->Top__DOT__storeValid;
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
    if (vlSelf->reset) {
        vlSelf->Top__DOT__memoryWritebackPayload[0U] = 0U;
        vlSelf->Top__DOT__memoryWritebackPayload[1U] = 0U;
        vlSelf->Top__DOT__memoryWritebackPayload[2U] = 0U;
        vlSelf->Top__DOT__memoryWritebackPayload[3U] = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__memoryWritebackControl))) {
        vlSelf->Top__DOT__memoryWritebackPayload[1U] 
            = (0xffffff7fU & vlSelf->Top__DOT__memoryWritebackPayload[1U]);
    } else if ((1U & (~ ((IData)(vlSelf->Top__DOT__memoryWritebackControl) 
                         >> 1U)))) {
        if ((0x800U & vlSelf->Top__DOT__executeMemoryPayload[1U])) {
            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                = (0xfffffdffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]);
        } else if ((0x400U & vlSelf->Top__DOT__executeMemoryPayload[1U])) {
            if ((0x200U & vlSelf->Top__DOT__executeMemoryPayload[1U])) {
                vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                    = ((0xfffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                       | (0xfffff000U & ((vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                          << 0x16U) 
                                         | (0x3ff000U 
                                            & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                               >> 0xaU)))));
                vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                    = ((0xfffff000U & vlSelf->Top__DOT__memoryWritebackPayload[2U]) 
                       | (0xfffU & (vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                    >> 0xaU)));
                vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                    = (0x200U | vlSelf->Top__DOT__memoryWritebackPayload[1U]);
            } else {
                if (VL_UNLIKELY(((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                  >> 0x10U) & (IData)(vlSelf->Top__DOT__loadDataValid)))) {
                    vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                        = ((IData)(vlSelf->reset) ? 0U
                            : vlSelf->Top__DOT__dmem_inst__DOT__mem
                           [(0x3fffU & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                        >> 0xeU))]);
                    if ((0U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                      >> 0xdU)))) {
                        vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b 
                            = (0xffU & (vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                                        >> (0x18U & 
                                            (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                             >> 9U))));
                        vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                            = ((0xfffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                               | (((0x1000U & vlSelf->Top__DOT__executeMemoryPayload[3U])
                                    ? (((- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b) 
                                                       >> 7U)))) 
                                        << 8U) | (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b))
                                    : (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b)) 
                                  << 0xcU));
                        vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                            = ((0xfffff000U & vlSelf->Top__DOT__memoryWritebackPayload[2U]) 
                               | (((0x1000U & vlSelf->Top__DOT__executeMemoryPayload[3U])
                                    ? (((- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b) 
                                                       >> 7U)))) 
                                        << 8U) | (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b))
                                    : (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__b)) 
                                  >> 0x14U));
                    } else if ((1U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                             >> 0xdU)))) {
                        vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h 
                            = (0xffffU & (vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                                          >> (0x10U 
                                              & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                 >> 9U))));
                        vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                            = ((0xfffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                               | (((0x1000U & vlSelf->Top__DOT__executeMemoryPayload[3U])
                                    ? (((- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h) 
                                                       >> 0xfU)))) 
                                        << 0x10U) | (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h))
                                    : (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h)) 
                                  << 0xcU));
                        vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                            = ((0xfffff000U & vlSelf->Top__DOT__memoryWritebackPayload[2U]) 
                               | (((0x1000U & vlSelf->Top__DOT__executeMemoryPayload[3U])
                                    ? (((- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h) 
                                                       >> 0xfU)))) 
                                        << 0x10U) | (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h))
                                    : (IData)(vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__h)) 
                                  >> 0x14U));
                    } else if ((3U == (3U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                             >> 0xdU)))) {
                        vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                            = ((0xfffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                               | (vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                                  << 0xcU));
                        vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                            = ((0xfffff000U & vlSelf->Top__DOT__memoryWritebackPayload[2U]) 
                               | (vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word 
                                  >> 0x14U));
                    }
                    VL_WRITEF("\n\nLoaded %08x at address %08x\n\n\n",
                              32,vlSelf->Top__DOT__memory__DOT__unnamedblk1__DOT__word,
                              32,((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                   << 0x14U) | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                >> 0xcU)));
                }
                vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                    = ((0xfffffdffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                       | (0x1fffe00U & ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                         >> 7U) & ((IData)(vlSelf->Top__DOT__loadDataValid) 
                                                   << 9U))));
            }
        } else if ((0x200U & vlSelf->Top__DOT__executeMemoryPayload[1U])) {
            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                = ((0xfffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                   | (0xfffff000U & vlSelf->Top__DOT__executeMemoryPayload[2U]));
            vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                = ((0xfffff000U & vlSelf->Top__DOT__memoryWritebackPayload[2U]) 
                   | (0xfffU & vlSelf->Top__DOT__executeMemoryPayload[3U]));
            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                = (0x200U | vlSelf->Top__DOT__memoryWritebackPayload[1U]);
        } else {
            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                = (0xfffffdffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]);
        }
        vlSelf->Top__DOT__memoryWritebackPayload[1U] 
            = ((0xfffffe7fU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
               | (0xffffff80U & ((0x100U & (((IData)(vlSelf->Top__DOT__memory__DOT__illegal) 
                                             << 8U) 
                                            | (0xffffff00U 
                                               & vlSelf->Top__DOT__executeMemoryPayload[1U]))) 
                                 | (0x80U & vlSelf->Top__DOT__executeMemoryPayload[1U]))));
        vlSelf->Top__DOT__memoryWritebackPayload[2U] 
            = ((0xfffU & vlSelf->Top__DOT__memoryWritebackPayload[2U]) 
               | ((IData)((((QData)((IData)(((vlSelf->Top__DOT__executeMemoryPayload[5U] 
                                              << 0xaU) 
                                             | (vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                                >> 0x16U)))) 
                            << 5U) | (QData)((IData)(
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                         >> 0x11U)))))) 
                  << 0xcU));
        vlSelf->Top__DOT__memoryWritebackPayload[3U] 
            = (0x1ffffU & (((IData)((((QData)((IData)(
                                                      ((vlSelf->Top__DOT__executeMemoryPayload[5U] 
                                                        << 0xaU) 
                                                       | (vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                                          >> 0x16U)))) 
                                      << 5U) | (QData)((IData)(
                                                               (0x1fU 
                                                                & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                                   >> 0x11U)))))) 
                            >> 0x14U) | ((IData)(((
                                                   ((QData)((IData)(
                                                                    ((vlSelf->Top__DOT__executeMemoryPayload[5U] 
                                                                      << 0xaU) 
                                                                     | (vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                                                        >> 0x16U)))) 
                                                    << 5U) 
                                                   | (QData)((IData)(
                                                                     (0x1fU 
                                                                      & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                                         >> 0x11U))))) 
                                                  >> 0x20U)) 
                                         << 0xcU)));
        vlSelf->Top__DOT__memoryWritebackPayload[0U] 
            = (IData)((0x7fffffffffULL & (((QData)((IData)(
                                                           vlSelf->Top__DOT__executeMemoryPayload[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelf->Top__DOT__executeMemoryPayload[0U])))));
        vlSelf->Top__DOT__memoryWritebackPayload[1U] 
            = ((0xffffff80U & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
               | (IData)(((0x7fffffffffULL & (((QData)((IData)(
                                                               vlSelf->Top__DOT__executeMemoryPayload[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelf->Top__DOT__executeMemoryPayload[0U])))) 
                          >> 0x20U)));
        vlSelf->Top__DOT__memoryWritebackPayload[1U] 
            = ((0xfffff3ffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
               | (0xc00U & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                            >> 5U)));
        if ((0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                          >> 1U)))) {
            vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                = ((0xfffU & vlSelf->Top__DOT__memoryWritebackPayload[1U]) 
                   | (0xfffff000U & vlSelf->Top__DOT__executeMemoryPayload[2U]));
            vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                = ((0xfffff000U & vlSelf->Top__DOT__memoryWritebackPayload[2U]) 
                   | (0xfffU & vlSelf->Top__DOT__executeMemoryPayload[3U]));
        }
    }
    if (vlSelf->reset) {
        vlSelf->Top__DOT__executeMemoryPayload[0U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[1U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[2U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[3U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[4U] = 0U;
        vlSelf->Top__DOT__executeMemoryPayload[5U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[0U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[1U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[2U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[3U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[4U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[5U] = 0U;
        vlSelf->Top__DOT__decodeExecutePayload[6U] = 0U;
    } else {
        if ((1U & (IData)(vlSelf->Top__DOT__executeMemoryControl))) {
            vlSelf->Top__DOT__executeMemoryPayload[1U] 
                = (0xffffff7fU & vlSelf->Top__DOT__executeMemoryPayload[1U]);
        } else if ((1U & (~ ((IData)(vlSelf->Top__DOT__executeMemoryControl) 
                             >> 1U)))) {
            vlSelf->Top__DOT__executeMemoryPayload[3U] 
                = ((0x1ffffU & vlSelf->Top__DOT__executeMemoryPayload[3U]) 
                   | (((IData)((((QData)((IData)(vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                 << 0x2cU) | (((QData)((IData)(
                                                               vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                               << 0xcU) 
                                              | ((QData)((IData)(
                                                                 vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                 >> 0x14U)))) 
                       << 0x16U) | (((4U & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                      ? 0U : (0x1fU 
                                              & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                 >> 5U))) 
                                    << 0x11U)));
            vlSelf->Top__DOT__executeMemoryPayload[4U] 
                = (((0x1ffffU & ((IData)((((QData)((IData)(
                                                           vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                           << 0x2cU) 
                                          | (((QData)((IData)(
                                                              vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                              << 0xcU) 
                                             | ((QData)((IData)(
                                                                vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                >> 0x14U)))) 
                                 >> 0xaU)) | (((4U 
                                                & vlSelf->Top__DOT__decodeExecutePayload[0U])
                                                ? 0U
                                                : (0x1fU 
                                                   & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                      >> 5U))) 
                                              >> 0xfU)) 
                   | ((0x3e0000U & ((IData)((((QData)((IData)(
                                                              vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                              << 0x2cU) 
                                             | (((QData)((IData)(
                                                                 vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                 << 0xcU) 
                                                | ((QData)((IData)(
                                                                   vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                   >> 0x14U)))) 
                                    >> 0xaU)) | ((IData)(
                                                         ((((QData)((IData)(
                                                                            vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                                            << 0x2cU) 
                                                           | (((QData)((IData)(
                                                                               vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                               << 0xcU) 
                                                              | ((QData)((IData)(
                                                                                vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                                 >> 0x14U))) 
                                                          >> 0x20U)) 
                                                 << 0x16U)));
            vlSelf->Top__DOT__executeMemoryPayload[5U] 
                = (0x3fffffU & ((0x1ffffU & ((IData)(
                                                     ((((QData)((IData)(
                                                                        vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                                        << 0x2cU) 
                                                       | (((QData)((IData)(
                                                                           vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                           << 0xcU) 
                                                          | ((QData)((IData)(
                                                                             vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                             >> 0x14U))) 
                                                      >> 0x20U)) 
                                             >> 0xaU)) 
                                | (0x3e0000U & ((IData)(
                                                        ((((QData)((IData)(
                                                                           vlSelf->Top__DOT__decodeExecutePayload[6U])) 
                                                           << 0x2cU) 
                                                          | (((QData)((IData)(
                                                                              vlSelf->Top__DOT__decodeExecutePayload[5U])) 
                                                              << 0xcU) 
                                                             | ((QData)((IData)(
                                                                                vlSelf->Top__DOT__decodeExecutePayload[4U])) 
                                                                >> 0x14U))) 
                                                         >> 0x20U)) 
                                                >> 0xaU))));
            vlSelf->Top__DOT__executeMemoryPayload[1U] 
                = ((0xfffU & vlSelf->Top__DOT__executeMemoryPayload[1U]) 
                   | ((IData)((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result)) 
                                << 0x20U) | (QData)((IData)(
                                                            ((IData)(vlSelf->forwardEnable2)
                                                              ? vlSelf->forwardData2
                                                              : 
                                                             ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                               << 0xcU) 
                                                              | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                                 >> 0x14U))))))) 
                      << 0xcU));
            vlSelf->Top__DOT__executeMemoryPayload[2U] 
                = (((IData)((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((IData)(vlSelf->forwardEnable2)
                                                            ? vlSelf->forwardData2
                                                            : 
                                                           ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                             << 0xcU) 
                                                            | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                               >> 0x14U))))))) 
                    >> 0x14U) | ((IData)(((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result)) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             ((IData)(vlSelf->forwardEnable2)
                                                               ? vlSelf->forwardData2
                                                               : 
                                                              ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                                << 0xcU) 
                                                               | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                                  >> 0x14U)))))) 
                                          >> 0x20U)) 
                                 << 0xcU));
            vlSelf->Top__DOT__executeMemoryPayload[3U] 
                = ((0xfffe0000U & vlSelf->Top__DOT__executeMemoryPayload[3U]) 
                   | (((IData)(((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result)) 
                                  << 0x20U) | (QData)((IData)(
                                                              ((IData)(vlSelf->forwardEnable2)
                                                                ? vlSelf->forwardData2
                                                                : 
                                                               ((vlSelf->Top__DOT__decodeExecutePayload[3U] 
                                                                 << 0xcU) 
                                                                | (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                                                   >> 0x14U)))))) 
                                >> 0x20U)) >> 0x14U) 
                      | (0x1f000U & ((vlSelf->Top__DOT__decodeExecutePayload[1U] 
                                      << 0xeU) | (0x3000U 
                                                  & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                     >> 0x12U))))));
            vlSelf->Top__DOT__executeMemoryPayload[1U] 
                = ((0xfffff1ffU & vlSelf->Top__DOT__executeMemoryPayload[1U]) 
                   | (0xe00U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                >> 9U)));
            vlSelf->Top__DOT__executeMemoryPayload[1U] 
                = ((0xfffffe7fU & vlSelf->Top__DOT__executeMemoryPayload[1U]) 
                   | (0xffffff80U & ((((IData)(vlSelf->Top__DOT__execute__DOT__illegal) 
                                       || (1U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                 >> 1U))) 
                                      << 8U) | (0x80U 
                                                & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                   << 7U)))));
            vlSelf->Top__DOT__executeMemoryPayload[0U] 
                = ((1U & vlSelf->Top__DOT__executeMemoryPayload[0U]) 
                   | ((IData)((((QData)((IData)((0xfU 
                                                 & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                    >> 0xcU)))) 
                                << 0x22U) | (((QData)((IData)(vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData)) 
                                              << 2U) 
                                             | (QData)((IData)(
                                                               (3U 
                                                                & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                                   >> 0x10U))))))) 
                      << 1U));
            vlSelf->Top__DOT__executeMemoryPayload[1U] 
                = ((0xffffff80U & vlSelf->Top__DOT__executeMemoryPayload[1U]) 
                   | (((IData)((((QData)((IData)((0xfU 
                                                  & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                     >> 0xcU)))) 
                                 << 0x22U) | (((QData)((IData)(vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData)) 
                                               << 2U) 
                                              | (QData)((IData)(
                                                                (3U 
                                                                 & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                                    >> 0x10U))))))) 
                       >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                               (0xfU 
                                                                & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                                   >> 0xcU)))) 
                                               << 0x22U) 
                                              | (((QData)((IData)(vlSelf->Top__DOT__execute__DOT__forwardCorrectedCSRReadData)) 
                                                  << 2U) 
                                                 | (QData)((IData)(
                                                                   (3U 
                                                                    & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                                                                       >> 0x10U)))))) 
                                             >> 0x20U)) 
                                    << 1U)));
            vlSelf->Top__DOT__executeMemoryPayload[0U] 
                = ((0xfffffffeU & vlSelf->Top__DOT__executeMemoryPayload[0U]) 
                   | (1U & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                            >> 5U)));
        }
        if ((1U & (IData)(vlSelf->Top__DOT__decodeExecuteControl))) {
            vlSelf->Top__DOT__decodeExecutePayload[0U] 
                = (0xfffffffeU & vlSelf->Top__DOT__decodeExecutePayload[0U]);
        } else if ((1U & (~ ((IData)(vlSelf->Top__DOT__decodeExecuteControl) 
                             >> 1U)))) {
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
    vlSelf->Top__DOT__dmem_inst__DOT__storeValid_q 
        = __Vdly__Top__DOT__dmem_inst__DOT__storeValid_q;
    vlSelf->Top__DOT__storeValid = __Vdly__Top__DOT__storeValid;
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
    if (__Vdlyvset__Top__DOT__dmem_inst__DOT__mem__v0) {
        vlSelf->Top__DOT__dmem_inst__DOT__mem[__Vdlyvdim0__Top__DOT__dmem_inst__DOT__mem__v0] 
            = __Vdlyvval__Top__DOT__dmem_inst__DOT__mem__v0;
    }
    vlSelf->dbg_MEM_WB_programCounter = ((vlSelf->Top__DOT__memoryWritebackPayload[3U] 
                                          << 0xfU) 
                                         | (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                            >> 0x11U));
    vlSelf->dbg_MEM_WB_Valid = (1U & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                      >> 7U));
    vlSelf->Top__DOT__dualValid = ((~ (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                       >> 8U)) & (IData)(vlSelf->dbg_MEM_WB_Valid));
    if ((0U != (3U & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                      >> 1U)))) {
        vlSelf->Top__DOT__writeData = ((vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                        << 0x1dU) | 
                                       (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                        >> 3U));
        vlSelf->Top__DOT__destinationEnable = vlSelf->Top__DOT__dualValid;
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
    }
    vlSelf->dbg_wb_value = ((IData)(vlSelf->Top__DOT__destinationEnable)
                             ? ((vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                 << 0x14U) | (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                              >> 0xcU))
                             : 0U);
    vlSelf->Top__DOT__csrDestinationEnable = ((0U != 
                                               (3U 
                                                & (vlSelf->Top__DOT__memoryWritebackPayload[0U] 
                                                   >> 1U))) 
                                              & ((IData)(vlSelf->Top__DOT__dualValid) 
                                                 & vlSelf->Top__DOT__memoryWritebackPayload[0U]));
    vlSelf->dbg_EX_MEM_programCounter = ((vlSelf->Top__DOT__executeMemoryPayload[5U] 
                                          << 0xaU) 
                                         | (vlSelf->Top__DOT__executeMemoryPayload[4U] 
                                            >> 0x16U));
    vlSelf->Top__DOT__storeData = (((vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                     << 0x14U) | (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                  >> 0xcU)) 
                                   << (0x18U & (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                                >> 9U)));
    vlSelf->dbg_EX_MEM_Valid = (1U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                      >> 7U));
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
                                         << 0xcU) | 
                                        (vlSelf->Top__DOT__decodeExecutePayload[5U] 
                                         >> 0x14U));
    vlSelf->Top__DOT__csrForwardData = 0U;
    vlSelf->Top__DOT__csrForwardEnable = 0U;
    if (((((0xfU & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                    >> 0xcU)) == (0xfU & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                          >> 3U))) 
          & vlSelf->Top__DOT__executeMemoryPayload[0U]) 
         & (IData)(vlSelf->dbg_EX_MEM_Valid))) {
        vlSelf->Top__DOT__csrForwardData = ((vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                             << 0x14U) 
                                            | (vlSelf->Top__DOT__executeMemoryPayload[2U] 
                                               >> 0xcU));
        vlSelf->Top__DOT__csrForwardEnable = 1U;
    } else if (((((0xfU & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 0xcU)) == (0xfU & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                 >> 3U))) 
                 & vlSelf->Top__DOT__memoryWritebackPayload[0U]) 
                & (IData)(vlSelf->dbg_MEM_WB_Valid))) {
        vlSelf->Top__DOT__csrForwardData = ((vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                             << 0x14U) 
                                            | (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                               >> 0xcU));
        vlSelf->Top__DOT__csrForwardEnable = 1U;
    }
    vlSelf->forwardEnable2 = 0U;
    vlSelf->forwardEnable1 = 0U;
    vlSelf->forwardData1 = 0U;
    if ((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                         >> 0xfU)))) {
        if (((((IData)(vlSelf->dbg_EX_MEM_Valid) & 
               (((0U != (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                               >> 9U))) & (2U != (7U 
                                                  & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                     >> 9U)))) 
                | (0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                >> 1U))))) & (0U != 
                                              (0x1fU 
                                               & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                  >> 0x11U)))) 
             & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                          >> 0xfU)) == (0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                 >> 0x11U))))) {
            vlSelf->forwardEnable1 = 1U;
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
        } else if (((((IData)(vlSelf->dbg_MEM_WB_Valid) 
                      & (IData)(vlSelf->Top__DOT__destinationEnable)) 
                     & (0U != (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                        >> 0xcU)))) 
                    & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                 >> 0xfU)) == (0x1fU 
                                               & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                                  >> 0xcU))))) {
            vlSelf->forwardEnable1 = 1U;
            vlSelf->forwardData1 = vlSelf->Top__DOT__writeData;
        }
    }
    vlSelf->forwardData2 = 0U;
    if ((0U != (0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                         >> 0xaU)))) {
        if (((((IData)(vlSelf->dbg_EX_MEM_Valid) & 
               (((0U != (7U & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                               >> 9U))) & (2U != (7U 
                                                  & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                                                     >> 9U)))) 
                | (0U != (3U & (vlSelf->Top__DOT__executeMemoryPayload[0U] 
                                >> 1U))))) & (0U != 
                                              (0x1fU 
                                               & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                  >> 0x11U)))) 
             & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                          >> 0xaU)) == (0x1fU & (vlSelf->Top__DOT__executeMemoryPayload[3U] 
                                                 >> 0x11U))))) {
            vlSelf->forwardEnable2 = 1U;
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
        } else if (((((IData)(vlSelf->dbg_MEM_WB_Valid) 
                      & (IData)(vlSelf->Top__DOT__destinationEnable)) 
                     & (0U != (0x1fU & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                        >> 0xcU)))) 
                    & ((0x1fU & (vlSelf->Top__DOT__decodeExecutePayload[2U] 
                                 >> 0xaU)) == (0x1fU 
                                               & (vlSelf->Top__DOT__memoryWritebackPayload[2U] 
                                                  >> 0xcU))))) {
            vlSelf->forwardEnable2 = 1U;
            vlSelf->forwardData2 = vlSelf->Top__DOT__writeData;
        }
    }
    vlSelf->Top__DOT__mretSignal = 0U;
    if ((IData)((5U == (7U & vlSelf->Top__DOT__decodeExecutePayload[0U])))) {
        vlSelf->Top__DOT__mretSignal = 1U;
    }
    vlSelf->dbg_ID_EX_Valid = (1U & vlSelf->Top__DOT__decodeExecutePayload[0U]);
    vlSelf->Top__DOT__fetch__DOT__programCounter = __Vdly__Top__DOT__fetch__DOT__programCounter;
    vlSelf->Top__DOT__mcause = 0U;
    vlSelf->Top__DOT__controlReset = 0U;
    vlSelf->dbg_pc = vlSelf->Top__DOT__fetch__DOT__programCounter;
    vlSelf->dbg_IF_ID_programCounter = ((vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                         << 0x1fU) 
                                        | (vlSelf->Top__DOT__fetchDecodePayload[1U] 
                                           >> 1U));
    vlSelf->dbg_IF_ID_instruction = ((vlSelf->Top__DOT__fetchDecodePayload[3U] 
                                      << 0x1fU) | (
                                                   vlSelf->Top__DOT__fetchDecodePayload[2U] 
                                                   >> 1U));
    vlSelf->dbg_IF_ID_Valid = (1U & vlSelf->Top__DOT__fetchDecodePayload[0U]);
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if (((IData)(vlSelf->dbg_MEM_WB_Valid) & (vlSelf->Top__DOT__memoryWritebackPayload[1U] 
                                                  >> 8U))) {
            if ((0x800U & vlSelf->Top__DOT__memoryWritebackPayload[1U])) {
                vlSelf->Top__DOT__mcause = 4U;
            } else if ((0x400U & vlSelf->Top__DOT__memoryWritebackPayload[1U])) {
                vlSelf->Top__DOT__mcause = 6U;
            }
            vlSelf->Top__DOT__controlReset = 1U;
        } else if (((IData)(vlSelf->dbg_EX_MEM_Valid) 
                    & (vlSelf->Top__DOT__executeMemoryPayload[1U] 
                       >> 8U))) {
            vlSelf->Top__DOT__mcause = 0U;
            vlSelf->Top__DOT__controlReset = 1U;
        } else if ((1U & (~ (IData)(vlSelf->Top__DOT__mretSignal)))) {
            if (((IData)(vlSelf->dbg_ID_EX_Valid) & 
                 (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                  >> 1U))) {
                vlSelf->Top__DOT__mcause = 2U;
                vlSelf->Top__DOT__controlReset = 1U;
            } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                        & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 4U))) {
                vlSelf->Top__DOT__mcause = 0xbU;
                vlSelf->Top__DOT__controlReset = 1U;
            } else if (((IData)(vlSelf->dbg_ID_EX_Valid) 
                        & (vlSelf->Top__DOT__decodeExecutePayload[0U] 
                           >> 3U))) {
                vlSelf->Top__DOT__mcause = 3U;
                vlSelf->Top__DOT__controlReset = 1U;
            }
        }
        vlSelf->dbg_trap = vlSelf->Top__DOT__controlReset;
        vlSelf->Top__DOT__instructionDataValid = 0U;
        vlSelf->Top__DOT__instructionData = 0x13U;
        if ((0U == (3U & vlSelf->dbg_pc))) {
            vlSelf->Top__DOT__instructionDataValid = 1U;
            vlSelf->Top__DOT__instructionData = vlSelf->Top__DOT__imem_inst__DOT__mem
                [(0x3fffU & (vlSelf->dbg_pc >> 2U))];
        }
    } else {
        vlSelf->dbg_trap = vlSelf->Top__DOT__controlReset;
        vlSelf->Top__DOT__instructionDataValid = 0U;
        vlSelf->Top__DOT__instructionData = 0x13U;
    }
    vlSelf->dbg_IMEM_valid = vlSelf->Top__DOT__instructionDataValid;
    vlSelf->dbg_IMEM_data = vlSelf->Top__DOT__instructionData;
}

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x11ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((0x12ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((0x14ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0x18ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((0x13ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0x1cULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0x1fULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___act_comb__TOP__2(vlSelf);
    }
}

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<5> __VpreTriggered;
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
VL_ATTR_COLD void VTop___024root___eval_postponed(VTop___024root* vlSelf);

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
            VL_FATAL_MT("Core/Top.sv", 3, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("Core/Top.sv", 3, "", "NBA region did not converge.");
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
                VL_FATAL_MT("Core/Top.sv", 3, "", "Active region did not converge.");
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
    VTop___024root___eval_postponed(vlSelf);
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
