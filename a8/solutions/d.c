#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b){return (a > b) ? a : b;}

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;

Node *createNode(int key){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void deleteSubTree(Node *node){
    if(!node) return;
    deleteSubTree(node->left);
    deleteSubTree(node->right);
    free(node);
}

void deleteNode(int key, Node* root) {
    if (root) {
        Node* left = root->left;
        Node* right = root->right;
        if (left) {
            if (left->key == key) {
                deleteSubTree(left);
                root->left = NULL;
                return;
            }
        }
        if (right) {
            if (right->key == key){
                deleteSubTree(right);
                root->right = NULL;
                return;
            }
        }
        deleteNode(key, root->left);
        deleteNode(key, root->right);
    }
    return;
}

Node* findParent(int key, Node* root, int* dir) {
    if (root) {
        Node* left = root->left;
        Node* right = root->right;

        if (left) {
            if (left->key == key) {
                *dir = 0;
                return root;
            }
        }

        if (right) {
            if (right->key == key) {
                *dir = 1;
                return root;
            }
        }

        Node* parent;

        parent = findParent(key, left, dir);
        if (parent) return parent;

        return findParent(key, right, dir);
    }

    return NULL;
}

void swapNodes(int a, int b, Node* root) {
    int dira = -1, dirb = -1;
    Node* pa = findParent(a, root, &dira);
    Node* pb = findParent(b, root, &dirb);
    Node* temp;

    if (dira < 0 || dirb < 0) return;

    switch ((dirb << 1) | dira) {
        case 0:
            temp = pa->left;
            pa->left = pb->left;
            pb->left = temp;
            break;

        case 1:
            temp = pa->right;
            pa->right = pb->left;
            pb->left = temp;
            break;

        case 2: 
            temp = pa->left;
            pa->left = pb->right;
            pb->right = temp;
            break;

        case 3: 
            temp = pa->right;
            pa->right = pb->right;
            pb->right = temp;
            break;

        default:
            break;
    }
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
            deleteNode(a, nodes[0]);
        }
        else{
            int a, b;
            scanf("%d %d", &a, &b);
            swapNodes(a, b, nodes[0]);
        }
    }
    printf("%d", diameter(nodes[0]) - 1);
}