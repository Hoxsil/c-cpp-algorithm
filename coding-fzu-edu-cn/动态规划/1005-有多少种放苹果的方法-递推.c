#include <stdio.h>
#define MAX 15
int dp[MAX][MAX];

void dfs(int m, int n){
    for(int i=1;i <= m;i++){
        for(int j=2;j <= n;j++){
            if (i-j >= 0)
                dp[i][j] = dp[i][j-1] + dp[i-j][j];
            else
                dp[i][j] = dp[i][i];
        }
    }
}

int main(){
    for(int i=0;i < MAX;i++){
        dp[0][i]=1;
        dp[i][1]=1;
    }
    dfs(MAX-1, MAX-1);

    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
}
