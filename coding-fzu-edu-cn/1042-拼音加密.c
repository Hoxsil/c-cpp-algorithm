#include <stdio.h>
#include <string.h>

int get_indented_number(long long num){
    while(num / 10 > 0){
        long long sum = num % 10;
        while(num > 0){
            num /= 10;
            sum += num % 10;
        }
        num = sum;
    }
    return num;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        char str[1005];
        scanf("%s", &str);
        int length = strlen(str);
        for(int i=1;i <= 6 ;i++){
            long long sum = 0;
            for(int j=i;j <= length;j+=6){
                sum += str[j-1];
            }
            printf("%d", get_indented_number(sum));
        }
        printf("\n");
    }
    return 0;
}