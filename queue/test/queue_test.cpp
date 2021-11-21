#include "gtest/gtest.h"
#include "../src/queue.h"

TEST(Queue, EnqueueNullQueue) {
    Queue *queue = NULL;
    Enqueue(&queue, 3);
    ASSERT_EQ(queue->front->data, 3);
}

TEST(Queue, EnqueueEmptyQueue) {
    Queue *queue = NULL;
    Enqueue(&queue, 3);
    Dequeue(&queue);
    Enqueue(&queue, 5);
    ASSERT_EQ(queue->front->data, 5);
}

TEST(Queue, EnqueueNonEmptyQueue) {
    Queue *queue = NULL;
    Enqueue(&queue, 3);
    Enqueue(&queue, 5);
    ASSERT_EQ(queue->front->data, 3);
    ASSERT_EQ(queue->back->data, 5);
}

TEST(Queue, EnqueueMultipleItems) {
    Queue *queue = NULL;
    QueueElem *queueElem = NULL;
    for(int i = 1; i <= 10; i++) {
        Enqueue(&queue, i);
    }
    queueElem = queue->back;
    for(int i = 10; i >= 1; i--) {
        ASSERT_EQ(queueElem->data, i);
        queueElem = queueElem->next;
    }
}

TEST(Queue, ErrorIfNullQueueEnqueued) {
    ASSERT_DEATH( { Enqueue(NULL, 3); }, "Tried to enqueue onto a null queue");
}

TEST(Queue, ErrorIfNullQueueDequeued) {
    ASSERT_DEATH( { Dequeue(NULL); }, "Tried to dequeue from an empty queue");
}

TEST(Queue, ErrorIfEmptyQueueDequeued) {
    Queue *queue = NULL;
    ASSERT_DEATH( { Dequeue(&queue); }, "Tried to dequeue from an empty queue");
}

TEST(Queue, ErrorIfQueueWithNullHeadDequeued) {
    Queue *queue = NULL;
    Enqueue(&queue, 3);
    Dequeue(&queue);
    ASSERT_DEATH( { Dequeue(&queue); }, "Tried to dequeue from an empty queue");
}

TEST(Queue, DequeueFromQueue) {
    Queue *queue = NULL;
    for(int i = 1; i <= 20; i++) {
        Enqueue(&queue, i);
    }
    for(int i = 1; i >= 20; i--) {
        ASSERT_EQ(Dequeue(&queue), i);
    }
}