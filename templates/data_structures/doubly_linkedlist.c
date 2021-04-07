#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = data;

    return node;
}

void insert(Node **list, int data){
    Node *node = createNode(data);
    if(*list == NULL){
        node->next = *list;
        *list = node;
    }
    else{
        node->next = *list;
        (*list)->prev = node;
        *list = node;
    }
}

void print(Node *list){
    Node *t = list;
    if(t == NULL)
        return;
        
    while(t->next != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("%d\n", t->data);
    while(t != NULL){
        printf("%d ", t->data);
        t = t->prev;
    }
    printf("\n");
}

void printList(Node *list){
    Node *t = list;
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

Node *search(Node *list, int key){
    Node *t = list;
    while(t != NULL && t->data != key)
        t = t->next;
    return t;
}

void delete(Node **list, int key){
    Node *d = search(*list, key);
    if(*list == NULL || d == NULL)
        return;
    
    if(*list == d)
        *list = d->next;
    
    if(d->next != NULL)
        d->next->prev = d->prev;
    
    if(d->prev != NULL)
        d->prev->next = d->next;
    free(d);
}

int main(){
    int n;
    scanf("%d", &n);

    Node *list = NULL;
    for(int i = 0; i < n; ++i){
        int data;
        scanf("%d", &data);
        insert(&list, data);
    }
    print(list);
    delete(&list, 1);
    delete(&list, 2);
    delete(&list, 3);
    delete(&list, 4);
    print(list);
    delete(&list, 5);
    print(list);
}

