#include <stdio.h>
#include <stdbool.h>

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

int main(){
    long long num;
    scanf("%lld", &num);
    printf(is_palindromic_number(num) ? "Y" : "N");
    return 0;
}