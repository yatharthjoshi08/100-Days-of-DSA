// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void dfs(int n, int** adj, bool* visited, int s) {
    visited[s] = true;
    printf("%d ", s);
    
    for (int i = 0; i < n; i++) {
        if (adj[s][i] && !visited[i]) {
            dfs(n, adj, visited, i);
        }
    }
}

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
    dfs(n, adj, visited, s);
    
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);
    
    printf("\n");
    return 0;
}
