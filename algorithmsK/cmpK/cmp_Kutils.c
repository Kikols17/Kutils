#ifndef CMP_KUTILS_C
#define CMP_KUTILS_C

#include <stdlib.h>
#include <string.h>

#include "cmp_Kutils.h"


/* Standard comparison functions */
int intcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two integers
     *
     *      INPUTS:
     *          a: pointer to the first integer
     *          b: pointer to the second integer
     *          datatype_size: size of the integers
     *
     *      OUTPUT:
     *          -1 if the first integer is less than the second
     *          0 if the integers are equal
     *          1 if the first integer is greater than the second
     *
     */
    //return -((*(int *)a)<(*(int *)b)) + ((*(int *)a)>(*(int *)b));
    if (*(int *)a == *(int *)b) {
        return 0;
    } else if (*(int *)a < *(int *)b) {
        return -1;
    } else {
        return 1;
    }
}

int doublecmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two doubles
     *
     *      INPUTS:
     *          a: pointer to the first double
     *          b: pointer to the second double
     *          datatype_size: size of the doubles
     *
     *      OUTPUT:
     *          -1 if the first double is less than the second
     *          0 if the doubles are equal
     *          1 if the first double is greater than the second
     *
     */
    //return -((*(double *)a)<(*(double *)b)) + ((*(double *)a)>(*(double *)b));
    if (*(double *)a == *(double *)b) {
        return 0;
    } else if (*(double *)a < *(double *)b) {
        return -1;
    } else {
        return 1;
    }
}

int charcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two characters
     *
     *      INPUTS:
     *          a: pointer to the first character
     *          b: pointer to the second character
     *          datatype_size: size of the characters
     *
     *      OUTPUT:
     *          -1 if the first character is less than the second
     *          0 if the characters are equal
     *          1 if the first character is greater than the second
     *
     */
    //return -((*(char *)a)<(*(char *)b)) + ((*(char *)a)>(*(char *)b));
    if (*(char *)a == *(char *)b) {
        return 0;
    } else if (*(char *)a < *(char *)b) {
        return -1;
    } else {
        return 1;
    }
}

int bincmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two structs based on their binary values
     *
     *      INPUTS:
     *          a: pointer to the first binary value
     *          b: pointer to the second binary value
     *          datatype_size: size of the binary values
     *
     *      OUTPUT:
     *          -1 if the first binary value is less than the second
     *          0 if the binary values are equal
     *          1 if the first binary value is greater than the second
     *
     */
    return memcmp(a, b, datatype_size);
}




#endif