// Problem: Implement Bubble Sort - Implement the algorithm.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the sorted array or search result

// Example:
// Input:
// 5
// 64 34 25 12 22

// Output:
// 12 22 25 34 64

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[10000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
    
    // Output
    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
