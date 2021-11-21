#include "gtest/gtest.h"
#include "../src/stack.h"

TEST(Stack, PushOntoEmptyStack) {
    Stack *stack = NULL;
    Push(&stack, 3);
    ASSERT_EQ(stack->top->data, 3);
    ASSERT_EQ(stack->top->next, nullptr);
}

TEST(Stack, PushOntoNonEmptyStack) {
    Stack *stack = NULL;
    Push(&stack, 3);
    Push(&stack, 5);
    ASSERT_EQ(stack->top->data, 5);
    ASSERT_EQ(stack->top->next->data, 3);
}

TEST(Stack, PopNullStack) {
    ASSERT_DEATH( { Pop(NULL); }, "Tried to pop an empty stack");
}

TEST(Stack, PopEmptyStack) {
    Stack *stack = NULL;
    ASSERT_DEATH( { Pop(&stack); }, "Tried to pop an empty stack");
}

TEST(Stack, PopStackWithNullHead) {
    Stack *stack = NULL;
    Push(&stack, 0);
    Pop(&stack);
    ASSERT_DEATH( { Pop(&stack); }, "Tried to pop an empty stack");
}

TEST(Stack, PopStack) {
    Stack *stack = NULL;
    Push(&stack, 3);
    ASSERT_EQ(Pop(&stack), 3);
}