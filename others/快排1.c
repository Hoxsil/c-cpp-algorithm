#include <stdio.h>

int a[100005];

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
    return;
}

// 中位数放到 a ，最小放到 b 最大放到 c
int mid(int *a, int *b, int *c){
    if(*b > *a) swap(a, b);
    if(*a > *c) swap(a, c);
    if(*b > *a) swap(a, b);
    return *a;
}

void qSortArray(int array[], int start, int last)
{
	int low = start;
	int high = last;
	if (low < high){
		while(1){
			while (low < last && array[low] <= array[start]) low++;
			while (high > start && array[high] >= array[start]) high--;
			if (low < high) swap(&array[low], &array[high]);
            else break;
		}
		swap(&array[start], &array[high]);
		qSortArray(array, start, high - 1);
		qSortArray(array, high + 1, last);
	}
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    qSortArray(a, 1, n);
    for(int i=1;i <= n;i++) printf("%d ", a[i]);
    return 0;
}