#include<stdio.h>
#define MAX 15

int memo[MAX][MAX];

int dfs(int m, int n){
    if (m==0) return 1;
    if (n==0) return 0;

    if (memo[m][n] != -1) return memo[m][n];

    if (n > m){
        memo[m][n] = dfs(m, m);
        return memo[m][n];
    }
    memo[m][n] = dfs(m, n-1)+dfs(m-n,n);
    return memo[m][n];
}

int main(void){
    for(int i=0;i < MAX;i++)
        for(int j=0;j < MAX;j++) memo[i][j]=-1;
    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dfs(a,b));
    }
    return 0;
}