#ifndef MUL_ACCEL_H
#define MUL_ACCEL_H

// Function prototype for multiplication accelerator
// Parameters:
//   a          - First floating point operand
//   b          - Second floating point operand
//   iterations - Number of times to perform multiplication
//   result     - Pointer to store the result

#ifdef __cplusplus
extern "C" {
#endif

void mul_accel(float a, float b, int iterations, float *result);

#ifdef __cplusplus
}
#endif

#endif // MUL_ACCEL_H
