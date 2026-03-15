// Problem Statement
// Construct a Binary Tree from the given level-order traversal.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers (-1 represents NULL)

// Output Format:
// - Print inorder traversal of the constructed tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 4 2 5 1 3 6

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) {
        printf("\n");
        return 0;
    }

    Node* root = createNode(arr[0]);
    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (front < rear && i < n) {
        Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    inorder(root);
    printf("\n");

    return 0;
}
