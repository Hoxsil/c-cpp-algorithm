// 本题使用埃氏分段筛，时间复杂度 O(nloglogn) 空间复杂度(sqrt n)
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int sqrt_n_odd_list[10005];
bool is_odd_list[10005];

int min(int a, int b){
    return a < b ? a : b;
}

// 获得前 sqrt n 项的素数列表（从 1 开始存储）并返回其长度
int get_sqrt_n_odd_list(int n){
    int num=0;
    for(int i=2;i*i <= n;i++) is_odd_list[i] = true;
    for(int i=2;i*i <= n;i++){
        if(!is_odd_list[i]) continue;
        sqrt_n_odd_list[++num] = i;
        // 此处不对所有的 n 筛完以控制内存
        for(int j=2*i;j*j <= n;j+=i)
            is_odd_list[j] = false;
    }
    return num;
}


int main(){
    int n;
    scanf("%d", &n);
    int odd_list_length = get_sqrt_n_odd_list(n);
    int num = odd_list_length, step = (int) sqrt(n);
    for(int start=step;start <= n;start += step){
        for(int i=0;i <= step;i++){
            is_odd_list[i] = true;
        }
        int end = min(n, start + step);
        for(int k=1;k <= odd_list_length;k++){
            int this_odd = sqrt_n_odd_list[k];
            for(int j=start - start % this_odd + this_odd;j <= end;j+=this_odd){
                is_odd_list[j-start] = false;
            }
        }
        for(int i=1;i <= end-start;i++){
            if(is_odd_list[i]) num++;
        }
    }
    printf("%d", num);
    return 0;
}