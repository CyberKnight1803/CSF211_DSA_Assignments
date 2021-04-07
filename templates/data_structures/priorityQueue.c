#include<stdio.h>
#include<stdlib.h>

typedef struct HeapNode{
    int elmnt;
    int priority;   // priority
}HeapNode;

typedef struct Heap{
    int *pos;
    int heapSize;
    int cSize;
    HeapNode **arr;
}Heap;

int parent(int i){
    return (i - 1) / 2;
}

int leftChild(int i){
    return 2 * i + 1;
}

int rightChild(int i){
    return 2 * i + 2;
}

HeapNode *createHeapNode(int elmnt, int priority){
    HeapNode *node = (HeapNode *)malloc(sizeof(HeapNode));
    node->elmnt = elmnt;
    node->priority = priority;
    
    return node;
}

Heap *initHeap(int size){
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->pos = (int *)malloc(sizeof(int) * size);
    h->heapSize = size;
    h->cSize = 0;
    h->arr = (HeapNode *)malloc(sizeof(HeapNode));

    return h;
}

void swapHeapNodes(HeapNode **a, HeapNode **b){
    HeapNode *t = *a;
    *a = *b;
    *b = t;
}

// MIN HEAP OPERATIONS

void minHeapify(Heap *h, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if(l < h->cSize && h->arr[l]->priority < h->arr[i]->priority)
        smallest = l;
    
    if(r < h->cSize && h->arr[r]->priority < h->arr[smallest]->priority)
        smallest = r;
    
    if(smallest != i){
        h->pos[h->arr[smallest]->elmnt] = i;
        h->pos[h->arr[i]->elmnt] = smallest;
        swapHeapNodes(&h->arr[smallest], &h->arr[i]);
        minHeapify(h, smallest);
    }
}

HeapNode *extractMin(Heap *h){
    if(h->cSize == 0)
        return NULL;
    
    HeapNode *root = h->arr[0];
    HeapNode *leaf = h->arr[h->cSize- 1];
    h->arr[0] = leaf;

    h->pos[root->elmnt] = h->cSize - 1;
    h->pos[leaf->elmnt] = 0;

    h->cSize--;
    minHeapify(h, 0);
    return root;
}

void decreaseKey(Heap *h, int elmnt, int priority){
    int i = h->pos[elmnt];
    h->arr[i]->priority = priority;

    while(h->arr[i]->priority < h->arr[(i - 1) / 2]->priority){
        h->pos[h->arr[i]->elmnt] = (i - 1) / 2;
        h->pos[h->arr[parent(i)]->elmnt] = i;

        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// MAX HEAP OPERATIONS

void maxHeapify(Heap *h, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if(l < h->cSize && h->arr[l]->priority > h->arr[i]->priority)
        largest = i;
    
    if(r < h->cSize && h->arr[r]->priority > h->arr[largest]->priority)
        largest = r;
    
    if(largest != i){
        h->pos[h->arr[largest]->elmnt] = i;
        h->pos[h->arr[i]->elmnt] = largest;
        swapHeapNodes(&h->arr[largest], &h->arr[i]);
        maxHeapify(h, largest);
    }
}

HeapNode *extractMax(Heap *h){
    if(h->cSize == 0)
        return NULL;
    
    HeapNode *root = h->arr[0];
    HeapNode *leaf = h->arr[h->cSize- 1];
    h->arr[0] = leaf;

    h->pos[root->elmnt] = h->cSize - 1;
    h->pos[leaf->elmnt] = 0;

    h->cSize--;
    maxHeapify(h, 0);
    return root;
}