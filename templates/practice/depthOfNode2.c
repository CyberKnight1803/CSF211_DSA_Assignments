// Sum of depths of all nodes of all subtrees
// Upgraded problem of 1st

#include<stdio.h>
#include<stdlib.h>

int sum = 0;

typedef struct Pair{
    int x, y;
}Pair;

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

// Pair.x = no.of nodes in subtree rooted at node
// Pair.y = sum of depths in that subtree

Pair dfs(Node *node){
    Pair p = (Pair){.x = 1, .y = 0};
    if(node->left){
        Pair child = dfs(node->left);
        p.y += child.y + child.x;
        p.x += child.x;
    }
    if(node->right){
        Pair child = dfs(node->right);
        p.y += child.y + child.x;
        p.x += child.x;
    }
    sum += p.y;
    return p;
}

int sumOfDepths(Node *root){
    sum = 0;
    dfs(root);
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