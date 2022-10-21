#include <stdlib.h>
#include <string.h>
#include "array.h"

array* arr_init(size_t data_size) {
    array* temp = NULL;
    temp = malloc(sizeof *temp);
    if(temp == NULL) return NULL;
    temp->arr = NULL;
    temp->data_size = data_size;
    temp->length = 0;
    return temp;
}

size_t arr_lenght(array* arr) {
    return arr->length;
}

void* arr_front(array* arr) {
    return (char*)(arr->arr);
}

void* arr_end(array* arr) {
    return (char*)(arr->arr) + ((arr->length - 1) * arr->data_size);
}

bool arr_push_back(array* arr, void* elem) {
    void* temp = NULL;
    temp = realloc(arr->arr, arr->data_size * (arr->length + 1));
    if(temp == NULL) return false;
    arr->arr = temp;
    memcpy(((char*) arr->arr) + (arr->length) * arr->data_size, elem, arr->data_size);
    arr->length = arr->length + 1;
    return true;
}

void* arr_pop_back(array* arr) {
    void* temp = NULL;
    void *data = NULL;
    if(arr == NULL) return NULL;
    if(arr->length = 0) return NULL;
    data = arr_end(arr);
    temp = realloc(arr->arr, (arr->length - 1) * arr->data_size);
    if(temp == NULL) return NULL;
    arr->arr = temp;
    arr->length = arr->length - 1;
    return data;
}

bool arr_insert(array* arr, int index, void* elem) {
    if(index > arr->length) return false;

    void* temp = NULL;
    temp = realloc(arr->arr, (arr->length + 1) * arr->data_size);
    if(temp == NULL) return false;

    for(int j=index; j<arr->length; j++) {
        void* after = ((char*) temp) + (j+1) * arr->data_size;
        void* before = ((char*) temp) + (j) * arr->data_size;
        memcpy(after, before, arr->data_size);
    }
    memcpy(((char*) temp) + (index) * arr->data_size, elem, arr->data_size);
    arr->arr = temp;
    arr->length += 1;
    return true;
}

void* arr_erase(array* arr, int index) {
    if(arr->length == 0) return false;
    if(index < arr->length && index > 0) return false;

    void* temp = NULL;
    temp = realloc(arr->arr, (arr->length - 1) * arr->data_size);
    if(temp == NULL) return false;

    for(int j=index; j<arr->length-1; j++) {
        void* after = ((char*) arr->arr) + (j+1) * arr->data_size;
        void* before = ((char*) temp) + (j) * arr->data_size;
        memcpy(before, after, arr->data_size);
    }
    arr->arr = temp;
    arr->length -= 1;
    return true;
}

void arr_swapp(array* arr1, array* arr2);

void arr_empty(array* arr) {
    arr->length = 0;
}

bool arr_is_empty(array* arr) {
    return (arr->length == 0);
}

array* linkedList_create_from_list(void* arr, int len, size_t type_size) {
    array* temp = arr_init(type_size);
    if(temp == NULL) return NULL;
    for(int i=1; i<len; i++) {
        arr_push_back(arr, (((char*)arr) + (i) * temp->data_size));
    }
    return temp;
}