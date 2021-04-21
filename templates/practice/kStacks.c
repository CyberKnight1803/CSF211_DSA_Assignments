// kStacks using one array

#include<stdio.h>

int free = 0;

int isFull(){
    return (free == -1)?1 : 0;
}

int isEmpty(int top[], int stack){
    return (top[stack] == -1) ? 1 : 0;
}

void push(int kStacks[], int top[], int next[], int stack, int data){
    if(isFull()){
        printf("FULL!");
        return;
    }
    int i = free;
    free = next[i];
    next[i] = top[stack];
    top[stack] = i;
    kStacks[i] = data; 
}

int pop(int kStacks[], int top[], int next[], int stack){
    if(isEmpty(top, stack)){
        return -1;
    }
    int i = top[stack];
    top[stack] = next[i];
    next[i] = free;
    free = i;
    return kStacks[i];
}

int main(){
    int k, n;
    scanf("%d %d",&k, &n);
    int kStacks[n], top[k], next[n];
    for(int i = 0; i < k; ++i){
        top[i] = -1;
    }
    for(int i = 0; i < n - 1; ++i){
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    
}