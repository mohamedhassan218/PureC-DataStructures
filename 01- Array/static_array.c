#include "static_array.h"
#include <stdlib.h>
#include <string.h>

// Function to initialize our array.
void static_array_init(StaticArray *array, size_t element_size)
{
    array->element_size = element_size;
    array->length = 0;
}

// Function to add element to our array.
int static_array_add(StaticArray *array, const void *element)
{
    if (array->length >= MAX_SIZE)
        return -1;
    void *new_element = malloc(array->element_size);
    if (new_element == NULL)
        return -1; // Memory allocation failed.
    memcpy(new_element, element, array->element_size);
    array->elements[array->length] = new_element;
    array->length++;
    return 0; // Sucess.
}

// Function to get a specific element from the array.
void *static_array_get(StaticArray *array, size_t index)
{
    if (index >= array->length)
    {
        return NULL;
    }
    return array->elements[index];
}

// Fucntion to get the length of the elements in the array.
size_t static_array_size(const StaticArray *array)
{
    return array->length;
}

// Function to remove a specific element from the array.
int static_array_remove(StaticArray *array, size_t index)
{
    if (index >= array->length)
        return -1; // Index out of bounds.
    free(array->elements[index]);
    for (size_t i = index; i < array->length - 1; i++)
        array->elements[i] = array->elements[i + 1]; // Shift elements.
    array->length--;
    return 0;
}

// Function to clear the content of our array.
void static_array_clear(StaticArray *array)
{
    for (size_t i = 0; i < array->length; i++)
        free(array->elements[i]); // Free each element.

    array->length = 0;
}