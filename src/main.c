#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "ui.h"

int main(int argc, char const *argv[])
{
    array* arr = init_arr();
    int choice = -1;

    do
    {
beginning:
        Menu();
        choice = Choice();
        switch (choice)
        {
        case 1:
        {
            int new_elem = 0, pos = 0;
            printf("Write the new element : ");
            if(!getInt(&new_elem)) {
                printf("Wrong input!");
                goto beginning;
            }
            printf("Write the position of the new element : ");
            if(!getInt(&pos)) {
                printf("Wrong input!");
                goto beginning;
            }
            if(!insert_into_arr(arr, new_elem, pos)) {
                printf("Failed to insert into array at position %d. Make sure it is in bound of the array length.\n", pos);
            }
            break;
        }
        case 2:
        {
            int pos = 0;
            printf("Write the position of the element to be deleted : ");
            if(!getInt(&pos)) {
                printf("Wrong input!");
                goto beginning;
            }
            if(!delete_into_arr(arr, pos)) {
                printf("Failed to delete into array at position %d. Make sure it is in bound of the array length.\n", pos);
            }
            break;
        }
        case 3:
        {
            printf("The length of the array is %d.\n", arr_lenght(arr));
            break;
        }
        case 4:
        {
            if(!empty_arr(arr)) {
                printf("The array is already empty.\n");
            }
            break;
        }
        case 5:
            print_arr(arr);
            break;
        case 6:
            printf("You're leaving the program.");
            break;
        default:
            printf("This is not a valid choice.\n");
            break;
        }
    } while (choice != 6);
    empty_arr(arr);
    free(arr);
    return 0;
}
