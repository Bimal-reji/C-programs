#include<stdio.h>

int main() {
    int A[10], n, i, low, high, mid, searchKey;
    int flag = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the search key: ");
    scanf("%d", &searchKey);

    // Initialize low and high for binary search
    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(A[mid] == searchKey) {
            printf("Element %d found at index %d.\n", searchKey, mid);
            flag = 1;
            break;
        } 
        else if(A[mid] < searchKey) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    if(flag == 0) {
        printf("Element %d not found.\n", searchKey);
    }

    return 0;
}
