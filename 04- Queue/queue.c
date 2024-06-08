#include <stdlib.h>
#include <string.h>
#include "queue.h"

// Initialize our queue.
Queue *create_queue(size_t data_size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
        return NULL; // Allocation failed.
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    queue->data_size = data_size;
    return queue;
}

// Destroy the queue and free memry
void destroy_queue(Queue *queue)
{
    // We free each element in the queue then free the queue poniter itself.
    while (!is_queue_empty(queue))
    {
        void *data = malloc(queue->data_size);
        if (data)
        {
            dequeue(queue, data);
            free(data);
        }
    }
    free(queue);
}

// Enqueue data into our queue.
int enqueue(Queue *queue, const void *data)
{
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!new_node)
        return -1; // Allocation failed.
    new_node->data = malloc(queue->data_size);
    if (!new_node->data)
    {
        free(new_node);
        return -1; // Allocation failed.
    }

    // REMEMBER: memcpy(destination, source, data_size)
    memcpy(new_node->data, data, queue->data_size);
    new_node->next = NULL;

    if (queue->rear)
        queue->rear->next = new_node; // Link the current last node's next pointer to the new node.

    // Update the rear pointer to point to the new node.
    queue->rear = new_node;

    if (!queue->front)
        queue->front = new_node; // Made the front pointer points to the new node in case of the queue was empty.
    queue->size++;
    return 0; // SUCCESS
}

// Dequeue data from our queue.
int dequeue(Queue *queue, void *data)
{
    if (is_queue_empty(queue))
        return -1;

    // FIRST IN FIRST OUT :D
    QueueNode *temp = queue->front;
    memcpy(data, temp->data, queue->data_size);
    queue->front = queue->front->next;
    if (!queue->front)
        queue->rear = NULL;
    free(temp->data);
    free(temp);
    queue->size--;
    return 0; // Success
}

// Get the size of the queue.
size_t queue_size(const Queue *queue)
{
    return queue->size;
}

// Check if the queue is empty.
int is_queue_empty(const Queue *queue)
{
    return (queue->size == 0);
}
