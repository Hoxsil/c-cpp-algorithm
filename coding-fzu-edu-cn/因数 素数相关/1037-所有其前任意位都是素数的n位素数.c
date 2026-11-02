#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_odd[1000001];

bool all_is_odd(int num){
    bool all_is_odd = true;
    while(num > 0){
        if(!is_odd[num]){
            all_is_odd = false;
            break;
        }
        num /= 10;
    }
    return all_is_odd;
}

int main(){
    int n;
    scanf("%d", &n);
    int start = pow(10, n-1);
    int end = pow(10, n) - 1;

    for(int i=2;i <= end;i++)
        is_odd[i] = true;

    for(int i=2;i*i <= end;i++){
        if(!is_odd[i]) continue;
        for(long long j=2*i;j <= end;j+=i)
            is_odd[j] = false;
    }
    
    for(int i=start;i <= end;i++){
        if(all_is_odd(i)) printf("%d\n", i);
    }
    return 0;
}