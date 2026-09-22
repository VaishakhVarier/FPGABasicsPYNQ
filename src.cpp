// ============================================================================
// exp_calc.cpp - HLS Implementation for Exponential Calculation
// Target: PYNQ-Z2 (Zynq-7020)
// ============================================================================

#include "exp_calc.h"

data_t exp_calc(data_t x) {
    // Interface pragmas for PYNQ-Z2 AXI-Lite
    #pragma HLS INTERFACE mode=s_axilite port=return
    #pragma HLS INTERFACE mode=s_axilite port=x
    
    // Pipeline for better performance
    #pragma HLS PIPELINE II=1
    
    // Calculate exponential using HLS math library
    data_t result = hls::expf(x);
    
    return result;
}