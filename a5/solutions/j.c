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

ll **createAdjM(int n){
    ll **adjM = (ll **)malloc(sizeof(ll *) * n);
    for(int i = 0; i < n; ++i){
        adjM[i] = (ll *)calloc(n, sizeof(ll));
    }
    return adjM;
}

void dijkstra(ll **graph, int src, int n){

    // Necessary initializations
    int *pQueue = (int *)calloc(n, sizeof(int));
    int pSize = 0;
    int *isVisited = (int *)calloc(n, sizeof(int));
    ll *cost = (ll *)calloc(n, sizeof(ll));

    for(int i = 0; i < n; ++i){
        cost[i] = inf;
    }

    cost[src] = 0;
    insertMinHeap(pQueue, &pSize, src);

    while(pSize){
        int u = extractMin(pQueue, &pSize);
        isVisited[u] = 1;

        for(int v = 0; v < n; ++v){
            if(graph[u][v] && isVisited[v] == 0){
                cost[v] = min(cost[v], cost[u] + graph[u][v]);
                insertMinHeap(pQueue, &pSize, v);
            }
        }
    }


    for(int i = 0; i < n; ++i){
        printf("%lld ", cost[i]);
    }
}

int main(){

    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    ll **graph = createAdjM(n);

    for(int i = 0; i < m; ++i){
        int u, v;
        ll w;

        scanf("%d %d %lld", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    dijkstra(graph, s, n);
}