#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stdio.h>

typedef int array_type;

typedef struct array {
    array_type* arr;
    int length;
} array;

array* init_arr();
int arr_lenght(array* arr);
bool insert_into_arr(array* arr, int elem, int i);
bool delete_into_arr(array* arr, int i);
bool empty_arr(array* arr);
void print_arr(array* arr); ///Need to be edited each time the type is changed.

#endif