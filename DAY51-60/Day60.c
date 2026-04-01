// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildLevelOrderTree(int* arr, int n) {
    if (n == 0) return NULL;
    
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    int i = 1;
    while (front < rear && i < n) {
        struct TreeNode* parent = queue[front++];
        
        if (i < n) {
            parent->left = createNode(arr[i++]);
            queue[rear++] = parent->left;
        }
        
        if (i < n) {
            parent->right = createNode(arr[i++]);
            queue[rear++] = parent->right;
        }
    }
    
    return root;
}

int isMinHeap(struct TreeNode* root) {
    if (!root) return 1;
    
    if (root->left && root->val > root->left->val) return 0;
    if (root->right && root->val > root->right->val) return 0;
    
    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct TreeNode* root = buildLevelOrderTree(arr, n);
    
    printf("%s\n", isMinHeap(root) ? "YES" : "NO");
    return 0;
}

