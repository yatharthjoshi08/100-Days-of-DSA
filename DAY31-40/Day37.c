// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

PriorityQueue pq = { .size = 0 };

int isEmpty() {
    return pq.size == 0;
}

void insert(int val) {

    pq.data[pq.size] = val;
    pq.size++;
    
    int i = pq.size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq.data[parent] <= pq.data[i]) {
            break;
        }
        int temp = pq.data[parent];
        pq.data[parent] = pq.data[i];
        pq.data[i] = temp;
        i = parent;
    }
}

int deleteMin() {
    if (isEmpty()) return -1;
    
    int result = pq.data[0];
    
    pq.data[0] = pq.data[pq.size - 1];
    pq.size--;
    
    int i = 0;
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < pq.size && pq.data[left] < pq.data[smallest]) {
            smallest = left;
        }
        if (right < pq.size && pq.data[right] < pq.data[smallest]) {
            smallest = right;
        }
        
        if (smallest == i) break;
        
        int temp = pq.data[i];
        pq.data[i] = pq.data[smallest];
        pq.data[smallest] = temp;
        i = smallest;
    }
    
    return result;
}

int peek() {
    if (isEmpty()) return -1;
    return pq.data[0];
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        }
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    
    return 0;
}
