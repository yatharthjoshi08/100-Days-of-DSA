// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* buildList(int n, int arr[]) {
    if (n <= 0) return NULL;
    
    Node* head = createNode(arr[0]);
    Node* tail = head;
    
    for (int i = 1; i < n; i++) {
        tail->next = createNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

void printList(Node* head) {
    if (head == NULL) return;
    
    Node* curr = head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(" ");
        }
        curr = curr->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

Node* rotateRight(Node* head, int k) {
    if (head == NULL || k == 0) return head;
    
    int n = getLength(head);
    k = k % n;
    if (k == 0) return head;
    
    Node* prev = head;
    for (int i = 1; i < n - k; i++) {
        prev = prev->next;
    }
    
    Node* newHead = prev->next;
    
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    tail->next = head;
    prev->next = NULL;
    return newHead;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int k;
    scanf("%d", &k);
    
    Node* head = buildList(n, arr);
    head = rotateRight(head, k);
    printList(head);
    
    freeList(head);
    free(arr);
    return 0;
}
