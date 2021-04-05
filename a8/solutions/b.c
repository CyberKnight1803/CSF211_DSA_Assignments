#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define ABS(x)((x) >= 0 ? (x): -(x))
const ll MOD = 1e9 + 7;

struct Node{
    ll data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;

Node *createNode(ll data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void postorder(Node *node, ll post[]){
    static int i = 0;
    if(node == NULL)
        return;
    postorder(node->left, post);
    postorder(node->right, post);
    post[i++] = node->data;
}

void preorder(Node *node, ll pre[]){
    static int j = 0;
    if(node == NULL)
        return;
    pre[j++] = node->data;
    preorder(node->left, pre);
    preorder(node->right, pre);
}

void inorder(Node *node, ll in[]){
    static int k = 0;
    if(node == NULL)
        return;
    inorder(node->left, in);
    in[k++] = node->data;
    inorder(node->right, in);
}

ll solution(Node *root, int n){
    ll A[n], B[n], C[n], S = 0; 
    preorder(root, A);
    postorder(root, B);
    inorder(root, C);

    for(int i = 0; i < n; ++i){
        S += ABS(A[i] - B[i]) * C[i];
    }
    return S % MOD;
}

int main(){
    int n;
    scanf("%d", &n);

    Node *nodes[n];
    for(int i = 0; i < n; ++i){
        ll data;
        scanf("%lld", &data);
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
    printf("%lld", solution(nodes[0], n));
}