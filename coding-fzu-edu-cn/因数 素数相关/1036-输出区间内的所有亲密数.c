#include <stdio.h>

int get_factor_sum(int num){
    int sum = 0;
    for(int i=1; i*i <= num; i++){
        if(num % i == 0){
            if(i == num/i) sum += i;
            else sum += i + num/i;
        }
    }
    return sum-num;
}

int main(){
    for(int num=2;num <= 20000;num++){
        int num_factor_sum = get_factor_sum(num);
        if(num == get_factor_sum(num_factor_sum)) printf("%d %d\n", num, num_factor_sum);
    }
    return 0;
}