#include <stdio.h>

int main(){
    for(int num=100;num <= 10000;num++){
        int sum = 0;
        for(int i=1; i*i <= num; i++){
            if(num % i == 0){
                if(i == num/i) sum += i;
                else sum += i + num/i;
            }
        }
        sum -= num;
        if(sum == num) printf("%d\n", num);
    }
    return 0;
}