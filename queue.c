#include <stdio.h>
#define max_size 3
int front = -1, rear = -1, Q[max_size];
void enqueue(int x) {
    if (rear == max_size - 1) printf("\nQUEUE OVERFLOW");
    else {
        if (front == -1) front = 0;
        Q[++rear] = x;
        printf("Enqueued: %d\n", x);
    }
}
void dequeue() {
    if (front == -1) printf("\nQUEUE UNDERFLOW");
    else {
        printf("Dequeued: %d\n", Q[front]);
        if (front == rear) front = rear = -1;
        else front++;
    }
}
void display() {
    if (front == -1) printf("QUEUE is empty\n");
    else {
        printf("QUEUE: ");
        for (int i = front; i <= rear; i++) printf("%d ", Q[i]);
        printf("\n");
    }
}
int main() {
    int choice, element;
    do {
        printf("\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
            printf("Enter element: "); 
            scanf("%d", &element); 
            enqueue(element); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
