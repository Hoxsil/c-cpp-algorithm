#include <stdio.h>

double min(double a, double b){
    return a < b ? a : b;
}
double get_time(double v_electric, double v_normal, double radium, double gap){
    if(gap <= radium) return gap / v_electric;
    else return radium / v_electric + (gap - radium) / v_normal;
    
}

int main(){
    int n, length, charge_station_num, radium, charge_time;
    int v_rabbit, v_electric, v_normal;
    scanf("%d", &n);
    for(int round = 1;round <= n;round ++){
        scanf("%d", &length);
        scanf("%d%d%d", &charge_station_num, &radium, &charge_time);
        scanf("%d%d%d", &v_rabbit, &v_electric, &v_normal);
        int charge_station[charge_station_num+5];
        for(int i=1;i <= charge_station_num;i++)
            scanf("%d", &charge_station[i]);
        // dp[i]表示到第 i 个充电站如果要充电的话，最快的时间
        double dp[charge_station_num+5];
        // 将终点视为一个加油站，以便一次动态规划得到答案
        charge_station[0] = 0;
        charge_station[charge_station_num + 1] = length;
        
        dp[0] = 0;
        for(int i=1;i <= charge_station_num + 1;i++){
            // fastest_time 表示不加当前站的充电时间，最快到达当前站的时间
            double fastest_time = -1; 
            for(int j=0;j < i;j++){
                int gap = charge_station[i] - charge_station[j];
                double cur_time = dp[j] + get_time(v_electric, v_normal, radium, gap);
                if(fastest_time == -1){
                    fastest_time = cur_time;
                }
                fastest_time = min(cur_time, fastest_time);
            }
            dp[i] = fastest_time + charge_time;
        }
        double turtle_time =  dp[charge_station_num + 1] - charge_time;
        double rabbit_time = ((double) length) / ((double) v_rabbit);

        printf(rabbit_time < turtle_time ? "Good job,rabbit!\n" : "What a pity rabbit!\n");
    }
    return 0;
}