#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; ++i){
        int idx = i;
        
        for(int j = i + 1; j < n; ++j){
            if(a[j] < a[idx])
                idx = j;
        }
        swap(&a[idx], &a[i]);
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
    selectionSort(a, n);
    printArr(a, n);
}