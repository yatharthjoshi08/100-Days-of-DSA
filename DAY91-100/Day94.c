// Problem: Sort array of non-negative integers using counting sort.
// Find max, build freq array, compute prefix sums, build output.

#include <stdio.h>
#include <stdlib.h> 

void countingSort(int arr[], int n) {
    if (n <= 1) return;

    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int *freq = (int*)calloc(max + 1, sizeof(int));
    if (!freq) return;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (int i = 1; i <= max; i++)
        freq[i] += freq[i - 1];

    int *output = (int*)malloc(n * sizeof(int));
    if (!output) {
        free(freq);
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        int val = arr[i];
        int pos = freq[val] - 1;
        output[pos] = val;
        freq[val]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(freq);
    free(output);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = 8;

    printf("Original: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted:   ");
    printArray(arr, n);

    return 0;
}
