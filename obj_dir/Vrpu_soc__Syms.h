// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VRPU_SOC__SYMS_H_
#define VERILATED_VRPU_SOC__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vrpu_soc.h"

// INCLUDE MODULE CLASSES
#include "Vrpu_soc___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vrpu_soc__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vrpu_soc* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vrpu_soc___024root             TOP;

    // CONSTRUCTORS
    Vrpu_soc__Syms(VerilatedContext* contextp, const char* namep, Vrpu_soc* modelp);
    ~Vrpu_soc__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
