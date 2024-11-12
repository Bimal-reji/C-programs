\#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in level order
struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (!root) return newNode;

    struct Node *temp, **queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];
        if (!temp->left) { temp->left = newNode; break; }
        else queue[rear++] = temp->left;
        
        if (!temp->right) { temp->right = newNode; break; }
        else queue[rear++] = temp->right;
    }
    free(queue);
    return root;
}

// Traversals
void inorder(struct Node* root) { if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); } }
void preorder(struct Node* root) { if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); } }
void postorder(struct Node* root) { if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); } }

// Find and delete the deepest node
void deleteDeepestNode(struct Node* root, struct Node* d_node) {
    struct Node *temp, **queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];
        if (temp->right) {
            if (temp->right == d_node) { temp->right = NULL; free(d_node); break; }
            queue[rear++] = temp->right;
        }
        if (temp->left) {
            if (temp->left == d_node) { temp->left = NULL; free(d_node); break; }
            queue[rear++] = temp->left;
        }
    }
    free(queue);
}

// Delete a node with given value
struct Node* deleteNode(struct Node* root, int data) {
    if (!root) return NULL;

    struct Node *temp, *key_node = NULL, **queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];
        if (temp->data == data) key_node = temp;
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    if (key_node) {
        key_node->data = temp->data;
        deleteDeepestNode(root, temp);
    }
    free(queue);
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Delete\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &data); root = insert(root, data); break;
            case 2: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 3: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 4: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 5: printf("Enter value to delete: "); scanf("%d", &data); root = deleteNode(root, data); break;
            case 6: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
