#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b){return (a > b) ? a : b;}

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

Node *linearSearch(Node *nodes[], int n, int t){
    for(int i = 0; i < n; ++i){
        if(nodes[i]->data == t)
            return nodes[i];
    }
    return NULL;
}   

int height(Node *root){
    if(root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

int diameter(Node *root){
    if(root == NULL)
        return 0;
    
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

int main(){
    int n, t;
    scanf("%d %d", &n, &t);

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
    while(t--){
        char command[7];
        scanf("%s", command);
        if(strcmp(command, "DELETE") == 0){
            int a;
            scanf("%d", &a);
            Node *node = linearSearch(nodes, n, a);
            node = NULL;
        }
        else{
            int a, b;
            scanf("%d %d", &a, &b);
            Node *A = linearSearch(nodes, n, a);
            Node *B = linearSearch(nodes, n, b);
            Node *t = A;
            A = B;
            B = t;
        }
    }
    printf("%d", diameter(nodes[0]));
}