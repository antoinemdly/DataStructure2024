#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "./../list/list.h"
#include "hash.h"

unsigned long int hashFunction(void *key){
    unsigned long hash = 0;
    char *string = key;

    for(int i = 0; i < strlen(string); i++){
        int position = string[i] - 'a' + 1;

        hash += position * pow(26,i);
    }

    return hash;
}

HashTable *hashCreate(int size, unsigned long int (*hashFunction)(void *)){
    HashTable *table = malloc(sizeof(HashTable));
    table->size = size;
    table->hashFunction = hashFunction;
    table->buckets = malloc(size * sizeof(void *));

    return table;
}

void hash_destroy(HashTable *table){

    free(table->buckets);
    free(table);
}

void hash_insert(HashTable *table, void *key, void* data){
    unsigned long int hash_index = (*table->hashFunction)(key) % table->size;

    table->buckets[hash_index] = data;
}

void hash_delete(HashTable *table, void *key){
    unsigned long int hash_index = (*table->hashFunction)(key) % table->size;

    table->buckets[hash_index] = NULL;
}

void *hash_get(HashTable *table, void *key){
    unsigned long int hash_index = (*table->hashFunction)(key) % table->size;

    return table->buckets[hash_index];
}

int hash_size(HashTable *table){
    int size = 0;

    for(int i = 0; i < table->size; i++){
        if(table->buckets[i] != NULL){
            size++;
        }
    }

    return size;
}



HashTableChain *hashChainCreate(int size, unsigned long int (*hashFunction)(void *)){
    HashTableChain *table = malloc(sizeof(HashTableChain));
    table->size = size;
    table->hashFunction = hashFunction;
    List **buckets = malloc(size*sizeof(List));
    for(int i = 0; i < size; i++){
        buckets[i] = list_create();
    }
    table->buckets = buckets;

    return table;
}

void hash_chain_destroy(HashTableChain *table){
    
    for(int i = 0; i < table->size; i++){
        list_destroy(table->buckets[i]);
    }

    free(table->buckets);
    free(table);
}

void hash_chain_insert(HashTableChain *table, void *key, void *data){
    unsigned long int hash_index = (*table->hashFunction)(key) % table->size;
    ChainNode *chainnode = malloc(sizeof(ChainNode));
    chainnode->data = data;
    chainnode->key = key;

    list_append(table->buckets[hash_index],chainnode);
}
void hash_chain_delete(HashTableChain *table, void *key){
    unsigned long int hash_index = (*table->hashFunction)(key) % table->size;

    List *list = table->buckets[hash_index];

    for(int i = 0; i < list_size(list); i++){
        ChainNode *chainnode = list_get(list,i);

        if(strcmp((char*)chainnode->key,(char*)key) == 0){
            list_delete(list, i);
            
            break;
        }
    }
}

void *hash_chain_get(HashTableChain *table, void *key){
    unsigned long int hash_index = (*table->hashFunction)(key) % table->size;

    List *chain = table->buckets[hash_index];

    void *data = NULL;

    for(int i = 0; i < list_size(chain); i++){
        ChainNode *chainnode = list_get(chain,i);
        char *string1 = (char*)chainnode->key;
        char *string2 = (char*)key;

        if(strcmp(string1, string2) == 0){
            return chainnode->data;
        }
    }
    
    return NULL;
}

int hash_chain_size(HashTableChain *table){
    int size = 0;

    for(int i = 0; i < table->size; i++){
        if(list_size(table->buckets[i]) != 0){
            size++;
        }
    }

    return size;
}