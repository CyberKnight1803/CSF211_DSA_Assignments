#include<stdio.h>

int max(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; ++i){
        if(max < a[i])
            max = a[i];
    }
    return max;
}

void countingSort(int a[], int n){
    int k = max(a, n);     // Find max to initialize c {0..k}
    int c[k + 1];

    for(int i = 0; i < k + 1; ++i)    // Fill 0s in c
        c[i] = 0;

    for(int i = 0; i < n; ++i)
        c[a[i]]++;                  // Keep  a count
    
    for(int i = 1; i < k + 1; ++i)
        c[i] += c[i - 1];

    int b[n];
    for(int i = n - 1; i >= 0; --i){
        b[--c[a[i]]] = a[i];
    }

    for(int i = 0; i < n; ++i) a[i] = b[i];   // Coping so that original array is sorted
}

void printArr(int a[], int n){
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}


int main(){
    int a[] = {10, 7, 1, 10, 23, 53, 32, 11, 3, 8, 4, 1};
    int n = sizeof(a) / sizeof(int);
    countingSort(a, n);
    printArr(a, n);
}