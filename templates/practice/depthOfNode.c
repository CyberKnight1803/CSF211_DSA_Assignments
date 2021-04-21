// sum of depth of all nodes
#include<stdio.h>
#include<stdlib.h>

int sum = 0;

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void dfs(Node *node, int depth){
    sum += depth;
    if(node->left){
        dfs(node->left, depth + 1);
    }
    if(node->right){
        dfs(node->right, depth + 1);
    }
}

int sumOfDepths(Node *root){
    sum = 0;
    dfs(root, 0);
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);    

    Node *nodes[n];
    for(int i = 0; i < n; ++i){
        int data;
        scanf("%d", &data);
        nodes[i] = createNode(data);
    }
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        char type;
        scanf("%d %d %c", &u, &v, &type);
        if(type == 'L'){
            nodes[u]->left = nodes[v];
        }
        else{
            nodes[u]->right = nodes[v];
        }
    }
    printf("%d", sumOfDepths(nodes[0]));
}