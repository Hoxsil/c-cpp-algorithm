#include <stdio.h>

// 找到有序数组 n 数组中 <= value 的元素的个数
int check_in_n(int n[], int len_n, int value){
    int l = 1, r = len_n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(n[mid] <= value){
            l = mid + 1;
        }
        else r = mid -1;
    }
    return r;
}

// 找到 m+n 数组中 <= value 的元素的个数
int check_in_m_n(int m[], int len_m, int n[], int len_n, int value){
    int sum=0;
    for(int i=1;i <= len_m;i++){
        int num = check_in_n(n, len_n, value-m[i]);
        if(num == 0) break;
        sum += num;
    }
    return sum;
}

int main(){
    int a[11] = {0, 7, 7, 7, 7, 7, 7, 7, 8, 9, 10};
    int b[11] = {0, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", check_in_n(a, 10, 5));
    printf("%d", check_in_m_n(a, 10, b, 10, 5));
    return 0;
}