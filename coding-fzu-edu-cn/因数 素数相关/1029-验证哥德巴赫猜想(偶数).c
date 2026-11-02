#include <stdio.h>
#include <stdbool.h>

int main(){
    long long n;
    scanf("%lld", &n);
    bool is_odd[n+1], find_result=false;

    for(int i=2;i <= n;i++)
        is_odd[i] = true;

    for(long long i=2;i*i <= n;i++){
        if(!is_odd[i]) continue;
        for(long long j=2*i;j <= n;j+=i)
            is_odd[j] = false;
    }

    for(long long i=2;i <= n;i++){
        if(!is_odd[i]) continue;
        long long k=n-i;
        if(!is_odd[k] || k < i) continue;
        printf("%lld=%lld+%lld\n", n, i, k);
        find_result = true;
        break;
    }
    return 0;
}