#include <stdio.h>

#include "dynamic_array.h"

int main(void) {
    DynamicArray *dynamicArray = NULL;
    Initialise(&dynamicArray);
    Add(dynamicArray, 10);
    Add(dynamicArray, 3);
    Add(dynamicArray, 4);
    Insert(dynamicArray, 1, 1);
    Insert(dynamicArray, 5, 3);
    Delete(dynamicArray, 0);
    PrintArray(dynamicArray);
    Destroy(dynamicArray);
}
