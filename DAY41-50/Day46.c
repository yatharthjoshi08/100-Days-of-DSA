// Problem: Level Order Traversal

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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    struct TreeNode* queue[2001];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int capacity = 4;
    int** result = malloc(capacity * sizeof(int*));
    int* colSizes = malloc(capacity * sizeof(int));
    
    while (front < rear) {
        int levelSize = rear - front;
        int* level = malloc(levelSize * sizeof(int));
        int idx = 0;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            level[idx++] = node->val;
            
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(int*));
            colSizes = realloc(colSizes, capacity * sizeof(int));
        }
        
        result[*returnSize] = level;
        colSizes[*returnSize] = levelSize;
        (*returnSize)++;
    }
    
    *returnColumnSizes = colSizes;
    return result;
}

struct TreeNode* createNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printLevelOrder(int** result, int returnSize, int* colSizes) {
    printf("Level order traversal:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < colSizes[i] - 1) printf(",");
        }
        printf("]\n");
    }
}

int main() {
    struct TreeNode* root1 = createNode(3);
    root1->left = createNode(9);
    root1->right = createNode(20);
    root1->right->left = createNode(15);
    root1->right->right = createNode(7);
    
    int returnSize1;
    int* returnColumnSizes1;
    int** result1 = levelOrder(root1, &returnSize1, &returnColumnSizes1);
    printf("Test Case 1:\n");
    printLevelOrder(result1, returnSize1, returnColumnSizes1);

    for (int i = 0; i < returnSize1; i++) {
        free(result1[i]);
    }
    free(result1);
    free(returnColumnSizes1);
    
    struct TreeNode* root2 = createNode(1);
    int returnSize2;
    int* returnColumnSizes2;
    int** result2 = levelOrder(root2, &returnSize2, &returnColumnSizes2);
    printf("\nTest Case 2:\n");
    printLevelOrder(result2, returnSize2, returnColumnSizes2);

    int returnSize3;
    int* returnColumnSizes3;
    int** result3 = levelOrder(NULL, &returnSize3, &returnColumnSizes3);
    printf("\nTest Case 3:\n");
    if (returnSize3 == 0) printf("[]\n");
    
    return 0;
}
