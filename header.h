// ============================================================================
// exp_calc.h - Header File for Exponential Calculation
// Target: PYNQ-Z2 (Zynq-7020)
// ============================================================================

#ifndef EXP_CALC_H
#define EXP_CALC_H

#include "ap_fixed.h"
#include "hls_math.h"

// Type definitions for PYNQ-Z2 optimization
typedef float data_t;

// Function prototype
data_t exp_calc(data_t x);

#endif // EXP_CALC_H