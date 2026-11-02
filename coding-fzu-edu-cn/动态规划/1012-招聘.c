#include <stdio.h>

int dp[51][51][2501];
int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}
int main(){
    int t, max_neg=0;
    scanf("%d", &t);
    for(int test_num=1;test_num <= t;test_num++){
        int n, n1, n2;
        int q1[51], q2[51], c1[51], c2[51];
        scanf("%d%d%d", &n, &n1, &n2);
        for(int i=1;i <= n;i++)
            scanf("%d%d%d%d", &q1[i], &c1[i], &q2[i], &c2[i]);
        
        for(int i=0;i <= n1;i++)
            for(int j=0;j <= n2;j++)
                for(int cur_neg=0;cur_neg <= max_neg;cur_neg++)
                    dp[i][j][cur_neg] = -1;
        dp[0][0][0] = 0;
        max_neg = 0;

        for(int k=1;k <= n;k++){
            max_neg += max(c1[k], c2[k]);
            for(int i=min(k, n1);i >= 0;i--){
                for(int j=min(k-i, n2);j >= 0;j--){
                    for(int cur_neg=1;cur_neg <= max_neg;cur_neg++){
                        // 边界判断：i-1 j-1 存在 当前负重-第k人 不为 -1 时 的价值应该存在
                        // 此时第 k 个人加入项目一
                        if(i-1 >= 0 && cur_neg-c1[k] >= 0 && dp[i-1][j][cur_neg-c1[k]] != -1){
                            dp[i][j][cur_neg] = max(dp[i][j][cur_neg], dp[i-1][j][cur_neg-c1[k]] + q1[k]);
                        }
                        // 此时第 k 个人加入项目二
                        if(j-1 >= 0 && cur_neg-c2[k] >= 0 && dp[i][j-1][cur_neg-c2[k]] != -1)
                            dp[i][j][cur_neg] = max(dp[i][j][cur_neg], dp[i][j-1][cur_neg-c2[k]] + q2[k]);
                    }
                }
            }
        }
        double max_value=0;
        for(int cur_neg=1;cur_neg <= max_neg;cur_neg++){
            double cur_value = (double) dp[n1][n2][cur_neg] / cur_neg;
            if(cur_value > max_value)
                max_value = cur_value;
        }
        printf("Case #%d: %f\n", test_num, max_value);
    }
    return 0;
}