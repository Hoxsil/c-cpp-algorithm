#include <stdio.h>

void dfs(int n){
    if(n == 1) return;
    if(n % 2 == 0){
        printf("%d/2=%d\n", n, n/2);
        dfs(n/2);
    }
    else{
        printf("%d*3+1=%d\n", n, (n*3+1));
        dfs(n*3+1);
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    dfs(n);
    return 0;
}