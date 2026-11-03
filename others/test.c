#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
    return;
}

int mid(int *a, int *b, int *c){
    if(*b > *a) swap(a, b);
    if(*a > *c) swap(a, c);
    if(*b > *a) swap(a, b);
    return *a;
}
int main(){
    while(true){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int mid_num = mid(&a, &b, &c);
        printf("%d\n", mid_num);
        printf("a:%d b:%d c:%d\n", a, b, c);
    }
    return 0;
}