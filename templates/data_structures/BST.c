#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int L, int H){
    int pivot = a[H];
    int pIdx = L - 1;

    for(int i = L; i <= H - 1; ++i){
        if(a[i] < pivot){                    
            pIdx++;
            swap(&a[pIdx], &a[i]);
        }
    }
    swap(&a[pIdx + 1], &a[H]);
    return pIdx + 1;
}

void qSort(int *a, int L, int H){
    if(L < H){
        int pIdx = partition(a, L, H);
        qSort(a, L, pIdx - 1);
        qSort(a, pIdx + 1, H);
    }
}

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
}Node;

Node *createNode(int key){
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderWalk(Node *root){
    if(root == NULL)
        return;
    inorderWalk(root->left);
    printf("%d ", root->key);
    inorderWalk(root->right);
}

void inorderTraversal(Node *root, int inorder[]){
    static int i = 0;
    if(root == NULL)
        return;
    
    inorderTraversal(root->left, inorder);
    inorder[i++] = root->key;
    inorderTraversal(root->right, inorder);
}

void formBST(int inorder[], Node *root, int *idx){
    if(root == NULL)
        return;
    formBST(inorder, root->left, idx);
    root->key = inorder[(*idx)++];
    formBST(inorder, root->right, idx);
}

void buildBST(Node *nodes[], int n){
    int inorder[n];
    inorderTraversal(nodes[0], inorder);
    qSort(inorder, 0, n - 1);
    int idx = 0;
    formBST(inorder, nodes[0], &idx);
}

Node *treeSearch(Node *root, int t);
Node *getMax(Node *root);
Node *getMin(Node *root);
Node *successor(Node *node);
void insert(Node **root, int key);
void transplant(Node **root, Node *u, Node *v);
void delete(Node **root, Node *z);

int main(){
    int n;
    scanf("%d", &n);

    Node *nodes[n];
    for(int i = 0; i < n; ++i){
        int key;
        scanf("%d", &key);
        nodes[i] = createNode(key);
    }

    for(int i = 0; i < n - 1; ++i){
        int x, y;
        char type;
        scanf("%d %d %c", &x, &y, &type);
        if(type == 'L'){
            nodes[x]->left = nodes[y];
            nodes[y]->parent = nodes[x];
        }
        else{
            nodes[x]->right = nodes[y];
            nodes[y]->parent = nodes[x];
        }
    }

    inorderWalk(nodes[0]);
    printf("\n");
    buildBST(nodes, n);
    inorderWalk(nodes[0]);
}

Node *treeSearch(Node *node, int t){
    while(node != NULL && node->key != t){
        if(t < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

Node *getMax(Node *node){
    while(node->right != NULL)
        node = node->right;
    return node;
}

Node *getMin(Node *node){
    while(node->left != NULL)
        node = node->left;
    return node;
}

Node *successor(Node *node){
    if(node->right != NULL)
        return getMin(node->right);
    
    Node *par = node->parent;
    while(par != NULL && node == par->right){
        node = par;
        par = par->parent;
    }
    return par;
}

void insert(Node **root, int key){
    Node *y = NULL;
    Node *x = *root;
    while(x != NULL){
        y = x;
        if(key < x->key)
            x = x->left;
        else 
            x = x->right;
    }
    Node *z = createNode(key);
    z->parent = y;
    if(y == NULL)
        *root = z;

    else if(z->key < y->key)
        y->left = z;
    else 
        y->right = z;
}

void transplant(Node **root, Node *u, Node *v){
    if(u->parent == NULL)
        *root = v;
    
    else if(u == u->parent->left)
        u->parent->left = v;
    
    else 
        u->parent->right = v;

    if(v != NULL)
        v->parent = u->parent;
}

void delete(Node **root, Node *z){
    Node *y;
    if(z->left == NULL)
        transplant(root, z, z->right);

    else if(z->right == NULL)
        transplant(root, z, z->left);
    
    else{
        y = getMin(z->right);
        if(y->parent != z){
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }        
}