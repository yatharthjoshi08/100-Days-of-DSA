// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdbool.h>

int stack[1001];
int top = -1;

void push(int node) {
    stack[++top] = node;
}

int pop() {
    return stack[top--];
}

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
    push(node);
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
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, V)) {
                printf("Cycle detected\n");
                return 0;
            }
        }
    }
    
    printf("Topological order: ");
    while (top >= 0) {
        printf("%d ", pop());
    }
    printf("\n");
    return 0;
}
