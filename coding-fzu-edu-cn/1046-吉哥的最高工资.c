#include <stdio.h>


int s[105], e[105], c[105], dp[1005][1005];

int max(int a, int b){
    return a > b ? a : b;
}

int dfs(int start, int end){
    if(dp[start][end] != -1) return dp[start][end];
    if(start == end){
        dp[end][end] = 0;
        return 0;
    }
    for(int i=start;i < end;i++){
        dp[start][end] = max(dp[start][end], dfs(start, i) + dfs(i+1, end));
    }
    return dp[start][end];
}

int main(){
    int t;
    scanf("%d", &t);
    for(int round=1;round <= t;round++){
        int t, n;
        scanf("%d%d", &t, &n);
        for(int i=0;i <= t;i++)
            for(int j=0;j <= t;j++)
                dp[i][j] = -1;
        for(int i=1;i <= n;i++){
            scanf("%d%d%d", &s[i], &e[i], &c[i]);
            dp[s[i]][e[i]] = max(dp[s[i]][e[i]], c[i]);
        }
        printf("%d\n", dfs(1, t));
    }
}