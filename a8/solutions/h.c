#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define HASHSIZE 20

ll ABS(ll x){
    return (x >= 0) ? x : -x;
}

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
    return ABS(key % HASHSIZE);
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

HashNode *get(HashTable *hashtable, ll key){
    ll slot = hash(key);
    HashNode *node = hashtable->slots[slot];

    while(node != NULL && node->key != key){
        node = node->next;
    }
    if(node == NULL)
        return NULL;
    return node;
}

int maxSubArr(ll a[], ll n){
    HashTable *cumSum = initHashTable();
    ll sum = 0;
    int max = 0;

    for(ll i = 0; i < n; ++i){
        sum += a[i];
        if(a[i] == 0 && max == 0)
            max = 1;
        if(sum == 0)
            max = i + 1;
        
        if(get(cumSum, sum) != NULL)
            max = (max > (i - get(cumSum, sum)->data)) ? max : (i - get(cumSum, sum)->data);
        else
            insert(cumSum, sum, i);
    }
    return max;
}

int main(){
    ll n;
    scanf("%lld", &n);
    ll a[n];
    for(int i = 0; i < n; ++i){
        scanf("%lld", &a[i]);
    }
    printf("%d", maxSubArr(a, n));
}