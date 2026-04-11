// Dijkstraâ€™s Algorithm (Shortest Path)
// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct AdjNode {
    int dest;
    int weight;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    AdjNode** head;
    int V;
} Graph;

typedef struct {
    int vertex;
    int dist;
} MinHeapNode;

typedef struct {
    int size;
    int capacity;
    int* pos;
    MinHeapNode** array;
} MinHeap;

AdjNode* createAdjNode(int dest, int weight) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->head = (AdjNode**)malloc(V * sizeof(AdjNode*));

    for (int i = 0; i < V; i++) {
        graph->head[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjNode* newNode = createAdjNode(dest, weight);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

MinHeapNode* newMinHeapNode(int vertex, int dist) {
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode->vertex = vertex;
    minHeapNode->dist = dist;
    return minHeapNode;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist) {
        smallest = left;
    }

    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist) {
        smallest = right;
    }

    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap)) {
        return NULL;
    }

    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap* minHeap, int vertex, int dist) {
    int i = minHeap->pos[vertex];

    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->vertex] = i;

        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap* minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int* dist = (int*)malloc(V * sizeof(int));

    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    dist[src] = 0;
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;

    minHeap->size = V;
    decreaseKey(minHeap, src, dist[src]);

    while (!isEmpty(minHeap)) {
        MinHeapNode* minNode = extractMin(minHeap);
        int u = minNode->vertex;

        AdjNode* crawl = graph->head[u];
        while (crawl != NULL) {
            int v = crawl->dest;

            if (isInMinHeap(minHeap, v) &&
                dist[u] != INF &&
                crawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }

            crawl = crawl->next;
        }
    }

    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    free(dist);
}

int main() {
    int V = 5;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    int src = 0;
    dijkstra(graph, src);

    return 0;
}
   