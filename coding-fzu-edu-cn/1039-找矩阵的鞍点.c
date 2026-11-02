#include <stdio.h>
#include <stdbool.h>

int matrix[12][12], max_i[12], min_j[12];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int j=1;j <= m;j++) min_j[j] = 999999;
    for(int i=1;i <= n;i++){
        for(int j=1;j <= m;j++){
            scanf("%d", &matrix[i][j]);
            if(max_i[i] < matrix[i][j]) max_i[i] = matrix[i][j];
            if(min_j[j] > matrix[i][j]) min_j[j] = matrix[i][j];
        }
    }
    bool find_result=false;
    for(int i=1;i <= n;i++){
        for(int j=1;j <= m;j++){
            if(matrix[i][j] == max_i[i] && matrix[i][j] == min_j[j]){
                printf("Matrix[%d,%d]=%d\n", i-1, j-1, matrix[i][j]);
                find_result = true;
            }
        }
    }
    if(!find_result) printf("0");
    return 0;
}