#ifndef STACK_H
#define STACK_H

#include <stddef.h>

// Define a generic type for the stack.
typedef void *StackElement;

typedef struct Stack
{
    StackElement *data; // Array of elements
    size_t capacity;    // Current capacity of the stack
    size_t size;        // Current size of the stack
} Stack;

Stack *create_stack(size_t initial_capacity);

void destroy_stack(Stack *stack);

int stack_push(Stack *stack, StackElement element);

StackElement stack_pop(Stack *stack);

StackElement stack_peek(const Stack *stack);

int stack_is_empty(const Stack *stack);

size_t stack_size(const Stack *stack);

int stack_resize(Stack *stack, size_t new_capacity);

#endif
