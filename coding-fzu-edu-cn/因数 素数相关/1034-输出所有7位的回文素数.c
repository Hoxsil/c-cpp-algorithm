#include <stdio.h>
#include <stdbool.h>

bool is_odd[10000001];

int get_length(int num){
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

int get_n_th_number(int n, int num){
    for(int i=1;i < n;i++) num /= 10;
    return num % 10;
}

bool is_palindromic_number(int num){
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
    for(int i=2;i <= 9999999;i++)
        is_odd[i] = true;

    for(int i=2;i*i <= 9999999;i++){
        if(!is_odd[i]) continue;
        for(int j=2*i;j <= 9999999;j+=i)
            is_odd[j] = false;
    }
    for(int i=1000000;i <= 9999999;i++){
        if(is_odd[i] && is_palindromic_number(i)) printf("%d\n", i);
    }
    return 0;
}