#include <stdio.h>
#define MAX 10

void printMatrix(int mat[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void printSparse(int sparse[MAX][3], int numElements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numElements; i++) printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

void sparseMatrix(int mat[MAX][MAX], int m, int n, int sparse[MAX][3]) {
    int k = 1;
    sparse[0][0] = m; sparse[0][1] = n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0) sparse[k++] = (int[]){i, j, mat[i][j]};
    sparse[0][2] = k - 1;
}

void addSparseMatrices(int S[MAX][3], int T[MAX][3], int result[MAX][3]) {
    int i = 1, j = 1, k = 1;
    if (S[0][0] != T[0][0] || S[0][1] != T[0][1]) { printf("Incompatible sizes\n"); return; }
    result[0][0] = S[0][0]; result[0][1] = S[0][1];
    while (i <= S[0][2] && j <= T[0][2]) {
        if (S[i][0] == T[j][0] && S[i][1] == T[j][1]) result[k++] = (int[]){S[i][0], S[i][1], S[i][2] + T[j][2]}, i++, j++;
        else if (S[i][0] < T[j][0] || (S[i][0] == T[j][0] && S[i][1] < T[j][1])) result[k++] = S[i++];
        else result[k++] = T[j++];
    }
    while (i <= S[0][2]) result[k++] = S[i++];
    while (j <= T[0][2]) result[k++] = T[j++];
    result[0][2] = k - 1;
}

void transposeSparseMatrix(int S[MAX][3], int T[MAX][3]) {
    int m = S[0][2], k = 1;
    T[0][0] = S[0][1]; T[0][1] = S[0][0]; T[0][2] = m;
    for (int i = 1; i <= m; i++) T[k++] = (int[]){S[i][1], S[i][0], S[i][2]};
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], m1, n1, m2, n2, S[MAX][3], T[MAX][3], result[MAX][3];
    printf("Enter rows and columns for 1st matrix: "); scanf("%d%d", &m1, &n1);
    for (int i = 0; i < m1; i++) for (int j = 0; j < n1; j++) scanf("%d", &A[i][j]);
    printf("Matrix 1:\n"); printMatrix(A, m1, n1);

    printf("Enter rows and columns for 2nd matrix: "); scanf("%d%d", &m2, &n2);
    if (m1 != m2 || n1 != n2) { printf("Incompatible matrix sizes\n"); return 0; }
    for (int i = 0; i < m2; i++) for (int j = 0; j < n2; j++) scanf("%d", &B[i][j]);
    printf("Matrix 2:\n"); printMatrix(B, m2, n2);

    sparseMatrix(A, m1, n1, S); sparseMatrix(B, m2, n2, T);
    printf("Sparse Matrix 1:\n"); printSparse(S, S[0][2] + 1);
    printf("Sparse Matrix 2:\n"); printSparse(T, T[0][2] + 1);

    addSparseMatrices(S, T, result);
    printf("Sum of Sparse Matrices:\n"); printSparse(result, result[0][2] + 1);

    transposeSparseMatrix(S, T);
    printf("Transpose of Matrix 1 (Sparse):\n"); printSparse(T, T[0][2] + 1);

    transposeSparseMatrix(T, result);
    printf("Transpose of Matrix 2 (Sparse):\n"); printSparse(result, result[0][2] + 1);

    return 0;
}
