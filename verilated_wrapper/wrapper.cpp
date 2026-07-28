#include "Vrpu_bf16_soc.h"
#include <cstdint>
#include "wrapper.h"

struct rpu_t {
    Vrpu_bf16_soc core;
};

static void rpu_eval(rpu_t* r) {
    r->core.eval();
}

static uint16_t* matrix_a_port(rpu_t* r, uint8_t row, uint8_t col) {
    switch ((row << 1) | col) {
        case 0: return &r->core.a00;
        case 1: return &r->core.a01;
        case 2: return &r->core.a10;
        case 3: return &r->core.a11;
        default: return nullptr;
    }
}

static uint16_t* matrix_b_port(rpu_t* r, uint8_t row, uint8_t col) {
    switch ((row << 1) | col) {
        case 0: return &r->core.b00;
        case 1: return &r->core.b01;
        case 2: return &r->core.b10;
        case 3: return &r->core.b11;
        default: return nullptr;
    }
}

extern "C" {

rpu_t* rpu_new(void) {
    Verilated::mkdir("logs");
    auto* r = new rpu_t;
    r->core.clk = 0;
    r->core.reset = 0;
    r->core.start = 0;
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
    r->core.reset = 1;
    rpu_tick(r);
    r->core.reset = 0;
    rpu_eval(r);
}

void rpu_set_a(rpu_t* r, uint8_t row, uint8_t col, uint16_t value) {
    if (uint16_t* port = matrix_a_port(r, row, col)) {
        *port = value;
    }
}

void rpu_set_b(rpu_t* r, uint8_t row, uint8_t col, uint16_t value) {
    if (uint16_t* port = matrix_b_port(r, row, col)) {
        *port = value;
    }
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

uint16_t rpu_get_c(rpu_t* r, uint8_t row, uint8_t col) {
    rpu_eval(r);
    switch ((row << 1) | col) {
        case 0: return r->core.c00;
        case 1: return r->core.c01;
        case 2: return r->core.c10;
        case 3: return r->core.c11;
        default: return 0;
    }
}

}
