#ifndef RPU_WRAPPER_H
#define RPU_WRAPPER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rpu_t rpu_t;

rpu_t* rpu_new(void);
void   rpu_free(rpu_t* r);

void rpu_set_clk       (rpu_t* r, uint8_t v);
void rpu_set_reset     (rpu_t* r, uint8_t v);
void rpu_set_cpu_we    (rpu_t* r, uint8_t v);
void rpu_set_cpu_addr  (rpu_t* r, uint8_t v);
void rpu_set_wdata_a   (rpu_t* r, uint8_t v);
void rpu_set_wdata_b   (rpu_t* r, uint8_t v);
void rpu_set_dma_start (rpu_t* r, uint8_t v);

uint8_t rpu_get_c00(rpu_t* r);
uint8_t rpu_get_c01(rpu_t* r);
uint8_t rpu_get_c10(rpu_t* r);
uint8_t rpu_get_c11(rpu_t* r);

void rpu_eval(rpu_t* r);
void rpu_tick(rpu_t* r);

#ifdef __cplusplus
}
#endif

#endif
