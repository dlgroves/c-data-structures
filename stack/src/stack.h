#ifndef STACK
#define STACK
typedef struct stackElem {
    int data;
    struct stackElem *next;
} StackElem;

typedef struct stack {
    StackElem *top;
} Stack;

void Push(Stack **, int);
int Pop(Stack **);
#endif