#include <stdio.h>

char get_num_in_0_36(int num){
    if(num >= 0 && num <= 9) return (char) num + '0';
    return (char) (num + 'A' -10);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        char base_num[32];
        int base, index=0;
        long long num;
        scanf("%lld%d", &num, &base);
        if(num == 0) printf("0");
        while(num > 0){
            base_num[index++] = get_num_in_0_36(num%base);
            num /= base;
        }
        index--;
        while(index >= 0){
            printf("%c", base_num[index--]);
        }
        printf("[%d]\n", base);
    }
    return 0;
}