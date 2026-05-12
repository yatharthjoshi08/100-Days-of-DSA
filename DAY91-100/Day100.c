// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT).

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int i = left, j = mid, k = 0;
    int rightCount = 0;
    
    Pair temp[right - left];

    while (i < mid && j < right) {
        if (arr[i].val <= arr[j].val) {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i < mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j < right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i < right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (right - left <= 1)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid, right, count);
    merge(arr, left, mid, right, count);
}

int* countSmaller(int* nums, int n) {
    Pair* arr = (Pair*)malloc(n * sizeof(Pair));
    int* count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n, count);

    free(arr);
    return count;
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int* result = countSmaller(nums, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}
