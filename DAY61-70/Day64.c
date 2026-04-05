// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int n, s;
    scanf("%d", &n);
    
    int** adj = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    scanf("%d", &s);
    
    bool* visited = calloc(n, sizeof(bool));
    int* queue = malloc(n * sizeof(int));
    int front = 0, rear = 0;
    
    queue[rear++] = s;
    visited[s] = true;
    printf("%d ", s);
    
    while (front < rear) {
        int curr = queue[front++];
        
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
                printf("%d ", i);
            }
        }
    }
    
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(visited);
    free(queue);
    
    printf("\n");
    return 0;
}
