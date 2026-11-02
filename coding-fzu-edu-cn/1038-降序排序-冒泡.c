#include <stdio.h>
#include <stdbool.h>

int a[105];
int main(){
    int n, tmp;
    scanf("%d", &n);
    for(int i=1;i <= n;i++) scanf("%d", &a[i]);
    while(true){
        bool no_switch = true;
        for(int i=1;i < n;i++){
            if(a[i] < a[i+1]){
                tmp = a[i+1];
                a[i+1] = a[i];
                a[i] = tmp;
                no_switch = false;
            }
        }
        if(no_switch) break;
    }
    for(int i=1;i <= n;i++) printf("%d ", a[i]);
    return 0;
}