#include <stdio.h>
#include <stdbool.h>

bool is_odd(long long num){
    bool is_odd = true;
    for(int i=2;i*i <= num;i++){
        if(num % i == 0){
            is_odd = false;
            break;
        }
    }
    return is_odd; 
}

int main(){
    int n;
    scanf("%d", &n);
    int i = n % 2 == 0 ? n+1 : n;
    while(true){
        if(is_odd(i) && is_odd(i+2)){
            printf("%d %d", i, i+2);
            break;
        }
        i++;
    }
    return 0;
}