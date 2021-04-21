// Min sweets

#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int r){
    int pivot = a[r];
    int pIdx = l - 1;

    for(int i = l; i <= r; ++i){
        if(a[i] < pivot){
            ++pIdx;
            swap(&a[i], &a[pIdx]);
        }
    }
    swap(&a[pIdx + 1], &a[r]);
    return pIdx + 1;
}

void qSort(int a[], int l, int r){
    if(l <= r){
        int pivot = partition(a, l, r);
        qSort(a, l, pivot - 1);
        qSort(a, pivot + 1, r);
    }
}

int minSweets(int a[], int n){
    qSort(a, 0, n - 1);
    int totalSweets = 1, sweets = 1;
    for(int i = 1; i < n; ++i){
        if(a[i] > a[i - 1]){
            ++sweets;
            totalSweets += sweets;
        }
        else
            totalSweets += sweets;
    }
    return totalSweets;
}

int main(){
    int n; scanf("%d", &n);
    int marks[n];

    for(int i = 0; i < n; ++i){
        scanf("%d", &marks[i]);
    }
    printf("%d", minSweets(marks, n));
}