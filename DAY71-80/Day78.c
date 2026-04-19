// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **graph = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        graph[i] = (int*)calloc(n + 1, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    bool *inMST = (bool*)calloc(n + 1, sizeof(bool));
    int *key = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) key[i] = INT_MAX;
    key[1] = 0;

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;
        int minVal = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (!inMST[i] && key[i] < minVal) {
                minVal = key[i];
                u = i;
            }
        }

        inMST[u] = true;
        totalWeight += (key[u] == INT_MAX ? 0 : key[u]);

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    for (int i = 0; i <= n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(inMST);
    free(key);

    return 0;
}
