#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if(b > a) a = b;
    if(c > a) a = c;
    printf("%.1lf", a);
}