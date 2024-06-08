#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

// Structure for queue node
typedef struct QueueNode
{
    void *data;
    struct QueueNode *next;
} QueueNode;

// Structure for queue
typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
    size_t size;
    size_t data_size; // Size of each data element
} Queue;

Queue *create_queue(size_t data_size);

void destroy_queue(Queue *queue);

int enqueue(Queue *queue, const void *data);

int dequeue(Queue *queue, void *data);

size_t queue_size(const Queue *queue);

int is_queue_empty(const Queue *queue);

#endif
