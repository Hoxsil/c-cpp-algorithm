#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double cos_A=(b*b + c*c - a*a)/(2*b*c);
    if(cos_A <= 1 && cos_A >= -1 && a > 0 && b > 0 && c > 0){
        double sin_A=sqrt(1-cos_A*cos_A);
        double S = 0.5*b*c*sin_A;
        printf("%.2lf", S);
    }
    else
        printf("ERROR_INPUT");
    return 0;
}