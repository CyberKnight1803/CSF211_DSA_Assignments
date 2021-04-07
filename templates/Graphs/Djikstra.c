#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
    return (a < b) ? a : b;
}

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
        h->pos[h->arr[(i - 1) / 2]->elmnt] = i;

        swapHeapNodes(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isNodeinHeap(Heap *h, int elmnt){
    if(h->pos[elmnt] < h->cSize)
        return 1;
    return 0;
}

typedef struct GraphNode{
    int vertex;
    int weight;
    struct GraphNode *next;
}GraphNode;

typedef struct Graph{
    int V, E;
    GraphNode **adjList;
}Graph;

GraphNode *createGraphNode(int v, int w){
    GraphNode *newGraphNode = (GraphNode *)malloc(sizeof(GraphNode));
    newGraphNode->vertex = v;
    newGraphNode->weight = w;
    newGraphNode->next = NULL;
    return newGraphNode;
}

Graph *initGraph(int V, int E){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->adjList = (GraphNode **)malloc(sizeof(GraphNode *) * V);
    G->V = V;
    G->E = E;

    for(int i = 0; i < V; ++i){
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(Graph *G, int u, int v, int w){
    GraphNode *newGraphNode = createGraphNode(v, w);
    newGraphNode->next = G->adjList[u];
    G->adjList[u] = newGraphNode;

    // Undirected graphs
    newGraphNode = createGraphNode(u, w);
    newGraphNode->next = G->adjList[v];
    G->adjList[v] = newGraphNode;
}

void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void Djikstra(Graph *G, int src){
    Heap *pq = initHeap(G->V);
    int cost[G->V];

    for(int i = 0; i < G->V; ++i){
        cost[i] = INT32_MAX;
        pq->arr[i] = createHeapNode(i, cost[i]);
        pq->pos[i] = i;
    }
    pq->cSize = G->V;
    pq->arr[src] = createHeapNode(src, cost[src]);
    pq->pos[src] = src;
    cost[src] = 0;
    decreaseKey(pq, src, cost[src]);

    while(pq->cSize != 0){
        HeapNode *node = extractMin(pq);
        int u = node->elmnt;

        for(GraphNode *t = G->adjList[u]; t != NULL; t = t->next){
            if(isNodeinHeap(pq, t->vertex) && cost[u] != INT32_MAX){
                if(t->weight + cost[u] < cost[t->vertex]){
                    cost[t->vertex] = t->weight + cost[u];
                    decreaseKey(pq, t->vertex, cost[t->vertex]);
                }
            }
        }
    }
    printArr(cost, G->V);
}

int main(){
    int V, E;
    scanf("%d %d", &V, &E);
    Graph *G = initGraph(V, E);

    for(int i = 0; i < G->E; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(G, u, v, w);
    }
    Djikstra(G, 0);
}