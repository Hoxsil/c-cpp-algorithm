#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    int n;
    scanf("%d", &n);
    while(n != 0){
        // cake_station[?][0] 是掉落的位置， [1] 是掉落的时间
        int cake_station_input[n+5][2];
        int all_time = -1;
        for(int i=1;i <= n;i++){
            scanf("%d%d", &cake_station_input[i][0], &cake_station_input[i][1]);
            if(cake_station_input[i][1] > all_time) all_time = cake_station_input[i][1];
        }
        int cake_station[all_time+5][11], dp[all_time+5][11];

        for(int i=0;i <= all_time;i++)
            for(int j=0;j <= 10;j++){
                cake_station[i][j] = 0;
                dp[i][j] = -1;
            }
        dp[0][5] = 0;
        // 记录 cake 落地的时间和位置
        for(int i=1;i <= n;i++){
            int x = cake_station_input[i][0];
            int time = cake_station_input[i][1];
            cake_station[time][x] ++;
        }

        for(int i=1;i <= all_time;i++){
            for(int j=0;j <= 10;j++){
                int max_last_second_cake = 0;
                if(j == 0) max_last_second_cake = max(dp[i-1][0], dp[i-1][1]);
                else if(j == 10) max_last_second_cake = max(dp[i-1][9], dp[i-1][10]);
                else max_last_second_cake = max(max(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]);
                if(max_last_second_cake != -1) dp[i][j] = max_last_second_cake + cake_station[i][j];
            }
        }
        int max_num = -1;
        for(int i=0;i <= 10;i++){
            if(dp[all_time][i] > max_num) max_num = dp[all_time][i];
        }
        printf("%d\n", max_num);
        scanf("%d", &n);
    }
    return 0;
}