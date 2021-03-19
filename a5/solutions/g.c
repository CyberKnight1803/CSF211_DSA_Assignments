#include<stdio.h>
#include<stdlib.h>
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

ll operations(ll *minHeap, ll *maxHeap, int minHeapSize, int maxHeapSize, ll sum, int k){
    ll s, l;
    while(k--){
        s = extractMin(minHeap, &minHeapSize);
        l = extractMax(maxHeap, &maxHeapSize);
        sum -= 2 * s;
        insertMinHeap(minHeap, &minHeapSize, l - s);
        insertMaxHeap(maxHeap, &maxHeapSize, l - s); 
    }
    return sum;
}

ll *copyArr(ll *a, int n){
    ll *arr = malloc(sizeof(ll) * n);
    for(int i = 0; i < n; ++i){
        arr[i] = a[i];
    } 
    return arr;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    ll minHeap[n], maxHeap[n], sum = 0;
    int minHeapSize = 0, maxHeapSize = 0;

    for(int i = 0; i < n; ++i){
        ll x;
        scanf("%lld", &x);
        sum += x;
        insertMinHeap(minHeap, &minHeapSize, x);
        insertMaxHeap(maxHeap, &maxHeapSize, x);
    }

    for(int i = 0; i < q; ++i){
        int k;
        scanf("%d", &k);
        ll *min = copyArr(minHeap, minHeapSize);
        ll *max = copyArr(maxHeap, maxHeapSize);

        printf("%lld\n", operations(min, max, minHeapSize, maxHeapSize, sum, k));
        free(min);
        free(max);
    }
}