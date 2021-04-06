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
    HashNode *hashnode = (HashNode *)malloc(sizeof(HashNode));
    hashnode->key = key;
    hashnode->data = data;
    hashnode->next = NULL;

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
        return -1;
    return node->data;
}

int main(){
    
}