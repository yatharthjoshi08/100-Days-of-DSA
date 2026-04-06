// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool dfs(int curr, int parent, bool visited[], int adj[][1001], int V) {
    visited[curr] = true;
    
    for (int i = 0; i < V; i++) {
        if (adj[curr][i]) {
            if (!visited[i]) {
                if (dfs(i, curr, visited, adj, V)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    int adj[1001][1001];
    memset(adj, 0, sizeof(adj));
    
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    bool visited[1001] = {false};
    
    bool hasCycle = false;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, V)) {
                hasCycle = true;
                break;
            }
        }
    }
    
    printf(hasCycle ? "YES\n" : "NO\n");
    return 0;
}
