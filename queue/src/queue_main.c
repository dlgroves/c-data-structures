#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
    Queue *queue = NULL;
    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    printf("%d\n", Dequeue(&queue));
    printf("%d\n", Dequeue(&queue));
    printf("%d\n", Dequeue(&queue));
    free(queue);
}
