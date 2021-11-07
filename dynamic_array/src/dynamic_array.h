#ifndef DYNAMICARRAY
#define DYNAMICARRAY

typedef struct dynamicArray {
    int *data;
    int length;
    int capacity;
} DynamicArray;

void Initialise(DynamicArray **dynamicArray);
void Destroy(DynamicArray *dynamicArray);
void Add(DynamicArray *dynamicArray, int elem);
void Insert(DynamicArray *dynamicArray, int elem, int index);
int Get(DynamicArray *dynamicArray, int index);
void Delete(DynamicArray *dynamicArray, int index);
void PrintArray(DynamicArray *dynamicArray);

#endif