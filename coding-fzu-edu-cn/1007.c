#include <stdio.h>
#define PI 3.14159265358979323

int main(){
    int r;
    scanf("%d", &r);
    printf("%.7f", PI * ((double) r) * ((double) r));
    return 0;
}