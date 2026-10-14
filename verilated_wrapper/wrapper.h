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
uint64_t rpu_read(rpu_t* r, uint32_t addr);
void rpu_start(rpu_t* r);

uint8_t  rpu_busy(rpu_t* r);
uint8_t  rpu_done(rpu_t* r);

#ifdef __cplusplus
}
#endif

#endif
