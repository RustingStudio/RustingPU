#include "Vrpu_soc.h"
#include "wrapper.h"

struct rpu_t {
    Vrpu_soc core;
};

extern "C" {

rpu_t* rpu_new(void) {
    Verilated::mkdir("logs");
    return new rpu_t;
}

void rpu_free(rpu_t* r) {
    delete r;
}

void rpu_set_clk(rpu_t* r, uint8_t v)       { r->core.clk = v; }
void rpu_set_reset(rpu_t* r, uint8_t v)      { r->core.reset = v; }
void rpu_set_cpu_we(rpu_t* r, uint8_t v)     { r->core.cpu_we = v; }
void rpu_set_cpu_addr(rpu_t* r, uint8_t v)   { r->core.cpu_addr = v; }
void rpu_set_wdata_a(rpu_t* r, uint8_t v)    { r->core.cpu_wdata_a = v; }
void rpu_set_wdata_b(rpu_t* r, uint8_t v)    { r->core.cpu_wdata_b = v; }
void rpu_set_dma_start(rpu_t* r, uint8_t v)  { r->core.dma_start = v; }

uint8_t rpu_get_c00(rpu_t* r) { return r->core.c00; }
uint8_t rpu_get_c01(rpu_t* r) { return r->core.c01; }
uint8_t rpu_get_c10(rpu_t* r) { return r->core.c10; }
uint8_t rpu_get_c11(rpu_t* r) { return r->core.c11; }

void rpu_eval(rpu_t* r) { r->core.eval(); }

void rpu_tick(rpu_t* r) {
    rpu_set_clk(r, 0);
    rpu_eval(r);
    rpu_set_clk(r, 1);
    rpu_eval(r);
}

}
