// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrpu_soc.h for the primary calling header

#include "Vrpu_soc__pch.h"

VL_ATTR_COLD void Vrpu_soc___024root___eval_static(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_static\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu_we__0 = vlSelfRef.cpu_we;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu_addr__0 = vlSelfRef.cpu_addr;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu_wdata_a__0 
        = vlSelfRef.cpu_wdata_a;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu_wdata_b__0 
        = vlSelfRef.cpu_wdata_b;
    vlSelfRef.__Vtrigprevexpr___TOP__dma_start__0 = vlSelfRef.dma_start;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vrpu_soc___024root___eval_initial(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_initial\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[0U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[1U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[2U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[3U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[4U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[5U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[6U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[7U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[8U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[9U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[10U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[11U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[12U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[13U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[14U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_b__DOT__memory[15U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[0U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[1U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[2U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[3U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[4U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[5U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[6U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[7U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[8U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[9U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[10U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[11U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[12U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[13U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[14U] = 0U;
        vlSelfRef.rpu_soc__DOT__memory_a__DOT__memory[15U] = 0U;
    }
}

VL_ATTR_COLD void Vrpu_soc___024root___eval_final(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_final\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_soc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vrpu_soc___024root___eval_phase__stl(Vrpu_soc___024root* vlSelf);

VL_ATTR_COLD void Vrpu_soc___024root___eval_settle(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_settle\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vrpu_soc___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/vasylt/hardware_dev/rtl/rpu_soc.sv", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vrpu_soc___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vrpu_soc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_soc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vrpu_soc___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vrpu_soc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD bool Vrpu_soc___024root___eval_phase__stl(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___eval_phase__stl\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrpu_soc___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vrpu_soc___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
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
    return (__VstlExecute);
}

bool Vrpu_soc___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_soc___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vrpu_soc___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( cpu_we)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( cpu_addr)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( cpu_wdata_a)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @( cpu_wdata_b)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @( dma_start)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vrpu_soc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_soc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vrpu_soc___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrpu_soc___024root___ctor_var_reset(Vrpu_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_soc___024root___ctor_var_reset\n"); );
    Vrpu_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->cpu_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2926808991039888122ull);
    vlSelf->cpu_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9730387426955054438ull);
    vlSelf->cpu_wdata_a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12555262791147970248ull);
    vlSelf->cpu_wdata_b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5793466770236682779ull);
    vlSelf->dma_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4393136156052734320ull);
    vlSelf->c00 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7022235423855613906ull);
    vlSelf->c01 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7362001346921410948ull);
    vlSelf->c10 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5112652809076934103ull);
    vlSelf->c11 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4085026105499164931ull);
    vlSelf->rpu_soc__DOT__dma_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14516890165193960727ull);
    vlSelf->rpu_soc__DOT__active_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14261587849595760180ull);
    vlSelf->rpu_soc__DOT____Vcellinp__math_core__b0_flat = 0;
    vlSelf->rpu_soc__DOT____Vcellinp__math_core__a0_flat = 0;
    vlSelf->rpu_soc__DOT__math_core__DOT__a1_skewed = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10402164560037963767ull);
    vlSelf->rpu_soc__DOT__math_core__DOT__b1_skewed = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4637926673410365346ull);
    vlSelf->rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_00_to_01 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5695240115397657075ull);
    vlSelf->rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_10_to_11 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 825771739403477834ull);
    vlSelf->rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_00_to_10 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15638021356770011359ull);
    vlSelf->rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_01_to_11 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13000426445511851228ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->rpu_soc__DOT__memory_b__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16508499913062656999ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->rpu_soc__DOT__memory_a__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8604540564213598715ull);
    }
    vlSelf->rpu_soc__DOT__dma__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10700768027347122624ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cpu_we__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cpu_addr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cpu_wdata_a__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cpu_wdata_b__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__dma_start__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
