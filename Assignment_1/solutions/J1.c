#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int vertex;
    struct node *next;
}node;

typedef struct graph{
    int V;
    node **adjL;
}graph;

node *createNode(int v){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

graph *generateGraph(int V){
    graph *newG = (graph *)malloc(sizeof(graph));
    newG->V = V;
    newG->adjL = (node **)malloc(sizeof(node *) * V);
    for(int i = 0; i < V; ++i){
        newG->adjL[i] = NULL;
    }
    return newG;
}

void addEdge(graph *g, int u, int v){
    node *newNode = createNode(v);
    newNode->next = g->adjL[u];
    g->adjL[u] = newNode;

    newNode = createNode(u);
    newNode->next = g->adjL[v];
    g->adjL[v] = newNode;
}

void twoColoring(graph *g, int *colorScheme){
    colorScheme[0] = 0;
    for(int i = 1; i < g->V; ++i){
        colorScheme[i] = -1;
    }
    node *tNode = NULL;
    for(int i = 0; i < g->V; ++i){
        for(tNode = g->adjL[i]; tNode != NULL; tNode = tNode->next){
            if(colorScheme[tNode->vertex] == 'N'){
                colorScheme[tNode->vertex] = !colorScheme[i];
            }
            else if(colorScheme[tNode->vertex] == colorScheme[i]){
                printf("NEED MORE COLOURS");
                return;
            }
        }
    }
    for(int i = 0; i < g->V; ++i){
        printf("%c", colorScheme[i]? 'R': 'B');
    }
}

int main(){
    int V, E;
    scanf("%d %d", &V, &E);

    int *colorScheme = (int *)malloc(sizeof(int) * (V + 1));
    graph *G = generateGraph(V);
    for(int i = 0; i < E; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(G, u, v);
    }
    twoColoring(G, colorScheme);
}