// Sum of distances from a node wrt to all nodes in tree.

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
    int sizeOfSubtree;
}Node;

Node *createNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->sizeOfSubtree = 0;
    return node;
}

// Pair.x = no.of nodes in subtree rooted at node
// Pair.y = sum of depths in that subtree

Pair dfs1(Node *node){
    Pair p = (Pair){.x = 1, .y = 0};
    if(node->left){
        Pair child = dfs1(node->left);
        p.y += child.y + child.x;
        p.x += child.x;
    }
    if(node->right){
        Pair child = dfs1(node->right);
        p.y += child.y + child.x;
        p.x += child.x;
    }
    node->sizeOfSubtree = p.x;
    return p;
}

void dfs2(Node *node, int sumDists_node, Node *target, int n){
    if(node == target)
        sum = sumDists_node;
    
    if(node->left){
        int newSum = sumDists_node - (node->left->sizeOfSubtree) + (n - node->left->sizeOfSubtree);
        dfs2(node->left, newSum, target, n);
    }
    if(node->right){
        int newSum = sumDists_node - (node->right->sizeOfSubtree) + (n - node->right->sizeOfSubtree);
        dfs2(node->right, newSum, target, n);
    }
}

int sumDists(Node *root, Node *target, int n){
    Pair p = dfs1(root);
    dfs2(root, p.y, target, n);
    return sum;
}

int main(){
    int n, k;
    scanf("%d", &n, &k);    

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
    printf("%d", sumDists(nodes[0], nodes[k], n));
}