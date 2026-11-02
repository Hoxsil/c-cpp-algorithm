#include <stdio.h>

int main(){
    long long a[3]={1, 1}, *cur;
    int i=3;
    do{
        long long *pre_1 = &a[(i+1)%3];
        long long *pre_2 = &a[(i)%3];
        cur = &a[(i+2)%3];
        *cur = *pre_1 + *pre_2;
        i++;
    }
    while(*cur <= 2147483647);
    printf("%d", i-1);
    return 0;
}