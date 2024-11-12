#include <stdio.h>

void swap(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }

void heapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) { swap(&arr[i], &arr[largest]); heapify(arr, n, largest); }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) { swap(&arr[0], &arr[i]); heapify(arr, i, 0); }
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void printArray(int arr[], int size) { 
   for (int i = 0; i < size; i++) 
       printf("%d ", arr[i]); 
   printf("\n");
}

int main() {
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);
    printf("Sorted array using Heap Sort:\n");
    printArray(arr, n);

    printf("Enter the number to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) 
        printf("Number %d found at index %d.\n", target, result);
    else 
        printf("Number %d not found in the array.\n", target);

    return 0;
}
