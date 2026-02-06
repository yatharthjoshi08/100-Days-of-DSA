// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

// Input:
// - First line: integer p (number of entries in server log 1)
// - Second line: p sorted integers representing arrival times from server 1
// - Third line: integer q (number of entries in server log 2)
// - Fourth line: q sorted integers representing arrival times from server 2)

// Output:
// - Print a single line containing all arrival times in chronological order, separated by spaces

// Example:
// Input:
// 5
// 10 20 30 50 70
// 4
// 15 25 40 60

// Output:
// 10 15 20 25 30 40 50 60 70

// Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed

#include<stdio.h>

int main(){
    int n,x;
    printf("Enter the size of 1st array: ");
    scanf("%d", &n);
    int a[100], b[100];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the size of 2nd array: ");
    scanf("%d", &x);
    for(int j=0; j<x; j++){
        scanf("%d", &b[j]);
    }
    int i=0, j=0;
    while(i < n && j < x){
        if(a[i] <= b[j]){
            printf("%d ", a[i]);
            i++;
        }
        else{
            printf("%d ", b[j]);
            j++;
        }
    }
    while(i<n){
        printf("%d ", a[i]);
        i++;
    }
    while(j<x){
        printf("%d ", b[j]);
        j++;
    }
    return 0;
}
