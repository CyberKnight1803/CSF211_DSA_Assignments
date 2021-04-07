#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int getParent(int i){
    return (i - 1) / 2;
}

int getLeftChild(int i){
    return 2 * i + 1;
}

int getRightChild(int i){
    return 2 * i + 2;
}

int getRoot(int a[], int n){
    if(n >= 1)
        return a[0];
    else
        return -1;
}

void minHeapify(int a[], int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if(l < n && a[l] < a[i])
        smallest = l;
    
    if(r < n && a[r] < a[smallest])
        smallest = r;
    
    if(smallest != i){
        swap(&a[i], &a[smallest]);
        minHeapify(a, n, smallest);
    }
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
        swap(&a[i], &a[largest]);
        maxHeapify(a, n, largest);
    }
}

void insertMinHeap(int a[], int *n, int key){
    if(*n == 0){
        a[(*n)++] = key;
        return;
    }
    a[(*n)++] = key;

    for(int i = ((*n) / 2) - 1; i >= 0; --i){
        minHeapify(a, *n, i);
    }
}

void insertMaxHeap(int a[], int *n, int key){
    if(*n == 0){
        a[(*n)++] = key;
        return;
    }
    a[(*n)++] = key;

    for(int i = ((*n) / 2) - 1; i >= 0; --i){
        maxHeapify(a, *n, i);
    }
}

int extractMin(int a[], int *n){
    if(*n == 0)
        return -1;
    
    if(*n == 1){
        (*n)--;
        return a[0];
    }

    int key = a[0];
    a[0] = a[(*n) - 1];
    --(*n);
    minHeapify(a, *n, 0);

    return key;
}

int extractMax(int a[], int *n){
    if(*n == 0)
        return -1;
    
    if(*n == 1){
        (*n)--;
        return a[0];
    }

    int key = a[0];
    a[0] = a[(*n) - 1];
    --(*n);
    maxHeapify(a, *n, 0);

    return key;
}

void buildMinHeap(int a[], int n){
    for(int i = (n / 2) - 1; i >= 0; --i)
        minHeapify(a, n, i);
}

void buildMaxHeap(int a[], int n){
    for(int i = (n / 2) - 1; i >= 0; --i)
        maxHeapify(a, n, i);
}

void printArr(int a[], int n){
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(a) / sizeof(int);
    buildMaxHeap(a, n);
    printArr(a, n);
}

