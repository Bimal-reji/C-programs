#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *head = NULL;

void display() {
    struct Node* temp = head;
    if (!head) printf("List is empty.\n");
    else {
        printf("Linked List: ");
        while (temp) { printf("%d -> ", temp->data); temp = temp->next; }
        printf("NULL\n");
    }
}

void insertAtBeginning(int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data; new->next = head; head = new;
}

void insertAtEnd(int data) {
    struct Node *new = (struct Node*)malloc(sizeof(struct Node)), *temp = head;
    new->data = data; new->next = NULL;
    if (!head) head = new;
    else { while (temp->next) temp = temp->next; temp->next = new; } }


void insertAny(int data, int pos) {
    struct Node *new = (struct Node*)malloc(sizeof(struct Node)), *temp = head;
    new->data = data;
    if (pos == 1) { new->next = head; head = new; }
    else {
        for (int i = 1; i < pos - 1 && temp; i++) 
        temp = temp->next;
        if (!temp) { printf("Position out of bounds.\n"); 
        free(new); 
        return; }
        new->next = temp->next; temp->next = new;
    }}

void deleteFromBeginning() {
    if (!head) printf("List is empty.\n");
    else { struct Node* temp = head; head = head->next; free(temp); }
}

void deleteFromEnd() {
    if (!head) printf("List is empty.\n");
    else if (!head->next) { free(head); head = NULL; }
    else {
        struct Node *temp = head, *prev = NULL;
        while (temp->next) { prev = temp; temp = temp->next; }
        prev->next = NULL; free(temp);
    }
}

void deleteFromPosition(int pos) {
    if (!head) printf("List is empty.\n");
    else if (pos == 1) { struct Node* temp = head; head = head->next; free(temp); }
    else {
        struct Node *temp = head, *prev = NULL;
        for (int i = 1; i < pos && temp; i++) { prev = temp; temp = temp->next; }
        if (!temp) printf("Position out of bounds.\n");
        else { prev->next = temp->next; free(temp); }
    }
}

int main() {
    int choice, data, pos;
    do {
        printf("\n1.Display 2.Insert Beginning 3.Insert End 4.Insert Position 5.Delete Beginning 6.Delete End 7.Delete Position 8.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: display(); break;
            case 2: printf("Enter data: "); scanf("%d", &data); insertAtBeginning(data); break;
            case 3: printf("Enter data: "); scanf("%d", &data); insertAtEnd(data); break;
            case 4: printf("Enter data and position: "); scanf("%d %d", &data, &pos); insertAny(data, pos); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: printf("Enter position: "); scanf("%d", &pos); deleteFromPosition(pos); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 8);
    return 0;
}
