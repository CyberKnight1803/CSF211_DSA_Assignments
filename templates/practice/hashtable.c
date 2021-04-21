#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define HASHSIZE 20


typedef struct HashNode{
    struct HashNode *next;
    ll key;
    ll data;
}HashNode;


typedef struct HashTable{
    HashNode *slots[HASHSIZE];
}HashTable;

HashNode *createHashNode(int key, int data){
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->next = NULL;
    node->key = key;
    node->data = data;

    return node;
}

HashTable *initHashTable(){
    HashTable *hashtable = (HashTable *)malloc(sizeof(HashTable));
    for(int i = 0; i < HASHSIZE; ++i){
        hashtable->slots[i] = NULL;
    }
    return hashtable;
}

ll hash(ll key){
    return key % HASHSIZE;
}

void insert(HashTable *hashtable, ll key, ll data){
    HashNode *hashnode = createHashNode(key, data);

    ll slot = hash(key);
    HashNode *slot_node = hashtable->slots[slot];
    if(slot_node == NULL)
        hashtable->slots[slot] = hashnode;
    else{
        while(slot_node->next != NULL)
            slot_node = slot_node->next;
        slot_node->next = hashnode;
    }
}

ll get(HashTable *hashtable, ll key){
    ll slot = hash(key);
    HashNode *node = hashtable->slots[slot];

    while(node != NULL && node->key != key){
        node = node->next;
    }
    if(node == NULL)
        return -999;
    return node->data;
}

typedef struct Node{
    ll data;
    struct Node *next;
}Node;

Node *createNode(ll data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void prepend(Node **list, ll data){
    Node *node = createNode(data);
    node->next = *list;
    *list = node;
}

void intersection(Node **list1, Node **list2){
    Node *list = NULL;
    HashTable *h = initHashTable();

    for(Node *t = *list1; t != NULL; t = t->next)
        insert(h, t->data, t->data);

    for(Node *t = *list2; t != NULL; t = t->next)
        if(get(h, t->data) != -999)
            prepend(&list, t->data);
    
    for(Node *t = list; t != NULL; t = t->next){
        printf("%lld ", t->data);
    }
}

int main(){
    Node *list1 = NULL;
    Node *list2 = NULL;
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i){
        ll data;
        scanf("%lld", &data);
        prepend(&list1, data);
    }
    for(int i = 0; i < n; ++i){
        ll data;
        scanf("%lld", &data);
        prepend(&list2, data);
    }
    intersection(&list1, &list2);
}