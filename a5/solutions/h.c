#include<stdio.h>
#define ll long long 

void swap(ll *a, ll *b){
    ll t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(ll *a, int n, int i){
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

void maxHeapify(ll *a, int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if(l < n && a[l] > a[i])
        largest = l;
    
    if(r < n && a[r] > a[largest])
        largest = r;
    
    if(largest != i){
        swap(&a[i], &a[largest]);
        maxHeapify(a, n, i);
    }
}

void insertMinHeap(ll *a, int *n, ll key){
    if(*n == 0){
        a[(*n)++] = key;
        return;
    }
    a[(*n)++] = key;

    for(int i = ((*n) / 2) - 1; i >= 0; --i){
        minHeapify(a, *n, i);
    }
}

void insertMaxHeap(ll *a, int *n, ll key){
    if(*n == 0){
        a[(*n)++] = key;
        return;
    }
    a[(*n)++] = key;

    for(int i = ((*n) / 2) - 1; i >= 0; --i){
        maxHeapify(a, *n, i);
    }
}

ll extractMin(ll *a, int *n){
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

ll extractMax(ll *a, int *n){
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


int main(){
 // Need to work on this
}