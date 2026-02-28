// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createCircularList(int n) {
    if (n <= 0) return;

    struct Node *prev = NULL;
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            prev = head;
        } else {
            prev->next = newNode;
            prev = newNode;
        }
    }

    if (prev != NULL) {
        prev->next = head;
    }
}

void printCircularList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    createCircularList(n);
    printCircularList();

    return 0;
}
