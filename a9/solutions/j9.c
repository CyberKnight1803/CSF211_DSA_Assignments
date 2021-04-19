#include<stdio.h>
#include<stdlib.h>
typedef struct Node_t {
char data[10] ;
struct Node_t * left ;
struct Node_t * right ;
}Node_t;

void rev(char *str)
{int l=0;
	   while (str[l] != '\0')
           l++;
   
	for(int i=0;i<l/2;i++)
	{
		char t=str[i];
		str[i]=str[l-i-1];
		str[l-i-1]=t;
	}
}


void Inorder(Node_t* node)
{
    if (node == NULL)
        return;
 
    Inorder(node->left);
      printf("%s ",node->data);
    Inorder(node->right);
}

int stringcompare(char *a,char *b)  
{  
   int flag=0;  
    while(*a!='\0' && *b!='\0')  
    {  
        if(*a!=*b)  
        {  
            flag=1;  
        }  
        a++;  
        b++;  
    }  
      
    if(flag==0)  
    return 0;  
    else  
    return 1;  
}  

int main()
{
int n;
scanf("%d",&n);
char str[10]="-1";
Node_t *arr[n];

for (int i=0; i<n; i++)
    {   arr[i] = (Node_t*)malloc(sizeof(Node_t));
	scanf (" %s", arr[i]->data);
    arr[i]->left = NULL;
    arr[i]->right = NULL;
       
    }

   for(int i=0;i<n;i++){ 
     int l=(2*i)+1;
     int r=(2*i)+2;
   if(l<n && stringcompare(arr[l]->data,str))
   	arr[i]->left=arr[l];
   else 
   	  arr[i]->left=NULL;
   	  
   if(r<n && stringcompare(arr[r]->data,str))
   	arr[i]->right=arr[r];
   	else
   	 	arr[i]->right=NULL;
   	
   	if(stringcompare(arr[i]->data,str))
   	   rev(arr[i]->data);
    }

  for(int i=0;i<n;i++){
  	Node_t * temp=arr[i]->left;
  	arr[i]->left=arr[i]->right;
  	arr[i]->right=temp;
  }
    Inorder(arr[0]);
	return 0;
}