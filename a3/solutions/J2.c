/* 
NAME : OMKAR VIJAY PITALE
ID : 2019A7PS0083H
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node_t{
    int key;
    struct Node_t *left, *right;
}Node_t;

Node_t *createNode(int key){
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

int findNodeInOrder(int _in[], int n, int s, int e, int key){
    int i = s;
    while(i <= e){
        if(_in[i] == key)
            return i;
        i++;
    }
    return -1;
}

Node_t *initBT(int _post[], int _in[], int n, int s, int e, int *pIdx){
    if(s > e)
        return NULL;
    
    Node_t *root = createNode(_post[(*pIdx)]);
    --(*pIdx);

    if(s == e)
        return root;
    
    int idx = findNodeInOrder(_in, n, s, e, root->key);
    root->right = initBT(_post, _in, n, idx + 1, e, pIdx);
    root->left = initBT(_post, _in, n, s, idx - 1, pIdx);

    return root;
}

void findPreOrderLeaves(Node_t *root){
    if(root){
        if(root->left == NULL && root->right == NULL){
            printf("%d ", root->key);
        }
        findPreOrderLeaves(root->left);
        findPreOrderLeaves(root->right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int pIdx = n - 1;
    int _in[n], _post[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &_post[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &_in[i]);
    }

    Node_t *tree = initBT(_post, _in, n, 0, n - 1, &pIdx);
    findPreOrderLeaves(tree);
}