#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef void *QueueElement;

typedef struct
{
    QueueElement *elements;
    size_t capacity;
    size_t front;
    size_t rear;
    size_t size;
} CircularQueue;

CircularQueue *create_queue(size_t capacity);

void destroy_queue(CircularQueue *queue);

bool is_full(CircularQueue *queue);

bool is_empty(CircularQueue *queue);

bool enqueue(CircularQueue *queue, QueueElement element);

QueueElement dequeue(CircularQueue *queue);

QueueElement front(CircularQueue *queue);

QueueElement rear(CircularQueue *queue);

#endif
