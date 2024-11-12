#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node* next; };
struct Queue { struct Node *front, *rear; };

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data; temp->next = NULL;
    if (!q->rear) q->front = q->rear = temp;
    else q->rear->next = temp, q->rear = temp;
    printf("Enqueued: %d\n", data);
}

int dequeue(struct Queue* q) {
    if (!q->front) return -1;
    struct Node* temp = q->front; int data = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp); return data;
}
void reverseQueue(struct Queue* q) {
    struct Node* stack = NULL;
    while (q->front) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = dequeue(q); temp->next = stack; stack = temp;
    }
    while (stack) { enqueue(q, stack->data); stack = stack->next; }
}
void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    if (!temp) { printf("Queue is empty.\n"); return; }
    printf("Queue: "); while (temp) { printf("%d ", temp->data); temp = temp->next; } printf("\n");
}
int main() {
    struct Queue* q = createQueue(); int choice, data;

    do {
        printf("\n1. Enqueue\n2. Display Queue\n3. Reverse Queue\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) { printf("Enter data: "); scanf("%d", &data); enqueue(q, data); }
        else if (choice == 2) displayQueue(q);
        else if (choice == 3) { reverseQueue(q); printf("Queue reversed.\n"); }
        else if (choice == 4) printf("Exiting...\n");
        else printf("Invalid choice. Try again.\n");
    } while (choice != 4);

    return 0;
}
