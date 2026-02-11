// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include<stdio.h>
#include<string.h>

int main(){
    char s[1000];
    scanf("%s",s);

    int len = strlen(s);
    int X = 1;
    for(int i =0; i<len/2; i++){
        if(s[i] != s[len-i-1]){
            X = 0;
            break;
        }
    }
    if(X){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}