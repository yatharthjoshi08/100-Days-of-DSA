// Problem Statement:
// Find the height (maximum depth) of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print the height of the tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 -1

// Output:
// 3

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

Node* buildTree(int* arr, int n) {
    if (n == 0) return NULL;
    
    Node* root = createNode(arr[0]);
    int front = 0, rear = 0;
    Node* queue[10001];
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
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[10001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    printf("%d\n", maxDepth(root));

    return 0;
}
