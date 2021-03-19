#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define ll long long
const ll inf = INT64_MAX;

ll min(ll x, ll y){
    return (x < y)? x : y;
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(int a[], int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if(l < n && a[l] < a[i])
        smallest = i;
    
    if(r < n && a[r] < a[smallest])
        smallest = r;
    
    if(smallest != i){
        swap(&a[i], &a[smallest]);
        minHeapify(a, n, smallest);
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

int extractMin(int a[], int *n){
    if(*n <= 0)
        return -1;
    
    int key = a[0];
    a[0] = a[(*n) - 1];
    --(*n);
    minHeapify(a, *n, 0);
    return key;
}


typedef struct Node{
    int vertex;
    struct Node *next;
    ll weight;
}Node;

typedef struct Graph{
    int V, E;
    Node **adjList;
    ll *cost;
}Graph;

Node *createNode(int v, ll w){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    newNode->weight = w;
    return newNode;
}

Graph *createGraph(int V, int E){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->adjList = (Node **)malloc(sizeof(Node *) * V);
    G->V = V;
    G->E = E;
    G->cost = (ll *)malloc(sizeof(ll) * V);
    for(int i = 0; i < V; ++i){
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(Graph *G, int u, int v, ll w){
    Node *newNode = createNode(v, w);
    newNode->next = G->adjList[u];
    G->adjList[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = G->adjList[v];
    G->adjList[v] = newNode;
}

void dijkstra(Graph *G, int src){
    int *pQueue = (int *)calloc(G->V, sizeof(int));
    int pSize = 0;

    int *isVisited = (int *)calloc(G->V, sizeof(int));
    for(int i = 0; i < G->V; ++i){
        G->cost[i] = inf;
    }
    G->cost[src] = 0;
    insertMinHeap(pQueue, &pSize, src);

    while(pSize){
        int u = extractMin(pQueue, &pSize);
        isVisited[u] = 1;

        for(Node *t = G->adjList[u]; t != NULL; t = t->next){
            if(isVisited[t->vertex] == 0){
                G->cost[t->vertex] = min(G->cost[t->vertex], G->cost[u] + t->weight);
                insertMinHeap(pQueue, &pSize, t->vertex);
            }
        }
    }

    for(int i = 0; i < G->V; ++i){
        printf("%lld ", G->cost[i]);
    }
}

int main(){
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    Graph *G = createGraph(n, m);
    for(int i = 0; i < G->E; ++i){
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        addEdge(G, u, v, w);
    }
    dijkstra(G, s);
}