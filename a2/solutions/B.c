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
    struct Node *next;
}Node;

typedef struct Graph{
    int V, E;
    Node **adjList;
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
}

int BFS(Graph *G, int source){
    Queue *Q = createQueue(G->V);
    int *isVisited = (int *)calloc(G->V, sizeof(int));
    int reachability = 1;
    isVisited[source] = 1;
    enqueue(Q, source);

    while(!isQueueEmpty(Q)){
        int v = dequeue(Q);
        for(Node *T = G->adjList[v]; T != NULL; T = T->next){
            if(isVisited[T->vertex] == 0){
                isVisited[T->vertex] = 1;
                enqueue(Q, T->vertex);
                reachability++;
            }
        }
    }
    return reachability;
}

int main(){
    int V, E;
    scanf("%d %d", &V, &E);

    Graph *G = createGraph(V, E);
    for(int i = 0; i < E; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(G, u - 1, v - 1);
    }

    int max = 0;
    for(int i = 1; i <= G->V; ++i){
        int reachability = BFS(G, i - 1);
        max = (reachability > max)? reachability: max;
    }
    printf("%d", max);
}