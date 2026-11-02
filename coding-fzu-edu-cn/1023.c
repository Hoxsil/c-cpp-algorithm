#include <stdio.h>

void print_n_ch(int n, char ch){
    for(int i=1;i <= n;i++)
        printf("%c", ch);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        print_n_ch(n-i, ' ');
        print_n_ch(2*i-1, '*');
        printf("\n");
    }
    return 0;
}