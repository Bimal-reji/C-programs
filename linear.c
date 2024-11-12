#include <stdio.h>

int main() {
    int A[30], n, i, searchKey, flag = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    printf("Enter the search key: ");
    scanf("%d", &searchKey);
    
    for(i = 0; i < n; i++) {
        if (A[i] == searchKey) {
            flag = 1;
            break;
        }
    }
    
    if(flag == 1) {
        printf("Search key %d found at index %d.\n", searchKey, i);
    } else {
        printf("Search key %d not found.\n", searchKey);
    }

    return 0;
}
