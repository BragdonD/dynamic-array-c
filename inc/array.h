#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

typedef struct array {
    void* arr;
    size_t data_size;
    size_t length;
} array;

array* arr_init(size_t data_size);
size_t arr_lenght(array* arr);
bool arr_push_back(array* arr, void* elem);
void* arr_pop_back(array* arr);
bool arr_insert(array* arr, int index, void* elem);
void* arr_erase(array* arr, int index);
void arr_swapp(array* arr1, array* arr2);
void arr_empty(array* arr);
void* arr_front(array* arr);
void* arr_end(array* arr);
bool arr_is_empty(array* arr);
array* linkedList_create_from_list(void* arr, int len, size_t type_size);

#endif
