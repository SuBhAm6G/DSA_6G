#include <stdio.h>
#include <stdlib.h>

void bfs(int n, int **adj, int *size, int start) {
    int *visited = (int*)calloc(n, sizeof(int));
    int queue[n];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < size[node]; i++) {
            int nxt = adj[node][i];
            if (!visited[nxt]) {
                queue[rear++] = nxt;
                visited[nxt] = 1;
            }
        }
    }
    free(visited);
}

int main() {
    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int **adj = (int**)malloc(n * sizeof(int*));
    int *size = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter number of adjacent nodes of vertex %d: ", i);
        scanf("%d", &size[i]);

        if (size[i] > n - 1) {
            printf("Warning: Invalid number of adjacent nodes.\n");
            return 1;
        }

        adj[i] = (int*)malloc(size[i] * sizeof(int));
        printf("Enter adjacent vertices of vertex %d: ", i);

        for (int j = 0; j < size[i]; j++) {
            int a;
            scanf("%d", &a);
            if (a < 0 || a >= n) {
                printf("Invalid vertex index.\n");
                return 1;
            }
            adj[i][j] = a;
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid start vertex.\n");
        return 1;
    }

    bfs(n, adj, size, start);

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);
    free(size);

    return 0;
}
