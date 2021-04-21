// O(n + klog n). Sorting method will take O(nlog n)


#include<stdio.h>
#include<stdlib.h>

typedef struct Point{
    int x, y;
}Point;

typedef struct HeapNode{
    Point elmnt;
    int priority;   // priority
}HeapNode;

typedef struct Heap{
    int heapSize;
    int cSize;
    HeapNode **arr;
}Heap;

HeapNode *createHeapNode(Point elmnt, int priority){
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

void insert(Heap *h, Point elmnt, int priority){
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

int EuclideanDistance(Point P){
    return P.x * P.x + P.y * P.y;
}

void kClosest(Point points[], int n, int k){
    Heap *pq = initHeap(n);
    for(int i = 0; i < n; ++i){
        pq->arr[i] = createHeapNode(points[i], EuclideanDistance(points[i]));
    }
    pq->cSize = n;
    buildMinHeap(pq);

    for(int i = 0; i < k; ++i){
        Point p = extractMin(pq)->elmnt;
        printf("%d %d\n", p.x, p.y);
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    Point points[n];
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    kClosest(points, n, k);
}