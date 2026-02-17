/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1
*/

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[100];

    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int max = a[0];
    int min = a[0];
    for(int i =0; i<n; i++){
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    return 0;
}