// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

#include <stdio.h>
#include <stdlib.h>

#define MAXN 2005

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

struct TreeNode* buildTree(int* arr, int* idx, int n) {
    if (*idx >= n || arr[*idx] == -1) {
        (*idx)++;
        return NULL;
    }
    struct TreeNode* root = createNode(arr[*idx]);
    (*idx)++;
    root->left = buildTree(arr, idx, n);
    root->right = buildTree(arr, idx, n);
    return root;
}

void verticalOrder(struct TreeNode* root) {
    if (!root) return;
    
    // First BFS: find HD range
    int hd_min = 0, hd_max = 0;
    struct TreeNode* q[MAXN];
    int hdq[MAXN];
    int front = 0, rear = 0;
    
    q[rear] = root; hdq[rear++] = 0;
    
    while (front < rear) {
        int hd = hdq[front];
        struct TreeNode* node = q[front++];
        
        hd_min = (hd < hd_min) ? hd : hd_min;
        hd_max = (hd > hd_max) ? hd : hd_max;
        
        if (node->left) {
            q[rear] = node->left;
            hdq[rear] = hd - 1;
            rear++;
        }
        if (node->right) {
            q[rear] = node->right;
            hdq[rear] = hd + 1;
            rear++;
        }
    }
    
    // Prepare columns
    int width = hd_max - hd_min + 1;
    int shift = -hd_min;
    int** columns = (int**)malloc(width * sizeof(int*));
    int* sizes = (int*)calloc(width, sizeof(int));
    
    // Second BFS: fill columns top-to-bottom
    front = 0; rear = 1;
    q[0] = root; hdq[0] = 0;
    
    while (front < rear) {
        int hd = hdq[front];
        struct TreeNode* node = q[front++];
        int col = hd + shift;
        
        sizes[col]++;
        if (sizes[col] == 1) {
            columns[col] = (int*)malloc(sizeof(int));
        } else {
            columns[col] = (int*)realloc(columns[col], sizes[col] * sizeof(int));
        }
        columns[col][sizes[col] - 1] = node->val;
        
        if (node->left) {
            q[rear] = node->left;
            hdq[rear] = hd - 1;
            rear++;
        }
        if (node->right) {
            q[rear] = node->right;
            hdq[rear] = hd + 1;
            rear++;
        }
    }
    
    // Print columns left to right
    for (int i = 0; i < width; i++) {
        if (sizes[i] > 0) {
            for (int j = 0; j < sizes[i]; j++) {
                printf("%d ", columns[i][j]);
            }
            printf("\n");
        }
    }
    
    // Cleanup
    for (int i = 0; i < width; i++) {
        if (columns[i]) free(columns[i]);
    }
    free(columns);
    free(sizes);
}

void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAXN];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int idx = 0;
    struct TreeNode* root = buildTree(arr, &idx, n);
    verticalOrder(root);
    
    freeTree(root);
    return 0;
}
