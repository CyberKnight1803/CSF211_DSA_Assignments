// USING adjacency list O(Elog V)

#include<stdio.h>
#include<stdlib.h>

typedef struct HeapNode{
    int elmnt;
    int priority;
}HeapNode;

typedef struct Heap{
    int *pos;
    int heapSize;
    int cSize;
    HeapNode **arr;
}Heap;

HeapNode *createHeapNode(int elmnt, int priority){
    HeapNode *node = (HeapNode *)malloc(sizeof(HeapNode));
    node->elmnt = elmnt;
    node->priority = priority;
    return node;
}

Heap *createHeap(int size){
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->pos = (int *)malloc(sizeof(int) * size);
    h->heapSize = size;
    h->cSize = 0;
    h->arr = (HeapNode **)malloc(sizeof(HeapNode *) * size);

    return h;
}

void swapHeapNodes(HeapNode **a, HeapNode **b){
    HeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(Heap *h, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 1;
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
    HeapNode *leaf = h->arr[h->cSize - 1];
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
        h->pos[h->arr[(i - 1) / 2]->elmnt] = i;

        swapHeapNodes(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isPresent(Heap *h, int elmnt){
    return (h->pos[elmnt] < h->cSize) ? 1 : 0;
}

typedef struct Node_g{
    int vertex, weight;
    struct Node_g *next;
}Node_g;

typedef struct Graph{
    Node_g **adjList;
    int V, E;
}Graph;

Node_g *createNode_g(int v, int w){
    Node_g *node = (Node_g *)malloc(sizeof(Node_g));
    node->next = NULL;
    node->vertex = v;
    node->weight = w;
    return node;
}

Graph *createGraph(int V, int E){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;
    g->E = E;
    g->adjList = (Node_g **)malloc(sizeof(Node_g *) * V);

    for(int i = 0; i < V; ++i){
        g->adjList[i] = NULL;
    }
    return g;
}

void addEdge(Graph *g, int u, int v, int w){
    Node_g *node = createNode_g(v, w);
    node->next = g->adjList[u];
    g->adjList[u] = node;

    node =  createNode_g(u, w);
    node->next = g->adjList[v];
    g->adjList[v] = node;
}


int minCost(int key[], int V){
    int min = 0;
    for(int i = 0; i < V; ++i){
        if(key[i] != INT32_MAX){
            min += key[i];
        }
    }
    return min;
}

void primMST(Graph *g){
    int V = g->V;
    int par[V], key[V];

    Heap *h = createHeap(V);
    for(int v = 1; v < V; ++v){
        par[v] = -1;
        key[v] = INT32_MAX;
        h->arr[v] = createHeapNode(v, key[v]);
        h->pos[v] = v;
    }
    
    key[0] = 0;
    h->arr[0] = createHeapNode(0, key[0]);
    h->pos[0] = 0;
    h->cSize = V;

    while(h->cSize != 0){
        HeapNode *node = extractMin(h);
        int u = node->elmnt;
        
        for(Node_g *t = g->adjList[u]; t != NULL; t = t->next){
            if(isPresent(h, t->vertex) && t->weight < key[t->vertex]){
                key[t->vertex] = t->weight;
                par[t->vertex] = u;
                decreaseKey(h, t->vertex, key[t->vertex]); 
            }
        }
    }
    printf("%d", minCost(key, V));
}

int main(){
    int V, E;
    scanf("%d %d", &V, &E);
    Graph *g = createGraph(V, E);

    for(int i = 0; i < E; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(g, u, v, w);
    }
    primMST(g);
}