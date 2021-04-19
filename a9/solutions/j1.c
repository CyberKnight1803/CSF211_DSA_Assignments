#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{ 
	char string[10]; 
	struct Node_t *left,*right; 
}Node_t;

Node_t *createNode(int key){ 
    int i=0;
	Node_t* node=(Node_t*)malloc(sizeof(Node_t)); 
	while(key != 0){
        (node->string)[i++] = key % 10 + '0';
        key = key / 10;
    }
    (node->string)[i]='\0';
	node->left=NULL;
	node->right=NULL; 
	return (node); 
} 

Node_t* insertLevelOrder(int a[], Node_t *root, int i, int n){ 
	if(i < n){ 
	    if(a[i] != -1){
		    Node_t* temp = createNode(a[i]); 
		    root = temp;
	    } 
	    else
	        return NULL;

		root->left=insertLevelOrder(a,root->left,2*i+1,n); 
		root->right=insertLevelOrder(a,root->right,2*i+2,n); 
	}
	return root; 
} 

void insert(Node_t* node){
    if(node==NULL)
        return;
        
    else
    {
        insert(node->left);
        insert(node->right);
        Node_t* temp;
        temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
}

void printInorder(Node_t* node) 
{ 
    if(node==NULL) 
        return; 
    printInorder(node->left); 
    printf("%s ",node->string);   
    printInorder(node->right); 
} 

int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    Node_t* root = insertLevelOrder(a,root,0,n);
    insert(root);
    printInorder(root);

    return 0;
}