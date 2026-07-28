// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrpu_bf16_soc.h for the primary calling header

#include "Vrpu_bf16_soc__pch.h"

VL_ATTR_COLD void Vrpu_bf16_soc___024root___eval_static(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_static\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vrpu_bf16_soc___024root___eval_initial(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_initial\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vrpu_bf16_soc___024root___eval_final(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_final\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_bf16_soc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vrpu_bf16_soc___024root___eval_phase__stl(Vrpu_bf16_soc___024root* vlSelf);

VL_ATTR_COLD void Vrpu_bf16_soc___024root___eval_settle(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_settle\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vrpu_bf16_soc___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/vasylt/hardware_dev/rtl/rpu_bf16_soc.sv", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vrpu_bf16_soc___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vrpu_bf16_soc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_bf16_soc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vrpu_bf16_soc___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vrpu_bf16_soc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vrpu_bf16_soc___024root___stl_sequent__TOP__0(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___stl_sequent__TOP__0\n"); );
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
    // Body
    vlSelfRef.busy = ((1U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                      | ((2U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)) 
                         | (3U == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state))));
    vlSelfRef.rpu_bf16_soc__DOT__core_reset = ((IData)(vlSelfRef.reset) 
                                               | (1U 
                                                  == (IData)(vlSelfRef.rpu_bf16_soc__DOT__state)));
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[0U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][0U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__c[1U][1U] = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[0U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][0U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_b[2U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__wire_a[1U][2U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[1U][1U] 
        = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
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

VL_ATTR_COLD bool Vrpu_bf16_soc___024root___eval_phase__stl(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___eval_phase__stl\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
        Vrpu_bf16_soc___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vrpu_bf16_soc___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vrpu_bf16_soc___024root___stl_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

bool Vrpu_bf16_soc___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_bf16_soc___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vrpu_bf16_soc___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( start)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( a00)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( a01)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @( a10)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @( a11)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @( b00)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @( b01)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @( b10)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @( b11)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vrpu_bf16_soc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_bf16_soc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vrpu_bf16_soc___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrpu_bf16_soc___024root___ctor_var_reset(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___ctor_var_reset\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->cycles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5117710715632478245ull);
    vlSelf->a00 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8488150198654393017ull);
    vlSelf->a01 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4045769853592923025ull);
    vlSelf->a10 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4942205671202721281ull);
    vlSelf->a11 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5263312398584485408ull);
    vlSelf->b00 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9622269029040842801ull);
    vlSelf->b01 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 47704135279670807ull);
    vlSelf->b10 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15140739210359568334ull);
    vlSelf->b11 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5856559541728353947ull);
    vlSelf->busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6386567572483775230ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->c00 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7022235423855613906ull);
    vlSelf->c01 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7362001346921410948ull);
    vlSelf->c10 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5112652809076934103ull);
    vlSelf->c11 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4085026105499164931ull);
    vlSelf->rpu_bf16_soc__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3418834915630357175ull);
    vlSelf->rpu_bf16_soc__DOT__stream_idx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3112842513405372693ull);
    vlSelf->rpu_bf16_soc__DOT__drain_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3765119836329062200ull);
    vlSelf->rpu_bf16_soc__DOT__core_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5044070137101586684ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__a_reg[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1341005002720186832ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__b_reg[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 635943226303525772ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->rpu_bf16_soc__DOT__a_flat[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3736881488740126305ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->rpu_bf16_soc__DOT__b_flat[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 816648711800212174ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__c[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9161606516400991670ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 3; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1644696576449221304ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 3; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10603415762656162277ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 3; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__math_core__DOT__wire_a[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14893528694871476150ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__math_core__DOT__wire_b[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8470204552449049533ull);
        }
    }
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11851244573565769024ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8793917436769517036ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9846074502837519666ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11811713419962339211ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5018046487057368712ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12156109244101866155ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12922549416583721240ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5429561057301739166ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__start__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__a00__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__a01__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__a10__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__a11__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__b00__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__b01__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__b10__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__b11__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
