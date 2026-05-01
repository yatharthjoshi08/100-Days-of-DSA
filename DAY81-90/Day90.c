// Problem Statement
// Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

// Determine the minimum time required to paint all boards.

// Input Format
// n k
// n space-separated integers representing board lengths

// Output Format
// Print the minimum time required to paint all boards.

// Sample Input
// 4 2
// 10 20 30 40

// Sample Output
// 60

// Explanation
// One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.

#include <stdio.h>

int isPossible(int *boards, int n, int k, long long t) {
    int painters = 1;
    long long currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > t)
            return 0;
        if (currSum + boards[i] > t) {
            painters++;
            currSum = boards[i];
        } else {
            currSum += boards[i];
        }
    }

    return (painters <= k) ? 1 : 0;
}

// Binary search for minimum time
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[100000];
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > maxLen)
            maxLen = boards[i];
    }

    long long low = maxLen, high = sum;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
