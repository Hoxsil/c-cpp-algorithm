#include <stdio.h>
#include <stdbool.h>

bool is_odd[10001];

int main(){
    for(int i=2;i <= 9999;i++)
        is_odd[i] = true;

    for(int i=2;i*i <= 9999;i++){
        if(!is_odd[i]) continue;
        for(int j=2*i;j <= 9999;j+=i)
            is_odd[j] = false;
    }
    int n=0;
    for(int i=1000;i <= 9999;i++){
        if(is_odd[i] && is_odd[i/10] && is_odd[i/100] && is_odd[i/1000]) n++;
    }
    printf("%d", n);
    return 0;
}