#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#define TABLE_SIZE 5

int main(void){
    HashTable *table = NULL;
    Initialise(&table, TABLE_SIZE);
    Insert(table, "name", "John Smith");
    Insert(table, "age", "31");
    char *result = Get(table, "name");
    if(result != NULL){
        printf("%s\n", result);
    }else{
        printf("NOT FOUND\n");
    }
    Destroy(&table);
}
