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
    int data;
    struct Node *left;
    struct Node *right;
    //struct Node *parent;
}Node;

Node *createNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderWalk(Node *root){
    if(root == NULL)
        return;
    inorderWalk(root->left);
    printf("%d ", root->data);
    inorderWalk(root->right);
}

void inorderTraversal(Node *root, int inorder[]){
    static int i = 0;
    if(root == NULL)
        return;
    
    inorderTraversal(root->left, inorder);
    inorder[i++] = root->data;
    inorderTraversal(root->right, inorder);
}

void formBST(int inorder[], Node *root, int *idx){
    if(root == NULL)
        return;
    formBST(inorder, root->left, idx);
    root->data = inorder[(*idx)++];
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
Node *getMax(Node*);

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
    inorderWalk(nodes[0]);
    printf("\n");
    buildBST(nodes, n);
    inorderWalk(nodes[0]);
}

Node *treeSearch(Node *node, int t){
    while(node != NULL && node->data != t){
        if(t < node->data)
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

