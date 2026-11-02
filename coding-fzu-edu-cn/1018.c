#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", (n*n*n + 3*n*n + 2*n)/6);
    return 0;
}