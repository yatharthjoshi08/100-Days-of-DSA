// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QNode {
    Node* node;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode* front;
    QNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enq(Queue* q, Node* node) {
    QNode* nq = (QNode*)malloc(sizeof(QNode));
    nq->node = node;
    nq->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = nq;
    } else {
        q->rear->next = nq;
        q->rear = nq;
    }
}

Node* deq(Queue* q) {
    if (q->front == NULL) return NULL;
    QNode* tmp = q->front;
    Node* node = tmp->node;
    q->front = tmp->next;
    if (q->front == NULL) q->rear = NULL;
    free(tmp);
    return node;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

Node* newNode(int data) {
    if (data == -1) return NULL;
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node* buildTreeFromLevelOrder(int* arr, int n) {
    if (n == 0) return NULL;

    Node** nodes = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; 2*i+1 < n; i++) {
        if (nodes[i] == NULL) continue;
        if (2*i+1 < n) nodes[i]->left = nodes[2*i+1];
        if (2*i+2 < n) nodes[i]->right = nodes[2*i+2];
    }

    Node* root = nodes[0];
    free(nodes);
    return root;
}

void zigzagLevelOrder(Node* root) {
    if (root == NULL) return;

    Queue* q = createQueue();
    enq(q, root);

    int level = 0;

    while (!isEmpty(q)) {
        int sz = 0;
        QNode* count = q->front;
        while (count) { sz++; count = count->next; }

        int* levelVals = (int*)malloc(sz * sizeof(int));
        int idx = 0;

        for (int i = 0; i < sz; i++) {
            Node* curr = deq(q);
            levelVals[idx++] = curr->data;

            if (curr->left)  enq(q, curr->left);
            if (curr->right) enq(q, curr->right);
        }

        if (level % 2 == 1) {
            for (int i = 0; i < sz/2; i++) {
                int t = levelVals[i];
                levelVals[i] = levelVals[sz-1-i];
                levelVals[sz-1-i] = t;
            }
        }

        for (int i = 0; i < sz; i++) {
            printf("%d ", levelVals[i]);
        }

        free(levelVals);
        level++;
    }

    free(q);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTreeFromLevelOrder(arr, n);
    zigzagLevelOrder(root);

    printf("\n");

    free(arr);
    return 0;
}
