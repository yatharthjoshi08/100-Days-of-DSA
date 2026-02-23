// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* createList(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

void printList(Node* head) {
    Node* current = head;
    int first = 1;
    while (current != NULL) {
        if (!first) printf(" ");
        printf("%d", current->data);
        first = 0;
        current = current->next;
    }
    printf("\n");
}

Node* merge(Node* l1, Node* l2) {
    Node dummy;
    dummy.next = NULL;
    Node* tail = &dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = (l1 != NULL) ? l1 : l2;
    
    return dummy.next;
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node* list1 = createList(n);
    
    int m;
    scanf("%d", &m);
    Node* list2 = createList(m);
    
    Node* merged = merge(list1, list2);
    printList(merged);
    
    freeList(merged);
    
    return 0;
}

