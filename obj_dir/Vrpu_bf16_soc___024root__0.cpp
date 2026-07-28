// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrpu_bf16_soc.h for the primary calling header

#include "Vrpu_bf16_soc__pch.h"

void Vrpu_bf16_soc___024root___eval_triggers_vec__ico(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_triggers_vec__ico\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.b11) 
                                                        != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__b11__0)) 
                                                       << 0x0000000aU) 
                                                      | ((((IData)(vlSelfRef.b10) 
                                                           != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__b10__0)) 
                                                          << 9U) 
                                                         | (((IData)(vlSelfRef.b01) 
                                                             != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__b01__0)) 
                                                            << 8U))) 
                                                     | (((((((IData)(vlSelfRef.b00) 
                                                             != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__b00__0)) 
                                                            << 3U) 
                                                           | (((IData)(vlSelfRef.a11) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__a11__0)) 
                                                              << 2U)) 
                                                          | ((((IData)(vlSelfRef.a10) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__a10__0)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelfRef.a01) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__a01__0)))) 
                                                         << 4U) 
                                                        | (((((IData)(vlSelfRef.a00) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__a00__0)) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.start) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__start__0)) 
                                                               << 2U)) 
                                                           | ((((IData)(vlSelfRef.reset) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.clk) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
    vlSelfRef.__Vtrigprevexpr___TOP__start__0 = vlSelfRef.start;
    vlSelfRef.__Vtrigprevexpr___TOP__a00__0 = vlSelfRef.a00;
    vlSelfRef.__Vtrigprevexpr___TOP__a01__0 = vlSelfRef.a01;
    vlSelfRef.__Vtrigprevexpr___TOP__a10__0 = vlSelfRef.a10;
    vlSelfRef.__Vtrigprevexpr___TOP__a11__0 = vlSelfRef.a11;
    vlSelfRef.__Vtrigprevexpr___TOP__b00__0 = vlSelfRef.b00;
    vlSelfRef.__Vtrigprevexpr___TOP__b01__0 = vlSelfRef.b01;
    vlSelfRef.__Vtrigprevexpr___TOP__b10__0 = vlSelfRef.b10;
    vlSelfRef.__Vtrigprevexpr___TOP__b11__0 = vlSelfRef.b11;
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
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000080ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000100ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000200ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000400ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
    }
}

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
    Vrpu_bf16_soc___024root___eval_triggers_vec__ico(vlSelf);
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
                           | (1U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)));
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
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
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
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
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
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
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
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
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
    IData/*31:0*/ __Vdly__cycles;
    __Vdly__cycles = 0;
    CData/*2:0*/ __Vdly__rpu_bf16_soc__DOT__state;
    __Vdly__rpu_bf16_soc__DOT__state = 0;
    CData/*0:0*/ __Vdly__rpu_bf16_soc__DOT__stream_idx;
    __Vdly__rpu_bf16_soc__DOT__stream_idx = 0;
    CData/*2:0*/ __Vdly__rpu_bf16_soc__DOT__drain_count;
    __Vdly__rpu_bf16_soc__DOT__drain_count = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__a_reg__v0;
    __VdlyVal__rpu_bf16_soc__DOT__a_reg__v0 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__a_reg__v0;
    __VdlySet__rpu_bf16_soc__DOT__a_reg__v0 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__b_reg__v0;
    __VdlyVal__rpu_bf16_soc__DOT__b_reg__v0 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__a_reg__v1;
    __VdlyVal__rpu_bf16_soc__DOT__a_reg__v1 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__a_reg__v1;
    __VdlySet__rpu_bf16_soc__DOT__a_reg__v1 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__b_reg__v1;
    __VdlyVal__rpu_bf16_soc__DOT__b_reg__v1 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__a_reg__v2;
    __VdlyVal__rpu_bf16_soc__DOT__a_reg__v2 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__b_reg__v2;
    __VdlyVal__rpu_bf16_soc__DOT__b_reg__v2 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__a_reg__v3;
    __VdlyVal__rpu_bf16_soc__DOT__a_reg__v3 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__b_reg__v3;
    __VdlyVal__rpu_bf16_soc__DOT__b_reg__v3 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__a_reg__v4;
    __VdlyVal__rpu_bf16_soc__DOT__a_reg__v4 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__a_reg__v4;
    __VdlySet__rpu_bf16_soc__DOT__a_reg__v4 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__b_reg__v4;
    __VdlyVal__rpu_bf16_soc__DOT__b_reg__v4 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__a_reg__v5;
    __VdlyVal__rpu_bf16_soc__DOT__a_reg__v5 = 0;
    CData/*0:0*/ __VdlySet__rpu_bf16_soc__DOT__a_reg__v5;
    __VdlySet__rpu_bf16_soc__DOT__a_reg__v5 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__b_reg__v5;
    __VdlyVal__rpu_bf16_soc__DOT__b_reg__v5 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__a_reg__v6;
    __VdlyVal__rpu_bf16_soc__DOT__a_reg__v6 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__b_reg__v6;
    __VdlyVal__rpu_bf16_soc__DOT__b_reg__v6 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__a_reg__v7;
    __VdlyVal__rpu_bf16_soc__DOT__a_reg__v7 = 0;
    SData/*15:0*/ __VdlyVal__rpu_bf16_soc__DOT__b_reg__v7;
    __VdlyVal__rpu_bf16_soc__DOT__b_reg__v7 = 0;
    // Body
    __Vdly__cycles = vlSelfRef.cycles;
    __Vdly__rpu_bf16_soc__DOT__drain_count = vlSelfRef.rpu_bf16_soc__DOT__drain_count;
    __Vdly__rpu_bf16_soc__DOT__stream_idx = vlSelfRef.rpu_bf16_soc__DOT__stream_idx;
    __Vdly__rpu_bf16_soc__DOT__state = vlSelfRef.rpu_bf16_soc__DOT__state;
    __VdlySet__rpu_bf16_soc__DOT__a_reg__v0 = 0U;
    __VdlySet__rpu_bf16_soc__DOT__a_reg__v1 = 0U;
    __VdlySet__rpu_bf16_soc__DOT__a_reg__v4 = 0U;
    __VdlySet__rpu_bf16_soc__DOT__a_reg__v5 = 0U;
    if (vlSelfRef.reset) {
        __Vdly__cycles = 0U;
        __Vdly__rpu_bf16_soc__DOT__state = 0U;
        vlSelfRef.done = 0U;
        __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
        __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
    } else {
        if (vlSelfRef.start) {
            __Vdly__cycles = 0U;
        } else if (vlSelfRef.busy) {
            __Vdly__cycles = ((IData)(1U) + vlSelfRef.cycles);
        }
        if ((4U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
                __Vdly__rpu_bf16_soc__DOT__state = 0U;
                vlSelfRef.done = 0U;
            } else if ((1U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
                __Vdly__rpu_bf16_soc__DOT__state = 0U;
                vlSelfRef.done = 0U;
            } else if (vlSelfRef.start) {
                __VdlyVal__rpu_bf16_soc__DOT__a_reg__v0 
                    = vlSelfRef.a00;
                __VdlySet__rpu_bf16_soc__DOT__a_reg__v0 = 1U;
                __VdlyVal__rpu_bf16_soc__DOT__b_reg__v0 
                    = vlSelfRef.b00;
                vlSelfRef.done = 0U;
                __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
                __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
                __Vdly__rpu_bf16_soc__DOT__state = 1U;
                __VdlyVal__rpu_bf16_soc__DOT__a_reg__v1 
                    = vlSelfRef.a01;
                __VdlySet__rpu_bf16_soc__DOT__a_reg__v1 = 1U;
                __VdlyVal__rpu_bf16_soc__DOT__b_reg__v1 
                    = vlSelfRef.b01;
                __VdlyVal__rpu_bf16_soc__DOT__a_reg__v2 
                    = vlSelfRef.a10;
                __VdlyVal__rpu_bf16_soc__DOT__b_reg__v2 
                    = vlSelfRef.b10;
                __VdlyVal__rpu_bf16_soc__DOT__a_reg__v3 
                    = vlSelfRef.a11;
                __VdlyVal__rpu_bf16_soc__DOT__b_reg__v3 
                    = vlSelfRef.b11;
            } else if ((4U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
                vlSelfRef.done = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
                if ((3U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__drain_count))) {
                    vlSelfRef.done = 1U;
                    __Vdly__rpu_bf16_soc__DOT__state = 4U;
                } else {
                    __Vdly__rpu_bf16_soc__DOT__drain_count 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.rpu_bf16_soc__DOT__drain_count)));
                }
            } else if (vlSelfRef.rpu_bf16_soc__DOT__stream_idx) {
                __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
                __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
                __Vdly__rpu_bf16_soc__DOT__state = 3U;
            } else {
                __Vdly__rpu_bf16_soc__DOT__stream_idx = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
            __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
            __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
            __Vdly__rpu_bf16_soc__DOT__state = 2U;
        } else if (vlSelfRef.start) {
            __VdlyVal__rpu_bf16_soc__DOT__a_reg__v4 
                = vlSelfRef.a00;
            __VdlySet__rpu_bf16_soc__DOT__a_reg__v4 = 1U;
            __VdlyVal__rpu_bf16_soc__DOT__b_reg__v4 
                = vlSelfRef.b00;
            vlSelfRef.done = 0U;
            __Vdly__rpu_bf16_soc__DOT__stream_idx = 0U;
            __Vdly__rpu_bf16_soc__DOT__drain_count = 0U;
            __Vdly__rpu_bf16_soc__DOT__state = 1U;
            __VdlyVal__rpu_bf16_soc__DOT__a_reg__v5 
                = vlSelfRef.a01;
            __VdlySet__rpu_bf16_soc__DOT__a_reg__v5 = 1U;
            __VdlyVal__rpu_bf16_soc__DOT__b_reg__v5 
                = vlSelfRef.b01;
            __VdlyVal__rpu_bf16_soc__DOT__a_reg__v6 
                = vlSelfRef.a10;
            __VdlyVal__rpu_bf16_soc__DOT__b_reg__v6 
                = vlSelfRef.b10;
            __VdlyVal__rpu_bf16_soc__DOT__a_reg__v7 
                = vlSelfRef.a11;
            __VdlyVal__rpu_bf16_soc__DOT__b_reg__v7 
                = vlSelfRef.b11;
        } else if ((4U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
            vlSelfRef.done = 1U;
        }
    }
    if (vlSelfRef.rpu_bf16_soc__DOT__core_reset) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0U;
    } else {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][1U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][0U];
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][0U];
    }
    vlSelfRef.cycles = __Vdly__cycles;
    vlSelfRef.rpu_bf16_soc__DOT__drain_count = __Vdly__rpu_bf16_soc__DOT__drain_count;
    vlSelfRef.rpu_bf16_soc__DOT__stream_idx = __Vdly__rpu_bf16_soc__DOT__stream_idx;
    vlSelfRef.rpu_bf16_soc__DOT__state = __Vdly__rpu_bf16_soc__DOT__state;
    if (__VdlySet__rpu_bf16_soc__DOT__a_reg__v0) {
        vlSelfRef.rpu_bf16_soc__DOT__a_reg[0U][0U] 
            = __VdlyVal__rpu_bf16_soc__DOT__a_reg__v0;
        vlSelfRef.rpu_bf16_soc__DOT__b_reg[0U][0U] 
            = __VdlyVal__rpu_bf16_soc__DOT__b_reg__v0;
    }
    if (__VdlySet__rpu_bf16_soc__DOT__a_reg__v1) {
        vlSelfRef.rpu_bf16_soc__DOT__a_reg[0U][1U] 
            = __VdlyVal__rpu_bf16_soc__DOT__a_reg__v1;
        vlSelfRef.rpu_bf16_soc__DOT__a_reg[1U][0U] 
            = __VdlyVal__rpu_bf16_soc__DOT__a_reg__v2;
        vlSelfRef.rpu_bf16_soc__DOT__a_reg[1U][1U] 
            = __VdlyVal__rpu_bf16_soc__DOT__a_reg__v3;
        vlSelfRef.rpu_bf16_soc__DOT__b_reg[0U][1U] 
            = __VdlyVal__rpu_bf16_soc__DOT__b_reg__v1;
        vlSelfRef.rpu_bf16_soc__DOT__b_reg[1U][0U] 
            = __VdlyVal__rpu_bf16_soc__DOT__b_reg__v2;
        vlSelfRef.rpu_bf16_soc__DOT__b_reg[1U][1U] 
            = __VdlyVal__rpu_bf16_soc__DOT__b_reg__v3;
    }
    if (__VdlySet__rpu_bf16_soc__DOT__a_reg__v4) {
        vlSelfRef.rpu_bf16_soc__DOT__a_reg[0U][0U] 
            = __VdlyVal__rpu_bf16_soc__DOT__a_reg__v4;
        vlSelfRef.rpu_bf16_soc__DOT__b_reg[0U][0U] 
            = __VdlyVal__rpu_bf16_soc__DOT__b_reg__v4;
    }
    if (__VdlySet__rpu_bf16_soc__DOT__a_reg__v5) {
        vlSelfRef.rpu_bf16_soc__DOT__a_reg[0U][1U] 
            = __VdlyVal__rpu_bf16_soc__DOT__a_reg__v5;
        vlSelfRef.rpu_bf16_soc__DOT__a_reg[1U][0U] 
            = __VdlyVal__rpu_bf16_soc__DOT__a_reg__v6;
        vlSelfRef.rpu_bf16_soc__DOT__a_reg[1U][1U] 
            = __VdlyVal__rpu_bf16_soc__DOT__a_reg__v7;
        vlSelfRef.rpu_bf16_soc__DOT__b_reg[0U][1U] 
            = __VdlyVal__rpu_bf16_soc__DOT__b_reg__v5;
        vlSelfRef.rpu_bf16_soc__DOT__b_reg[1U][0U] 
            = __VdlyVal__rpu_bf16_soc__DOT__b_reg__v6;
        vlSelfRef.rpu_bf16_soc__DOT__b_reg[1U][1U] 
            = __VdlyVal__rpu_bf16_soc__DOT__b_reg__v7;
    }
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.busy = ((1U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                      | ((2U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                         | (3U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))));
    vlSelfRef.rpu_bf16_soc__DOT__core_reset = ((IData)(vlSelfRef.reset) 
                                               | (1U 
                                                  == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)));
    if ((2U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))) {
        vlSelfRef.rpu_bf16_soc__DOT__a_flat[0U] = vlSelfRef.rpu_bf16_soc__DOT__a_reg[0U]
            [vlSelfRef.rpu_bf16_soc__DOT__stream_idx];
        vlSelfRef.rpu_bf16_soc__DOT__a_flat[1U] = vlSelfRef.rpu_bf16_soc__DOT__a_reg[1U]
            [vlSelfRef.rpu_bf16_soc__DOT__stream_idx];
        vlSelfRef.rpu_bf16_soc__DOT__b_flat[0U] = vlSelfRef.rpu_bf16_soc__DOT__b_reg
            [vlSelfRef.rpu_bf16_soc__DOT__stream_idx][0U];
        vlSelfRef.rpu_bf16_soc__DOT__b_flat[1U] = vlSelfRef.rpu_bf16_soc__DOT__b_reg
            [vlSelfRef.rpu_bf16_soc__DOT__stream_idx][1U];
    } else {
        vlSelfRef.rpu_bf16_soc__DOT__a_flat[0U] = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__a_flat[1U] = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__b_flat[0U] = 0U;
        vlSelfRef.rpu_bf16_soc__DOT__b_flat[1U] = 0U;
    }
    vlSelfRef.c00 = vlSelfRef.rpu_bf16_soc__DOT__c[0U][0U];
    vlSelfRef.c01 = vlSelfRef.rpu_bf16_soc__DOT__c[0U][1U];
    vlSelfRef.c10 = vlSelfRef.rpu_bf16_soc__DOT__c[1U][0U];
    vlSelfRef.c11 = vlSelfRef.rpu_bf16_soc__DOT__c[1U][1U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[0U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[0U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__a_flat[1U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[0U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[0U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__b_flat[1U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[0U][0U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][1U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[0U][0U];
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[0U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][1U];
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
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b 
                = ((8U <= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff))
                    ? 0U : VL_SHIFTR_III(8,8,8, (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b), (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff)));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a 
                = ((8U <= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff))
                    ? 0U : VL_SHIFTR_III(8,8,8, (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a), (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff)));
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x000001ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum)))));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                     << 8U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a)) 
                   >= (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                        << 8U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger)
                          ? ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU) : ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator) 
                                          >> 0x0fU)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff 
                = (0x000000ffU & (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b))
                                   ? ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b))
                                   : ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a))));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))
                    ? 0U : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                             << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                                 << 7U) 
                                                | (0x0000007fU 
                                                   & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b 
                = ((8U <= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff))
                    ? 0U : VL_SHIFTR_III(8,8,8, (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b), (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff)));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a 
                = ((8U <= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff))
                    ? 0U : VL_SHIFTR_III(8,8,8, (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a), (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff)));
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x000001ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum)))));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                     << 8U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a)) 
                   >= (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                        << 8U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger)
                          ? ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU) : ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator) 
                                          >> 0x0fU)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff 
                = (0x000000ffU & (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b))
                                   ? ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b))
                                   : ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a))));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))
                    ? 0U : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                             << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                                 << 7U) 
                                                | (0x0000007fU 
                                                   & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b 
                = ((8U <= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff))
                    ? 0U : VL_SHIFTR_III(8,8,8, (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b), (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff)));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a 
                = ((8U <= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff))
                    ? 0U : VL_SHIFTR_III(8,8,8, (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a), (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff)));
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x000001ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum)))));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                     << 8U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a)) 
                   >= (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                        << 8U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger)
                          ? ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU) : ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator) 
                                          >> 0x0fU)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff 
                = (0x000000ffU & (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b))
                                   ? ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b))
                                   : ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a))));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))
                    ? 0U : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                             << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                                 << 7U) 
                                                | (0x0000007fU 
                                                   & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b 
                = ((8U <= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff))
                    ? 0U : VL_SHIFTR_III(8,8,8, (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b), (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff)));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a 
                = ((8U <= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff))
                    ? 0U : VL_SHIFTR_III(8,8,8, (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a), (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff)));
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x000001ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum)))));
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                     << 8U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a)) 
                   >= (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                        << 8U) | (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger)
                          ? ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU) : ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator) 
                                          >> 0x0fU)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff 
                = (0x000000ffU & (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b))
                                   ? ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b))
                                   : ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shifted_mant_a))));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_diff;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 7U))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))
                    ? 0U : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                             << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                                 << 7U) 
                                                | (0x0000007fU 
                                                   & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))));
        }
    }
}

void Vrpu_bf16_soc___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___trigger_orInto__act_vec_vec\n"); );
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
VL_ATTR_COLD void Vrpu_bf16_soc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vrpu_bf16_soc___024root___eval_phase__act(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_phase__act\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((IData)(vlSelfRef.clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrpu_bf16_soc___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vrpu_bf16_soc___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vrpu_bf16_soc___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vrpu_bf16_soc___024root___eval_phase__nba(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_phase__nba\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vrpu_bf16_soc___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vrpu_bf16_soc___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vrpu_bf16_soc___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vrpu_bf16_soc___024root___eval(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vrpu_bf16_soc___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/vasylt/hardware_dev/rtl/rpu_bf16_soc.sv", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vrpu_bf16_soc___024root___eval_phase__ico(vlSelf);
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vrpu_bf16_soc___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/vasylt/hardware_dev/rtl/rpu_bf16_soc.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vrpu_bf16_soc___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/vasylt/hardware_dev/rtl/rpu_bf16_soc.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vrpu_bf16_soc___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vrpu_bf16_soc___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vrpu_bf16_soc___024root___eval_debug_assertions(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_debug_assertions\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");
    }
}
#endif  // VL_DEBUG
