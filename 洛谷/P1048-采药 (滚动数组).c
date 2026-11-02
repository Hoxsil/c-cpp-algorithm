#include<stdio.h>

int dp[1005];
int time[105], value[105];

int main(){
    int n, all_time;
    scanf("%d%d", &all_time, &n);
    for(int i=1;i <= n;i++)
        scanf("%d%d", &time[i], &value[i]);
    for(int i=1;i <= n;i++){
        for(int j=0;j <= all_time;j++){
            int picked_value = j + time[i] <= all_time ? dp[j + time[i]] + value[i]: 0;
            if(picked_value > dp[j]) dp[j] = picked_value;
        }
    }
    printf("%d", dp[0]);
    return 0;
}