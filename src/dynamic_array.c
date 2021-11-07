#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

#define INITIAL_SIZE 3
#define GROWTH_FACTOR 2

#define ERR_EXIT(A, ...) fprintf(stderr, __VA_ARGS__); exit(A);

#define ERR_CODE_OOM 1
#define ERR_MSG_OOM "Failed to allocate %zu bytes, exiting...\n"

#define ERR_CODE_OOB 2
#define ERR_MSG_OOB "Out of bounds: length=%d index=%d\n"

void Initialise(DynamicArray **dynamicArray) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if(array == NULL) {
        ERR_EXIT(ERR_CODE_OOM, ERR_MSG_OOM, sizeof(DynamicArray));
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
            ERR_EXIT(ERR_CODE_OOM, ERR_MSG_OOM, dynamicArray->capacity * sizeof(int));
        }
    }
    dynamicArray->data[dynamicArray->length] = elem;
    dynamicArray->length++;
}

void Insert(DynamicArray *dynamicArray, int elem, int index) {
    if(index < 0 || index > dynamicArray->length) {
        ERR_EXIT(ERR_CODE_OOB, ERR_MSG_OOB, dynamicArray->length, index);
    }
    if(dynamicArray->length == dynamicArray->capacity) { //no space to insert new elements
        dynamicArray->capacity *= GROWTH_FACTOR;
        dynamicArray->data = (int *)realloc(dynamicArray->data, dynamicArray->capacity * sizeof(int));
        if(dynamicArray->data == NULL) {
            ERR_EXIT(ERR_CODE_OOM, ERR_MSG_OOM, dynamicArray->capacity * sizeof(int));
        }
    }
    memmove(&(dynamicArray->data[index + 1]), &(dynamicArray->data[index]), (dynamicArray->length - index) * sizeof(int));
    dynamicArray->data[index] = elem;
    dynamicArray->length++;
}

int Get(DynamicArray *dynamicArray, int index) {
    if(index < 0 || index >= dynamicArray->length) {
        ERR_EXIT(ERR_CODE_OOB, ERR_MSG_OOB, dynamicArray->length, index);
    }
    return dynamicArray->data[index];
}

void Delete(DynamicArray *dynamicArray, int index) {
    if(index < 0 || index >= dynamicArray->length) {
        ERR_EXIT(ERR_CODE_OOB, ERR_MSG_OOB, dynamicArray->length, index);
    }
    memmove(&(dynamicArray->data[index]), &(dynamicArray->data[index + 1]), (dynamicArray->length - index) * sizeof(int));
    dynamicArray->length--;
}

void PrintArray(DynamicArray *dynamicArray) {
    int i = 0;
    for(i = 0; i < dynamicArray->length; i++) {
        printf("Index=%d, Value=%d\n", i, Get(dynamicArray, i));
    }
}
