// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrpu_bf16_soc.h for the primary calling header

#include "Vrpu_bf16_soc__pch.h"

VL_ATTR_COLD void Vrpu_bf16_soc___024root___stl_sequent__TOP__3(Vrpu_bf16_soc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrpu_bf16_soc___024root___stl_sequent__TOP__3\n"); );
    Vrpu_bf16_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_b = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_a = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
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
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
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
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0;
    SData/*11:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0;
    CData/*7:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0;
    SData/*8:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0;
    CData/*0:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0;
    // Body
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
        }
    }
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_a 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_b 
        = (0x000000ffU & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator) 
                          >> 7U));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_a 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_b 
        = (0x00000080U | (0x0000007fU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator)));
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__max_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__sign_c = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger = 0U;
    vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
    if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator;
    } else if ((0U == (0x00007fffU & (IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator)))) {
        vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result 
            = vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result;
    } else {
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
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
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
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
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
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
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp = 0U;
    rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant = 0U;
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
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_a;
        rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
            = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_b;
        if (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
             > (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                  << 3U));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff 
                = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_b) 
                                  - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_a)));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__exp_diff;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  << 3U));
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout = 0;
            vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky = 0;
            if (VL_GTES_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout 
                    = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value;
            } else if (VL_LTES_III(32, 0x0000000cU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout 
                    = ((0U != (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value))
                        ? 1U : 0U);
            } else {
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky = 0U;
                if (VL_LTS_III(32, 0U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value)));
                }
                if (VL_LTS_III(32, 1U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 1U)));
                }
                if (VL_LTS_III(32, 2U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 2U)));
                }
                if (VL_LTS_III(32, 3U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 3U)));
                }
                if (VL_LTS_III(32, 4U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 4U)));
                }
                if (VL_LTS_III(32, 5U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 5U)));
                }
                if (VL_LTS_III(32, 6U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 6U)));
                }
                if (VL_LTS_III(32, 7U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 7U)));
                }
                if (VL_LTS_III(32, 8U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 8U)));
                }
                if (VL_LTS_III(32, 9U, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 9U)));
                }
                if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                                 | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                                    >> 0x0aU)));
                }
                if (VL_LTS_III(32, 0x0000000bU, vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift)) {
                    vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky 
                        = ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky) 
                           | ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value) 
                              >> 0x0000000bU));
                }
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout 
                    = VL_SHIFTR_III(12,12,32, (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value), vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift);
                vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout 
                    = ((0x0ffeU & (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout)) 
                       | (1U & ((IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout) 
                                | (IData)(vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky))));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a 
                = vlSelfRef.__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout;
        }
        if (((1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                    >> 0x0fU)) == (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator) 
                                         >> 0x0fU)))) {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum 
                = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                  + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                         >> 0x0fU));
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__mant_sum;
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((0x00000800U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                       >> 1U);
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(1U) + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)));
            }
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger 
                = ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                   >= (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b));
            if (rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__a_bigger) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b)));
            } else {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c 
                    = (1U & ((IData)(vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator) 
                             >> 0x0fU));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_b) 
                                      - (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__aligned_a)));
            }
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                = rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__max_exp;
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
            if ((((0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)) 
                  & (~ ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                        >> 0x0aU))) & (0U != (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)))) {
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant 
                    = (0x00000fffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                      << 1U));
                rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp 
                    = (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                      - (IData)(1U)));
            }
        }
        if ((0U == (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant))) {
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = 0U;
        } else {
            rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant 
                = (0x000001ffU & ((IData)((((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                            >> 2U) 
                                           & (0U != 
                                              (0x000bU 
                                               & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant)))))
                                   ? ((IData)(1U) + 
                                      (0x000000ffU 
                                       & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                          >> 3U))) : 
                                  (0x000000ffU & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_mant) 
                                                  >> 3U))));
            vlSelfRef.rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result 
                = ((0x00000100U & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant))
                    ? (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | ((0x00007f80U 
                                            & (((IData)(1U) 
                                                + (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp)) 
                                               << 7U)) 
                                           | (0x0000007fU 
                                              & ((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant) 
                                                 >> 1U))))
                    : (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__sign_c) 
                        << 0x0000000fU) | (((IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__norm_exp) 
                                            << 7U) 
                                           | (0x0000007fU 
                                              & (IData)(rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__rounded_mant)))));
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrpu_bf16_soc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vrpu_bf16_soc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vrpu_bf16_soc___024root___stl_sequent__TOP__0(Vrpu_bf16_soc___024root* vlSelf);
VL_ATTR_COLD void Vrpu_bf16_soc___024root___stl_sequent__TOP__1(Vrpu_bf16_soc___024root* vlSelf);
VL_ATTR_COLD void Vrpu_bf16_soc___024root___stl_sequent__TOP__2(Vrpu_bf16_soc___024root* vlSelf);

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
                Vrpu_bf16_soc___024root___stl_sequent__TOP__1(vlSelf);
                Vrpu_bf16_soc___024root___stl_sequent__TOP__2(vlSelf);
                Vrpu_bf16_soc___024root___stl_sequent__TOP__3(vlSelf);
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( mem_we)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( mem_addr)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @( mem_wdata)\n");
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
    vlSelf->mem_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15973559030946811212ull);
    vlSelf->mem_addr = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 326597072690670135ull);
    vlSelf->mem_wdata = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5431754401481461448ull);
    vlSelf->mem_rdata = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9659133473039683418ull);
    vlSelf->cycles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5117710715632478245ull);
    vlSelf->busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6386567572483775230ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->rpu_bf16_soc__DOT__mem_a[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14792176862453164243ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->rpu_bf16_soc__DOT__mem_b[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5454478108575469526ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->rpu_bf16_soc__DOT__mem_c[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2514889393522165236ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->rpu_bf16_soc__DOT__ext_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9829169803862355837ull);
    }
    vlSelf->rpu_bf16_soc__DOT__reg_a_base = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2635169769632300861ull);
    vlSelf->rpu_bf16_soc__DOT__reg_b_base = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 856152841307919063ull);
    vlSelf->rpu_bf16_soc__DOT__reg_c_base = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2704527372921300639ull);
    vlSelf->rpu_bf16_soc__DOT__start_request = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2445175572501467536ull);
    vlSelf->rpu_bf16_soc__DOT__dma_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14301303106665318047ull);
    vlSelf->rpu_bf16_soc__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3418834915630357175ull);
    vlSelf->rpu_bf16_soc__DOT__stream_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3112842513405372693ull);
    vlSelf->rpu_bf16_soc__DOT__drain_count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3765119836329062200ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->rpu_bf16_soc__DOT__a_flat[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3736881488740126305ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->rpu_bf16_soc__DOT__b_flat[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 816648711800212174ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__c[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9161606516400991670ull);
        }
    }
    vlSelf->rpu_bf16_soc__DOT__core_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5044070137101586684ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 9; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1644696576449221304ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 9; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10603415762656162277ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 9; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__math_core__DOT__wire_a[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14893528694871476150ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->rpu_bf16_soc__DOT__math_core__DOT__wire_b[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8470204552449049533ull);
        }
    }
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__2__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__3__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__4__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__5__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__5__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__6__KET____DOT__chain__BRA__5__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__1__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__1__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__2__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__2__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__3__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__3__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__4__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__4__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__5__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__5__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__6__KET____DOT__d_a__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__7__KET____DOT__chain__BRA__6__KET____DOT__d_b__data_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__accumulator = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__b_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__a_out = 0;
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13475418514338128484ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7232126980302650981ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4092172444523585392ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12534567803850744807ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10759959323491171886ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10531767590998240257ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8923695458389374210ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12551407185506271198ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4562152743281853960ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11056262035877019027ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5997476086714534538ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3292138727764260360ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3982877057589973752ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5255689898421457863ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3676145586631148875ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1551646220582950003ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2138461006689454863ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3448335535922551220ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6818280501558384743ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13496294266187743241ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 304735072585093287ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9792241366141125291ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14875726773006590878ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 812153053002982812ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14509641963275680680ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10850445727102625230ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1728460425815100605ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12095536557509941916ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14990790006425932906ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4879632375411399369ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3400777958399197636ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8898918649660992019ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1867853368484500353ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17608256813414471155ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18387369242137363173ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17625235862633630622ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11868476620337589807ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6789674700912079492ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4555199964171141994ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14649220360523757417ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16081615177947681415ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9460548621040626811ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2065369411839453782ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16765598096770781105ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12472799937183300837ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8103532514767235753ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17896280089494892618ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15218213372885401930ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7164266465415150449ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1230632976491258402ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10028166083647104765ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6666307227944304904ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 634703443779122852ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1514613701476218628ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7536738844338471005ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3950712490882696032ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11008294373780775913ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10407424271617413605ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1802518325828262613ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18078686997726420654ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8219789081946834254ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18267998238813109570ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1912726134916034728ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13468131114269995088ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7328217159661184086ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8530200318839219887ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1054281603230044359ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13688743258367821624ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3216296823926498072ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14896121082079886819ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18396268647214062733ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 994406505124708178ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3054272188547463442ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12828601166680184446ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16236118933203568885ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16476142070299703996ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10863145913938020866ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13185718834272931088ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6150502678075826635ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10723056512675206689ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4332372123231557477ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6146517573352878730ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6075385286516211915ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3765821753961172900ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16643918414502024730ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5783180554147184345ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17919178946454725074ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8814564367610390476ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14806327843534000705ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11262706303660204075ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16044391388112168591ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 470309178512983160ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 636972044476840190ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9859480360267840293ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17040517158217581422ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2461675597790534527ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14491229881272757831ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8905671893373051761ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10907104459021215393ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9623625509601607364ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2712193341578623848ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1401440502614172425ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11753404854242215158ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4747829289704953475ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 390042409095268929ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4684115616106637928ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6633726392491385121ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14198625517804479224ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11851244573565769024ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8793917436769517036ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9846074502837519666ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11811713419962339211ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9237994686755399688ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 557427545980140215ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12051330445100536411ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10777259133725820743ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9316003244342606496ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3004435122513509242ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8573560155461784801ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11272850270232349155ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9832877475587117775ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4855075543946964605ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3150611487727527383ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11489958136722692787ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5018046487057368712ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12156109244101866155ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12922549416583721240ull);
    vlSelf->rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5429561057301739166ull);
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__0__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__1__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__2__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__3__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__4__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__5__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__6__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__7__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__8__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__9__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__10__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__10__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__10__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__10__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__11__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__11__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__11__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__11__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__12__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__12__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__12__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__12__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__13__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__13__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__13__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__13__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__14__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__14__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__14__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__14__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__15__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__15__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__15__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__7__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__15__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__16__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__16__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__16__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__16__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__17__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__17__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__17__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__17__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__18__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__18__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__18__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__18__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__19__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__19__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__19__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__19__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__20__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__20__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__20__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__20__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__21__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__21__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__21__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__21__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__22__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__22__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__22__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__22__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__23__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__23__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__23__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__23__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__24__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__24__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__24__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__24__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__25__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__25__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__25__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__25__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__26__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__26__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__26__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__26__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__27__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__27__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__27__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__27__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__28__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__28__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__28__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__28__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__29__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__29__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__29__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__29__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__30__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__30__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__30__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__30__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__31__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__31__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__31__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__6__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__31__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__32__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__32__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__32__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__32__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__33__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__33__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__33__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__33__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__34__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__34__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__34__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__34__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__35__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__35__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__35__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__35__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__36__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__36__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__36__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__36__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__37__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__37__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__37__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__37__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__38__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__38__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__38__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__38__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__39__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__39__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__39__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__39__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__40__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__40__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__40__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__40__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__41__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__41__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__41__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__41__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__42__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__42__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__42__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__42__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__43__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__43__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__43__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__43__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__44__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__44__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__44__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__44__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__45__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__45__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__45__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__45__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__46__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__46__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__46__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__46__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__47__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__47__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__47__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__5__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__47__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__48__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__48__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__48__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__48__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__49__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__49__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__49__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__49__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__50__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__50__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__50__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__50__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__51__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__51__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__51__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__51__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__52__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__52__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__52__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__52__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__53__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__53__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__53__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__53__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__54__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__54__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__54__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__54__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__55__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__55__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__55__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__55__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__56__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__56__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__56__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__56__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__57__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__57__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__57__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__57__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__58__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__58__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__58__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__58__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__59__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__59__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__59__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__59__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__60__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__60__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__60__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__60__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__61__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__61__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__61__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__61__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__62__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__62__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__62__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__62__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__63__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__63__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__63__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__4__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__63__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__64__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__64__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__64__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__64__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__65__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__65__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__65__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__65__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__66__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__66__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__66__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__66__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__67__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__67__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__67__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__67__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__68__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__68__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__68__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__68__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__69__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__69__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__69__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__69__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__70__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__70__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__70__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__70__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__71__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__71__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__71__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__71__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__72__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__72__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__72__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__72__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__73__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__73__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__73__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__73__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__74__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__74__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__74__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__74__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__75__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__75__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__75__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__75__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__76__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__76__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__76__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__76__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__77__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__77__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__77__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__77__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__78__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__78__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__78__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__78__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__79__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__79__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__79__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__79__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__80__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__80__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__80__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__80__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__81__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__81__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__81__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__81__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__82__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__82__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__82__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__82__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__83__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__83__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__83__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__83__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__84__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__84__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__84__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__84__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__85__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__85__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__85__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__85__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__86__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__86__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__86__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__86__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__87__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__87__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__87__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__87__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__88__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__88__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__88__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__88__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__89__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__89__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__89__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__89__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__90__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__90__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__90__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__90__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__91__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__91__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__91__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__91__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__92__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__92__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__92__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__92__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__93__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__93__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__93__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__93__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__94__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__94__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__94__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__94__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__95__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__95__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__95__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__95__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__96__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__96__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__96__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__96__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__97__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__97__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__97__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__97__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__98__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__98__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__98__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__98__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__99__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__99__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__99__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__99__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__100__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__100__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__100__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__100__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__101__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__101__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__101__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__101__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__102__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__102__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__102__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__102__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__103__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__103__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__103__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__103__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__104__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__104__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__104__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__104__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__105__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__105__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__105__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__105__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__106__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__106__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__106__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__106__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__107__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__107__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__107__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__107__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__108__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__108__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__108__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__108__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__109__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__109__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__109__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__109__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__110__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__110__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__110__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__110__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__111__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__111__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__111__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__111__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__112__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__112__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__112__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__112__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__113__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__113__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__113__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__7__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__113__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__114__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__114__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__114__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__114__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__115__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__115__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__115__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__6__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__115__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__116__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__116__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__116__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__116__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__117__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__117__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__117__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__5__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__117__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__118__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__4__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__119__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__120__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__121__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__122__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__123__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__124__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__125__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__126__sticky = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__Vfuncout = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__value = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__shift = 0;
    vlSelf->__Vfunc_rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__acc__DOT__shift_right_sticky__127__sticky = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__start__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__mem_we__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__mem_addr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__mem_wdata__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
