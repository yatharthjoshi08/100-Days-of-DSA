// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Edge* edges = malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    int src = 0;  // Assume source 0

    int* dist = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = (i == src) ? 0 : INT_MAX;
    }

    for (int iter = 0; iter < n - 1; iter++) {
        for (int i = 0; i < m; i++) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if (dist[u] != INT_MAX && dist[u] + (long long)w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    int negCycle = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (dist[u] != INT_MAX && dist[u] + (long long)w < dist[v]) {
            negCycle = 1;
            break;
        }
    }

    if (negCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        printf("Shortest distances: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", dist[i] == INT_MAX ? -1 : dist[i]);
        }
        printf("\n");
    }

    free(dist);
    free(edges);
    return 0;
}
