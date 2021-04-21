#include<stdio.h>
#include<stdlib.h>

typedef struct Tuple{
    int i, j;
}Tuple;

typedef struct HeapNode{
    Tuple elmnt;
    int priority;   // priority
}HeapNode;

typedef struct Heap{
    int heapSize;
    int cSize;
    HeapNode **arr;
}Heap;

HeapNode *createHeapNode(Tuple elmnt, int priority){
    HeapNode *node = (HeapNode *)malloc(sizeof(HeapNode));
    node->elmnt = elmnt;
    node->priority = priority;
    
    return node;
}

Heap *initHeap(int size){
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->heapSize = size;
    h->cSize = 0;
    h->arr = (HeapNode **)malloc(sizeof(HeapNode*) * size);


    return h;
}

void swapHeapNodes(HeapNode **a, HeapNode **b){
    HeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(Heap *h, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if(l < h->cSize && h->arr[l]->priority < h->arr[i]->priority)
        smallest = l;
    
    if(r < h->cSize && h->arr[r]->priority < h->arr[smallest]->priority)
        smallest = r;
    
    if(smallest != i){
        swapHeapNodes(&h->arr[smallest], &h->arr[i]);
        minHeapify(h, smallest);
    }
}

void buildMinHeap(Heap *h){
    for(int i = (h->heapSize / 2) - 1; i >= 0; --i)
        minHeapify(h, i);
}

void insert(Heap *h, Tuple elmnt, int priority){
    HeapNode *node = createHeapNode(elmnt, priority);
    if(h->cSize == 0){
        h->arr[h->cSize++] = node;
        return;
    }
    h->arr[h->cSize++] = node;
    for(int i = ((h->cSize / 2) - 1); i >= 0; --i)
        minHeapify(h, i);
}

HeapNode *extractMin(Heap *h){
    if(h->cSize == 0)
        return NULL;
    
    HeapNode *root = h->arr[0];
    HeapNode *leaf = h->arr[h->cSize- 1];
    h->arr[0] = leaf;
    h->cSize--;

    minHeapify(h, 0);
    return root;
}


void merge(int **a, int n[], int k, int sum){
    Heap *pq = initHeap(k);
    int stack[sum], top = -1;
    for(int i = 0; i < k; ++i){
        Tuple x = (Tuple){.i = i, .j = 0};
        HeapNode *node = createHeapNode(x, a[i][0]);
        pq->arr[i] = node;
    }
    pq->cSize = k;
    buildMinHeap(pq);

    while(pq->cSize != 0){
        HeapNode *node = extractMin(pq);
        int i = node->elmnt.i;
        int j = node->elmnt.j;

        stack[++top] = node->priority;
        if(j + 1 < n[i]){
            Tuple t = (Tuple){.i = i, .j = j + 1};
            insert(pq, t, a[i][j + 1]);
        }
    }

    for(int i = 0; i < sum; ++i){
        printf("%d ", stack[i]);
    }
}

int **createKArrays(int n[], int k){
    int **a = (int **)malloc(sizeof(int *) * k);
    for(int i = 0; i < k; ++i){
        a[i] = (int *)malloc(sizeof(int) * n[i]);
    }
    return a;
}

int main(){
    int k;
    scanf("%d", &k);
    int n[k], sum  = 0;
    for(int i = 0; i < k; ++i){
        scanf("%d", &n[i]);
        sum += n[i];
    }
    int **a = createKArrays(n, k);
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n[i]; ++j){
            scanf("%d", &a[i][j]);
        }
    }
    
    merge(a, n, k, sum);
}