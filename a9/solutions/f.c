#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int key){
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node **root, int key){
    Node *y = NULL;
    Node *x = *root;
    while(x != NULL){
        y = x;
        if(key < x->key)
            x = x->left;
        else if (key > x->key) 
            x = x->right;
        else
            return;
    }
    Node *z = createNode(key);
    if(y == NULL)
        *root = z;

    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

void postorder(Node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}


int main(){
    int n;
    scanf("%d", &n);
    Node *root = NULL;

    while(n--){
        int key;
        scanf("%d", &key);
        insert(&root, key);
    }
    postorder(root);
}