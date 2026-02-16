/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15
*/
#include<stdio.h>

int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    int matrix[100][100];
    int sum = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i =0; i<n && i<m; i++){
        sum += matrix[i][i];
    }

    printf("%d", sum);
    return 0;
}