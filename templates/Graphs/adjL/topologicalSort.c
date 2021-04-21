#include<stdio.h>
#include<stdlib.h>


typedef struct Node_g{
    int vertex;
    struct Node_g *next;
}Node_g;

typedef struct Graph{
    int V, E;
    Node_g **adjList;
}Graph;

Node_g *createNode(int v){
    Node_g *node = (Node_g *)malloc(sizeof(Node_g));
    node->next = NULL;
    node->vertex = v;

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

void addEdge(Graph *g, int u, int v){
    Node_g *node = createNode(v);
    node->next = g->adjList[u];
    g->adjList[u] = node;
}

void topologicalSort(Graph *g, int src, int isVisited[], int vStack[], int *top){
    isVisited[src] = 1;
    for(Node_g *t = g->adjList[src]; t != NULL; t = t->next){
        if(!isVisited[t->vertex]){
            topologicalSort(g, t->vertex, isVisited, vStack, top);
        }
    }
    vStack[++(*top)] = src;
}

void TS(Graph *g){
    int vStack[g->V], top = -1;
    int *isVisited = (int *)calloc(g->V, sizeof(int));

    for(int i = 0; i < g->V; ++i){
        if(!isVisited[i])
            topologicalSort(g, i, isVisited, vStack, &top);
    }
    while(top != -1){
        printf("%d ", vStack[top--]);
    }
}

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    Graph *g = createGraph(v, e);
    for(int i = 0; i < e; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }
    TS(g);
}