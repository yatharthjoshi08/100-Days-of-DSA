// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front, rear;
    int capacity, size;
} CircularQueue;

CircularQueue* createQueue(int n) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = n * 2;
    q->arr = (int*)malloc((n * 2) * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isFull(CircularQueue* q) {
    return q->size == q->capacity;
}

void enqueue(CircularQueue* q, int val) {
    if (isFull(q)) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeue(CircularQueue* q) {
    if (q->size == 0) return -1;
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return 0;
}

void printQueue(CircularQueue* q) {
    int count = 0;
    int i = q->front;
    while (count < q->size) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->capacity;
        count++;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    CircularQueue* q = createQueue(n);
    
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }
    
    printQueue(q);
    
    free(q->arr);
    free(q);
    return 0;
}
