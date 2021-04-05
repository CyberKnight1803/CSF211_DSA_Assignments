#include<stdio.h>

int getMax(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; ++i){
        if(max < a[i])
            max = a[i];
    }
    return max;
}

void countingSort(int a[], int n, int significantDigit){
    int c[10] = {0};    // Since only 10 digits

    for(int i = 0; i < n; ++i)
        c[(a[i] / significantDigit) % 10]++;                  // Keep  a count
    
    for(int i = 1; i < 10; ++i)
        c[i] += c[i - 1];

    int b[n];
    for(int i = n - 1; i >= 0; --i){
        b[--c[(a[i] / significantDigit) % 10]] = a[i];
    }

    for(int i = 0; i < n; ++i) a[i] = b[i];   // Coping so that original array is sorted
}

void radixSort(int a[], int n){
    int k = getMax(a, n);
    for(int significantDigit = 1; k / significantDigit > 0; significantDigit *= 10)
        countingSort(a, n, significantDigit);
}

void printArr(int a[], int n){
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}


int main(){
    int a[] = {10, 7, 1, 10, 23, 53, 32, 11, 3, 8, 4, 1};
    int n = sizeof(a) / sizeof(int);
    radixSort(a, n);
    printArr(a, n);
}