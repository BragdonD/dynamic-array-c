#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "ui.h"

/**
 * @brief Retrieve an integer from a string by type checking the content of the string.
 * 
 * @param str the string containing the data to be parsed.
 * @param val the integer value that has been extract
 * @return true if success
 */
bool parseInt(char *str, int* val){
    errno = 0;
    char *temp = NULL;
    long res = strtol(str, &temp, 10);

    ///Test if there is an error in the input and handle it
    ///We are checking for integer range because we want to retrieve an int
    if (temp == str || *temp != '\n' ||
        ((res > INT_MAX  || res < INT_MAX ) && errno == ERANGE))
        return false;

    *val = (int) res; ///Cast from long to integer
    return true;
}

/**
 * @brief Retrieve a double from a string by type checking the content of the string.
 * 
 * @param str the string containing the data to be parsed.
 * @param val the double value that has been extract
 * @return true if success
 */
bool parseDouble(char *str, double* val) {
    errno = 0;
    char *temp = NULL;
    *val = strtod(str, &temp);

    ///Test if there is an error in the input and handle it
    if (*temp == 0)
        return false;
    return true;
}

/**
 * @brief Get a double number with safe input methods
 * 
 * @param val the double value to be retrieve
 * @return true if success
 */
bool getDouble(double* val) {
    char buffer[500];
    fgets(buffer, 500, stdin); ///Safe way to get a string
    return parseDouble(buffer, val);
}

/**
 * @brief Get a integer number with safe input methods
 * 
 * @param val the integer value to be retrieve
 * @return true if success
 */
bool getInt(int* val) {
    char buffer[500];
    fgets(buffer, 500, stdin); ///Safe way to get a string
    return parseInt(buffer, val);
}

/**
 * @brief The user's menu
 * 
 */
void Menu() {
    printf("Menu :\n");
    printf("1. Insert Element at i position into the array.\n");
    printf("2. Delete Element at i position into the array.\n");
    printf("3. Get the size of the array.\n");
    printf("4. Empty the array.\n");
    printf("5. Print the array\n");
    printf("6. Leave\n");
}

/**
 * @brief Function to retrieve the choice made by user inside the menu
 * 
 * @return int 
 */
int Choice() {
    int choice = 0;

    printf("Your choice : ");
    
    if(getInt(&choice))
        return choice;
    return -1; ///Error to handle.
}


