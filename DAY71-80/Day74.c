// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

#include <stdio.h>
#include <string.h>

#define MAX_N 1005
#define MAX_NAME 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX_N][MAX_NAME];
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char candidates[MAX_N][MAX_NAME];
    int counts[MAX_N];
    int unique = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], candidates[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(candidates[unique], votes[i]);
            counts[unique] = 1;
            unique++;
        }
    }

    int best = 0;
    for (int i = 1; i < unique; i++) {
        if (counts[i] > counts[best] ||
            (counts[i] == counts[best] && strcmp(candidates[i], candidates[best]) < 0)) {
            best = i;
        }
    }

    printf("%s %d\n", candidates[best], counts[best]);
    return 0;
}
