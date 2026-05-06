// Problem: Count number of inversions using modified merge sort.
// Inversion if i < j and a[i] > a[j].

#include <stdio.h>
#include <stdlib.h>

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1); 
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return count;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += mergeSortAndCount(arr, temp, left, mid);
        count += mergeSortAndCount(arr, temp, mid + 1, right);
        count += mergeAndCount(arr, temp, left, mid, right);
    }
    return count;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = 4;
    int *temp = (int*)malloc(n * sizeof(int));
    
    long long inv_count = mergeSortAndCount(arr, temp, 0, n - 1);
    
    printf("Inversion Count: %lld\n", inv_count);
    free(temp);
    return 0;
}
