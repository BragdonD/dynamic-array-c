#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char const *argv[])
{
    array* arr = arr_init(sizeof(int));
    arr_empty(arr);
    free(arr);
    return 0;
}
