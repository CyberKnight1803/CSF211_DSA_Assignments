#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void deleteSubTree(Node* node) {
    if (!node) return;

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
            if (right->key == key) {
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

Node* createTree(int n, int arr[n]) {
    Node* treeArr[n];

    for (int i = 0; i < n; i++) {
        treeArr[i] = createNode(arr[i]);
    }

    int u, v;
    char dir;

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d %c%*c", &u, &v, &dir);

        switch (dir) {
            case 'L':
                treeArr[u]->left = treeArr[v];
                break;
            case 'R':
                treeArr[u]->right = treeArr[v];
                break;

            default:
                break;
        }
    }

    return treeArr[0];
}

void printTree(Node* node) {
    if (node) {
        printf("%d ", node->key);
        printTree(node->left);
        printTree(node->right);
    }
}

int height(Node* node) {
    if (!node) return 0;

    return 1 + max(height(node->left), height(node->right));
}

int diameter(Node* root) {
    if (!root) return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    Node* root = createTree(n, arr);

    char instruction[10];
    int a, b;
    while (t--) {
        scanf("%s%*c", instruction);

        switch (instruction[0]) {
            case 'D':
                scanf("%d", &a);
                deleteNode(a, root);
                break;
            case 'S':
                scanf("%d %d", &a, &b);
                swapNodes(a, b, root);
                break;
        }
    }
    printf("%d", diameter(root) - 1);
    return 0;
}