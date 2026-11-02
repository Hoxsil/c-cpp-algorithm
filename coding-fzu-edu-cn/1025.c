#include <stdio.h>

int main(){
    int n, a=0, i=1;
    scanf("%d", &n);
    int origin_n = n;
    while(n > 0){
        a += (n % 10) * i;
        n /= 10;
        i++;
    }
    printf("%d%d", origin_n, a % 10);
    return 0;
}