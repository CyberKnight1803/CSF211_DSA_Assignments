#include<stdio.h>
#include<stdlib.h>

int **createAdjM(int V, int E){
    int **adjM = (int **)malloc(sizeof(int *) * V);
    for(int i = 0; i < V; ++i){
        adjM[i] = (int *)malloc(sizeof(int) * V);
    }
    for(int i = 0; i < E; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        adjM[u][v] = 1;
        adjM[v][u] = 1; // In case of undirected graph
    }
}

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    int **adjM = createAdjM(v, e);
}