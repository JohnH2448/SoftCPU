// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
    vlSelf->__VstlTriggered.set(1U, ((IData)(vlSelf->Top__DOT__memoryWritebackControl) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__Top__DOT__memoryWritebackControl__0)));
    vlSelf->__VstlTriggered.set(2U, ((IData)(vlSelf->Top__DOT__readAddress1) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress1__0)));
    vlSelf->__VstlTriggered.set(3U, ((IData)(vlSelf->Top__DOT__readAddress2) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress2__0)));
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__memoryWritebackControl__0 
        = vlSelf->Top__DOT__memoryWritebackControl;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress1__0 
        = vlSelf->Top__DOT__readAddress1;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__readAddress2__0 
        = vlSelf->Top__DOT__readAddress2;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.set(1U, 1U);
        vlSelf->__VstlTriggered.set(2U, 1U);
        vlSelf->__VstlTriggered.set(3U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
