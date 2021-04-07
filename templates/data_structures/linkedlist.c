#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *createNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

// We prepend because it takes O(1) time, appending takes O(n)
void insert(Node **list, int data){
    Node *node = createNode(data);
    node->next = *list;
    *list = node;
}

void printList(Node *list){
    Node *t = list;
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void append(Node *list, int data);
Node *search(Node *list, int key);
void reverse(Node **list);
void delete(Node **list, int key);

int main(){
    int n;
    scanf("%d", &n);
    Node *list = NULL;
    for(int i = 0; i < n; ++i){
        int data;
        scanf("%d", &data);
        insert(&list, data);
    }
    printList(list);
}

void append(Node *list, int data){
    Node *t = list;
    Node *node = createNode(data);
    while(t->next != NULL)
        t = t->next;
    t->next = node;
}

Node *search(Node *list, int key){
    Node *t = list;
    while(t->data != key && t != NULL)
        t = t->next;
    return t;
}

void reverse(Node **list){
    Node *pNode = NULL, *cNode = *list;
    Node *next = NULL;

    while(cNode != NULL){
        next = cNode->next;
        cNode->next = pNode;
        pNode = cNode;
        cNode = next;
    }
    *list = pNode;
}

void delete(Node **list, int key){
    Node *p = *list;
    if(p->data == key){
        *list = p->next;
        free(p);
        return;
    }
    for(Node *t = p->next; t != NULL; t = t->next){
        if(t->data == key){
            p->next = t->next;
            free(t);
            return;
        }
        p = t;
    }
}
