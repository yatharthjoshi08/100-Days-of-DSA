// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* top = NULL;

Node* createNode(char c) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = c;
    node->next = NULL;
    return node;
}

void push(char c) {
    Node* node = createNode(c);
    node->next = top;
    top = node;
}

char pop() {
    if (top == NULL) return '\0';
    Node* temp = top;
    char c = top->data;
    top = top->next;
    free(temp);
    return c;
}

char peek() {
    return top ? top->data : '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char* infix) {
    char postfix[1000] = {0};
    int k = 0;
    
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            postfix[k++] = c;
        } else if (isOperator(c)) {
            while (peek() && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
    }
    
    while (top) {
        postfix[k++] = pop();
    }
    
    printf("%s\n", postfix);
}

void freeStack() {
    while (top) {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    char infix[100];
    scanf("%s", infix);
    infixToPostfix(infix);
    freeStack();
    return 0;
}
