#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

// Define the structure for a node in the linked-list.
typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

// Define the structure for the linked list.
typedef struct
{
    Node *head;
    size_t element_size;
} SinglyLinkedList;

void init_list(SinglyLinkedList *list, size_t element_size);

void destroy_list(SinglyLinkedList *list);

void insert_beginning(SinglyLinkedList *list, void *data);

void insert_end(SinglyLinkedList *list, void *data);

void delete_value(SinglyLinkedList *list, void *data, int (*compare_func)(void *, void *));

Node *search_list(SinglyLinkedList *list, void *data, int (*compare_func)(void *, void *));

void print_list(SinglyLinkedList *list, void (*print_func)(void *));

Node *create_node(void *data, size_t element_size);

#endif
