#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
    return;
}

int mid(int *a, int *b, int *c){
    if(*b > *a) swap(a, b);
    if(*a > *c) swap(a, c);
    if(*b > *a) swap(a, b);
    return *a;
}

void quick_sort(int array[], int start, int end){
    if(start < end){
        int left = start;
        int right = end;
        int base = mid(&array[start], &array[end], &array[(start+end)/2]);
        while(left < right){
            while(array[right] >= base && left < right) right--;
            array[left] = array[right];
            while(array[left] <= base && left < right) left++;
            array[right] = array[left];
        }
        array[left] = base;
        quick_sort(array, start, left-1);
        quick_sort(array, left+1, end);
    }
    return;
}

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
long long check_in_m_n(int m[], int len_m, int n[], int len_n, int value){
    long long sum=0;
    for(int i=1;i <= len_m;i++){
        int num = check_in_n(n, len_n, value-m[i]);
        if(num == 0) break;
        sum += num;
    }
    return sum;
}

int find_k_th_num(int m[], int len_m, int n[], int len_n, long long k){
    int left = m[1] + n[1], right = m[len_m] + n[len_n], mid;
    while(left < right){
        int mid = (left+right)/2;
        long long cnt = check_in_m_n(m, len_m, n, len_n, mid);
        if(cnt < k) left = mid + 1;
        else right = mid;
    }
    return left;
}

int m[100005], n[100005];

int main(){
    int m_num, n_num;
    long long k;
    while(scanf("%d%d%lld", &m_num, &n_num, &k) == 3){
        for(int i=1;i <= m_num;i++) scanf("%d", &m[i]);
        for(int i=1;i <= n_num;i++) scanf("%d", &n[i]);
        quick_sort(m, 1, m_num);
        quick_sort(n, 1, n_num);
        int num = find_k_th_num(m, m_num, n, n_num, k);
        printf("%d\n", num);
    }
    return 0;
}