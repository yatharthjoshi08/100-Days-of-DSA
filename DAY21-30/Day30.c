// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createNode(int c, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int c, int e) {
    Node* newNode = createNode(c, e);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void swap(Node* a, Node* b) {
    int temp_coeff = a->coeff;
    int temp_exp = a->exp;
    a->coeff = b->coeff;
    a->exp = b->exp;
    b->coeff = temp_coeff;
    b->exp = temp_exp;
}

void bubbleSort(Node* head) {
    if (head == NULL) return;
    int swapped;
    Node* ptr;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != NULL) {
            if (ptr->exp < ptr->next->exp) {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

void printPolynomial(Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    Node* temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first) printf(" + ");
        if (temp->coeff == 1 && temp->exp > 0) {
        } else {
            printf("%d", temp->coeff);
        }
        if (temp->exp > 0) {
            printf("x");
            if (temp->exp > 1) {
                printf("^%d", temp->exp);
            }
        }
        first = 0;
        temp = temp->next;
    }
}

void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        insertAtEnd(&head, c, e);
    }
    bubbleSort(head);
    printPolynomial(head);
    freeList(&head);
    return 0;
}
