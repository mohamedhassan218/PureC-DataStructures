#include "circular_queue.h"
#include <stdlib.h>

// Function to create a circualr queue.
CircularQueue *create_queue(size_t capacity)
{
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    if (!queue)
        return NULL; // ALLOCATION FAILED :(
    queue->elements = (QueueElement *)malloc(capacity * sizeof(QueueElement));
    if (!queue->elements)
    {
        free(queue);
        return NULL;
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = capacity - 1;
    queue->size = 0;
    return queue;
}

// Function to destroy our queue.
void destroy_queue(CircularQueue *queue)
{
    if (queue)
    {
        free(queue->elements);
        free(queue);
    }
}

// Check if the queue if full.
bool is_full(CircularQueue *queue)
{
    return queue->size == queue->capacity;
}

// Check if the queue is empty.
bool is_empty(CircularQueue *queue)
{
    return queue->size == 0;
}

// Function to add alement to our queue.
bool enqueue(CircularQueue *queue, QueueElement element)
{
    if (is_full(queue))
        return false;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = element;
    queue->size++;
    return true;
}

// Function to remove an element from our queue.
QueueElement dequeue(CircularQueue *queue)
{
    if (is_empty(queue))
        return NULL;

    QueueElement element = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return element;
}

// Get the front element.
QueueElement front(CircularQueue *queue)
{
    if (is_empty(queue))
        return NULL;
    return queue->elements[queue->front];
}

// Get the rear element.
QueueElement rear(CircularQueue *queue)
{
    if (is_empty(queue))
        return NULL;
    return queue->elements[queue->rear];
}