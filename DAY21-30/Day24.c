// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* buildList(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0; i < n; i++) {
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
    Node* curr = head;
    int first = 1;
    while (curr != NULL) {
        if (!first) printf(" ");
        printf("%d", curr->data);
        first = 0;
        curr = curr->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node* head = buildList(n);
    
    int key;
    scanf("%d", &key);

    if (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        Node* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = temp->next;
                free(temp);
                break;
            }
            curr = curr->next;
        }
    }
    
    printList(head);
    freeList(head);
    return 0;
}
