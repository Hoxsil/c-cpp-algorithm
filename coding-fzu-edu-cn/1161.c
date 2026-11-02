#include<stdio.h>
#include<string.h>
int main(){
    char s[40];
    unsigned long long num = 0;
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        num = num * 2 + (s[i] - '0');
    }
    printf("%lld\n", num);
    return 0;
}