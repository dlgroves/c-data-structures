#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Enqueue(Queue **theQueue, int elem) {
    if(theQueue == NULL) {
        fprintf(stderr, "Tried to enqueue onto a null queue\n");
        exit(1);
    }
    QueueElem *result = (QueueElem *)malloc(sizeof(QueueElem));
    if(result == NULL) {
        fprintf(stderr, "Failed to allocate %zu bytes of memory, exiting...", sizeof(QueueElem));
        exit(2);
    }
    result->data = elem;
    result->next = NULL;
    result->prev = NULL;

    if(*theQueue == NULL){
        *theQueue = (Queue *)malloc(sizeof(Queue));
        if(*theQueue == NULL) {
            fprintf(stderr, "Failed to allocate %zu bytes of memory, exiting...\n", sizeof(Queue));
            exit(2);
        }
        (*theQueue)->front = result;
    }else if((*theQueue)->front == NULL) {
        (*theQueue)->front = result;
    }else{
        (*theQueue)->back->prev = result;
        result->next = (*theQueue)->back;
    }
    (*theQueue)->back = result;
}

int Dequeue(Queue **theQueue) {
    if(theQueue == NULL || *theQueue == NULL || (*theQueue)->front == NULL){
        fprintf(stderr, "Tried to dequeue from an empty queue\n");
        exit(1);
    }
    QueueElem *frontElem = (*theQueue)->front;
    int result = frontElem->data;
    (*theQueue)->front = frontElem->prev;
    if((*theQueue)->front == NULL){
        (*theQueue)->back = NULL;
    }
    free(frontElem);
    return result;
}