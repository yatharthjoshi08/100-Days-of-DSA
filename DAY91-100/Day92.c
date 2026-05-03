// Problem: Implement Quick Sort using partition method (Lomuto or Hoare).

#include <stdio.h>

int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        int pi = lomutoPartition(arr, low, high);
        quickSortLomuto(arr, low, pi - 1);
        quickSortLomuto(arr, pi + 1, high);
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

    printf("Original array: ");
    printArray(arr, n);

    quickSortLomuto(arr, 0, n - 1);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}


// #include <stdio.h>

// int hoarePartition(int arr[], int low, int high) {
//     int pivot = arr[low];
//     int i = low - 1;
//     int j = high + 1;

//     while (1) {
//         do { i++; } while (arr[i] < pivot);
//         do { j--; } while (arr[j] > pivot);
//         if (i >= j) return j;
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
// }

// void quickSortHoare(int arr[], int low, int high) {
//     if (low < high) {
//         int pi = hoarePartition(arr, low, high);
//         quickSortHoare(arr, low, pi);
//         quickSortHoare(arr, pi + 1, high);
//     }
// }

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main() {
//     int arr[] = {38, 27, 43, 10, 5, 65};
//     int n = 6;

//     printf("Original: ");
//     printArray(arr, n);

//     quickSortHoare(arr, 0, n - 1);

//     printf("Sorted:   ");
//     printArray(arr, n);

//     return 0;
// }
