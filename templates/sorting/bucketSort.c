#include<stdio.h>
#include<stdlib.h>
#define SIZE 10    // No of Buckets

typedef struct Node{
    float data;
    struct Node *next;
}Node;

Node *createNode(float data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **list, float data){
    Node *newNode = createNode(data);
    newNode->next = *list;
    *list = newNode;
}

Node **initBuckets(int size){
    Node **buckets = (Node **)malloc(sizeof(Node *) * size);
    for(int i = 0; i < size; ++i){
        buckets[i] = NULL;
    }
    return buckets;
}

void sortedInsert(Node** list, Node* newNode)
{
    Node* current;
    if (*list == NULL || (*list)->data >= newNode->data){
        newNode->next = *list;
        *list = newNode;
    }
    else{
        current = *list;
        while (current->next!=NULL && current->next->data < newNode->data)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertionSort(struct Node **list)
{
    struct Node *sorted = NULL;
    struct Node *current = *list;

    while (current != NULL){
        struct Node *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *list = sorted;
}


void bucketSort(float a[], int n){
    Node **buckets = initBuckets(SIZE);
    
    for(int i = 0; i < n; ++i){
        int idx = SIZE * a[i];
        insert(&buckets[idx], a[i]);
    }

    for(int i = 0; i < SIZE; ++i){
        insertionSort(&buckets[i]);
    }
    int j = 0;
    for(int i = 0; i < SIZE; ++i){
        for(Node *t = buckets[i]; t != NULL; t = t->next){
            a[j++] = t->data;
        }
    }
}

void printArr(float a[], int n){
    for(int i = 0; i < n; ++i){
        printf("%f ", a[i]);
    }
}

int main(){
    float a[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(a) / sizeof(float);

    bucketSort(a, n);
    printArr(a, n);
}