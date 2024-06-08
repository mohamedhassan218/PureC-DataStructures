#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize our doubley linked-list.
void init_dlist(DoublyLinkedList *list, size_t element_size, void (*free_func)(void *))
{
    list->head = NULL;
    list->tail = NULL;
    list->element_size = element_size;
}

// Destroy our list.
void destroy_dlist(DoublyLinkedList *list)
{
    DNode *current = list->head;
    DNode *next;

    // Loop until we reach the last node.
    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

// Create a new node.
DNode *create_dnode(void *data, size_t element_size)
{
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = malloc(element_size);
    memcpy(new_node->data, data, element_size);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Insert an element at the beginning of the list.
void insert_beginning(DoublyLinkedList *list, void *data)
{
    DNode *new_node = create_dnode(data, list->element_size);

    // Made the next of the new node points to what the head points to.
    new_node->next = list->head;

    if (list->head != NULL)
        list->head->prev = new_node;
    else // Means that that list was empty.
        list->tail = new_node;

    // Made the head points to the new node.
    list->head = new_node;

    // REMEMBER THAT THIS IS NOT A CIRCULAR LINKED-LIST.
}

// Insert an element at the end of the list.
void insert_end(DoublyLinkedList *list, void *data)
{
    DNode *new_node = create_dnode(data, list->element_size);
    new_node->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = new_node;
    else
        list->head = new_node;

    list->tail = new_node;
}

// Delete an element from the list by value.
void delete_value(DoublyLinkedList *list, void *data, int (*compare_func)(void *, void *))
{
    // Start from the head of the list.
    DNode *current = list->head;

    // Loop on the list until we reach the end.
    while (current != NULL)
    {
        // If the current node's data matches the data we want to delete.
        if (compare_func(data, current->data) == 0)
        {
            // If the current node is not the head, update the previous node's next pointer.
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                // If the current node is the head, update the list's head.
                list->head = current->next;

            // If the current node is not the tail, update the next node's previous pointer.
            if (current->next != NULL)
                current->next->prev = current->prev;
            else
                // If the current node is the tail, update the list's tail.
                list->tail = current->prev;

            // Free the data of the current node.
            free(current->data);

            // Free the current node.
            free(current);

            // Return from the function as we have deleted the node.
            return;
        }
        // Move to the next node.
        current = current->next;
    }
}

// Search for an element in the list.
// We assume that the user wil provide his own compare helper method.
DNode *search_dlist(DoublyLinkedList *list, void *data, int (*compare_func)(void *, void *))
{
    DNode *current = list->head;
    while (current != NULL)
    {
        if (compare_func(data, current->data) == 0)
            return current;
        current = current->next;
    }
    return NULL; // 404 NOT FOUND :(
}

// Print the list.
// We assume that the user wil provide his own print helper method.
void print_dlist(DoublyLinkedList *list, void (*print_func)(void *))
{
    DNode *current = list->head;
    while (current != NULL)
    {
        print_func(current->data);
        current = current->next;
    }
    printf("\n");
}

// Insert an element before a given node
void insert_before(DoublyLinkedList *list, DNode *node, void *data)
{
    if (node == NULL)
        return;
    DNode *new_node = create_dnode(data, list->element_size);
    new_node->next = node;
    new_node->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = new_node;
    else
        list->head = new_node;
    node->prev = new_node;
}

// Insert an element after a given node
void insert_after(DoublyLinkedList *list, DNode *node, void *data)
{
    if (node == NULL)
        return;
    DNode *new_node = create_dnode(data, list->element_size);
    new_node->prev = node;
    new_node->next = node->next;
    if (node->next != NULL)
        node->next->prev = new_node;
    else
        list->tail = new_node;
    node->next = new_node;
}
