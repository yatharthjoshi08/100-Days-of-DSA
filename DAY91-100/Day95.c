// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float val;
    struct Node* next;
};

struct Node* insertionSort(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* sorted = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* next = curr->next;
        if (!sorted || sorted->val >= curr->val) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->val < curr->val)
                temp = temp->next;
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
}

void bucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)calloc(n, sizeof(struct Node*));
    
    for (int i = 0; i < n; i++) {
        int bi = (int)(n * arr[i]);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = arr[i];
        newNode->next = buckets[bi];
        buckets[bi] = newNode;
    }
    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        struct Node* temp = buckets[i];
        while (temp) {
            arr[idx++] = temp->val;
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%.4f ", arr[i]);
    
    bucketSort(arr, n);

    printf("\nSorted:   ");
    for (int i = 0; i < n; i++) printf("%.4f ", arr[i]);
    printf("\n");
    return 0;
}
