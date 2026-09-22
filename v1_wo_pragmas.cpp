#include <ap_int.h>

// Define data type and matrix size
typedef float data_t;
#define SIZE 16

// Top-level function for Vitis HLS
void matmul_16x16(data_t A[SIZE][SIZE], data_t B[SIZE][SIZE], data_t C[SIZE][SIZE]) {
    #pragma HLS interface m_axi  port=A
    #pragma HLS interface m_axi  port=B
    #pragma HLS interface m_axi  port=C
    #pragma HLS interface s_axilite port=return
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            data_t sum = 0;
            for (int k = 0; k < SIZE; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}
