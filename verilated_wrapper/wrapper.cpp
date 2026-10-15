#include "Vrpu_top.h"
#include <cstdint>
#include "wrapper.h"

struct rpu_t {
    Vrpu_top core;
};

// Every function that changes an input evaluates before it returns, so the outputs are
// always settled between calls; the readers below evaluate only when they change an input.
static void rpu_eval(rpu_t* r) {
    r->core.eval();
}

// mem_wdata is HOST_WORDS 64-bit words wide: a QData for one word, a VlWide of 32-bit
// words above. Words from `count` on are zero.
static void set_wdata(QData& port, const uint64_t* words, uint32_t count) {
    port = count > 0 ? words[0] : 0;
}

template <std::size_t W>
static void set_wdata(VlWide<W>& port, const uint64_t* words, uint32_t count) {
    for (std::size_t i = 0; i < W; i++) {
        port[i] = i / 2 < count ? static_cast<uint32_t>(words[i / 2] >> (32 * (i % 2))) : 0;
    }
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
    set_wdata(r->core.mem_wdata, nullptr, 0);
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

uint32_t rpu_write_words(rpu_t* r, uint32_t addr, const uint64_t* words, uint32_t count) {
    r->core.mem_addr = addr;
    set_wdata(r->core.mem_wdata, words, count);
    r->core.mem_we = 1;
    rpu_eval(r);
    uint32_t ticks = 1;
    for (; !r->core.mem_ready; ticks++) {
        rpu_tick(r);
    }
    rpu_tick(r);
    r->core.mem_we = 0;
    rpu_eval(r);
    return ticks;
}

void rpu_write(rpu_t *r, uint32_t addr, uint64_t value) {
    rpu_write_words(r, addr, &value, 1);
}

uint64_t rpu_read(rpu_t* r, uint32_t addr) {
    r->core.mem_we = 0;
    if (r->core.mem_addr != addr) {
        r->core.mem_addr = addr;
        rpu_eval(r);
    }
    return r->core.mem_rdata;
}

void rpu_start(rpu_t* r) {
    r->core.start = 1;
    rpu_tick(r);
    r->core.start = 0;
    rpu_eval(r);
}

uint8_t rpu_busy(rpu_t* r) {
    return r->core.busy ? 1 : 0;
}

uint8_t rpu_done(rpu_t* r) {
    return r->core.done ? 1 : 0;
}

}
