#include <stdio.h>
int n, top = -1, A[10];
void push() {
    if (top == n - 1) printf("\nSTACK OVERFLOW");
    else {
        printf("Enter value to push: ");
        scanf("%d", &A[++top]);
    }
}
void pop() {
    if (top == -1) printf("\nSTACK UNDERFLOW");
    else printf("\nPopped element: %d", A[top--]);
}
void display() {
    if (top == -1) printf("\nSTACK is empty");
    else {
        printf("Elements in STACK: ");
        for (int i = top; i >= 0; i--) printf("%d ", A[i]);
    }
}
int main() {
    int choice;
    printf("Enter the size of STACK: ");
    scanf("%d", &n);
    do {
        printf("\n1: Push\n2: Pop\n3: Display\n4: Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("\nExiting"); break;
            default: printf("\nInvalid choice");
        }
    } while (choice != 4);
    return 0;
}
