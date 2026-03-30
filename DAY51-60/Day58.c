// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3

// Output:
// 4 5 2 3 1

// Explanation:
// Preorder identifies root, inorder splits left and right subtrees.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int val) {
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

int preIndex = 0;

struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;
    
    struct Node* root = newNode(preorder[preIndex++]);
    
    if (inStart == inEnd) return root;
    
    int inIdx = search(inorder, inStart, inEnd, root->data);
    
    root->left = buildTree(preorder, inorder, inStart, inIdx - 1);
    root->right = buildTree(preorder, inorder, inIdx + 1, inEnd);
    
    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int preorder[3000], inorder[3000];
    
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    
    preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1);
    
    postorder(root);
    printf("\n");
    
    return 0;
}
