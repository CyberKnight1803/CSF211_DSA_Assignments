#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;

int main(){
    int n;
    scanf("%d", &n);

    Node *nodes[n];
    for(int i = 0; i < n; ++i){
        int data;
        scanf("%d", &data);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        nodes[i] = newNode;
    }

    for(int i = 0; i < n - 1; ++i){
        int x, y;
        char type;
        scanf("%d %d %c", &x, &y, &type);
        if(type == 'L'){
            nodes[x]->left = nodes[y];
        }
        else{
            nodes[x]->right = nodes[y];
        }
    }

    Node *stack[n];
    int top = -1;
    Node *t = nodes[0];

    while(t != NULL || top != -1){
        while(t != NULL){
            stack[++top] = t;
            t = t->left;
        }
        t = stack[top--];
        printf("%d ", t->data);
        t = t->right;
    }
}