#include "Vrpu_soc__pch.h"

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
    , c00{vlSymsp->TOP.c00}
    , c01{vlSymsp->TOP.c01}
    , c10{vlSymsp->TOP.c10}
    , c11{vlSymsp->TOP.c11}
    , rootp{&(vlSymsp->TOP)}
{
    contextp()->addModel(this);
}

Vrpu_soc::Vrpu_soc(const char* _vcname__)
    : Vrpu_soc(Verilated::threadContextp(), _vcname__)
{
}


Vrpu_soc::~Vrpu_soc() {
    delete vlSymsp;
}


#ifdef VL_DEBUG
void Vrpu_soc___024root___eval_debug_assertions(Vrpu_soc___024root* vlSelf);
#endif
void Vrpu_soc___024root___eval_static(Vrpu_soc___024root* vlSelf);
void Vrpu_soc___024root___eval_initial(Vrpu_soc___024root* vlSelf);
void Vrpu_soc___024root___eval_settle(Vrpu_soc___024root* vlSelf);
void Vrpu_soc___024root___eval(Vrpu_soc___024root* vlSelf);

void Vrpu_soc::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrpu_soc::eval_step\n"); );
#ifdef VL_DEBUG
    Vrpu_soc___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif
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
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

bool Vrpu_soc::eventsPending() { return false; }

uint64_t Vrpu_soc::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}


const char* Vrpu_soc::name() const {
    return vlSymsp->name();
}


void Vrpu_soc___024root___eval_final(Vrpu_soc___024root* vlSelf);

VL_ATTR_COLD void Vrpu_soc::final() {
    contextp()->executingFinal(true);
    Vrpu_soc___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

const char* Vrpu_soc::hierName() const { return vlSymsp->name(); }
const char* Vrpu_soc::modelName() const { return "Vrpu_soc"; }
unsigned Vrpu_soc::threads() const { return 1; }
void Vrpu_soc::prepareClone() const { contextp()->prepareClone(); }
void Vrpu_soc::atClone() const {
    contextp()->threadPoolpOnClone();
}
