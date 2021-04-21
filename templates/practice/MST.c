#include<stdio.h>
#include<stdlib.h>

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

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    Graph *g = createGraph(v, e);
    for(int i = 0; i < e; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }
}