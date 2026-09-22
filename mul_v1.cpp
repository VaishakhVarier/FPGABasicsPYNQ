#include "mul_accel.h"

extern "C" {
void mul_accel(float a, float b, float *result) {
    *result = a * b;
}
}
