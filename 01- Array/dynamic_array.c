#include "dynamic_array.h"
#include <stdlib.h>
#include <string.h>

// Function to initialize our array.
void dynamic_array_init(DynamicArray *array, size_t element_size)
{
    array->element_size = element_size;
    array->length = 0;
    array->capacity = INITIAL_CAPACITY;
    array->elements = malloc(array->capacity * sizeof(void *));
}

// Function to add new alement to our array.
int dynamic_array_add(DynamicArray *array, const void *element)
{
    if (array->length >= array->capacity)
    {
        // Double the capacity.
        size_t new_capacity = array->capacity * 2;
        void **new_elements = realloc(array->elements, new_capacity * sizeof(void *));
        if (new_elements == NULL)
            return -1;
        array->elements = new_elements;
        array->capacity = new_capacity;
    }

    void *new_element = malloc(array->element_size);
    if (new_element == NULL)
        return -1;

    memcpy(new_element, element, array->element_size);
    array->elements[array->length] = new_element;
    array->length++;
    return 0;
}

// Function to get an element from our array.
void *dynamic_array_get(DynamicArray *array, size_t index)
{
    if (index >= array->length)
        return NULL;
    return array->elements[index];
}

// Function to remove a specific element.
int dynamic_array_remove(DynamicArray *array, size_t index)
{
    if (index >= array->length)
        return -1;
    free(array->elements[index]);
    for (size_t i = index; i < array->length - 1; i++)
        array->elements[i] = array->elements[i + 1]; // Shift items.
    array->length--;
    return 0;
}

// Function to get the number of elements in the array.
size_t dynamic_array_size(const DynamicArray *array)
{
    return array->length;
}

// Function to free our array.
void dynamic_array_free(DynamicArray *array)
{
    for (size_t i = 0; i < array->length; i++)
        free(array->elements[i]);
    array->length = 0;
    free(array->elements);
    array->elements = NULL;
    array->capacity = 0;
}