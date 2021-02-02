#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    struct node *prev;
    char data;
};

void createNode(struct node** list, char new_data) 
{ 
    struct node* new_node =  (struct node *)malloc(sizeof(struct node)); 
    new_node->data  = new_data; 
    new_node->next = *list; 
    new_node->prev = NULL; 
    if (*list !=  NULL) 
      (*list)->prev = new_node ; 
    *list = new_node; 
} 
int isPalindrome(struct node *leftNode) 
{ 
    if (leftNode == NULL) 
       return 1; 

    struct node *rightNode = leftNode; 
    while (rightNode->next != NULL) 
        rightNode = rightNode->next; 
  
    while (leftNode != rightNode) 
    { 
        if (leftNode->data != rightNode->data) 
            return 0; 
  
        leftNode = leftNode->next; 
        rightNode = rightNode->prev; 
    } 
    return 1; 
} 

int main(){
    int n; scanf("%d", &n);
    char *c = (char *)malloc(sizeof(char) * (n + 1));
    struct node *list = NULL;
    scanf("%s", c);
    int i = 0;
    while(n--){
        createNode(&list, c[i]);
        i++;
    }

    isPalindrome(list) ? printf("PALINDROME") : printf("NOT A PALINDROME");
}