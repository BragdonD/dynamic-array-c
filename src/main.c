#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char const *argv[])
{
    array* arr = init_arr();
    empty_arr(arr);
    free(arr);
    return 0;
}
