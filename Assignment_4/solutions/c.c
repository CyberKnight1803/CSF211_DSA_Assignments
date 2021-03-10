#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 13

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
    int *distance;
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

Graph *createGraph(int V){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->adjList = (Node **)malloc(sizeof(Node *) * V);
    G->distance = (int *)calloc(V, sizeof(int));
    G->V = V;
    G->E = 0;

    for(int i = 0; i < V; ++i){
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(Graph *G, int u, int v){
    Node *newNode = createNode(v);
    newNode->next = G->adjList[u];
    G->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = G->adjList[v];
    G->adjList[v] = newNode;
}

int BFS(Graph *G, int source, int final){
    Queue *Q = createQueue(G->V);
    int *isVisited = (int *)calloc(G->V, sizeof(int));
    G->distance[source] = 0;
    isVisited[source] = 1;
    enqueue(Q, source);

    while(!isQueueEmpty(Q)){
        int v = dequeue(Q);
        for(Node *T = G->adjList[v]; T != NULL; T = T->next){
            if(isVisited[T->vertex] == 0){
                G->distance[T->vertex] = G->distance[v] + 1;
                if(T->vertex == final)
                    return G->distance[final] - 1;
                isVisited[T->vertex] = 1;
                enqueue(Q, T->vertex);
            }
        }
    }
    return -1;
}

int isOrthographicNeighbour(char *s1, char *s2){      // Differ by one letter only
    if(strlen(s1) != strlen(s2))
        return 0;
    
    int changes = 0;
    for(int i = 0; i < strlen(s1); ++i){
        if(s1[i] != s2[i])
            changes++;
        if(changes > 1)
            return 0;
    }
    return 1;
}

int main(){
    int n; scanf("%d", &n);
    char Dictionary[n + 1][N];
    for(int i = 0; i < n + 1; ++i){
        scanf("%s%*c", Dictionary[i]);
    }

    Graph *D = createGraph(n + 1);
    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < n + 1; ++j){
            if(isOrthographicNeighbour(Dictionary[i], Dictionary[j])){
                addEdge(D, i, j);
            }
        }
    }
    
   printf("%d", BFS(D, 0, n));
}