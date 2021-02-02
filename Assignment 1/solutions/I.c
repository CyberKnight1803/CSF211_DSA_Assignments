#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void createList(struct node *list){
    scanf("%d", &list->data);

    if(list->data != -1){
        list->next = (struct node*)malloc(sizeof(struct node));
        createList(list->next);
    }
    else{
        list->next = NULL;
    }
    return;
}

void printList(struct node *list){
    if(list->next != NULL && list->data != -1){
        printf("%d ", list->data);
        printList(list->next);
    }
    else if(list->data != -1){
        printf("%d", list->data);
    }
}

void reverseList(struct node **list){
    struct node *tNode = *list, *pNode, *cNode;
    if(tNode->next != NULL){
        pNode = tNode;
        cNode = tNode->next;
        tNode = tNode->next;
        pNode->next = NULL;

        while(tNode->next != NULL){
            tNode = tNode->next;
            cNode->next = pNode;
            pNode = cNode;
            cNode = tNode;
        }
        *list = pNode;
    }
}

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));

    createList(head);
    reverseList(&head);
    printList(head);
}