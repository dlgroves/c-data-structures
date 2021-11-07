#include "gtest/gtest.h"
#include "../src/dynamic_array.h"

TEST(DynamicArray, CanBeInitialised){
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    ASSERT_EQ(dynamicArray->length, 0);
    ASSERT_EQ(dynamicArray->capacity, 3);
}

TEST(DynamicArray, AddElement){
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 2);
    ASSERT_EQ(dynamicArray->length, 1);
    ASSERT_EQ(dynamicArray->capacity, 3);
    ASSERT_EQ(dynamicArray->data[0], 2);
}

TEST(DynamicArray, AddElementBeyondCapacity){
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 1);
    Add(dynamicArray, 2);
    Add(dynamicArray, 3);
    Add(dynamicArray, 4);
    ASSERT_EQ(dynamicArray->length, 4);
    ASSERT_EQ(dynamicArray->capacity, 6);
}

TEST(DynamicArray, InsertIntoEmptyDynamicArray) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Insert(dynamicArray, 3, 0);
    ASSERT_EQ(dynamicArray->length, 1);
    ASSERT_EQ(dynamicArray->capacity, 3);
    ASSERT_EQ(dynamicArray->data[0], 3);
}

TEST(DynamicArray, InsertElementAtHead) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 2);
    Insert(dynamicArray, 3, 0);
    ASSERT_EQ(dynamicArray->length, 2);
    ASSERT_EQ(dynamicArray->capacity, 3);
    ASSERT_EQ(dynamicArray->data[0], 3);
    ASSERT_EQ(dynamicArray->data[1], 2);
}

TEST(DynamicArray, InsertElementAtTail) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 2);
    Insert(dynamicArray, 3, 1);
    ASSERT_EQ(dynamicArray->length, 2);
    ASSERT_EQ(dynamicArray->capacity, 3);
    ASSERT_EQ(dynamicArray->data[0], 2);
    ASSERT_EQ(dynamicArray->data[1], 3);
}

TEST(DynamicArray, InsertElementInMiddle) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 2);
    Add(dynamicArray, 1);
    Insert(dynamicArray, 3, 1);
    ASSERT_EQ(dynamicArray->length, 3);
    ASSERT_EQ(dynamicArray->capacity, 3);
    ASSERT_EQ(dynamicArray->data[0], 2);
    ASSERT_EQ(dynamicArray->data[1], 3);
    ASSERT_EQ(dynamicArray->data[2], 1);
}

TEST(DynamicArray, InsertNegativeIndex) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    ASSERT_DEATH( { Insert(dynamicArray, 3, -1); }, "Out of bounds: length=0 index=-1" );
}

TEST(DynamicArray, InsertOutOfBounds) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    ASSERT_DEATH( { Insert(dynamicArray, 3, 1); }, "Out of bounds: length=0 index=1" );
}

TEST(DynamicArray, GetElement) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 3);
    ASSERT_EQ(Get(dynamicArray, 0), 3);
}

TEST(DynamicArray, GetNegativeBounds) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    ASSERT_DEATH( { Get(dynamicArray, -1); }, "Out of bounds: length=0 index=-1");
}

TEST(DynamicArray, GetOutOfBounds) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    ASSERT_DEATH( { Get(dynamicArray, 0); }, "Out of bounds: length=0 index=0");
}

TEST(DynamicArray, DeleteElementAtHead) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 3);
    Delete(dynamicArray, 0);
    ASSERT_EQ(dynamicArray->length, 0);
    ASSERT_EQ(dynamicArray->capacity, 3);
}

TEST(DynamicArray, DeleteElementInMiddle) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 2);
    Add(dynamicArray, 3);
    Add(dynamicArray, 1);
    Delete(dynamicArray, 1);
    ASSERT_EQ(dynamicArray->length, 2);
    ASSERT_EQ(dynamicArray->capacity, 3);
    ASSERT_EQ(dynamicArray->data[0], 2);
    ASSERT_EQ(dynamicArray->data[1], 1);
}

TEST(DynamicArray, DeleteElementAtTail) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    Add(dynamicArray, 2);
    Add(dynamicArray, 3);
    Add(dynamicArray, 1);
    Delete(dynamicArray, 2);
    ASSERT_EQ(dynamicArray->length, 2);
    ASSERT_EQ(dynamicArray->capacity, 3);
    ASSERT_EQ(dynamicArray->data[0], 2);
    ASSERT_EQ(dynamicArray->data[1], 3);    
}

TEST(DynamicArray, DeleteNegativeBounds) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    ASSERT_DEATH( { Delete(dynamicArray, -1); }, "Out of bounds: length=0 index=-1");
}

TEST(DynamicArray, DeleteOutOfBounds) {
    DynamicArray *dynamicArray;
    Initialise(&dynamicArray);
    ASSERT_DEATH( { Delete(dynamicArray, 0); }, "Out of bounds: length=0 index=0");
}