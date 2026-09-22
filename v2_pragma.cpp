#include <ap_int.h>

typedef float data_t;
#define SIZE 16

void matmul_16x16(
    data_t A[SIZE][SIZE],
    data_t B[SIZE][SIZE],
    data_t C[SIZE][SIZE]
) {

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            data_t sum = 0;

            for (int k = 0; k < SIZE; k++) {

#pragma HLS UNROLL //Important Part!!
                sum += A[i][k] * B[k][j];
            }

            C[i][j] = sum;
        }
    }
}