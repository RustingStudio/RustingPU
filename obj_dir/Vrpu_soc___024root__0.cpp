// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrpu_soc.h for the primary calling header

#include "Vrpu_soc__pch.h"

bool Vrpu_soc___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_soc___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vrpu_soc___024root___eval_phase__ico(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_phase__ico\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        (((((IData)(vlSelfRef.dma_start) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__dma_start__0)) 
                                                           << 6U) 
                                                          | ((((IData)(vlSelfRef.cpu_wdata_b) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu_wdata_b__0)) 
                                                              << 5U) 
                                                             | (((IData)(vlSelfRef.cpu_wdata_a) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu_wdata_a__0)) 
                                                                << 4U))) 
                                                         | (((((IData)(vlSelfRef.cpu_addr) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu_addr__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.cpu_we) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu_we__0)) 
                                                                << 2U)) 
                                                            | ((((IData)(vlSelfRef.reset) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.clk) 
                                                                  != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
        vlSelfRef.__Vtrigprevexpr___TOP__cpu_we__0 
            = vlSelfRef.cpu_we;
        vlSelfRef.__Vtrigprevexpr___TOP__cpu_addr__0 
            = vlSelfRef.cpu_addr;
        vlSelfRef.__Vtrigprevexpr___TOP__cpu_wdata_a__0 
            = vlSelfRef.cpu_wdata_a;
        vlSelfRef.__Vtrigprevexpr___TOP__cpu_wdata_b__0 
            = vlSelfRef.cpu_wdata_b;
        vlSelfRef.__Vtrigprevexpr___TOP__dma_start__0 
            = vlSelfRef.dma_start;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (8ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000010ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000020ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000040ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrpu_soc___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vrpu_soc___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((8ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_sequent__TOP__0
                    vlSelfRef.cpu_rdata = (((2U & (IData)(vlSelfRef.cpu_addr))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.cpu_addr))
                                                 ? (IData)(vlSelfRef.rpu_soc__DOT__c11)
                                                 : (IData)(vlSelfRef.rpu_soc__DOT__c10))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.cpu_addr))
                                                 ? (IData)(vlSelfRef.rpu_soc__DOT__c01)
                                                 : (IData)(vlSelfRef.rpu_soc__DOT__c00))) 
                                           & (- (IData)((IData)(
                                                                (4U 
                                                                 == 
                                                                 (0x0cU 
                                                                  & (IData)(vlSelfRef.cpu_addr)))))));
                }
            }
            if ((0x000000000000000cULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    vlSelfRef.rpu_soc__DOT__active_addr 
                        = ((IData)(vlSelfRef.cpu_we)
                            ? (IData)(vlSelfRef.cpu_addr)
                            : (IData)(vlSelfRef.rpu_soc__DOT__dma_addr));
                    vlSelfRef.rpu_soc__DOT____Vcellinp__math_core__a0_flat 
                        = (0x0000000fU & vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory
                           [vlSelfRef.rpu_soc__DOT__active_addr]);
                    vlSelfRef.rpu_soc__DOT____Vcellinp__math_core__b0_flat 
                        = (0x0000000fU & vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory
                           [vlSelfRef.rpu_soc__DOT__active_addr]);
                }
            }
        }
    }
    return (__VicoExecute);
}

bool Vrpu_soc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*1:0*/, 128> Vrpu_soc__ConstPool__TABLE_h3455db76_0;

void Vrpu_soc___024root___eval_nba(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_nba\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            CData/*7:0*/ __Vinline_0__nba_sequent__TOP__0___VdlyVal__rpu_soc__DOT__memory_b__DOT__memory__v0;
            __Vinline_0__nba_sequent__TOP__0___VdlyVal__rpu_soc__DOT__memory_b__DOT__memory__v0 = 0;
            CData/*3:0*/ __Vinline_0__nba_sequent__TOP__0___VdlyDim0__rpu_soc__DOT__memory_b__DOT__memory__v0;
            __Vinline_0__nba_sequent__TOP__0___VdlyDim0__rpu_soc__DOT__memory_b__DOT__memory__v0 = 0;
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_b__DOT__memory__v0;
            __Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_b__DOT__memory__v0 = 0;
            CData/*7:0*/ __Vinline_0__nba_sequent__TOP__0___VdlyVal__rpu_soc__DOT__memory_a__DOT__memory__v0;
            __Vinline_0__nba_sequent__TOP__0___VdlyVal__rpu_soc__DOT__memory_a__DOT__memory__v0 = 0;
            CData/*3:0*/ __Vinline_0__nba_sequent__TOP__0___VdlyDim0__rpu_soc__DOT__memory_a__DOT__memory__v0;
            __Vinline_0__nba_sequent__TOP__0___VdlyDim0__rpu_soc__DOT__memory_a__DOT__memory__v0 = 0;
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_a__DOT__memory__v0;
            __Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_a__DOT__memory__v0 = 0;
            __Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_b__DOT__memory__v0 = 0U;
            __Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_a__DOT__memory__v0 = 0U;
            if (vlSelfRef.reset) {
                vlSelfRef.rpu_soc__DOT__dma__DOT__state = 0U;
                vlSelfRef.rpu_soc__DOT__c00 = 0U;
                vlSelfRef.rpu_soc__DOT__c10 = 0U;
                vlSelfRef.rpu_soc__DOT__c01 = 0U;
                vlSelfRef.rpu_soc__DOT__c11 = 0U;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_00_to_10 = 0U;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_00_to_01 = 0U;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_10_to_11 = 0U;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_01_to_11 = 0U;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__a1_skewed = 0U;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__b1_skewed = 0U;
            } else {
                vlSelfRef.rpu_soc__DOT__dma__DOT__state 
                    = Vrpu_soc__ConstPool__TABLE_h3455db76_0
                    [(((IData)(vlSelfRef.rpu_soc__DOT__dma_addr) 
                       << 3U) | (((IData)(vlSelfRef.dma_start) 
                                  << 2U) | (IData)(vlSelfRef.rpu_soc__DOT__dma__DOT__state)))];
                vlSelfRef.rpu_soc__DOT__c00 = (0x000000ffU 
                                               & (((IData)(vlSelfRef.rpu_soc__DOT____Vcellinp__math_core__a0_flat) 
                                                   * (IData)(vlSelfRef.rpu_soc__DOT____Vcellinp__math_core__b0_flat)) 
                                                  + (IData)(vlSelfRef.rpu_soc__DOT__c00)));
                vlSelfRef.rpu_soc__DOT__c10 = (0x000000ffU 
                                               & (((IData)(vlSelfRef.rpu_soc__DOT__math_core__DOT__a1_skewed) 
                                                   * (IData)(vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_00_to_10)) 
                                                  + (IData)(vlSelfRef.rpu_soc__DOT__c10)));
                vlSelfRef.rpu_soc__DOT__c01 = (0x000000ffU 
                                               & (((IData)(vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_00_to_01) 
                                                   * (IData)(vlSelfRef.rpu_soc__DOT__math_core__DOT__b1_skewed)) 
                                                  + (IData)(vlSelfRef.rpu_soc__DOT__c01)));
                vlSelfRef.rpu_soc__DOT__c11 = (0x000000ffU 
                                               & (((IData)(vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_10_to_11) 
                                                   * (IData)(vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_01_to_11)) 
                                                  + (IData)(vlSelfRef.rpu_soc__DOT__c11)));
                vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_00_to_10 
                    = vlSelfRef.rpu_soc__DOT____Vcellinp__math_core__b0_flat;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_00_to_01 
                    = vlSelfRef.rpu_soc__DOT____Vcellinp__math_core__a0_flat;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_10_to_11 
                    = vlSelfRef.rpu_soc__DOT__math_core__DOT__a1_skewed;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_01_to_11 
                    = vlSelfRef.rpu_soc__DOT__math_core__DOT__b1_skewed;
                vlSelfRef.rpu_soc__DOT__math_core__DOT__a1_skewed 
                    = (0x0000000fU & (vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory
                                      [vlSelfRef.rpu_soc__DOT__active_addr] 
                                      >> 4U));
                vlSelfRef.rpu_soc__DOT__math_core__DOT__b1_skewed 
                    = (0x0000000fU & (vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory
                                      [vlSelfRef.rpu_soc__DOT__active_addr] 
                                      >> 4U));
            }
            if (vlSelfRef.cpu_we) {
                __Vinline_0__nba_sequent__TOP__0___VdlyVal__rpu_soc__DOT__memory_b__DOT__memory__v0 
                    = vlSelfRef.cpu_wdata_b;
                __Vinline_0__nba_sequent__TOP__0___VdlyDim0__rpu_soc__DOT__memory_b__DOT__memory__v0 
                    = vlSelfRef.rpu_soc__DOT__active_addr;
                __Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_b__DOT__memory__v0 = 1U;
                __Vinline_0__nba_sequent__TOP__0___VdlyVal__rpu_soc__DOT__memory_a__DOT__memory__v0 
                    = vlSelfRef.cpu_wdata_a;
                __Vinline_0__nba_sequent__TOP__0___VdlyDim0__rpu_soc__DOT__memory_a__DOT__memory__v0 
                    = vlSelfRef.rpu_soc__DOT__active_addr;
                __Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_a__DOT__memory__v0 = 1U;
            }
            vlSelfRef.cpu_rdata = (((2U & (IData)(vlSelfRef.cpu_addr))
                                     ? ((1U & (IData)(vlSelfRef.cpu_addr))
                                         ? (IData)(vlSelfRef.rpu_soc__DOT__c11)
                                         : (IData)(vlSelfRef.rpu_soc__DOT__c10))
                                     : ((1U & (IData)(vlSelfRef.cpu_addr))
                                         ? (IData)(vlSelfRef.rpu_soc__DOT__c01)
                                         : (IData)(vlSelfRef.rpu_soc__DOT__c00))) 
                                   & (- (IData)((IData)(
                                                        (4U 
                                                         == 
                                                         (0x0cU 
                                                          & (IData)(vlSelfRef.cpu_addr)))))));
            if (__Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_a__DOT__memory__v0) {
                vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[__Vinline_0__nba_sequent__TOP__0___VdlyDim0__rpu_soc__DOT__memory_a__DOT__memory__v0] 
                    = __Vinline_0__nba_sequent__TOP__0___VdlyVal__rpu_soc__DOT__memory_a__DOT__memory__v0;
            }
            if (__Vinline_0__nba_sequent__TOP__0___VdlySet__rpu_soc__DOT__memory_b__DOT__memory__v0) {
                vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[__Vinline_0__nba_sequent__TOP__0___VdlyDim0__rpu_soc__DOT__memory_b__DOT__memory__v0] 
                    = __Vinline_0__nba_sequent__TOP__0___VdlyVal__rpu_soc__DOT__memory_b__DOT__memory__v0;
            }
        }
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            CData/*3:0*/ __Vinline_0__nba_sequent__TOP__1___Vdly__rpu_soc__DOT__dma_addr;
            __Vinline_0__nba_sequent__TOP__1___Vdly__rpu_soc__DOT__dma_addr = 0;
            __Vinline_0__nba_sequent__TOP__1___Vdly__rpu_soc__DOT__dma_addr 
                = vlSelfRef.rpu_soc__DOT__dma_addr;
            if ((0U == (IData)(vlSelfRef.rpu_soc__DOT__dma__DOT__state))) {
                __Vinline_0__nba_sequent__TOP__1___Vdly__rpu_soc__DOT__dma_addr = 0U;
            } else if ((1U == (IData)(vlSelfRef.rpu_soc__DOT__dma__DOT__state))) {
                __Vinline_0__nba_sequent__TOP__1___Vdly__rpu_soc__DOT__dma_addr 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.rpu_soc__DOT__dma_addr)));
            }
            vlSelfRef.rpu_soc__DOT__dma_addr = __Vinline_0__nba_sequent__TOP__1___Vdly__rpu_soc__DOT__dma_addr;
            vlSelfRef.rpu_soc__DOT__active_addr = ((IData)(vlSelfRef.cpu_we)
                                                    ? (IData)(vlSelfRef.cpu_addr)
                                                    : (IData)(vlSelfRef.rpu_soc__DOT__dma_addr));
        }
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            vlSelfRef.rpu_soc__DOT____Vcellinp__math_core__a0_flat 
                = (0x0000000fU & vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory
                   [vlSelfRef.rpu_soc__DOT__active_addr]);
            vlSelfRef.rpu_soc__DOT____Vcellinp__math_core__b0_flat 
                = (0x0000000fU & vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory
                   [vlSelfRef.rpu_soc__DOT__active_addr]);
        }
    }
}

void Vrpu_soc___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_soc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vrpu_soc___024root___eval_phase__act(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_phase__act\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((~ (IData)(vlSelfRef.clk)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1)) 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrpu_soc___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vrpu_soc___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vrpu_soc___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vrpu_soc___024root___eval_phase__nba(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_phase__nba\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vrpu_soc___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vrpu_soc___024root___eval_nba(vlSelf);
        Vrpu_soc___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vrpu_soc___024root___eval(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vrpu_soc___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/vasylt/hardware_dev/rtl/rpu_soc.sv", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vrpu_soc___024root___eval_phase__ico(vlSelf);
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vrpu_soc___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/vasylt/hardware_dev/rtl/rpu_soc.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vrpu_soc___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/vasylt/hardware_dev/rtl/rpu_soc.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vrpu_soc___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vrpu_soc___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vrpu_soc___024root___eval_debug_assertions(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_debug_assertions\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.cpu_we & 0xfeU)))) {
        Verilated::overWidthError("cpu_we");
    }
    if (VL_UNLIKELY(((vlSelfRef.cpu_addr & 0xf0U)))) {
        Verilated::overWidthError("cpu_addr");
    }
    if (VL_UNLIKELY(((vlSelfRef.dma_start & 0xfeU)))) {
        Verilated::overWidthError("dma_start");
    }
}
#endif  // VL_DEBUG
