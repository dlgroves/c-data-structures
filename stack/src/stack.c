#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Push(Stack **stack, int data){
    if(*stack == NULL){
        *stack = (Stack *)malloc(sizeof(Stack));;
        if(*stack == NULL) {
            fprintf(stderr, "Failed to allocate %zu bytes; exiting...\n", sizeof(Stack));
            exit(1);
        }
        (*stack)->top = NULL;
    }
    StackElem *top = (*stack)->top;
    (*stack)->top = (StackElem *)malloc(sizeof(StackElem));
    if((*stack)->top == NULL) {
        fprintf(stderr, "Failed to allocate %zu bytes; exiting...\n", sizeof(Stack));
        exit(1);
    }
    (*stack)->top->data = data;
    (*stack)->top->next = top;
}

int Pop(Stack **stack){
    if(stack == NULL || *stack == NULL || (*stack)->top == NULL){
        fprintf(stderr, "Tried to pop an empty stack\n");
        exit(1);
    }
    StackElem *topElem = (*stack)->top;
    int result = topElem->data;
    (*stack)->top = topElem->next;
    free(topElem);
    return result;
}