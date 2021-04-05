#include<stdio.h>

void insertionSort(int a[], int n){
    for(int i = 1; i < n; ++i){
        int j = i - 1;
        int key = a[i];

        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
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
    insertionSort(a, n);
    printArr(a, n);
}