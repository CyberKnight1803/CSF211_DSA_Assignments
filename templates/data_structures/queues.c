#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    int size, r;
    Node *front;
    Node *rear;
}Queue;

Node *createNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

Queue *initQueue(int size){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->size = size;
    Q->front = NULL;
    Q->rear = NULL;

    return Q;
}

int isQueueEmpty(Queue *Q){
    if(Q->rear = NULL)
        return 1;
    return 0;
}

int isQueueFull(Queue *Q){
    if(Q->r == Q->size)
        return 1;
    return 0;
}

void enqueue(Queue *Q, int data){
    if(isQueueFull(Q))
        return;

    Node *node = createNode(data);
    Q->r++;
    if(isQueueEmpty(Q)){
        Q->front = node;
        Q->rear = node;
    }
    else{
        Q->rear->next = node;
        Q->rear = node;
    }
}

int dequeue(Queue *Q){
    if(isQueueEmpty(Q))
        return -1;
    
    Node *t = Q->front;
    Q->r--;
    int data = Q->front->data;
    Q->front = Q->front->next;
    if(Q->front == NULL)
        Q->rear = NULL;

    free(t);
    return data;
}

void printQueue(Queue *Q){
    Node *t = Q->front;
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
}

int main(){
    Queue *Q = createQueue(3);
}
