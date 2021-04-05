#include<stdio.h>
#include<stdlib.h>
#define True 1

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

struct Stack{
    Node **s;
    int top;
};
typedef struct Stack Stack;

Stack *createStack(int size){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->s = (Node **)malloc(sizeof(Node *) * size);
    stack->top = -1;

    return stack;
}

void swap(Stack **a, Stack **b){
    Stack *t = *a;
    *a = *b;
    *b = t;
}

void zigzag(Node *root, int n){
    
    Stack *current = createStack(n);
    Stack *next = createStack(n);
    int LtoR = True;

    current->s[++(current->top)] = root;
    while(current->top != -1){
        Node *t = current->s[(current->top)--];
        if(t){
            printf("%d ", t->data);
            if(LtoR){
                if(t->left)
                    next->s[++(next->top)] = t->left;
                if(t->right)
                    next->s[++(next->top)] = t->right;
            }
            else{
                if(t->right)
                    next->s[++(next->top)] = t->right;
                if(t->left)
                    next->s[++(next->top)] = t->left;
            }
        }
        if(current->top == -1){
            LtoR = !LtoR;
            swap(&current, &next);
        }
    }
}

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
    zigzag(nodes[0], n);
}