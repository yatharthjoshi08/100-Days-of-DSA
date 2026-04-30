// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

// Books must be allocated in contiguous order.

// Input Format
// n m
// n space-separated integers representing pages in books

// Output Format
// Print the minimum possible value of the maximum pages assigned to any student.

// Sample Input
// 4 2
// 12 34 67 90

// Sample Output
// 113

// Explanation
// One optimal allocation is:
// Student 1: 12 + 34 + 67 = 113
// Student 2: 90
// Maximum pages = 113 (minimum possible).

#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int canAllocate(int pages[], int n, int m, long long maxPages) {
    int students = 1;
    long long curr = 0;
    
    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages) return 0;
        if (curr + pages[i] <= maxPages) {
            curr += pages[i];
        } else {
            students++;
            curr = pages[i];
        }
    }
    return students <= m;
}

long long allocatePages(int pages[], int n, int m) {
    if (m > n) return -1;
    
    long long lo = pages[0];
    long long hi = 0;
    
    for (int i = 0; i < n; i++) {
        lo = max(lo, pages[i]);
        hi += pages[i];
    }
    
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canAllocate(pages, n, m, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int pages[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    
    printf("%lld\n", allocatePages(pages, n, m));
    return 0;
}
