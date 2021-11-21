#ifndef HASHTABLE
#define HASHTABLE

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} Node;

typedef struct hashTable {
    Node **table;
    int size;
} HashTable;

void Initialise(HashTable **, int size);
void Destroy(HashTable **);
char *Get(HashTable *, char *);
void Insert(HashTable *, char *, char *);

#endif
