#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int *queue;
    int front;
    int rear;
    int size;
};

void createQueue(struct Queue *q, int size){
    q->queue = (int *)malloc(sizeof(int) * size);
    q->size = size;
    q->front = 0;
    q->rear = 0;
}

int isQueueEmpty(struct Queue *q){
    return (q->front == q->rear)? 1 : 0;
}

int dequeue(struct Queue *q){
    if(q->front == q->rear){
        return -1;
    }
    else{
        int data = q->queue[q->front];
        q->front++;
        return data;
    }
}

void enqueue(struct Queue *q, int data){
    if(q->rear == q->size){
        return;
    }
    else{
        q->queue[q->rear] = data;
        q->rear++;
    }
}

int bfs(int V, int **adjM, int source, struct Queue *q, char *colorScheme){
    int *isVisited = (int *)malloc(sizeof(int) * V);
    enqueue(q, source);
    isVisited[source] = 1; 
    colorScheme[source] = 'R';

    while(!isQueueEmpty(q)){
        int v = dequeue(q);

        for(int i = 0; i < V; ++i){
            if(adjM[v][i] == 1 && isVisited[i] == 0){
                enqueue(q, i);
                isVisited[i] = 1;
                colorScheme[i] = (colorScheme[v] == 'R')? 'B': 'R';
            }
            else if(adjM[v][i] == 1 && isVisited[i] == 1){
                if(colorScheme[v] == colorScheme[i]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int twoColoring(int V, int **adjM, char *colorScheme){

    colorScheme[0] = 'R';
    for(int i = 1; i < V; ++i){
        colorScheme[i] = 'N';
    }

    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            if(adjM[i][j] == 1 && colorScheme[j] == 'N'){
                colorScheme[j] = (colorScheme[i] == 'R')? 'B': 'R';
            }
            else if(colorScheme[j] == colorScheme[i]){
                return 0;
            }
        }
    }
    return 1;
}

void generateAdjM(int E, int **adjM){
    int u, v;
    for(int i = 0; i < E; ++i){
        scanf("%d %d", &u, &v);
        adjM[u][v] = 1;
        adjM[v][u] = 1;
    }
}

int main(){
    int V, E;
    scanf("%d %d", &V, &E);
    int **adjM = (int **)malloc(sizeof(int *) * V);  
    for(int i = 0; i < V; ++i){
        adjM[i] = malloc(sizeof(int) * V);
    }
    generateAdjM(E, adjM);

    struct Queue *vQueue = (struct Queue *)malloc(sizeof(struct Queue));
    createQueue(vQueue, V);

    char *colorScheme = (char *)malloc(sizeof(char) * (V+1));
    colorScheme[V] = '\0';

    if(twoColoring(V, adjM, colorScheme)){
        for(int i = 0; i < V; ++i){
            printf("%c", colorScheme[i]);
        }
    }
    else{
        printf("NEED MORE COLOURS");
    }
}
