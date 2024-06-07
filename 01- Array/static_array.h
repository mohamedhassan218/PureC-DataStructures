#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <stddef.h>

#define MAX_SIZE 100

typedef struct
{
    // Array of void pointers to hold our elements.
    void *elements[MAX_SIZE];

    // The size of each element.
    size_t element_size;

    // Current number of elements in the array.
    size_t length;
} StaticArray;

void static_array_init(StaticArray *array, size_t element_size);

int static_array_add(StaticArray *array, const void *element);

void *static_array_get(StaticArray *array, size_t index);

int static_array_remove(StaticArray *array, size_t index);

size_t static_array_size(const StaticArray *array);

void static_array_clear(StaticArray *array);

#endif STATIC_ARRAY_H