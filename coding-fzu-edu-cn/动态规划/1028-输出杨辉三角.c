#include <stdio.h>
int line[20];
int main(){
    int n;
    scanf("%d", &n);
    line[1] = 1;
    printf("1    \n");
    for(int i=2;i <= n;i++){
        for(int j=i;j >= 1;j--){
            printf("%-5d", line[j-1] + line[j]);
            line[j] += line[j-1];
        }
        printf("\n");
    }
    return 0;
}