// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    if (graph->adjLists == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d: ", i);

        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            struct Node* ptr = temp;
            temp = temp->next;
            free(ptr);
        }
    }

    free(graph->adjLists);
    free(graph);
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);
    freeGraph(graph);

    return 0;
}
