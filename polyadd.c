#include<stdio.h>

struct polynomial {
    int coeff;
    int expo;
};

int main() {
    struct polynomial p1[10],p2[10],p3[20];  
    int N1, N2, i = 0, j = 0, k = 0, N3 = 0;

    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &N1);
    
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &N2);

    printf("Enter terms of 1st polynomial (coeff expo):\n");
    for (i = 0; i < N1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &p1[i].coeff, &p1[i].expo);  // Corrected scanf format
    }

    printf("Enter terms of 2nd polynomial (coeff expo):\n");
    for (i = 0; i < N2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &p2[i].coeff, &p2[i].expo);  // Corrected scanf format
    }

    i = 0;
    j = 0;
    k = 0;

    // Merge the two polynomials
    while (i < N1 && j < N2) {
        if (p1[i].expo > p2[j].expo) {
            p3[k] = p1[i];
            i++;
        } else if (p1[i].expo < p2[j].expo) {
            p3[k] = p2[j];
            j++;
        } else {
            // If exponents are the same, add the coefficients
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
        }
        k++;
    }

    // Add any remaining terms from p1
    while (i < N1) {
        p3[k] = p1[i];
        i++;
        k++;
    }

    // Add any remaining terms from p2
    while (j < N2) {
        p3[k] = p2[j];
        j++;
        k++;
    }

    N3 = k;

    // Print the resulting polynomial
    printf("Resultant polynomial: ");
    for (k = 0; k < N3; k++) {
        printf("%dx^%d", p3[k].coeff, p3[k].expo);
        if (k < N3 - 1 && p3[k + 1].coeff >= 0) {
            printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
