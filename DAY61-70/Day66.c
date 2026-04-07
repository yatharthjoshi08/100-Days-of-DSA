// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>
#include <stdbool.h>

bool dfs(int node, bool visited[], bool recStack[], int adj[][1001], int V) {
    visited[node] = true;
    recStack[node] = true;
    
    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, visited, recStack, adj, V)) {
                    return true;
                }
            } else if (recStack[i]) {
                return true;
            }
        }
    }
    
    recStack[node] = false;
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    int adj[1001][1001] = {0};
    
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    
    bool visited[1001] = {false};
    bool recStack[1001] = {false};
    
    bool cycle = false;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, V)) {
                cycle = true;
                break;
            }
        }
    }
    
    printf(cycle ? "YES\n" : "NO\n");
    return 0;
}
