#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

void swapStr(char **a, char **b){
    char *t = *a;
    *a = *b;
    *b = t;
}

void reverse(char s[]){
    int n = strlen(s);
    for(int i = 0; i < n / 2; ++i)
        swap(&s[i], &s[n - i - 1]);
}

typedef struct Node_t{
    struct Node_t *left, *right;
    char key[N];
}Node_t;

Node_t *createNode(char *S){
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    reverse(S);
    strcpy(node->key, S);
    node->left = NULL;
    node->right = NULL;

    return node;
}

void invert(Node_t *node){
    if (node == NULL) 
		return;
    else{ 
		Node_t *temp; 

		invert(node->left); 
		invert(node->right); 

		temp = node->left; 
		node->left = node->right; 
		node->right = temp; 
	}  
}

void inorder(Node_t *node){
    if(!node)
        return;
    inorder(node->left);
    if(strcmp(node->key, "1-"))
        printf("%s ", node->key);
    inorder(node->right);
}

int main(){
    int n; scanf("%d", &n);
    Node_t *nodes[n];
    char S[N + 1];
    for(int i = 0; i < n; ++i){
        scanf("%s", S);
        Node_t *node;
        if(strcmp(S, "-1"))
            node = createNode(S);
        else 
            node = NULL;
        nodes[i] = node;
    }
    for(int i = 0; 2 * i + 2 < n; ++i){
        nodes[i]->left = nodes[2 * i + 1];
        nodes[i]->right = nodes[2 * i + 2];
    }
    invert(nodes[0]);
    inorder(nodes[0]);
}