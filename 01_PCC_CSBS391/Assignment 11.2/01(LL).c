#include <stdio.h>
#include <stdlib.h>

// Minimal struct for adjacency list nodes
struct Node {
    int vertex;
    struct Node* next;
};

/**
 * Performs BFS traversal on a graph.
 * All memory (queue, visited) is allocated and freed locally.
 */
void bfs(struct Node** adjLists, int startVertex, int numVertices) {
    if (adjLists == NULL || numVertices <= 0) return;

    // 1. Array-based queue (local to this function)
    int* queue = (int*)malloc(numVertices * sizeof(int));
    int front = 0, rear = 0;

    // 2. Visited array (local to this function)
    // calloc initializes memory to 0 (i.e., all false)
    int* visited = (int*)calloc(numVertices, sizeof(int));

    // 3. Enqueue start vertex and mark as visited
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS Traversal: ");

    // 4. Main BFS loop
    while (front < rear) {
        // Dequeue
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices
        struct Node* temp = adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex; // Enqueue
            }
            temp = temp->next;
        }
    }

    printf("\n");

    // Clean up local memory
    free(queue);
    free(visited);
}

// Main function to build graph and run BFS
int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    if (V <= 0) return 1;

    // Create adjacency list (array of node pointers)
    struct Node** adjLists = (struct Node**)calloc(V, sizeof(struct Node*));

    printf("Enter adjacent nodes for each vertex (end with -1):\n");
    
    for (int i = 0; i < V; i++) {
        printf("Enter adjacent nodes of node %d: ", i);
        
        int adj_v;
        while (scanf("%d", &adj_v) == 1 && adj_v != -1) {
            
            if (adj_v < 0 || adj_v >= V) {
                printf("Invalid vertex %d, skipping.\n", adj_v);
                continue;
            }

            // --- Add edge from i to adj_v ---
            // (Inserts at the head of the list for O(1) insertion)
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->vertex = adj_v;
            newNode->next = adjLists[i];
            adjLists[i] = newNode;
        }
    }

    int startNode;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startNode);

    if (startNode >= 0 && startNode < V) {
        bfs(adjLists, startNode, V);
    } else {
        printf("Invalid start node.\n");
    }

    // --- Free the graph (adjacency list) ---
    for (int i = 0; i < V; i++) {
        struct Node* temp = adjLists[i];
        while (temp != NULL) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adjLists);

    return 0;
}