// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

#include <stdio.h>
#include <stdlib.h>

#define MAXV 100005
#define MAXE 1000005
#define INF 1000000000000000000LL

typedef struct {
    int to, w, next;
} Edge;

typedef struct {
    long long d;
    int v;
} Node;

Edge edges[MAXE];
int head[MAXV];
long long dist[MAXV];
int visited[MAXV];
int ecnt = 0;
int n, m;

typedef struct {
    Node *heap;
    int size;
    int cap;
} MinHeap;

void add_edge(int u, int v, int w) {
    edges[ecnt].to = v;
    edges[ecnt].w = w;
    edges[ecnt].next = head[u];
    head[u] = ecnt++;
}

MinHeap* create_heap(int cap) {
    MinHeap *pq = (MinHeap*)malloc(sizeof(MinHeap));
    pq->heap = (Node*)malloc((cap + 5) * sizeof(Node));
    pq->size = 0;
    pq->cap = cap + 5;
    return pq;
}

void push(MinHeap *pq, long long d, int v) {
    int i = ++pq->size;
    while (i > 1 && pq->heap[i / 2].d > d) {
        pq->heap[i] = pq->heap[i / 2];
        i /= 2;
    }
    pq->heap[i].d = d;
    pq->heap[i].v = v;
}

Node pop(MinHeap *pq) {
    Node root = pq->heap[1];
    Node last = pq->heap[pq->size--];
    int i = 1, child;
    while ((child = i * 2) <= pq->size) {
        if (child + 1 <= pq->size && pq->heap[child + 1].d < pq->heap[child].d)
            child++;
        if (last.d <= pq->heap[child].d) break;
        pq->heap[i] = pq->heap[child];
        i = child;
    }
    pq->heap[i] = last;
    return root;
}

int empty(MinHeap *pq) {
    return pq->size == 0;
}

void dijkstra(int src) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    MinHeap *pq = create_heap(MAXE);
    dist[src] = 0;
    push(pq, 0, src);

    while (!empty(pq)) {
        Node cur = pop(pq);
        int u = cur.v;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int w = edges[i].w;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(pq, dist[v], v);
            }
        }
    }

    free(pq->heap);
    free(pq);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) head[i] = -1;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(source);

    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        if (dist[i] == INF) printf("-1");
        else printf("%lld", dist[i]);
    }
    printf("\n");

    return 0;
}
