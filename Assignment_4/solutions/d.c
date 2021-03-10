#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *queue;
    int front;
    int rear;
    int size;
}Queue;

typedef struct Node{
    int vertex;
    float weight;
    struct Node *next;
}Node;

typedef struct Graph{
    int V, E;
    Node **adjList;
    float *probabilities;
    int *articleList;
}Graph;

Queue *createQueue(int size){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->queue = (int *)malloc(sizeof(int) * size);
    Q->size = size;
    Q->front = 0;
    Q->rear = 0;
    return Q;
}   

int isQueueEmpty(Queue *Q){
    return (Q->front == Q->rear)? 1: 0;
}

void enqueue(Queue *Q, int data){
    if(Q->rear == Q->size){
        return;
    }
    else{
        Q->queue[Q->rear] = data;
        Q->rear++;
    }
}

int dequeue(Queue *Q){
    if(Q->front == Q->rear){
        return -1;
    }
    else{
        int data = Q->queue[Q->front];
        Q->front++;
        if(Q->front == Q->rear){
            Q->front = 0;
            Q->rear = 0;
        }
        return data;
    }
}

Node *createNode(int v, float p){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = p;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int V, int E){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->adjList = (Node **)malloc(sizeof(Node *) * V);
    G->probabilities = (float *)calloc(V, sizeof(float));
    G->articleList = (int *)calloc(V, sizeof(int));
    G->V = V;
    G->E = E;

    for(int i = 0; i < V; ++i){
        G->articleList[i] = i;
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(Graph *G, int u, int v, float p){
    Node *newNode = createNode(v, p);
    newNode->next = G->adjList[u];
    G->adjList[u] = newNode;
}

void BFS(Graph *G, int source){
    Queue *Q = createQueue(G->V);
    int *isVisited = (int *)calloc(G->V, sizeof(int));
    isVisited[source] = 1;
    enqueue(Q, source);

    while(!isQueueEmpty(Q)){
        int v = dequeue(Q);
        for(Node *T = G->adjList[v]; T != NULL; T = T->next){
            if(isVisited[T->vertex] == 0){     
                isVisited[T->vertex] = 1;
                G->probabilities[T->vertex] = T->weight * G->probabilities[v];
                enqueue(Q, T->vertex);
            }
        }
    }
}

void computeQ(Graph *G, float *Q){
    for(int i = 0; i < G->V; ++i){
        for(Node *T = G->adjList[i]; T != NULL; T = T->next){
            Q[i] += T->weight;
        }
        Q[i] = G->probabilities[i] * (1 - Q[i]);
    }
}

int custom_cmp(int a, int b, float *Q){
    float diff = Q[a] - Q[b];
    if(diff < 0) 
        return 1;
    if(diff >= 0)
        return 0;
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int L, int H, float *Q){
    int pivot = arr[H];     // last element as pivot
    int pIdx = L - 1;

    for(int i = L; i <= H - 1; ++i){
       if(custom_cmp(arr[i], pivot, Q)){
           ++pIdx;
           swap(&arr[pIdx], &arr[i]);
       } 
    }
    swap(&arr[pIdx + 1], &arr[H]);
    return pIdx + 1;
}

void qSort(int *arr, int L, int H, float *Q){
    if(L < H){
        int pIdx = partition(arr, L, H, Q);
        qSort(arr, L, pIdx - 1, Q);
        qSort(arr, pIdx + 1, H, Q);
    }
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->V; v++) {
        Node* temp = graph->adjList[v];
        printf("\n Vertex %d: ", v);
        while (temp) {
            printf("(%d, %f) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int N, E, S;
    scanf("%d %d %d", &N, &E, &S);

    Graph *wiki = createGraph(N, E);

    wiki->probabilities[S] = 1.0;
    for(int i = 0; i < wiki->E; ++i){
        int u, v;
        float p;
        scanf("%d %d %f", &u, &v, &p);
        addEdge(wiki, u, v, p);
        wiki->probabilities[v] = p;
    }

    float *Q = (float *)calloc(N, sizeof(float));
    BFS(wiki, S);
    computeQ(wiki, Q);
    qSort(wiki->articleList, 0, N - 1, Q);
    
    for(int i = N - 1; i >= 0; --i){
        printf("%d ", wiki->articleList[i]);
    }
}