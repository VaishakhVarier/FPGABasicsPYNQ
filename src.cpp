#include "div_accel.h"

extern "C" {
void div_accel(float a, float b, int iterations, float *result) {
#pragma HLS INTERFACE mode=s_axilite port=a
#pragma HLS INTERFACE mode=s_axilite port=b
#pragma HLS INTERFACE mode=s_axilite port=iterations
#pragma HLS INTERFACE mode=m_axi depth=1 port=result offset=slave bundle=gmem
#pragma HLS INTERFACE mode=s_axilite port=return

    // Input validation
    if (iterations <= 0) {
        *result = 0.0f;
        return;
    }
    
    // Check for division by zero
    if (b == 0.0f) {
        *result = 0.0f;  // Or handle as appropriate for your use case
        return;
    }

    float res = a / b;  // Initialize with first division
    
    // Perform remaining divisions
    for(int i = 1; i < iterations; i++) {
#pragma HLS PIPELINE II=1
#pragma HLS LOOP_TRIPCOUNT min=1 max=10000 avg=5000
        res = a / b;
    }
    
    *result = res;
}
}