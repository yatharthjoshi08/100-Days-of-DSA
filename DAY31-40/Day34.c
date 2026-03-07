// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void push(int val) {
    Node* node = createNode(val);
    node->next = top;
    top = node;
}

int pop() {
    if (top == NULL) return 0;
    Node* temp = top;
    int val = top->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");
    
    while (token != NULL) {
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            int b = pop();
            int a = pop();
            
            int result;
            if (token[0] == '+') result = a + b;
            else if (token[0] == '-') result = a - b;
            else if (token[0] == '*') result = a * b;
            else result = a / b;
            
            push(result);
        } else {
            push(atoi(token));
        }
        
        token = strtok(NULL, " ");
    }
    
    return top ? top->data : 0;
}

void freeStack() {
    while (top) {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;
    
    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    
    freeStack();
    return 0;
}
