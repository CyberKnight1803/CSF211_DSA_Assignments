#include<stdio.h>
#include<stdlib.h>
#define N 26
int idx = 0;

typedef struct Node{
    int v;
    struct Node *next;
}Node;

typedef struct Graph{
    int V, E;
    Node **adjList;
    int *visited;
}Graph;

Node *createNode(int v){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = NULL;

    return newNode;
}

Graph *createGraph(int V, int E){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->V = V;
    G->E = E;
    G->visited = (int *)calloc(N, sizeof(int));
    G->adjList = (Node **)malloc(sizeof(Node *) * V);
    for(int i = 0; i < V; ++i){
        G->adjList[i] = NULL;
    }

    return G;
}

void addEdge(Graph *G, int u, int v){
    // Directed graph
    Node *newNode = createNode(v);
    newNode->next = G->adjList[u];
    G->adjList[u] = newNode;
}

int DFS(Graph *G, int source, int *charStack){
    G->visited[source] = 1;
    for(Node *T = G->adjList[source]; T != NULL; T = T->next){
        if(G->visited[T->v] == 0){
            if(DFS(G, T->v, charStack))
                return 1;
        }
        else if(G->visited[T->v] == 1)
            return 1;
    }
    G->visited[source] = -1;
    charStack[idx] = source;           // Adding to stack
    idx++;

    return 0;
}

void topologicalSort(Graph *G, int *charNodes, int *languageOrder){
    for(int i = 0; i < N; ++i){
        if(charNodes[i] && !G->visited[i]){
            if(DFS(G, i, languageOrder)){
                printf("ALIENS BE CRAZY");
                return;
            }
        }
    }

    for(int i = idx - 1; i >= 0; --i){
        printf("%c", (char)(languageOrder[i] + 'A'));
    }
}

int main(){
    int E; scanf("%d%*c", &E);
    int charNodes[N] = {0}, languageOrder[N] = {0};
    Graph *G = createGraph(N, E);

    for(int i = 0; i < E; ++i){
        char u, v;
        scanf("%c %c%*c", &u, &v);
        addEdge(G, (int)u - 'A', (int)v - 'A');
        charNodes[(int)u - 'A'] = 1;
        charNodes[(int)v - 'A'] = 1;
    }
    topologicalSort(G, charNodes, languageOrder);
}

