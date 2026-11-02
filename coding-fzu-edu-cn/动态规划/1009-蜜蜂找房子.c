#include<stdio.h>
int memo[95]={0, 1, 1};
int dfs(int n){
    if(memo[n] != 0) return memo[n];
    memo[n] = dfs(n-1) + dfs(n-2);
    return memo[n];
}
int main(){
    int all_test_num;
    scanf("%d", &all_test_num);
    for(int round=1;round <= all_test_num;round++){
        int a, b, nest_num;
        scanf("%d%d", &a, &b);
        nest_num = b - a + 1;
        printf("%d\n", dfs(nest_num));
    }
    return 0;
}