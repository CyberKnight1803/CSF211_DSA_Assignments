#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int vertex;
    struct Node *next;
}Node;

typedef struct Graph{
    int V, E;
    Node **adjList;
    int *hops;
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
    G->hops = (int *)calloc(V, sizeof(int));
    G->V = V;
    G->E = E;

    for(int i = 0; i < V; ++i){
        G->hops[i] = -1;
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

int main(){
    int V, E;
    scanf("%d %d", &V, &E);
}