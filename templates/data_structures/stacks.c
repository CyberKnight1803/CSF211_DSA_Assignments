#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Stack{
    int size, t;
    Node *top;
}Stack;

Node *createNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

Stack *initStack(int size){
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->size = size;
    S->top = NULL;
    S->t = 0;

    return S;
}

int isStackEmpty(Stack *S){
    if(S->top = NULL)
        return 1;
    return 0;
}

int isStackFull(Stack *S){
    if(S->t = S->size)
        return 1;
    return 0;
}

void push(Stack *S, int data){
    if(isStackFull(S))
        return;
    
    Node *node = createNode(data);
    S->t++;
    node->next = S->top;
    S->top = node;
}

int pop(Stack *S){
    if(isStackEmpty(S))
        return -1;
    
    int data = S->top->data;
    Node *t = S->top;
    S->top = S->top->next;
    free(t);
    S->t--;
    return data;
}

void printStack(Stack *S){
    Node *t = S->top;
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
}

int main(){
    
}