// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->size == q->capacity) {
        return;
    }
    
    if (q->front == -1) {
        q->front = 0;
    }
    
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
}

void displayQueue(Queue* q) {
    if (q->size == 0) return;
    
    int count = 0;
    int i = q->front;
    
    while (count < q->size) {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->capacity;
        count++;
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

int main() {
    int n;
    scanf("%d", &n);
    
    Queue* q = createQueue(n);
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }
    
    displayQueue(q);
    
    freeQueue(q);
    return 0;
}
