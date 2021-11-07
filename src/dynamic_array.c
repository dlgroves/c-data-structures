#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

#define INITIAL_SIZE 3
#define GROWTH_FACTOR 2

void Initialise(DynamicArray **dynamicArray) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if(array == NULL) {
        fprintf(stderr, "Failed to allocate %zu bytes, exiting...\n", sizeof(DynamicArray));
        exit(1);
    }
    array->data = (int *)malloc(INITIAL_SIZE * sizeof(int));
    array->length = 0;
    array->capacity = INITIAL_SIZE;
    *dynamicArray = array;
}

void Destroy(DynamicArray *dynamicArray) {
    free(dynamicArray->data);
    free(dynamicArray);
}

void Add(DynamicArray *dynamicArray, int elem) {
    if(dynamicArray->capacity == dynamicArray->length) {
        dynamicArray->capacity *= GROWTH_FACTOR;
        dynamicArray->data = (int *)realloc(dynamicArray->data, dynamicArray->capacity * sizeof(int));
        if(dynamicArray->data == NULL) {
            fprintf(stderr, "Failed to allocate %zu bytes, exiting...\n", dynamicArray->capacity * sizeof(int));
            exit(1);
        }
    }
    dynamicArray->data[dynamicArray->length] = elem;
    dynamicArray->length++;
}

void Insert(DynamicArray *dynamicArray, int elem, int index) {
    if(index < 0 || index > dynamicArray->length) {
        fprintf(stderr, "Out of bounds: length=%d index=%d\n", dynamicArray->length, index);
        exit(2);
    }
    if(dynamicArray->length == dynamicArray->capacity) { //no space to insert new elements
        dynamicArray->capacity *= GROWTH_FACTOR;
        dynamicArray->data = (int *)realloc(dynamicArray->data, dynamicArray->capacity * sizeof(int));
        if(dynamicArray->data == NULL) {
            fprintf(stderr, "Failed to allocate %zu bytes, exiting...\n", dynamicArray->capacity * sizeof(int));
            exit(1);
        }
    }
    memmove(&(dynamicArray->data[index + 1]), &(dynamicArray->data[index]), (dynamicArray->length - index) * sizeof(int));
    dynamicArray->data[index] = elem;
    dynamicArray->length++;
}

int Get(DynamicArray *dynamicArray, int index) {
    if(index < 0 || index >= dynamicArray->length) {
        fprintf(stderr, "Out of bounds: length=%d index=%d\n", dynamicArray->length, index);
        exit(2);
    }
    return dynamicArray->data[index];
}

void Delete(DynamicArray *dynamicArray, int index) {
    if(index < 0 || index >= dynamicArray->length) {
        fprintf(stderr, "Out of bounds: length=%d index=%d\n", dynamicArray->length, index);
        exit(2);
    }
    memmove(&(dynamicArray->data[index]), &(dynamicArray->data[index + 1]), (dynamicArray->length - index) * sizeof(int));
    dynamicArray->length--;
}

void Printarray(DynamicArray *dynamicArray) {
    int i = 0;
    for(i = 0; i < dynamicArray->length; i++) {
        printf("Index=%d, Value=%d\n", i, Get(dynamicArray, i));
    }
}
