#include <stdio.h>
#include <stdbool.h>

bool is_ac[505][255][505];
int main(){
    for(int i=0;i <= 498;i++){
        int a=i, b=1, c=i;
        while(a + b + c <= 998 && b <= 254){
            is_ac[a][b][c] = true;
            b++;
            c = a + c;
        }
    }
    int n;
    scanf("%d", &n);
    for(int test_num=1;test_num <= n;test_num++){
        int sum=0, a=0, b=0, c=0, i=0;
        bool find_z=false, find_j=false, is_wrong=false, ac_judge;
        char str[1005];
        scanf("%s", str);
        while(str[i]){
            if(str[i] == 'o') sum++;
            if(str[i] == 'z'){
                if(find_z){
                    is_wrong = true;
                    break;
                }
                find_z = true;
                a = sum;
                sum = 0;
            }
            if(str[i] == 'j'){
                if(find_j || (!find_z)){
                    is_wrong = true;
                    break;
                }
                find_j = true;
                b = sum;
                sum = 0;
            }
            i++;
        }
        if(is_wrong) ac_judge = false;
        else{
            c = sum;
            ac_judge = is_ac[a][b][c];
        }
        printf(ac_judge ? "Accepted\n" : "Wrong Answer\n");
    }
    return 0;
}