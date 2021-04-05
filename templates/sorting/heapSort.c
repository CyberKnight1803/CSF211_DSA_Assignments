#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(int a[], int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if(l < n && a[l] > a[i])
        largest = l;
    
    if(r < n && a[r] > a[largest])
        largest = r;
    
    if(largest != i){
        swap(&a[largest], &a[i]);
        maxHeapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n){
    for(int i = (n / 2) - 1; i >= 0; --i)
        maxHeapify(a, n, i);
}

void heapSort(int a[], int n){
    int heapSize = n;
    buildMaxHeap(a, n);
    for(int i = n - 1; i > 0; --i){
        swap(&a[0], &a[i]);
        heapSize--;
        maxHeapify(a, heapSize, 0);
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
    heapSort(a, n);
    printArr(a, n);
}