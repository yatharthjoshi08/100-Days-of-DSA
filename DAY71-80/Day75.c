// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int sum;
    int index;
    struct Node* next;
};

#define HASH_SIZE 1009

int hashFunction(int key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

struct Node* createNode(int sum, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

int search(struct Node* hashTable[], int sum) {
    int hashIndex = hashFunction(sum);
    struct Node* temp = hashTable[hashIndex];

    while (temp != NULL) {
        if (temp->sum == sum)
            return temp->index;
        temp = temp->next;
    }
    return -2;
}

void insert(struct Node* hashTable[], int sum, int index) {
    int hashIndex = hashFunction(sum);
    struct Node* newNode = createNode(sum, index);
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

int maxLenZeroSum(int arr[], int n) {
    struct Node* hashTable[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++)
        hashTable[i] = NULL;

    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0)
            maxLen = i + 1;

        int prevIndex = search(hashTable, prefixSum);

        if (prevIndex != -2) {
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            insert(hashTable, prefixSum, i);
        }
    }

    return maxLen;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxLenZeroSum(arr, n);
    printf("Length of longest zero-sum subarray: %d\n", result);

    return 0;
}
