#include "gtest/gtest.h"
#include "../src/hashtable.h"

TEST(HashTable, CanBeInitialised){
    HashTable *hashTable;
    Initialise(&hashTable, 3);
    ASSERT_NE(hashTable, nullptr);
    ASSERT_EQ(hashTable->size, 3);
    for(int i = 0; i < hashTable->size; i++) {
        ASSERT_EQ(hashTable->table[i], nullptr);
    }
}

TEST(HashTable, CanBeDestroyed) {
    HashTable *hashTable;
    Initialise(&hashTable, 3);
    Destroy(&hashTable);
    ASSERT_EQ(hashTable, nullptr);
}

TEST(HashTable, CanInsert) {
    HashTable *hashTable;
    Initialise(&hashTable, 1);
    Insert(hashTable, "greeting", "hello");
    ASSERT_EQ(hashTable->table[0]->key, "greeting");
    ASSERT_EQ(hashTable->table[0]->value, "hello");
}

TEST(HashTable, CanRetrieve) {
    HashTable *hashTable;
    Initialise(&hashTable, 1);
    Insert(hashTable, "greeting", "hello");
    char *result = Get(hashTable, "greeting");
    ASSERT_EQ(result, "hello");
}

TEST(HashTable, CanRetrieveFromCollision) {
    HashTable *hashTable;
    Initialise(&hashTable, 1);
    Insert(hashTable, "greeting", "hello");
    Insert(hashTable, "subject", "world");
    char *result = Get(hashTable, "subject");
    ASSERT_EQ(result, "world");
}

TEST(HashTable, CanOverwrite) {
    HashTable *hashTable;
    Initialise(&hashTable, 1);
    Insert(hashTable, "greeting", "hello");
    Insert(hashTable, "greeting", "howdy");
    char *result = Get(hashTable, "greeting");
    ASSERT_EQ(result, "howdy");
}

TEST(HashTable, CanOverwriteCollision) {
    HashTable *hashTable;
    Initialise(&hashTable, 1);
    Insert(hashTable, "greeting", "hello");
    Insert(hashTable, "subject", "world");
    Insert(hashTable, "subject", "universe");
    char *result = Get(hashTable, "subject");
    ASSERT_EQ(result, "universe");
}

TEST(HashTable, ErrorsInsertingIntoNull) {
    ASSERT_DEATH({ Insert(NULL, "greeting", "hello"); }, "Tried to insert into a null table");
}

TEST(HashTable, ErrorsFetchingFromNull) {
    ASSERT_DEATH({ Get(NULL, "greeting"); }, "Tried to fetch from a null table");
}