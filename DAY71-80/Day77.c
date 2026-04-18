// Problem Statement
// Using BFS or DFS, check if the entire graph is connected.

// Input Format
// n m
// edges

// Output Format
// CONNECTED
// NOT CONNECTED

// Sample Input
// 4 2
// 1 2
// 3 4

// Sample Output
// NOT CONNECTED

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *head = (int *)malloc((n + 1) * sizeof(int));
    int *to = (int *)malloc(2 * m * sizeof(int));
    int *next = (int *)malloc(2 * m * sizeof(int));
    int *visited = (int *)calloc(n + 1, sizeof(int));
    int *queue = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) head[i] = -1;

    int idx = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        to[idx] = v; next[idx] = head[u]; head[u] = idx++;
        to[idx] = u; next[idx] = head[v]; head[v] = idx++;
    }

    int front = 0, rear = 0;
    queue[rear++] = 1;
    visited[1] = 1;

    while (front < rear) {
        int u = queue[front++];
        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}
