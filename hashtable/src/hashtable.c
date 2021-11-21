#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

Node *_getNode(HashTable *, char *);
unsigned long _hash(char *);

void Initialise(HashTable **table, int size) {
    *table = (HashTable *)malloc(sizeof(HashTable));
    (*table)->table = (Node **)malloc(size * sizeof(Node *));
    int i;
    for(i = 0; i < size; i++){
        (*table)->table[i] = NULL;
    }
    (*table)->size = size;
}

void Destroy(HashTable **table) {
    int i;
    for(i = 0; i < (*table)->size; i++){
        if((*table)->table[i] != NULL){
            free((*table)->table[i]);
            (*table)->table[i] = NULL;
        }
    }
    free((*table)->table);
    free(*table);
    *table = NULL;
}

void Insert(HashTable *table, char *key, char *value){
    if(table == NULL){
        fprintf(stderr, "Tried to insert into a null table\n");
        exit(1);
    }
    unsigned long theHash = _hash(key) % table->size;
    Node *ptr = table->table[theHash];
    Node *prev = ptr;
    if(ptr != NULL){
        while(ptr != NULL){
            if(!strcmp(ptr->key, key)){
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL){
            ptr = (Node *)malloc(sizeof(Node));
            prev->next = ptr;
        }
        ptr->key = key;
        ptr->value = value;
    } else {
        ptr = (Node *)malloc(sizeof(Node));
        ptr->key = key;
        ptr->value = value;
        ptr->next = NULL;
        table->table[theHash] = ptr;
    }
}

char *Get(HashTable *table, char *key){
    Node *result;
    if((result = _getNode(table, key)) != NULL){
        return result->value;
    }
    return NULL;
}

Node *_getNode(HashTable *table, char *key){
    if(table == NULL){
        fprintf(stderr, "Tried to fetch from a null table\n");
        exit(2);
    }
    unsigned long theHash = _hash(key) % table->size;
    Node *elem;
    if((elem = table->table[theHash]) != NULL){
        while(elem != NULL){
            if(!strcmp(key, elem->key)){
                return elem;
            }
            elem = elem->next;
        }
    }
    return NULL;
}

/**
* http://www.cse.yorku.ca/~oz/hash.html
*/
unsigned long _hash(char *str) {
    unsigned long hash = 5381;
    char c;
    while ((c = *str++) != '\0'){
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}
