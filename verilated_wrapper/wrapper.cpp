#include "Vrpu_top.h"
#include <cstdint>
#include "wrapper.h"

struct rpu_t {
    Vrpu_top core;
};

static constexpr uint8_t N = 8;

static void rpu_eval(rpu_t* r) {
    r->core.eval();
}

extern "C" {

rpu_t* rpu_new(void) {
    Verilated::mkdir("logs");
    auto* r = new rpu_t;
    r->core.clk = 0;
    r->core.reset = 0;
    r->core.start = 0;
    r->core.mem_we = 0;
    r->core.mem_addr = 0;
    r->core.mem_wdata = 0;
    rpu_eval(r);
    return r;
}

void rpu_free(rpu_t* r) {
    delete r;
}

void rpu_tick(rpu_t* r) {
    r->core.clk = 0;
    rpu_eval(r);
    r->core.clk = 1;
    rpu_eval(r);
}

uint32_t rpu_cycles(rpu_t *r) {
    rpu_eval(r);
    return r->core.cycles;
}

void rpu_reset(rpu_t* r) {
    r->core.start = 0;
    r->core.mem_we = 0;
    r->core.reset = 1;
    rpu_tick(r);
    r->core.reset = 0;
    rpu_eval(r);
}

void rpu_write(rpu_t *r, uint16_t addr, uint16_t value) {
    r->core.mem_addr = addr;
    r->core.mem_wdata = value;
    r->core.mem_we = 1;
    rpu_tick(r);
    r->core.mem_we = 0;
    rpu_eval(r);
}

uint16_t rpu_read(rpu_t* r, uint16_t addr) {
    r->core.mem_we = 0;
    r->core.mem_addr = addr;
    rpu_eval(r);
    return r->core.mem_rdata;
}

void rpu_start(rpu_t* r) {
    r->core.start = 1;
    rpu_tick(r);
    r->core.start = 0;
    rpu_eval(r);
}

uint8_t rpu_busy(rpu_t* r) {
    rpu_eval(r);
    return r->core.busy ? 1 : 0;
}

uint8_t rpu_done(rpu_t* r) {
    rpu_eval(r);
    return r->core.done ? 1 : 0;
}

}
