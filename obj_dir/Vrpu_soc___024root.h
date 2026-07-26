// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vrpu_soc.h for the primary calling header

#ifndef VERILATED_VRPU_SOC___024ROOT_H_
#define VERILATED_VRPU_SOC___024ROOT_H_  // guard

#include "verilated.h"


class Vrpu_soc__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vrpu_soc___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(cpu_we,0,0);
    VL_IN8(cpu_addr,3,0);
    VL_IN8(cpu_wdata_a,7,0);
    VL_IN8(cpu_wdata_b,7,0);
    VL_IN8(dma_start,0,0);
    VL_OUT8(c00,7,0);
    VL_OUT8(c01,7,0);
    VL_OUT8(c10,7,0);
    VL_OUT8(c11,7,0);
    CData/*3:0*/ rpu_soc__DOT__dma_addr;
    CData/*3:0*/ rpu_soc__DOT__active_addr;
    CData/*3:0*/ rpu_soc__DOT____Vcellinp__math_core__b0_flat;
    CData/*3:0*/ rpu_soc__DOT____Vcellinp__math_core__a0_flat;
    CData/*3:0*/ rpu_soc__DOT__math_core__DOT__a1_skewed;
    CData/*3:0*/ rpu_soc__DOT__math_core__DOT__b1_skewed;
    CData/*3:0*/ rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_00_to_01;
    CData/*3:0*/ rpu_soc__DOT__math_core__DOT__core__DOT__wire_a_10_to_11;
    CData/*3:0*/ rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_00_to_10;
    CData/*3:0*/ rpu_soc__DOT__math_core__DOT__core__DOT__wire_b_01_to_11;
    CData/*1:0*/ rpu_soc__DOT__dma__DOT__state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__cpu_we__0;
    CData/*3:0*/ __Vtrigprevexpr___TOP__cpu_addr__0;
    CData/*7:0*/ __Vtrigprevexpr___TOP__cpu_wdata_a__0;
    CData/*7:0*/ __Vtrigprevexpr___TOP__cpu_wdata_b__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__dma_start__0;
    CData/*0:0*/ __VicoDidInit;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> rpu_soc__DOT__memory_b__DOT__memory;
    VlUnpacked<CData/*7:0*/, 16> rpu_soc__DOT__memory_a__DOT__memory;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vrpu_soc__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vrpu_soc___024root(Vrpu_soc__Syms* symsp, const char* namep);
    ~Vrpu_soc___024root();
    VL_UNCOPYABLE(Vrpu_soc___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
