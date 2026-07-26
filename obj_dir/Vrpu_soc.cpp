// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vrpu_soc__pch.h"

//============================================================
// Constructors

Vrpu_soc::Vrpu_soc(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vrpu_soc__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , cpu_we{vlSymsp->TOP.cpu_we}
    , cpu_addr{vlSymsp->TOP.cpu_addr}
    , cpu_wdata_a{vlSymsp->TOP.cpu_wdata_a}
    , cpu_wdata_b{vlSymsp->TOP.cpu_wdata_b}
    , dma_start{vlSymsp->TOP.dma_start}
    , cpu_rdata{vlSymsp->TOP.cpu_rdata}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vrpu_soc::Vrpu_soc(const char* _vcname__)
    : Vrpu_soc(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vrpu_soc::~Vrpu_soc() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vrpu_soc___024root___eval_debug_assertions(Vrpu_soc___024root* vlSelf);
#endif  // VL_DEBUG
void Vrpu_soc___024root___eval_static(Vrpu_soc___024root* vlSelf);
void Vrpu_soc___024root___eval_initial(Vrpu_soc___024root* vlSelf);
void Vrpu_soc___024root___eval_settle(Vrpu_soc___024root* vlSelf);
void Vrpu_soc___024root___eval(Vrpu_soc___024root* vlSelf);

void Vrpu_soc::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrpu_soc::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vrpu_soc___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vrpu_soc___024root___eval_static(&(vlSymsp->TOP));
        Vrpu_soc___024root___eval_initial(&(vlSymsp->TOP));
        Vrpu_soc___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vrpu_soc___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vrpu_soc::eventsPending() { return false; }

uint64_t Vrpu_soc::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vrpu_soc::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vrpu_soc___024root___eval_final(Vrpu_soc___024root* vlSelf);

VL_ATTR_COLD void Vrpu_soc::final() {
    contextp()->executingFinal(true);
    Vrpu_soc___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vrpu_soc::hierName() const { return vlSymsp->name(); }
const char* Vrpu_soc::modelName() const { return "Vrpu_soc"; }
unsigned Vrpu_soc::threads() const { return 1; }
void Vrpu_soc::prepareClone() const { contextp()->prepareClone(); }
void Vrpu_soc::atClone() const {
    contextp()->threadPoolpOnClone();
}
