#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int get_length(long long num){
    int count=0;
    if (num == 0) count = 1;
    else{
        while (num > 0) {
            num /= 10;
            count++;
        }
    }
    return count;
}

int get_n_th_number(int n, long long num){
    for(int i=1;i < n;i++) num /= 10;
    return num % 10;
}

long long get_reverse_num(long long num){
    long long reverse_num=0;
    while(num > 0){
        reverse_num = (reverse_num * 10) + (num % 10);
        num /= 10;
    }
    return reverse_num;
}

bool is_palindromic_number(long long num){
    bool is_palindromic_number = true;
    int length = get_length(num);
    for(int i=1;i <= length/2;i++){
        if(get_n_th_number(i, num) != get_n_th_number(length - i + 1, num)){
            is_palindromic_number = false;
            break;
        }
    }
    return is_palindromic_number;
}

int dfs(long long num, int cur_step){
    if(cur_step > 8) return 0;
    long long next_num = num + get_reverse_num(num);
    if(is_palindromic_number(next_num)) return cur_step;
    else return dfs(next_num, cur_step+1);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        int num;
        scanf("%d", &num);
        printf("%d\n", dfs(num, 1));
    }
    return 0;
}