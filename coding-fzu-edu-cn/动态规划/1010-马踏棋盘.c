#include <stdio.h>

int flag[6][6];
int step_x[8]={1,1,-1,-1,2,2,-2,-2};
int step_y[8]={2,-2,2,-2,1,-1,1,-1};

bool in_bounds(int x, int y){
    return x>=1 && y>=1 && x<=5 && y<=5;
}

int dfs(int x, int y, int step){
    if(step == 0) return 1;
    flag[x][y] = 1;
    int sum = 0;
    for(int i=0;i < 8;i++){
        int next_x = x+step_x[i];
        int next_y = y+step_y[i];
        if(flag[next_x][next_y] == 0 && in_bounds(next_x, next_y))
            sum += dfs(next_x, next_y, step-1);
    }
    flag[x][y] = 0;
    return sum;
}

int main(){
    int origin_x, origin_y;
    scanf("%d%d", &origin_x, &origin_y);
    printf("%d", dfs(origin_x, origin_y, 24));
    return 0;
}