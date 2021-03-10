#include<stdio.h>
#include<stdlib.h>

//

int main(){
    int V;
    scanf("%d", &V);

    int E = (V * (V - 1)) / 2;

    int e[2];
    int degree = V - 1;

    int *inDegree = (int *)calloc(V, sizeof(int));
    int *outDegree = (int *)calloc(V, sizeof(int));

    for(int i = 1; i < E; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        outDegree[u - 1] += 1;
        inDegree[v - 1] += 1; 
    }

    for(int k = 0, i = 0; i < V; ++i){
        if(inDegree[i] + outDegree[i] != V - 1){
            e[k] = i;
            k++;
        }
    }

    if(outDegree[e[0]] >= outDegree[e[1]]){
        printf("%d %d", e[0] + 1, e[1] + 1);
    }
    else{
        printf("%d %d", e[1] + 1, e[0] + 1);
    }
}