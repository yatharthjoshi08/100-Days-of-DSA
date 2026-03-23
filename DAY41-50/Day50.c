// Problem: BST Search

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        return root;
    }
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
}

int main() {
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    
    struct TreeNode* result = searchBST(root, 2);
    printf("val=2: %s (val=%d)\n", 
           result ? "FOUND" : "NULL", 
           result ? result->val : -1);

    result = searchBST(root, 5);
    printf("val=5: %s\n", result ? "FOUND" : "NULL");
    
    return 0;
}
