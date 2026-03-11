// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

MinHeap heap = { .size = 0 };

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(int i) {
    while (i > 0 && heap.data[parent(i)] > heap.data[i]) {
        swap(&heap.data[parent(i)], &heap.data[i]);
        i = parent(i);
    }
}

void heapify_down(int i) {
    int min_idx = i;
    int l = left(i);
    int r = right(i);
    
    if (l < heap.size && heap.data[l] < heap.data[min_idx]) {
        min_idx = l;
    }
    if (r < heap.size && heap.data[r] < heap.data[min_idx]) {
        min_idx = r;
    }
    
    if (min_idx != i) {
        swap(&heap.data[i], &heap.data[min_idx]);
        heapify_down(min_idx);
    }
}

void insert(int val) {
    if (heap.size >= MAX_SIZE) return;
    heap.data[heap.size] = val;
    heap.size++;
    heapify_up(heap.size - 1);
}

int peek() {
    if (heap.size == 0) return -1;
    return heap.data[0];
}

int extractMin() {
    if (heap.size == 0) return -1;
    int min_val = heap.data[0];
    heap.data[0] = heap.data[heap.size - 1];
    heap.size--;
    if (heap.size > 0) {
        heapify_down(0);
    }
    return min_val;
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
    }
    
    return 0;
}
