// Problem Statement:
// Print the nodes visible when the binary tree is viewed from the right side.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print right view nodes

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 1 3 6

// Explanation:
// At each level, the rightmost node is visible from the right view.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_node(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* build_tree(int* arr, int n) {
    if (n == 0) return NULL;
    
    struct TreeNode* root = create_node(arr[0]);
    struct TreeNode** queue = malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int i = 1;
    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = create_node(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = create_node(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

void print_right_view(struct TreeNode* root) {
    if (!root) return;
    
    struct TreeNode** q = malloc(100 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    q[rear++] = root;
    
    while (front < rear) {
        int level_size = rear - front;
        for (int i = 0; i < level_size; i++) {
            struct TreeNode* curr = q[front++];
            if (i == level_size - 1) {
                printf("%d ", curr->val);
            }
            if (curr->left) q[rear++] = curr->left;
            if (curr->right) q[rear++] = curr->right;
        }
    }
    free(q);
}

void free_tree(struct TreeNode* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct TreeNode* root = build_tree(arr, n);
    print_right_view(root);
    free_tree(root);
    free(arr);
    return 0;
}
