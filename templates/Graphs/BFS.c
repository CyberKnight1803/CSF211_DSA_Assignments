#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *queue;
    int front;
    int rear;
    int size;
}Queue;

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

typedef struct Node{
    int vertex;
    struct Node *next;
}Node;

typedef struct Graph{
    int V, E;
    Node **adjList;
}Graph;

Node *createNode(int v){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int V, int E){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->adjList = (Node **)malloc(sizeof(Node *) * V);
    G->V = V;
    G->E = E;

    for(int i = 0; i < V; ++i){
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(Graph *G, int u, int v){
    Node *newNode = createNode(v);
    newNode->next = G->adjList[u];
    G->adjList[u] = newNode;

    // Undirected graphs
    newNode = createNode(u);
    newNode->next = G->adjList[v];
    G->adjList[v] = newNode;
}

void BFS(Graph *G, int src){
    Queue *Q = createQueue(G->V);
    int *isVisited = (int *)calloc(G->V, sizeof(int));
    isVisited[src] = 1;
    enqueue(Q, src);
    printf("%d ", src);
    while(!isQueueEmpty(Q)){
        int v = dequeue(Q);
        printf("%d ", v);
        for(Node *T = G->adjList[v]; T != NULL; T = T->next){
            if(isVisited[T->vertex] == 0){
                isVisited[T->vertex] = 1;
                enqueue(Q, T->vertex);
            }
        }
    }
}

int main(){
    int v, e, src;
    scanf("%d %d %d", &v, &e, &src);
    Graph *g = createGraph(v, e);
    for(int i = 0; i < g->E; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }
    BFS(g, src);
}