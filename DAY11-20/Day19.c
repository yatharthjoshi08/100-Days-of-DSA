// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare);
    
    int min_abs = abs(arr[0] + arr[1]);
    int first = arr[0], second = arr[1];
    
    int left = 0, right = n - 1;
    while(left < right) {
        int curr_sum = arr[left] + arr[right];
        int curr_abs = abs(curr_sum);
        
        if(curr_abs < min_abs) {
            min_abs = curr_abs;
            first = arr[left];
            second = arr[right];
        }
        
        if(curr_sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    if(first > second) {
        int temp = first;
        first = second;
        second = temp;
    }
    printf("%d %d\n", first, second);
    
    free(arr);
    return 0;
}
