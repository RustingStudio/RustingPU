// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrpu_bf16_soc.h for the primary calling header

#include "Vrpu_bf16_soc__pch.h"

void Vrpu_bf16_soc___024root___ctor_var_reset(Vrpu_bf16_soc___024root* vlSelf);

Vrpu_bf16_soc___024root::Vrpu_bf16_soc___024root(Vrpu_bf16_soc__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vrpu_bf16_soc___024root___ctor_var_reset(this);
}

void Vrpu_bf16_soc___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vrpu_bf16_soc___024root::~Vrpu_bf16_soc___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
