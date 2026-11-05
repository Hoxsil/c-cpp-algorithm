#include <stdio.h>
#include <string.h>

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    int n;
    char s1[50005], s2[50005];
    scanf("%d", &n);
    for(int r=1;r <= n;r++){
        scanf("%50000s%50000s", &s1, &s2);
        int len_s1 = strlen(s1);
        int len_s2 = strlen(s2);
        int min_gap = 50005;
        for(int i=0;i + len_s2 <= len_s1;i++){
            int gap = 0;
            for(int j=0;j < len_s2;j++){
                if(s1[j+i] != s2[j]) gap++;
            }
            min_gap = min(min_gap, gap);
        }
        printf("Case #%d: %d\n", r, min_gap);
    }
    return 0;
}