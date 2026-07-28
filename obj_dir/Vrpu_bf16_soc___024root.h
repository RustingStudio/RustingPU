// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vrpu_bf16_soc.h for the primary calling header

#ifndef VERILATED_VRPU_BF16_SOC___024ROOT_H_
#define VERILATED_VRPU_BF16_SOC___024ROOT_H_  // guard

#include "verilated.h"


class Vrpu_bf16_soc__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vrpu_bf16_soc___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(start,0,0);
        VL_OUT8(busy,0,0);
        VL_OUT8(done,0,0);
        CData/*2:0*/ rpu_bf16_soc__DOT__state;
        CData/*0:0*/ rpu_bf16_soc__DOT__stream_idx;
        CData/*2:0*/ rpu_bf16_soc__DOT__drain_count;
        CData/*0:0*/ rpu_bf16_soc__DOT__core_reset;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__start__0;
        CData/*0:0*/ __VicoDidInit;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_IN16(a00,15,0);
        VL_IN16(a01,15,0);
        VL_IN16(a10,15,0);
        VL_IN16(a11,15,0);
        VL_IN16(b00,15,0);
        VL_IN16(b01,15,0);
        VL_IN16(b10,15,0);
        VL_IN16(b11,15,0);
        VL_OUT16(c00,15,0);
        VL_OUT16(c01,15,0);
        VL_OUT16(c10,15,0);
        VL_OUT16(c11,15,0);
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_a__data_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__delays__BRA__1__KET____DOT__chain__BRA__0__KET____DOT__d_b__data_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__accumulator;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__b_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__a_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__accumulator;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__b_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT____Vcellout__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__a_out;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_mult_result;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe_cell__DOT__wire_add_result;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_mult_result;
        SData/*15:0*/ rpu_bf16_soc__DOT__math_core__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe_cell__DOT__wire_add_result;
        SData/*15:0*/ __Vtrigprevexpr___TOP__a00__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__a01__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__a10__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__a11__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__b00__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__b01__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__b10__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__b11__0;
        VL_OUT(cycles,31,0);
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 2>, 2> rpu_bf16_soc__DOT__a_reg;
    };
    struct {
        VlUnpacked<VlUnpacked<SData/*15:0*/, 2>, 2> rpu_bf16_soc__DOT__b_reg;
        VlUnpacked<SData/*15:0*/, 2> rpu_bf16_soc__DOT__a_flat;
        VlUnpacked<SData/*15:0*/, 2> rpu_bf16_soc__DOT__b_flat;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 2>, 2> rpu_bf16_soc__DOT__c;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 3>, 2> rpu_bf16_soc__DOT__math_core__DOT__a_delay_chain;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 3>, 2> rpu_bf16_soc__DOT__math_core__DOT__b_delay_chain;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 3>, 2> rpu_bf16_soc__DOT__math_core__DOT__wire_a;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 2>, 3> rpu_bf16_soc__DOT__math_core__DOT__wire_b;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vrpu_bf16_soc__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vrpu_bf16_soc___024root(Vrpu_bf16_soc__Syms* symsp, const char* namep);
    ~Vrpu_bf16_soc___024root();
    VL_UNCOPYABLE(Vrpu_bf16_soc___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
