// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insertBST(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

int findLCA(struct Node* root, int p, int q) {
    if (p > q) { int temp = p; p = q; q = temp; }
    while (root != NULL) {
        if (root->data >= p && root->data <= q) {
            return root->data;
        }
        if (root->data > q) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return -1;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int p, q;
    scanf("%d %d", &p, &q);
    
    struct Node* root = NULL;
    for (int i = 0; i < N; i++) {
        root = insertBST(root, arr[i]);
    }
    
    printf("%d\n", findLCA(root, p, q));
    
    return 0;
}
