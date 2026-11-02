#include <stdio.h>

int main(){
    int num=496;
    int sum = 0;
    for(int i=1; i*i <= num; i++){
        if(num % i == 0){
            printf("%d\n", i);
            if(i == num/i) sum += i;
            else sum += i + num/i;
        }
    }
    printf("num:%d sum:%d\n", num, sum);
    if(sum == num) printf("%d\n", num);
    return 0;
}