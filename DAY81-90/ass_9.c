// Perform BFS on a given Graph

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int vertices;
    int adj[MAX][MAX];
} Graph;

Graph* createGraph(int v) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertices = v;
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            g->adj[i][j] = 0;
    return g;
}

void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;  // Directed; uncomment next line for undirected
    // g->adj[v][u] = 1;
}

void bfs(Graph* g, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;
    
    printf("BFS Traversal: ");
    while(front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        
        for(int i = 0; i < g->vertices; i++) {
            if(g->adj[curr][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int v, e, start;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    Graph* g = createGraph(v);
    
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v):\n");
    for(int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }
    
    printf("Enter starting node: ");
    scanf("%d", &start);
    bfs(g, start);
    
    free(g);
    return 0;
}

