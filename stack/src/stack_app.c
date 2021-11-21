#include "stack.h"

int main(void){
    Stack *stack = NULL;
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    printf("%d\n", Pop(&stack));
    printf("%d\n", Pop(&stack));
    printf("%d\n", Pop(&stack));
    free(stack);
    return 0;
}
