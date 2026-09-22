#define N 16
#define M 16
#define P 16

void matrixmul(int A[N][M], int B[M][P], int AB[N][P]) {
    // for each row of AB
    for (int i = 0; i < N; ++i) {
        // for each column of AB
        for (int j = 0; j < P; ++j) {
            // compute (AB)i,j
            int ABij = 0;
            // product
            for (int k = 0; k < M; ++k) {
                ABij += A[i][k] * B[k][j];
            }
            AB[i][j] = ABij;
        }
    }
}