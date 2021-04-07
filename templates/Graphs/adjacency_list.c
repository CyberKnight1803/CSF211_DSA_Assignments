#include<stdio.h>
#include<stdlib.h>

typedef struct GraphNode{
    int vertex;
    struct GraphNode *next;
}GraphNode;

typedef struct Graph{
    int V, E;
    GraphNode **adjList;
}Graph;

GraphNode *createGraphNode(int v){
    GraphNode *newGraphNode = (GraphNode *)malloc(sizeof(GraphNode));
    newGraphNode->vertex = v;
    newGraphNode->next = NULL;
    return newGraphNode;
}

Graph *initGraph(int V, int E){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->adjList = (GraphNode **)malloc(sizeof(GraphNode *) * V);
    G->V = V;
    G->E = E;

    for(int i = 0; i < V; ++i){
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(Graph *G, int u, int v){
    GraphNode *newGraphNode = createGraphNode(v);
    newGraphNode->next = G->adjList[u];
    G->adjList[u] = newGraphNode;

    // Undirected graphs
    newGraphNode = createGraphNode(u);
    newGraphNode->next = G->adjList[v];
    G->adjList[v] = newGraphNode;
}

int main(){
    int V, E;
    scanf("%d %d", &V, &E);
}