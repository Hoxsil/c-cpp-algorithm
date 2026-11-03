#include <stdio.h>

int a[100005];

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
    return;
}

// 中位数放到 a 最大放到 b 最小放到 c
int mid(int *a, int *b, int *c){
    if(*c > *a) swap(a, c);
    if(*a > *b) swap(a, b);
    if(*c > *a) swap(a, c);
    return *a;
}

void quick_sort(int array[], int start, int end){
    if(start < end){
        int left = start;
        int right = end;
        int base = mid(&array[start], &array[end], &array[(start+end)/2]);
        while(left < right){
            while(array[right] <= base && left < right) right--;
            array[left] = array[right];
            while(array[left] >= base && left < right) left++;
            array[right] = array[left];
        }
        // 此时 left = right
        array[left] = base;
        quick_sort(array, start, left-1);
        quick_sort(array, left+1, end);
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    quick_sort(a, 1, n);
    for(int i=1;i <= n;i++) printf("%d ", a[i]);
    return 0;
}