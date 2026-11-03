#include <stdio.h>

// dp[i] 定义为，i 球时，先手方是否必赢
int dp[10005],input[105];
int pick_num_list[4]={1, 3, 7, 8};

int main(){
    int n, max_num=0;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        scanf("%d", &input[i]);
        if(max_num < input[i]) max_num = input[i];
    }
    dp[0] = 1;
    dp[2] = 1;
    for(int i=3;i <= max_num;i++){
        for(int j=0;j < 4;j++){
            if(i - pick_num_list[j] >= 0){
                if(dp[i-pick_num_list[j]] == 0){
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    for(int i=1;i <= n;i++)
        printf("%d\n", dp[input[i]]);
    return 0;
}