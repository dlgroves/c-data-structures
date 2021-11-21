#ifndef QUEUE
#define QUEUE

typedef struct queueElem {
    int data;
    struct queueElem *next;
    struct queueElem *prev;
} QueueElem;

typedef struct queue {
    QueueElem *front;
    QueueElem *back;
} Queue;

void Enqueue(Queue **queue, int elem);
int Dequeue(Queue **queue);

#endif