#include <stdio.h>

// 让 n 个 a 到 c, b 为缓冲
void dfs(char a, char b, char c, int n){
    if(n == 1) printf("%c move to %c\n", a, c);
    if(n >= 2){
        dfs(a, c, b, n-1);
        printf("%c move to %c\n", a, c);
        dfs(b, a, c, n-1);
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    dfs('A', 'B', 'C', n);
    return 0;
}