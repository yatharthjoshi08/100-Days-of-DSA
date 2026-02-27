// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

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
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
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

Node* advance(Node* head, int steps) {
    for (int i = 0; i < steps; i++) {
        head = head->next;
    }
    return head;
}

Node* findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    Node* p1 = head1;
    Node* p2 = head2;
    
    if (len1 > len2) {
        p1 = advance(p1, len1 - len2);
    } else if (len2 > len1) {
        p2 = advance(p2, len2 - len1);
    }
    
    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return (p1 != NULL) ? p1 : NULL;
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
    Node* list1 = buildList(n);
    
    int m;
    scanf("%d", &m);
    Node* list2 = buildList(m);
    
    Node* intersect = findIntersection(list1, list2);
    
    if (intersect != NULL) {
        printf("%d\n", intersect->data);
    } else {
        printf("No Intersection\n");
    }
    
    freeList(list1);
    freeList(list2);
    
    return 0;
}
