#include<stdio.h>

int dp[105][1005];
int time[105], value[105];
int max(int a,int b){
    return a > b ? a : b;
}
int main(){
    int all_time,n;
    scanf("%d%d", &all_time, &n);
    for(int i=1;i <= n;i++)
        scanf("%d%d", &time[i], &value[i]);
    for(int i=1;i <= n;i++)
        for(int j=0;j <= all_time;j++){
            // 如果不采最多的价值
            int status_1_value = dp[i-1][j];
            // 如果采了最多的价值
            int status_2_value = j + time[i] > all_time ? 0 : dp[i-1][j+time[i]] + value[i];
            dp[i][j] = max(status_1_value, status_2_value);
        }
    printf("%d", dp[n][0]);
    return 0;
}