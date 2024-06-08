#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

// Define the structure for a node in the doubly linked-list.
typedef struct DNode
{
    void *data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

// Define the structure for the doubly linked list.
typedef struct
{
    DNode *head;
    DNode *tail;
    size_t element_size; // Size of each element.
} DoublyLinkedList;

void init_dlist(DoublyLinkedList *list, size_t element_size);

void destroy_dlist(DoublyLinkedList *list);

void insert_beginning(DoublyLinkedList *list, void *data);

void insert_end(DoublyLinkedList *list, void *data);

void delete_value(DoublyLinkedList *list, void *data, int (*compare_func)(void *, void *));

DNode *search_dlist(DoublyLinkedList *list, void *data, int (*compare_func)(void *, void *));

void print_dlist(DoublyLinkedList *list, void (*print_func)(void *));

void insert_before(DoublyLinkedList *list, DNode *node, void *data);

void insert_after(DoublyLinkedList *list, DNode *node, void *data);

DNode *create_dnode(void *data, size_t element_size);

#endif
