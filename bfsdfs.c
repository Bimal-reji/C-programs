#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int A[MAX][MAX];
int visited[MAX];

// Function to initialize the graph with no edges
void initGraph(int vertices) {
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            A[i][j] = 0;
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    A[u][v] = 1;
    A[v][u] = 1; // Assuming an undirected graph
}

// Depth-First Search (DFS) using recursion
void DFS(int vertex, int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < vertices; i++)
        if (A[vertex][i] == 1 && !visited[i])
            DFS(i, vertices);
}

// Breadth-First Search (BFS) using a queue
void BFS(int start, int vertices) {
    int queue[MAX], front = -1, rear = -1;

    visited[start] = 1;
    queue[++rear] = start;
    printf("%d ", start);

    while (front != rear) {
        int vertex = queue[++front];
        
        for (int i = 0; i < vertices; i++) {
            if (A[vertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

// Reset visited array for a new traversal
void resetVisited(int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
}

int main() {
    int vertices, edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    initGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex for DFS and BFS: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    resetVisited(vertices);
    DFS(start, vertices);
    printf("\n");

    printf("BFS traversal: ");
    resetVisited(vertices);
    BFS(start, vertices);
    printf("\n");

    return 0;
}
