#include <stdio.h>

void make_n2_biger_than_n1(int *n1, int *n2){
    int tmp;
    if(*n1 > *n2){
        tmp = *n2;
        *n2 = *n1;
        *n1 = tmp;
    }
    return;
}

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    make_n2_biger_than_n1(&a, &b);
    make_n2_biger_than_n1(&b, &c);
    make_n2_biger_than_n1(&a, &b);
    printf("%d %d %d", a, b, c);
    return 0;
}