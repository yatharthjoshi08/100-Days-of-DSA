// Problem Statement:
// Convert a binary tree into its mirror image by swapping left and right children at every node.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print inorder traversal of mirrored tree

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 7 3 6 1 5 2 4

// Explanation:
// Each node’s left and right children are swapped recursively.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTreeFromLevel(int level[], int n) {
    if (n == 0 || level[0] == -1) return NULL;

    struct TreeNode* root = createNode(level[0]);
    struct TreeNode** queue = (struct TreeNode**) malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];

        if (i < n && level[i] != -1) {
            curr->left = createNode(level[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && level[i] != -1) {
            curr->right = createNode(level[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void mirror(struct TreeNode* root) {
    if (!root) return;

    mirror(root->left);
    mirror(root->right);

    struct TreeNode* temp = root->left;
    root->left  = root->right;
    root->right = temp;
}

void inorder(struct TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
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

    int* level = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &level[i]);
    }

    struct TreeNode* root = buildTreeFromLevel(level, n);
    mirror(root);
    inorder(root);
    printf("\n");

    free(level);
    freeTree(root);

    return 0;
}
