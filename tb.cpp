#include <iostream>

#define SIZE 16
typedef float data_t;

void matmul_16x16(
    data_t A[SIZE][SIZE],
    data_t B[SIZE][SIZE],
    data_t C[SIZE][SIZE]
);

int main() {

    data_t A[SIZE][SIZE];
    data_t B[SIZE][SIZE];
    data_t C[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            A[i][j] = (i + j) % 5;
            B[i][j] = (i == j) ? 1 : 0;
        }
    }

    matmul_16x16(A, B, C);

    std::cout << "Output Matrix C:\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << C[i][j] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}