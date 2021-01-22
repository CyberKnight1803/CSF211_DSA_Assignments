#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    struct node *prev;
    char data;
};

void createNode(struct node **list, char data){
    struct node *t = *list;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(*list == NULL){
        newNode->prev = NULL;
        *list = newNode;
        return;
    }
    
    while(t->next != NULL){
        t = t->next;
    }

    newNode->prev = t;
    return;
}

int isPalindrome(struct node *leftMostNode){
    if(leftMostNode == NULL){
        return 1;
    }

    struct node *rightMostNode = leftMostNode;
    while(rightMostNode->next != NULL){
        rightMostNode = rightMostNode->next;
    }

    while(leftMostNode != rightMostNode){
        if(leftMostNode->data != rightMostNode->data) return 0;

        leftMostNode = leftMostNode->next;
        rightMostNode = rightMostNode->prev;
    }
    return 1;
}

int main(){
    int n; scanf("%d", &n);
    char c;
    struct node *list = NULL;

    for(int i = 0; i < n; ++i){
        scanf("%c", &c);
        createNode(&list, c);
    }

    isPalindrome(list) ? printf("PALINDROME") : printf("NOT A PALINDROME");
}