// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int value) {
    Node* newNode = createNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s, int times) {
    for (int i = 0; i < times && s->top != NULL; i++) {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

void printStack(Stack* s) {
    Node* temp = s->top;
    int first = 1;
    while (temp) {
        if (!first) printf(" ");
        printf("%d", temp->data);
        first = 0;
        temp = temp->next;
    }
    printf("\n");
}

void freeStack(Stack* s) {
    while (s->top) {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    free(s);
}

int main() {
    int n;
    scanf("%d", &n);
    
    Stack* s = createStack();
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(s, val);
    }
    
    int m;
    scanf("%d", &m);
    pop(s, m);
    
    printStack(s);
    
    freeStack(s);
    return 0;
}
