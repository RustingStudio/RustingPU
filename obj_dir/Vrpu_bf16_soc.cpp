// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vrpu_bf16_soc__pch.h"

//============================================================
// Constructors

Vrpu_bf16_soc::Vrpu_bf16_soc(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vrpu_bf16_soc__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , start{vlSymsp->TOP.start}
    , busy{vlSymsp->TOP.busy}
    , done{vlSymsp->TOP.done}
    , a00{vlSymsp->TOP.a00}
    , a01{vlSymsp->TOP.a01}
    , a10{vlSymsp->TOP.a10}
    , a11{vlSymsp->TOP.a11}
    , b00{vlSymsp->TOP.b00}
    , b01{vlSymsp->TOP.b01}
    , b10{vlSymsp->TOP.b10}
    , b11{vlSymsp->TOP.b11}
    , c00{vlSymsp->TOP.c00}
    , c01{vlSymsp->TOP.c01}
    , c10{vlSymsp->TOP.c10}
    , c11{vlSymsp->TOP.c11}
    , cycles{vlSymsp->TOP.cycles}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vrpu_bf16_soc::Vrpu_bf16_soc(const char* _vcname__)
    : Vrpu_bf16_soc(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vrpu_bf16_soc::~Vrpu_bf16_soc() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vrpu_bf16_soc___024root___eval_debug_assertions(Vrpu_bf16_soc___024root* vlSelf);
#endif  // VL_DEBUG
void Vrpu_bf16_soc___024root___eval_static(Vrpu_bf16_soc___024root* vlSelf);
void Vrpu_bf16_soc___024root___eval_initial(Vrpu_bf16_soc___024root* vlSelf);
void Vrpu_bf16_soc___024root___eval_settle(Vrpu_bf16_soc___024root* vlSelf);
void Vrpu_bf16_soc___024root___eval(Vrpu_bf16_soc___024root* vlSelf);

void Vrpu_bf16_soc::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrpu_bf16_soc::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vrpu_bf16_soc___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vrpu_bf16_soc___024root___eval_static(&(vlSymsp->TOP));
        Vrpu_bf16_soc___024root___eval_initial(&(vlSymsp->TOP));
        Vrpu_bf16_soc___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vrpu_bf16_soc___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vrpu_bf16_soc::eventsPending() { return false; }

uint64_t Vrpu_bf16_soc::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vrpu_bf16_soc::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vrpu_bf16_soc___024root___eval_final(Vrpu_bf16_soc___024root* vlSelf);

VL_ATTR_COLD void Vrpu_bf16_soc::final() {
    contextp()->executingFinal(true);
    Vrpu_bf16_soc___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vrpu_bf16_soc::hierName() const { return vlSymsp->name(); }
const char* Vrpu_bf16_soc::modelName() const { return "Vrpu_bf16_soc"; }
unsigned Vrpu_bf16_soc::threads() const { return 1; }
void Vrpu_bf16_soc::prepareClone() const { contextp()->prepareClone(); }
void Vrpu_bf16_soc::atClone() const {
    contextp()->threadPoolpOnClone();
}
