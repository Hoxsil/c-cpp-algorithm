#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        int a;
        scanf("%d", &a);
        if(a >= 90) printf("A ");
        else if(a >= 80) printf("B ");
        else if (a >= 70) printf("C ");
        else if(a >= 60) printf("D ");
        else printf("E ");
    }
    return 0;
}