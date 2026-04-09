// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

#define V 6

int* topologicalSort(int adj[V][V], int *resultSize) {
    int indegree[V] = {0};

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    int queue[V];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int *result = (int *)malloc(V * sizeof(int));
    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    *resultSize = count;

    if (count != V) {
        free(result);
        return NULL;
    }

    return result;
}

int main() {
    int adj[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    int resultSize;
    int *result = topologicalSort(adj, &resultSize);

    if (result == NULL) {
        printf("Graph contains cycle!\n");
    } else {
        printf("Topological order: ");
        for (int i = 0; i < resultSize; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    return 0;
}
