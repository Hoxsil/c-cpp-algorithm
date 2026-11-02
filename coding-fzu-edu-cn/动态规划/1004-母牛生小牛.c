#include<stdio.h>
int n, input_list[1000], num_list[1000]={1, 1, 1, 1}, max_num;
void get_num_list(int n){
    for(int i=1;i < n;i++){
        num_list[i+3]+=num_list[i];
        num_list[i+1]+=num_list[i];
    }
    return;
}

int main(void){
    while (1) {
        int a;
        scanf("%d", &a);
        if(a == 0){
            break;
        }
        if(max_num < a)
            max_num = a;
        n++;
        input_list[n]=a;
    }
    get_num_list(max_num);
    for(int i=1;i <= n;i++){
        printf("%d\n", num_list[input_list[i]]);
    }
    return 0;
}