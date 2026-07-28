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

void rpu_set_a(rpu_t* r, uint8_t row, uint8_t col, uint16_t value);
void rpu_set_b(rpu_t* r, uint8_t row, uint8_t col, uint16_t value);
void rpu_start(rpu_t* r);

uint8_t  rpu_busy(rpu_t* r);
uint8_t  rpu_done(rpu_t* r);
uint16_t rpu_get_c(rpu_t* r, uint8_t row, uint8_t col);

#ifdef __cplusplus
}
#endif

#endif
