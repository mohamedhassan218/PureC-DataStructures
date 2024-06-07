#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

#define INITIAL_CAPACITY 10

typedef struct
{
    void **elements;
    size_t element_size;
    size_t length;
    size_t capacity;
} DynamicArray;

void dynamic_array_init(DynamicArray *array, size_t element_size);

int dynamic_array_add(DynamicArray *array, const void *element);

void *dynamic_array_get(DynamicArray *array, size_t index);

int dynamic_array_remove(DynamicArray *array, size_t index);

size_t dynamic_array_size(const DynamicArray *array);

void dynamic_array_free(DynamicArray *array);

#endif DYNAMIC_ARRAY_H