#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int linearSearch(int a[], int n, int t){
    for(int i = 0; i < n; ++i){
        if(a[i] == t){
            return i;
        }
    }
    return -1;
}

void postorder(int preorder[], int inorder[], int n){
    int root = linearSearch(inorder, n, preorder[0]);

    if(root != 0)
        postorder(preorder + 1, inorder, root);
    if(root != n - 1)
        postorder(preorder + root + 1, inorder + root + 1, n - root - 1);
    
    printf("%d ", preorder[0]);
}

int main(){
    int n;
    scanf("%d", &n);

    int inorder[n], preorder[n];

    for(int i = 0; i < n; ++i){
        scanf("%d", &inorder[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &preorder[i]);
    }

    postorder(preorder, inorder, n);
}