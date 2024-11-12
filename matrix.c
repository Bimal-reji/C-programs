#include <stdio.h>

void printMatrix(int mat[10][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
} 

void printSparse(int sparse[20][3], int numElements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void sparseMatrix(int mat[10][10], int m, int n, int sparse[20][3]) {
    int k = 1; // Counter for sparse matrix elements
    sparse[0][0] = m;  // Number of rows
    sparse[0][1] = n;  // Number of columns
    
    // Traverse the matrix and store non-zero elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;  // Number of non-zero elements
}

void addSparseMatrices(int S[20][3], int T[20][3], int result[20][3]) {
    int m = S[0][2], n = T[0][2];
    int i = 1, j = 1, k = 1;

    if (S[0][0] != T[0][0] || S[0][1] != T[0][1]) {
        printf("Incompatible matrix size\n");
        return;
    }

    // Set up the result sparse matrix
    result[0][0] = S[0][0];
    result[0][1] = S[0][1];

    while (i <= m && j <= n) {
        if (S[i][0] == T[j][0] && S[i][1] == T[j][1]) {
            // Add values if the positions match
            result[k][0] = S[i][0];
            result[k][1] = S[i][1];
            result[k][2] = S[i][2] + T[j][2];
            i++;
            j++;
            k++;
        } else if (S[i][0] < T[j][0] || (S[i][0] == T[j][0] && S[i][1] < T[j][1])) {
            // Copy S[i] to result if S is smaller
            result[k][0] = S[i][0];
            result[k][1] = S[i][1];
            result[k][2] = S[i][2];
            i++;
            k++;
        } else {
            // Copy T[j] to result if T is smaller
            result[k][0] = T[j][0];
            result[k][1] = T[j][1];
            result[k][2] = T[j][2];
            j++;
            k++;
        }
    }

    // Copy remaining elements from S if any
    while (i <= m) {
        result[k][0] = S[i][0];
        result[k][1] = S[i][1];
        result[k][2] = S[i][2];
        i++;
        k++;
    }

    // Copy remaining elements from T if any
    while (j <= n) {
        result[k][0] = T[j][0];
        result[k][1] = T[j][1];
        result[k][2] = T[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;  // Number of non-zero elements in result
}

void transposeSparseMatrix(int S[20][3], int T[20][3]) {
    int m = S[0][2];  // Number of non-zero elements in the original sparse matrix
    int k = 1;

    // Set up the result sparse matrix for transpose
    T[0][0] = S[0][1];  // Rows in result = Columns in S
    T[0][1] = S[0][0];  // Columns in result = Rows in S
    T[0][2] = m;         // Number of non-zero elements remains the same

    // Loop through the sparse matrix and transpose
    for (int i = 1; i <= m; i++) {
        T[k][0] = S[i][1];  // Transpose row index
        T[k][1] = S[i][0];  // Transpose column index
        T[k][2] = S[i][2];  // Copy the value
        k++;
    }
}

int main() {
    int A[10][10], B[10][10], m1, n1, m2, n2;
    int S[20][3], T[20][3], result[20][3];

    // Input first matrix
    printf("Enter number of rows and columns of 1st matrix: ");
    scanf("%d%d", &m1, &n1);
    printf("Enter the matrix: ");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Matrix 1:\n");
    printMatrix(A, m1, n1);

    // Input second matrix
    printf("Enter number of rows and columns of 2nd matrix: ");
    scanf("%d%d", &m2, &n2);
    if (m1 != m2 || n1 != n2) {
        printf("Matrix dimensions must be the same for addition.\n");
        return 0;
    }
    printf("Enter the matrix: ");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    printf("Matrix 2:\n");
    printMatrix(B, m2, n2);

    // Convert to sparse matrices
    sparseMatrix(A, m1, n1, S);
    sparseMatrix(B, m2, n2, T);

    // Print sparse matrices
    printf("Sparse representation of Matrix 1:\n");
    printSparse(S, S[0][2] + 1);
    printf("Sparse representation of Matrix 2:\n");
    printSparse(T, T[0][2] + 1);

    // Add the sparse matrices
    addSparseMatrices(S, T, result);

    // Print result
    printf("Sparse representation of the sum of matrices:\n");
    printSparse(result, result[0][2] + 1);

    // Transpose Sparse Matrices
    transposeSparseMatrix(S, T);
    printf("Transpose of Matrix 1 (Sparse):\n");
    printSparse(T, T[0][2] + 1);

    transposeSparseMatrix(T, result);
    printf("Transpose of Matrix 2 (Sparse):\n");
    printSparse(result, result[0][2] + 1);

    return 0;
}
