#include<stdio.h>
#include<stdlib.h>

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

void DFS(Graph *G, int src){
    int vStack[G->V], top = -1;
    int *isVisited = (int *)calloc(G->V, sizeof(int));
    isVisited[src] = 1;
    vStack[++top] = src;

    while(top != -1){
        int u = vStack[top--];
        printf("%d ", u);
        for(Node *t = G->adjList[u]; t != NULL; t = t->next){
            if(isVisited[t->vertex] == 0){
                isVisited[t->vertex] = 1;
                vStack[++top] = t->vertex;
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
    DFS(g, src);
}