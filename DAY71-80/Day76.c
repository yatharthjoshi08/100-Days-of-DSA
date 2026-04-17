// Problem Statement
// Using DFS or BFS, count number of connected components.

// Input Format
// n m
// edges

// Output Format
// Number of connected components.

// Sample Input
// 6 3
// 1 2
// 2 3
// 5 6

// Sample Output
// 3

// Explanation
// Components: {1,2,3}, {4}, {5,6}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m;
int *adj[100005];
int deg[100005];
bool visited[100005];

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int *u = (int*)malloc(m * sizeof(int));
    int *v = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u[i], &v[i]);
        deg[u[i]]++;
        deg[v[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(deg[i] * sizeof(int));
        deg[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        adj[u[i]][deg[u[i]]++] = v[i];
        adj[v[i]][deg[v[i]]++] = u[i];
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);

    for (int i = 1; i <= n; i++) free(adj[i]);
    free(u);
    free(v);
    return 0;
}
