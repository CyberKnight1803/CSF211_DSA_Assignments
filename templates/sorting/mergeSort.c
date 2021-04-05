#include<stdio.h>

void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int lArr[n1], rArr[n2];
    for(int i = 0; i < n1; ++i){
        lArr[i] = a[l + i];
    }
    for(int i = 0; i < n2; ++i){
        rArr[i] = a[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(lArr[i] <= rArr[j])
            a[k++] = lArr[i++];
        else 
            a[k++] = rArr[j++];
    }
    while(i < n1)
        a[k++] = lArr[i++];
    while(i < n2)
        a[k++] = rArr[j++];
}

void MergeSort(int a[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        merge(a, l, m, r);
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
    MergeSort(a, 0, n - 1);
    printArr(a, n);
}