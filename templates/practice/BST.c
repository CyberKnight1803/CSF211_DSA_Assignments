#include<stdio.h>
#include<stdlib.h>

typedef struct Node_t{
    int key;
    Node_t *left, *right, *parent;
}Node_t;

Node_t *createNode(int key){
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->key = key;

    return node;
}

int main(){
    int n;
    scanf("%d", &n);
    Node_t *nodes[n];

    for(int i = 0; i < n; ++i){
        int key;
        scanf("%d", &key);
        nodes[i] = createNode(key);
    }
    for(int i = 0; i < n - 1; ++i){
        int x, y;
        char type;

        scanf("%d %d %c", &x, &y, &type);

        switch(type){
            case 'L':
                nodes[x]->left = nodes[y];
                nodes[y]->parent = nodes[x];
                break;
            
            case 'R':
                nodes[x]->right = nodes[y];
                nodes[y]->parent = nodes[x];
                break;
            
            default:
                break;
        }
    }
    Node_t *root = nodes[0];
}