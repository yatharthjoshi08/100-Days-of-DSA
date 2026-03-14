// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) return -1;
    Node* temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* queue = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    
    Stack* stack = createStack();
    
    for (int i = 0; i < n; i++) {
        push(stack, queue[i]);
    }
    
    for (int i = 0; i < n; i++) {
        queue[i] = pop(stack);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", queue[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    free(queue);
    while (stack->top) {
        pop(stack);
    }
    free(stack);
    return 0;
}
