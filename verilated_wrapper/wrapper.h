#ifndef RPU_WRAPPER_H
#define RPU_WRAPPER_H

#include <cstdint>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rpu_t rpu_t;

rpu_t* rpu_new(void);
void   rpu_free(rpu_t* r);

void rpu_reset(rpu_t* r);
void rpu_tick(rpu_t* r);
uint32_t rpu_cycles(rpu_t* r);

void rpu_write(rpu_t* r, uint32_t addr, uint64_t value);
// One bus write of up to HOST_WORDS words (count of them, the rest zero). Returns the
// cycles it took: one, plus one for each cycle a C store held the memory write port.
uint32_t rpu_write_words(rpu_t* r, uint32_t addr, const uint64_t* words, uint32_t count);
uint64_t rpu_read(rpu_t* r, uint32_t addr);
void rpu_start(rpu_t* r);

uint8_t  rpu_busy(rpu_t* r);
uint8_t  rpu_done(rpu_t* r);

#ifdef __cplusplus
}
#endif

#endif
