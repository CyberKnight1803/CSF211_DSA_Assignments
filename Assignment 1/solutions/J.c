#include<stdio.h>
#include<stdlib.h>

struct queue{
    int *arr;
    int size;
    int F;
    int R;
};

struct queue* createQueue(int size){
    struct queue* Q = (struct queue *)malloc(sizeof(struct queue));
    Q->size = size;
    Q->F = 0;
    Q->R = size - 1;
    Q->arr = (int *)malloc(sizeof(int) * size);
    return Q;
}





int main(){
    int V, E;
    scanf("%d %d", &V, &E);
    int *u = (int *)malloc(sizeof(int) * E);
    int *v = (int *)malloc(sizeof(int) * E);

    for(int i = 0; i < E; ++i){
        scanf("%d %d", &u[i], &v[i]);
    }

}
