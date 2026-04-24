// Problem: Implement Selection Sort - Implement the algorithm.

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
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[min_idx];
        nums[min_idx] = temp;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
