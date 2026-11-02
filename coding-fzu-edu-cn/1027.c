#include <stdio.h>

int move_x[4]={1, 0, -1, 0};
int move_y[4]={0, 1, 0, -1};
int matrix[22][22];

int main(){
    int n, fill_num=0;
    scanf("%d", &n);
    for(int layer=1;layer <= n/2;layer++){
        int x=layer-1, y=layer-1;
        matrix[x][y] = ++fill_num;
        int all_step = n - 2 * layer + 1;
        for(int i=0;i < 4;i++){
            for(int step = i == 3 ? 2 : 1; step <= all_step;step++){
                x += move_x[i]; y += move_y[i];
                matrix[x][y] = ++fill_num;
            }
        }
    }
    if(n % 2 == 1) matrix[n/2][n/2] = n*n;
    matrix[0][0] = 1;
    for(int j=0;j < n;j++){
        for(int i=0;i < n;i++) printf("%4d", matrix[i][j]);
        printf("\n");
    }
    return 0;
}