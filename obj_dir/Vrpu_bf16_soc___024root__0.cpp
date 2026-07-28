// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrpu_bf16_soc.h for the primary calling header

#include "Vrpu_bf16_soc__pch.h"

bool Vrpu_bf16_soc___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___trigger_anySet__ico\n"); );
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
VL_ATTR_COLD void Vrpu_bf16_soc___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vrpu_bf16_soc___024root___eval_phase__ico(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_phase__ico\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        (((((IData)(vlSelfRef.mem_wdata) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_wdata__0)) 
                                                           << 5U) 
                                                          | (((IData)(vlSelfRef.mem_addr) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_addr__0)) 
                                                             << 4U)) 
                                                         | (((((IData)(vlSelfRef.mem_we) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_we__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.start) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__start__0)) 
                                                                << 2U)) 
                                                            | ((((IData)(vlSelfRef.reset) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.clk) 
                                                                  != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
        vlSelfRef.__Vtrigprevexpr___TOP__start__0 = vlSelfRef.start;
        vlSelfRef.__Vtrigprevexpr___TOP__mem_we__0 
            = vlSelfRef.mem_we;
        vlSelfRef.__Vtrigprevexpr___TOP__mem_addr__0 
            = vlSelfRef.mem_addr;
        vlSelfRef.__Vtrigprevexpr___TOP__mem_wdata__0 
            = vlSelfRef.mem_wdata;
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
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrpu_bf16_soc___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vrpu_bf16_soc___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((2ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_sequent__TOP__0
                    vlSelfRef.rpu_bf16_soc__DOT__core_reset 
                        = ((IData)(vlSelfRef.reset) 
                           | (3U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)));
                }
            }
            if ((0x0000000000000010ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_sequent__TOP__1
                    IData/*31:0*/ __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr;
                    __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr = 0;
                    __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr 
                        = vlSelfRef.mem_addr;
                    vlSelfRef.mem_rdata = ((0U == __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                            ? 0U : 
                                           ((1U == __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                             ? (((IData)(vlSelfRef.done) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.busy))
                                             : ((2U 
                                                 == __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                                 ? (IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_a_base)
                                                 : 
                                                ((3U 
                                                  == __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                                  ? (IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_b_base)
                                                  : 
                                                 ((4U 
                                                   == __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                                   ? (IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_c_base)
                                                   : 
                                                  (((0x00001000U 
                                                     <= __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr) 
                                                    & (0x00002000U 
                                                       > __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr))
                                                    ? vlSelfRef.rpu_bf16_soc__DOT__ext_mem
                                                   [
                                                   (0x00000fffU 
                                                    & __Vinline_0__eval_ico___Vinline_0__ico_sequent__TOP__1_rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)]
                                                    : 0U))))));
                }
            }
        }
    }
    return (__VicoExecute);
}

bool Vrpu_bf16_soc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___trigger_anySet__act\n"); );
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

void Vrpu_bf16_soc___024root___nba_sequent__TOP__0(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___nba_sequent__TOP__0\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ rpu_bf16_soc__DOT__unnamedblk3__DOT__addr;
    rpu_bf16_soc__DOT__unnamedblk3__DOT__addr = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0;
    SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0;
    CData/*6:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0;
    CData/*3:0*/ __Vdly__rpu_bf16_soc__DOT__state;
    __Vdly__rpu_bf16_soc__DOT__state = 0;
    IData/*31:0*/ __Vdly__cycles;
    __Vdly__cycles = 0;
    CData/*2:0*/ __Vdly__rpu_bf16_soc__DOT__stream_idx;
    __Vdly__rpu_bf16_soc__DOT__stream_idx = 0;
    CData/*4:0*/ __Vdly__rpu_bf16_soc__DOT__drain_count;
    __Vdly__rpu_bf16_soc__DOT__drain_count = 0;
    CData/*5:0*/ __Vdly__rpu_bf16_soc__DOT__dma_idx;
    __Vdly__rpu_bf16_soc__DOT__dma_idx = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__ext_mem__v0;
    __VdlyVal__rpu_bf16_soc__DOT__ext_mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__rpu_bf16_soc__DOT__ext_mem__v0;
    __VdlyDim0__rpu_bf16_soc__DOT__ext_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__ext_mem__v0;
    __VdlySet__rpu_bf16_soc__DOT__ext_mem__v0 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__ext_mem__v1;
    __VdlyVal__rpu_bf16_soc__DOT__ext_mem__v1 = 0;
    SData/*11:0*/ __VdlyDim0__rpu_bf16_soc__DOT__ext_mem__v1;
    __VdlyDim0__rpu_bf16_soc__DOT__ext_mem__v1 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__ext_mem__v1;
    __VdlySet__rpu_bf16_soc__DOT__ext_mem__v1 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v0;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v0 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__mem_c__v0;
    __VdlySet__rpu_bf16_soc__DOT__mem_c__v0 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v1;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v1 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__mem_c__v1;
    __VdlySet__rpu_bf16_soc__DOT__mem_c__v1 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v2;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v2 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v3;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v3 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v4;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v4 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v5;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v5 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v6;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v6 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v7;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v7 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v8;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v8 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v9;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v9 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v10;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v10 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v11;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v11 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v12;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v12 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v13;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v13 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v14;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v14 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v15;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v15 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v16;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v16 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v17;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v17 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v18;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v18 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v19;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v19 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v20;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v20 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v21;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v21 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v22;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v22 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v23;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v23 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v24;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v24 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v25;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v25 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v26;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v26 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v27;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v27 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v28;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v28 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v29;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v29 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v30;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v30 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v31;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v31 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v32;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v32 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v33;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v33 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v34;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v34 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v35;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v35 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v36;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v36 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v37;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v37 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v38;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v38 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v39;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v39 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v40;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v40 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v41;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v41 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v42;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v42 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v43;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v43 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v44;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v44 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v45;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v45 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v46;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v46 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v47;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v47 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v48;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v48 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v49;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v49 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v50;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v50 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v51;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v51 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v52;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v52 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v53;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v53 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v54;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v54 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v55;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v55 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v56;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v56 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v57;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v57 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v58;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v58 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v59;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v59 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v60;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v60 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v61;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v61 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v62;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v62 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_c__v63;
    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v63 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_b__v0;
    __VdlyVal__rpu_bf16_soc__DOT__mem_b__v0 = 0;
    CData/*5:0*/ __VdlyDim0__rpu_bf16_soc__DOT__mem_b__v0;
    __VdlyDim0__rpu_bf16_soc__DOT__mem_b__v0 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__mem_b__v0;
    __VdlySet__rpu_bf16_soc__DOT__mem_b__v0 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__mem_a__v0;
    __VdlyVal__rpu_bf16_soc__DOT__mem_a__v0 = 0;
    CData/*5:0*/ __VdlyDim0__rpu_bf16_soc__DOT__mem_a__v0;
    __VdlyDim0__rpu_bf16_soc__DOT__mem_a__v0 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__mem_a__v0;
    __VdlySet__rpu_bf16_soc__DOT__mem_a__v0 = 0;
    // Body
    __VdlySet__rpu_bf16_soc__DOT__ext_mem__v0 = 0U;
    __Vdly__cycles = vlSelfRef.cycles;
    __Vdly__rpu_bf16_soc__DOT__drain_count = vlSelfRef.rpu_bf16_soc__DOT__drain_count;
    __Vdly__rpu_bf16_soc__DOT__dma_idx = vlSelfRef.rpu_bf16_soc__DOT__dma_idx;
    __VdlySet__rpu_bf16_soc__DOT__ext_mem__v1 = 0U;
    __VdlySet__rpu_bf16_soc__DOT__mem_c__v0 = 0U;
    __VdlySet__rpu_bf16_soc__DOT__mem_c__v1 = 0U;
    __VdlySet__rpu_bf16_soc__DOT__mem_b__v0 = 0U;
    __VdlySet__rpu_bf16_soc__DOT__mem_a__v0 = 0U;
    __Vdly__rpu_bf16_soc__DOT__stream_idx = vlSelfRef.rpu_bf16_soc__DOT__stream_idx;
    __Vdly__rpu_bf16_soc__DOT__state = vlSelfRef.rpu_bf16_soc__DOT__state;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (vlSelfRef.mem_we) {
            if ((0U != (IData)(vlSelfRef.mem_addr))) {
                if ((2U != (IData)(vlSelfRef.mem_addr))) {
                    if ((3U != (IData)(vlSelfRef.mem_addr))) {
                        if ((4U != (IData)(vlSelfRef.mem_addr))) {
                            if (((0x1000U <= (IData)(vlSelfRef.mem_addr)) 
                                 & (0x2000U > (IData)(vlSelfRef.mem_addr)))) {
                                __VdlyVal__rpu_bf16_soc__DOT__ext_mem__v0 
                                    = vlSelfRef.mem_wdata;
                                __VdlyDim0__rpu_bf16_soc__DOT__ext_mem__v0 
                                    = (0x00000fffU 
                                       & (IData)(vlSelfRef.mem_addr));
                                __VdlySet__rpu_bf16_soc__DOT__ext_mem__v0 = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelfRef.reset) {
        __Vdly__rpu_bf16_soc__DOT__state = 0U;
        __Vdly__cycles = 0U;
        __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
        __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
        __Vdly__rpu_bf16_soc__DOT__dma_idx = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__start_request = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__reg_c_base = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__reg_b_base = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__reg_a_base = 0U;
    } else {
        if (vlSelfRef.busy) {
            __Vdly__cycles = ((IData)(1U) + vlSelfRef.cycles);
        }
        if ((8U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
            __Vdly__rpu_bf16_soc__DOT__state = 0U;
        } else if ((4U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
                    if (((IData)(vlSelfRef.rpu_bf16_soc__DOT__start_request) 
                         | (IData)(vlSelfRef.start))) {
                        __Vdly__cycles = 0U;
                        __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
                        __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
                        __Vdly__rpu_bf16_soc__DOT__dma_idx = 0U;
                        __Vdly__rpu_bf16_soc__DOT__state = 1U;
                    }
                } else {
                    __VdlyVal__rpu_bf16_soc__DOT__ext_mem__v1 
                        = vlSelfRef.rpu_bf16_soc__DOT__mem_c
                        [vlSelfRef.rpu_bf16_soc__DOT__dma_idx];
                    __VdlyDim0__rpu_bf16_soc__DOT__ext_mem__v1 
                        = (0x00000fffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_c_base) 
                                          + (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx)));
                    __VdlySet__rpu_bf16_soc__DOT__ext_mem__v1 = 1U;
                    if ((0x3fU == (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx))) {
                        __Vdly__rpu_bf16_soc__DOT__dma_idx = 0U;
                        __Vdly__rpu_bf16_soc__DOT__state = 7U;
                    } else {
                        __Vdly__rpu_bf16_soc__DOT__dma_idx 
                            = (0x0000003fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx)));
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
                if ((0x0fU == (IData)(vlSelfRef.rpu_bf16_soc__DOT__drain_count))) {
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v0 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[0U][0U];
                    __VdlySet__rpu_bf16_soc__DOT__mem_c__v0 = 1U;
                    __Vdly__rpu_bf16_soc__DOT__dma_idx = 0U;
                    __Vdly__rpu_bf16_soc__DOT__state = 6U;
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v1 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[0U][1U];
                    __VdlySet__rpu_bf16_soc__DOT__mem_c__v1 = 1U;
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v2 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[0U][2U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v3 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[0U][3U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v4 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[0U][4U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v5 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[0U][5U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v6 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[0U][6U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v7 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[0U][7U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v8 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[1U][0U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v9 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[1U][1U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v10 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[1U][2U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v11 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[1U][3U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v12 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[1U][4U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v13 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[1U][5U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v14 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[1U][6U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v15 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[1U][7U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v16 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[2U][0U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v17 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[2U][1U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v18 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[2U][2U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v19 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[2U][3U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v20 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[2U][4U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v21 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[2U][5U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v22 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[2U][6U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v23 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[2U][7U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v24 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[3U][0U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v25 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[3U][1U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v26 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[3U][2U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v27 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[3U][3U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v28 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[3U][4U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v29 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[3U][5U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v30 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[3U][6U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v31 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[3U][7U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v32 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[4U][0U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v33 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[4U][1U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v34 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[4U][2U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v35 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[4U][3U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v36 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[4U][4U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v37 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[4U][5U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v38 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[4U][6U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v39 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[4U][7U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v40 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[5U][0U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v41 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[5U][1U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v42 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[5U][2U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v43 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[5U][3U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v44 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[5U][4U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v45 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[5U][5U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v46 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[5U][6U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v47 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[5U][7U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v48 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[6U][0U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v49 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[6U][1U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v50 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[6U][2U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v51 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[6U][3U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v52 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[6U][4U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v53 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[6U][5U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v54 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[6U][6U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v55 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[6U][7U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v56 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[7U][0U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v57 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[7U][1U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v58 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[7U][2U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v59 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[7U][3U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v60 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[7U][4U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v61 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[7U][5U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v62 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[7U][6U];
                    __VdlyVal__rpu_bf16_soc__DOT__mem_c__v63 
                        = vlSelfRef.rpu_bf16_soc__DOT__c[7U][7U];
                } else {
                    __Vdly__rpu_bf16_soc__DOT__drain_count 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.rpu_bf16_soc__DOT__drain_count)));
                }
            } else if ((7U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx))) {
                __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
                __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
                __Vdly__rpu_bf16_soc__DOT__state = 5U;
            } else {
                __Vdly__rpu_bf16_soc__DOT__stream_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)));
            }
        } else if ((2U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
                __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
                __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
                __Vdly__rpu_bf16_soc__DOT__state = 4U;
            } else {
                __VdlyVal__rpu_bf16_soc__DOT__mem_b__v0 
                    = vlSelfRef.rpu_bf16_soc__DOT__ext_mem
                    [(0x00000fffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_b_base) 
                                     + (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx)))];
                __VdlyDim0__rpu_bf16_soc__DOT__mem_b__v0 
                    = vlSelfRef.rpu_bf16_soc__DOT__dma_idx;
                __VdlySet__rpu_bf16_soc__DOT__mem_b__v0 = 1U;
                if ((0x3fU == (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx))) {
                    __Vdly__rpu_bf16_soc__DOT__dma_idx = 0U;
                    __Vdly__rpu_bf16_soc__DOT__state = 3U;
                } else {
                    __Vdly__rpu_bf16_soc__DOT__dma_idx 
                        = (0x0000003fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx)));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
            __VdlyVal__rpu_bf16_soc__DOT__mem_a__v0 
                = vlSelfRef.rpu_bf16_soc__DOT__ext_mem
                [(0x00000fffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_a_base) 
                                 + (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx)))];
            __VdlyDim0__rpu_bf16_soc__DOT__mem_a__v0 
                = vlSelfRef.rpu_bf16_soc__DOT__dma_idx;
            __VdlySet__rpu_bf16_soc__DOT__mem_a__v0 = 1U;
            if ((0x3fU == (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx))) {
                __Vdly__rpu_bf16_soc__DOT__dma_idx = 0U;
                __Vdly__rpu_bf16_soc__DOT__state = 2U;
            } else {
                __Vdly__rpu_bf16_soc__DOT__dma_idx 
                    = (0x0000003fU & ((IData)(1U) + (IData)(vlSelfRef.rpu_bf16_soc__DOT__dma_idx)));
            }
        } else if (((IData)(vlSelfRef.rpu_bf16_soc__DOT__start_request) 
                    | (IData)(vlSelfRef.start))) {
            __Vdly__cycles = 0U;
            __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
            __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
            __Vdly__rpu_bf16_soc__DOT__dma_idx = 0U;
            __Vdly__rpu_bf16_soc__DOT__state = 1U;
        }
        vlSelfRef.rpu_bf16_soc__DOT__start_request = 0U;
        if (vlSelfRef.mem_we) {
            if ((0U == (IData)(vlSelfRef.mem_addr))) {
                vlSelfRef.rpu_bf16_soc__DOT__start_request 
                    = (1U & (IData)(vlSelfRef.mem_wdata));
            }
            if ((0U != (IData)(vlSelfRef.mem_addr))) {
                if ((2U != (IData)(vlSelfRef.mem_addr))) {
                    if ((3U != (IData)(vlSelfRef.mem_addr))) {
                        if ((4U == (IData)(vlSelfRef.mem_addr))) {
                            vlSelfRef.rpu_bf16_soc__DOT__reg_c_base 
                                = vlSelfRef.mem_wdata;
                        }
                    }
                    if ((3U == (IData)(vlSelfRef.mem_addr))) {
                        vlSelfRef.rpu_bf16_soc__DOT__reg_b_base 
                            = vlSelfRef.mem_wdata;
                    }
                }
                if ((2U == (IData)(vlSelfRef.mem_addr))) {
                    vlSelfRef.rpu_bf16_soc__DOT__reg_a_base 
                        = vlSelfRef.mem_wdata;
                }
            }
        }
    }
    if (vlSelfRef.rpu_bf16_soc__DOT__core_reset) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__6__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__6__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__5__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__5__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__5__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__5__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0U;
    } else {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][7U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__6__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__6__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][6U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__5__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__5__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__5__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__5__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][5U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][4U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][3U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[3U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[3U][2U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[3U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[3U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[3U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[3U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[2U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[2U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[2U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[2U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][0U];
    }
    vlSelfRef.cycles = __Vdly__cycles;
    vlSelfRef.rpu_bf16_soc__DOT__drain_count = __Vdly__rpu_bf16_soc__DOT__drain_count;
    vlSelfRef.rpu_bf16_soc__DOT__dma_idx = __Vdly__rpu_bf16_soc__DOT__dma_idx;
    if (__VdlySet__rpu_bf16_soc__DOT__ext_mem__v0) {
        vlSelfRef.rpu_bf16_soc__DOT__ext_mem[__VdlyDim0__rpu_bf16_soc__DOT__ext_mem__v0] 
            = __VdlyVal__rpu_bf16_soc__DOT__ext_mem__v0;
    }
    if (__VdlySet__rpu_bf16_soc__DOT__ext_mem__v1) {
        vlSelfRef.rpu_bf16_soc__DOT__ext_mem[__VdlyDim0__rpu_bf16_soc__DOT__ext_mem__v1] 
            = __VdlyVal__rpu_bf16_soc__DOT__ext_mem__v1;
    }
    if (__VdlySet__rpu_bf16_soc__DOT__mem_c__v0) {
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[0U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v0;
    }
    if (__VdlySet__rpu_bf16_soc__DOT__mem_c__v1) {
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[1U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v1;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[2U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v2;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[3U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v3;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[4U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v4;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[5U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v5;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[6U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v6;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[7U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v7;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[8U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v8;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[9U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v9;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[10U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v10;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[11U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v11;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[12U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v12;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[13U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v13;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[14U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v14;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[15U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v15;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[16U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v16;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[17U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v17;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[18U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v18;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[19U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v19;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[20U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v20;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[21U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v21;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[22U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v22;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[23U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v23;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[24U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v24;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[25U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v25;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[26U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v26;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[27U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v27;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[28U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v28;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[29U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v29;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[30U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v30;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[31U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v31;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[32U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v32;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[33U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v33;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[34U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v34;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[35U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v35;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[36U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v36;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[37U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v37;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[38U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v38;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[39U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v39;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[40U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v40;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[41U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v41;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[42U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v42;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[43U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v43;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[44U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v44;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[45U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v45;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[46U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v46;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[47U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v47;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[48U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v48;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[49U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v49;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[50U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v50;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[51U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v51;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[52U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v52;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[53U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v53;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[54U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v54;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[55U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v55;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[56U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v56;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[57U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v57;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[58U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v58;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[59U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v59;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[60U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v60;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[61U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v61;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[62U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v62;
        vlSelfRef.rpu_bf16_soc__DOT__mem_c[63U] = __VdlyVal__rpu_bf16_soc__DOT__mem_c__v63;
    }
    if (__VdlySet__rpu_bf16_soc__DOT__mem_b__v0) {
        vlSelfRef.rpu_bf16_soc__DOT__mem_b[__VdlyDim0__rpu_bf16_soc__DOT__mem_b__v0] 
            = __VdlyVal__rpu_bf16_soc__DOT__mem_b__v0;
    }
    if (__VdlySet__rpu_bf16_soc__DOT__mem_a__v0) {
        vlSelfRef.rpu_bf16_soc__DOT__mem_a[__VdlyDim0__rpu_bf16_soc__DOT__mem_a__v0] 
            = __VdlyVal__rpu_bf16_soc__DOT__mem_a__v0;
    }
    vlSelfRef.rpu_bf16_soc__DOT__stream_idx = __Vdly__rpu_bf16_soc__DOT__stream_idx;
    vlSelfRef.rpu_bf16_soc__DOT__state = __Vdly__rpu_bf16_soc__DOT__state;
    vlSelfRef.rpu_bf16_soc__DOT__core_reset = ((IData)(vlSelfRef.reset) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)));
    vlSelfRef.busy = ((3U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                      | ((4U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                         | ((1U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                            | ((2U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                               | ((5U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                                  | (6U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))))));
    vlSelfRef.done = (7U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state));
    vlSelfRef.rpu_bf16_soc__DOT__a_flat[0U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_a
                                               [vlSelfRef.rpu_bf16_soc__DOT__stream_idx] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__a_flat[1U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_a
                                               [(0x0000003fU 
                                                 & ((IData)(8U) 
                                                    + (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__a_flat[2U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_a
                                               [(0x0000003fU 
                                                 & ((IData)(0x10U) 
                                                    + (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__a_flat[3U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_a
                                               [(0x0000003fU 
                                                 & ((IData)(0x18U) 
                                                    + (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__a_flat[4U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_a
                                               [(0x0000003fU 
                                                 & ((IData)(0x20U) 
                                                    + (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__a_flat[5U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_a
                                               [(0x0000003fU 
                                                 & ((IData)(0x28U) 
                                                    + (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__a_flat[6U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_a
                                               [(0x0000003fU 
                                                 & ((IData)(0x30U) 
                                                    + (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__a_flat[7U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_a
                                               [(0x0000003fU 
                                                 & ((IData)(0x38U) 
                                                    + (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__b_flat[0U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_b
                                               [(0x0000003fU 
                                                 & VL_MULS_III(32, (IData)(8U), (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx)))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__b_flat[1U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_b
                                               [(0x0000003fU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    VL_MULS_III(32, (IData)(8U), (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx))))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__b_flat[2U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_b
                                               [(0x0000003fU 
                                                 & ((IData)(2U) 
                                                    + 
                                                    VL_MULS_III(32, (IData)(8U), (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx))))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__b_flat[3U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_b
                                               [(0x0000003fU 
                                                 & ((IData)(3U) 
                                                    + 
                                                    VL_MULS_III(32, (IData)(8U), (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx))))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__b_flat[4U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_b
                                               [(0x0000003fU 
                                                 & ((IData)(4U) 
                                                    + 
                                                    VL_MULS_III(32, (IData)(8U), (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx))))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__b_flat[5U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_b
                                               [(0x0000003fU 
                                                 & ((IData)(5U) 
                                                    + 
                                                    VL_MULS_III(32, (IData)(8U), (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx))))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__b_flat[6U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_b
                                               [(0x0000003fU 
                                                 & ((IData)(6U) 
                                                    + 
                                                    VL_MULS_III(32, (IData)(8U), (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx))))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__b_flat[7U] = (vlSelfRef.rpu_bf16_soc__DOT__mem_b
                                               [(0x0000003fU 
                                                 & ((IData)(7U) 
                                                    + 
                                                    VL_MULS_III(32, (IData)(8U), (IData)(vlSelfRef.rpu_bf16_soc__DOT__stream_idx))))] 
                                               & (- (IData)(
                                                            (4U 
                                                             == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)))));
    vlSelfRef.rpu_bf16_soc__DOT__c[7U][7U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[7U][6U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[7U][5U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[7U][4U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[7U][3U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[7U][2U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[7U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[7U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[6U][7U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[6U][6U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[6U][5U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[6U][4U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[6U][3U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[6U][2U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[6U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[6U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[5U][7U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[5U][6U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[5U][5U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[5U][4U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[5U][3U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[5U][2U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[5U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[5U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[4U][7U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[4U][6U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[4U][5U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[4U][4U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[4U][3U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[4U][2U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[4U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[4U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[3U][7U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[3U][6U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[3U][5U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[3U][4U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[3U][3U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[3U][2U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[3U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[3U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[2U][7U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[2U][6U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[2U][5U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[2U][4U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[2U][3U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[2U][2U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[2U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[2U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][7U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][6U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][5U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][4U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][3U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][2U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][7U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][6U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][5U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][4U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][3U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][2U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][8U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[8U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[8U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[8U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[8U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[8U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[8U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[8U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[8U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][8U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][8U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][8U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][8U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][8U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][8U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][8U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__6__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__6__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__5__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__5__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__5__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__5__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[3U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[3U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[3U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[3U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[3U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[3U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[2U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[2U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[2U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[2U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[0U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[0U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[1U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[2U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[2U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[3U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[3U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[4U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[5U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[6U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[7U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[0U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[0U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[1U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[2U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[2U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[3U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[3U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[4U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[5U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[6U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[7U];
    rpu_bf16_soc__DOT__unnamedblk3__DOT__addr = vlSelfRef.mem_addr;
    vlSelfRef.mem_rdata = ((0U == rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                            ? 0U : ((1U == rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                     ? (((IData)(vlSelfRef.done) 
                                         << 1U) | (IData)(vlSelfRef.busy))
                                     : ((2U == rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                         ? (IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_a_base)
                                         : ((3U == rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                             ? (IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_b_base)
                                             : ((4U 
                                                 == rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)
                                                 ? (IData)(vlSelfRef.rpu_bf16_soc__DOT__reg_c_base)
                                                 : 
                                                (((0x00001000U 
                                                   <= rpu_bf16_soc__DOT__unnamedblk3__DOT__addr) 
                                                  & (0x00002000U 
                                                     > rpu_bf16_soc__DOT__unnamedblk3__DOT__addr))
                                                  ? vlSelfRef.rpu_bf16_soc__DOT__ext_mem
                                                 [(0x00000fffU 
                                                   & rpu_bf16_soc__DOT__unnamedblk3__DOT__addr)]
                                                  : 0U))))));
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[0U][0U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][1U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[2U][2U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[3U][3U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[4U][4U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[5U][5U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[6U][6U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[7U][7U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[0U][0U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][1U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[2U][2U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][3U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[3U][3U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][4U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[4U][4U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][5U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[5U][5U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][6U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[6U][6U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][7U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[7U][7U];
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][7U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][7U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][7U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][7U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][7U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][7U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][7U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][7U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][6U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][6U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][6U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][6U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][6U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][6U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][6U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][6U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][5U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][5U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][5U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][5U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][5U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][5U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][5U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][5U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][4U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][4U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][4U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][4U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][4U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][4U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][4U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][4U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][3U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][3U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][3U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][3U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][3U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][3U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][3U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][3U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][2U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][2U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][2U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][2U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][2U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][2U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][2U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][2U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][1U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][1U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][1U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][1U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][1U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][1U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][1U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][1U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][0U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][0U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][0U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][0U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][0U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][0U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[7U][0U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[7U][0U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][7U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][7U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][7U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][7U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][7U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][7U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][7U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][7U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][6U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][6U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][6U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][6U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][6U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][6U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][6U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][6U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][5U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][5U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][5U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][5U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][5U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][5U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][5U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][5U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][4U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][4U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][4U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][4U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][4U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][4U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][4U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][4U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][3U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][3U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][3U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][3U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][3U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][3U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][3U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][3U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][2U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][2U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][2U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][2U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][2U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][2U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][2U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][2U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][1U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][1U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][1U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][1U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][1U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][1U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][1U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][1U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][0U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][0U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][0U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][0U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][0U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][0U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[6U][0U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[6U][0U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][7U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][7U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][7U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][7U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][7U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][7U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][7U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][7U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][6U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][6U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][6U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][6U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][6U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][6U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][6U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][6U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][5U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][5U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][5U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][5U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][5U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][5U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][5U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][5U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][4U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][4U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][4U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][4U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][4U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][4U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][4U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][4U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][3U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][3U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][3U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][3U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][3U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][3U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][3U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][3U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][2U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][2U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][2U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][2U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][2U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][2U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][2U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][2U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][1U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][1U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][1U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][1U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][1U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][1U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][1U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][1U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][0U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][0U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][0U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][0U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][0U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][0U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[5U][0U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[5U][0U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][7U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][7U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][7U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][7U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][7U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][7U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][7U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][7U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][6U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][6U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][6U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][6U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][6U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][6U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][6U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][6U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][5U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][5U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][5U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][5U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][5U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][5U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][5U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][5U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][4U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][4U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][4U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][4U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][4U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][4U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][4U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][4U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][3U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][3U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][3U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][3U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][3U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][3U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][3U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][3U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][2U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][2U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][2U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][2U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][2U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][2U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][2U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][2U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][1U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][1U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][1U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][1U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][1U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][1U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][1U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][1U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][0U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][0U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][0U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][0U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][0U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][0U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[4U][0U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[4U][0U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][7U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][7U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][7U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][7U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][7U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][7U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][7U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][7U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][6U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][6U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][6U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][6U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][6U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][6U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][6U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][6U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][5U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][5U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][5U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][5U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][5U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][5U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][5U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][5U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][4U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][4U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][4U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][4U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][4U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][4U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][4U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][4U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][3U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][3U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][3U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][3U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][3U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][3U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][3U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][3U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][2U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][2U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][2U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][2U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][2U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][2U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][2U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][2U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][1U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][1U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][1U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][1U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][1U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][1U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][1U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][1U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][0U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][0U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][0U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][0U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][0U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][0U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[3U][0U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[3U][0U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][7U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][7U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][7U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][7U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][7U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][7U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][7U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][7U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][6U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][6U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][6U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][6U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][6U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][6U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][6U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][6U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][5U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][5U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][5U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][5U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][5U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][5U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][5U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][5U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][4U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][4U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][4U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][4U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][4U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][4U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][4U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][4U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][3U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][3U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][3U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][3U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][3U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][3U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][3U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][3U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][2U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][2U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][2U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][2U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][2U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][2U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][2U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][2U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][1U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][1U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][1U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][1U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][1U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][1U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][1U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][1U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][0U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][0U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][0U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][0U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][0U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][0U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[2U][0U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][0U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][7U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][7U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][7U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][7U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][7U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][7U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][7U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][7U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][6U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][6U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][6U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][6U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][6U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][6U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][6U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][6U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][5U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][5U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][5U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][5U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][5U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][5U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][5U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][5U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][4U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][4U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][4U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][4U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][4U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][4U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][4U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][4U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][3U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][3U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][3U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][3U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][3U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][3U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][3U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][3U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][2U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][2U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][2U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][2U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][2U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][2U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][2U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][2U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][0U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][0U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][0U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][0U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][7U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][7U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][7U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][7U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][7U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][7U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][7U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][7U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][6U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][6U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][6U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][6U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][6U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][6U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][6U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][6U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][5U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][5U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][5U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][5U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][5U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][5U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][5U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][5U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][4U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][4U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][4U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][4U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][4U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][4U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][4U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][4U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][3U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][3U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][3U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][3U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][3U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][3U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][3U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][3U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][2U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][2U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][2U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][2U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][2U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][2U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][2U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][2U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][1U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][1U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][1U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][1U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract = 0U;
    if (((0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][0U])) 
         | (0U == (0x00007fffU & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][0U])))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = 0U;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c 
            = (1U & ((vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][0U] 
                      ^ vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][0U]) 
                     >> 0x0fU));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c 
            = (0x000001ffU & (((0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][0U] 
                                               >> 7U)) 
                               + (0x000000ffU & (vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][0U] 
                                                 >> 7U))) 
                              - (IData)(0x007fU)));
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult 
            = (0x0000ffffU & ((0x00000080U | (0x0000007fU 
                                              & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][0U])) 
                              * (0x00000080U | (0x0000007fU 
                                                & vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][0U]))));
        if ((0x00008000U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 8U));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp 
                = (0x000000ffU & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__exp_c));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract 
                = (0x0000007fU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__fract_mult) 
                                  >> 7U));
        }
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result 
            = (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__sign_c) 
                << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_exp) 
                                    << 7U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__mul__DOT__final_fract)));
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
        }
    }
}
