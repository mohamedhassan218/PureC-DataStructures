#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to initialize our list.
void init_list(SinglyLinkedList *list, size_t element_size)
{
    list->head = NULL;
    list->element_size = element_size;
}

// Destroy the list and free memory
void destroy_list(SinglyLinkedList *list)
{
    Node *current = list->head;
    Node *next;

    // Loop until we reach the last node in the linked-list.
    while (current != NULL)
    {
        // Increment the next pointer to point to the next node.
        next = current->next;

        // Free the current data and then free the node itself.
        free(current->data);
        free(current);

        // Increment the current to point to the same node as next.
        current = next;
    }
    list->head = NULL;
}

// Create a new node with the given data and return it.
Node *create_node(void *data, size_t element_size)
{
    // Allocate address to our new node.
    Node *new_node = (Node *)malloc(sizeof(Node));

    // Allocate space for the data to our new node.
    new_node->data = malloc(element_size);

    // Add data to the data address of the new node.
    memcpy(new_node->data, data, element_size);
    new_node->next = NULL;
    return new_node;
}

// Insert an element at the beginning of the list.
void insert_beginning(SinglyLinkedList *list, void *data)
{
    // Create the node.
    Node *new_node = create_node(data, list->element_size);

    // Made it points to what the head was pointing to.
    new_node->next = list->head;

    // Made the head points to our new node.
    list->head = new_node;
}

// Insert an element at the end of the list.
void insert_end(SinglyLinkedList *list, void *data)
{
    // Create the node itself.
    Node *new_node = create_node(data, list->element_size);

    if (list->head == NULL) // In case of this is the first node to be inserted.
        list->head = new_node;
    else
    {
        // Create current pointer to point to the first node.
        Node *current = list->head;

        // Loop until we reach the last node in the linked-list.
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Made the last node to points to our new node.
        current->next = new_node;
    }
}

// Delete an element from the list by value.
// We assume that the user will configure his own compare helper function.
void delete_value(SinglyLinkedList *list, void *data, int (*compare_func)(void *, void *))
{
    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (compare_func(data, current->data) == 0)
        {
            if (previous == NULL)
                list->head = current->next; // This means that we wanna delete the first node.
            else
                previous->next = current->next;

            // Free the space of the data and after that free the node itself.
            free(current->data);
            free(current);
            return; // STOP
        }

        // Increment our pointers.
        previous = current;
        current = current->next;
    }
}

// Search for an element in the list.
Node *search_list(SinglyLinkedList *list, void *data, int (*compare_func)(void *, void *))
{
    Node *current = list->head;
    while (current != NULL)
    {
        if (compare_func(data, current->data) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

// Print our linked-list.
// We assume that the user will configure his own print helper function.
void print_list(SinglyLinkedList *list, void (*print_func)(void *))
{
    Node *current = list->head;
    while (current != NULL)
    {
        print_func(current->data);
        current = current->next;
    }
    printf("\n");
}
