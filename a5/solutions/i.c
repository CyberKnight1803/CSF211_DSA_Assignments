#include<stdio.h>

#define ll long long

const ll mod = 1e9 + 7;


void swap(ll *a, ll *b){
    ll t = *a;
    *a = *b;
    *b = t;
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

ll maxChocolates(ll *heap, int *heapSize, int d){
    ll sum = 0;
    for(int i = 0; i < d; ++i){
        ll max = extractMax(heap, heapSize);
        sum = (sum + max) % mod;
        insertMaxHeap(heap, heapSize, max / 3);
    }
    return sum;
}

int main(){

    int n, d;
    scanf("%d %d", &n, &d);

    ll heap[n];
    int heapSize = 0;
    for(int i = 0; i < n; ++i){
        ll x;
        scanf("%lld", &x);
        insertMaxHeap(heap, &heapSize, x);
    }

    printf("%lld", maxChocolates(heap, &heapSize, d));
}