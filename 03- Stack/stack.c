#include "stack.h"
#include <stdlib.h>
#include <string.h>

// Define a macro for the initial capacity if not provided.
#define INITIAL_CAPACITY 10

// Function to create and initialize a new stack.
Stack *create_stack(size_t initial_capacity)
{
    if (initial_capacity == 0)
        initial_capacity = INITIAL_CAPACITY;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL; // Allocation failed.
    stack->data = (StackElement *)malloc(initial_capacity * sizeof(StackElement));
    if (stack->data == NULL)
    {
        free(stack);
        return NULL; // Memory allocation failed
    }
    stack->capacity = initial_capacity;
    stack->size = 0;
    return stack;
}

// Function to destroy the stack.
void destroy_stack(Stack *stack)
{
    if (stack != NULL)
    {
        // Free the data inside the stack then free the stack itself.
        free(stack->data);
        free(stack);
    }
}

// Function to push element to our stack.
int stack_push(Stack *stack, StackElement element)
{
    if (stack->size >= stack->capacity)
    {
        // Resize the stack if it's full.
        if (stack_resize(stack, stack->capacity * 2) != 0)
            return -1; // Failed to resize the stack.
    }
    stack->data[stack->size++] = element;
    return 0; // SUCCESS
}

// Function to pop an element from our stack.
StackElement stack_pop(Stack *stack)
{
    if (stack->size == 0)
        return NULL; // Our stack is empty.
    return stack->data[--stack->size];
}

// Function to return the top element without removing it.
StackElement stack_peek(const Stack *stack)
{
    if (stack->size == 0)
        return NULL;
    return stack->data[stack->size - 1];
}

// Check if the stack is empty.
int stack_is_empty(const Stack *stack)
{
    return stack->size == 0;
}

// Get current size of the stack.
size_t stack_size(const Stack *stack)
{
    return stack->size;
}

// Funcion to resize our stack to add more elements.
int stack_resize(Stack *stack, size_t new_capacity)
{
    if (new_capacity <= stack->capacity)
        return 0; // We need bigger capacity.
    StackElement *new_data = (StackElement *)realloc(stack->data, new_capacity * sizeof(StackElement));
    if (new_data == NULL)
        return -1; // MEMEORY ALLOCATION FAILED.
    stack->data = new_data;
    stack->capacity = new_capacity;
    return 0; // SUCCESS.
}