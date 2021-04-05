#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// can design custom compare
int cmp(int element, int pivot){
    return element < pivot ? 1 : 0;
}

int partition(int *a, int L, int H){
    int pivot = a[H];
    int pIdx = L - 1;

    for(int i = L; i <= H - 1; ++i){
        if(cmp(a[i], pivot)){                     // added custom cmp instead of a[i] < pivot
            pIdx++;
            swap(&a[pIdx], &a[i]);
        }
    }
    swap(&a[pIdx + 1], &a[H]);
    return pIdx + 1;
}

void qSort(int *a, int L, int H){
    if(L < H){
        int pIdx = partition(a, L, H);
        qSort(a, L, pIdx - 1);
        qSort(a, pIdx + 1, H);
    }
}

void printArr(int a[], int n){
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

int main(){
    int a[] = {10, 7, 1, 10, 23, 53, 32, 11, 3, 8, 4, 1};
    int n = sizeof(a) / sizeof(int);
    qSort(a, 0, n - 1);
    printArr(a, n);
}