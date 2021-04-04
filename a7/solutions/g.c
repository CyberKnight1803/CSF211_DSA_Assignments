#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void printList(Node *list){
    Node *t = list;
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
}

Node *reverseList(Node **list){
    Node *pNode = NULL, *cNode = *list;
    Node *tNode = NULL;

    while(cNode != NULL){
        tNode = cNode->next;
        cNode->next = pNode;
        pNode = cNode;
        cNode = tNode->next;
    }
    *list = pNode;
}

Node *modifiedReverse(Node **list, int a[], int k){
    Node *tNode = *list;
    int nodes = 1;
    while(nodes < k){
        tNode = tNode->next;
        ++nodes;
    }

    Node *pivot = tNode->next;
    tNode->next = NULL;

    Node *pNode = NULL, *cNode = *list;
    Node *t = NULL;

    while(cNode != NULL){
        t = cNode->next;
        cNode->next = pNode;
        pNode = cNode;
        cNode = t->next;
    }
    *list = pNode;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    Node *list = (Node *)malloc(sizeof(Node));
    Node *t = list;
    for(int i = 0; i < n - 1; ++i){
        scanf("%d", &t->data);
        t->next = (Node *)malloc(sizeof(Node));
        t = t->next;
    }
    scanf("%d", t->data);
    t->next = NULL;

    int a[k];
    for(int i = 0; i < k; ++i){
        scanf("%d", &a[i]);
    }
}