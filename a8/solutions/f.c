#include<stdio.h>
#include<stdlib.h>

struct Node{
    int idx;
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;

Node *createNode(int idx, int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->idx = idx;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int LCA(Node *nodes[], int n1, int n2){
    Node *root = nodes[0];

    while (root != NULL)
    {
        if (root->data > nodes[n1]->data && root->data > nodes[n2]->data)
            root = root->left;

        else if (root->data < nodes[n1]->data && root->data < nodes[n2]->data)
            root = root->right;

        else
            break;
    }
    return root->idx;
}


int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    Node *nodes[n];
    for(int i = 0; i < n; ++i){
        int data;
        scanf("%d", &data);
        nodes[i] = createNode(i, data);
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
    for(int i = 0; i < q; ++i){
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        printf("%d ", LCA(nodes, n1, n2));
    }
}
