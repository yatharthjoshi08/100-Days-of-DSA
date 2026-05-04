// Problem: Sort an array using insertion sort.
// Stable sort. Good for nearly sorted arrays.

#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 10, 5, 65};
    int n = 6;

    printf("Original: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted:   ");
    printArray(arr, n);

    return 0;
}
