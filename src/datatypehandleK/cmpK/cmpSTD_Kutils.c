#ifndef CMPSTD_KUTILS_C
#define CMPSTD_KUTILS_C

#include <stdlib.h>
#include <string.h>

#include "cmpSTD_Kutils.h"
#include "../../macro_Kutils.h"


/* This file contains the standard comparison functions for the Kutils library (all the C default datatypes).
 * If you are looking to add custom comparison functions, you can add them to "cmpCST_Kutils.*" files.
 */


/* Standard comparison functions */

// Characters
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
    UNUSED_K(datatype_size);
    //return -((*(char *)a)<(*(char *)b)) + ((*(char *)a)>(*(char *)b));
    if (*(char *)a == *(char *)b) {
        return 0;
    } else if (*(char *)a < *(char *)b) {
        return -1;
    } else {
        return 1;
    }
}

int scharcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two signed characters
     *
     *      INPUTS:
     *          a: pointer to the first signed character
     *          b: pointer to the second signed character
     *          datatype_size: size of the signed characters
     *
     *      OUTPUT:
     *          -1 if the first signed character is less than the second
     *          0 if the signed characters are equal
     *          1 if the first signed character is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(signed char *)a)<(*(signed char *)b)) + ((*(signed char *)a)>(*(signed char *)b));
    if (*(signed char *)a == *(signed char *)b) {
        return 0;
    } else if (*(signed char *)a < *(signed char *)b) {
        return -1;
    } else {
        return 1;
    }
}

int ucharcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two unsigned characters
     *
     *      INPUTS:
     *          a: pointer to the first unsigned character
     *          b: pointer to the second unsigned character
     *          datatype_size: size of the unsigned characters
     *
     *      OUTPUT:
     *          -1 if the first unsigned character is less than the second
     *          0 if the unsigned characters are equal
     *          1 if the first unsigned character is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(unsigned char *)a)<(*(unsigned char *)b)) + ((*(unsigned char *)a)>(*(unsigned char *)b));
    if (*(unsigned char *)a == *(unsigned char *)b) {
        return 0;
    } else if (*(unsigned char *)a < *(unsigned char *)b) {
        return -1;
    } else {
        return 1;
    }
}




// Integers
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
    UNUSED_K(datatype_size);
    //return -((*(int *)a)<(*(int *)b)) + ((*(int *)a)>(*(int *)b));
    if (*(int *)a == *(int *)b) {
        return 0;
    } else if (*(int *)a < *(int *)b) {
        return -1;
    } else {
        return 1;
    }
}

int shintcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two short integers
     *
     *      INPUTS:
     *          a: pointer to the first short integer
     *          b: pointer to the second short integer
     *          datatype_size: size of the short integers
     *
     *      OUTPUT:
     *          -1 if the first short integer is less than the second
     *          0 if the short integers are equal
     *          1 if the first short integer is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(short int *)a)<(*(short int *)b)) + ((*(short int *)a)>(*(short int *)b));
    if (*(short int *)a == *(short int *)b) {
        return 0;
    } else if (*(short int *)a < *(short int *)b) {
        return -1;
    } else {
        return 1;
    }
}

int ushintcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two unsigned short integers
     *
     *      INPUTS:
     *          a: pointer to the first unsigned short integer
     *          b: pointer to the second unsigned short integer
     *          datatype_size: size of the unsigned short integers
     *
     *      OUTPUT:
     *          -1 if the first unsigned short integer is less than the second
     *          0 if the unsigned short integers are equal
     *          1 if the first unsigned short integer is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(unsigned short int *)a)<(*(unsigned short int *)b)) + ((*(unsigned short int *)a)>(*(unsigned short int *)b));
    if (*(unsigned short int *)a == *(unsigned short int *)b) {
        return 0;
    } else if (*(unsigned short int *)a < *(unsigned short int *)b) {
        return -1;
    } else {
        return 1;
    }
}

int uintcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two unsigned integers
     *
     *      INPUTS:
     *          a: pointer to the first unsigned integer
     *          b: pointer to the second unsigned integer
     *          datatype_size: size of the unsigned integers
     *
     *      OUTPUT:
     *          -1 if the first unsigned integer is less than the second
     *          0 if the unsigned integers are equal
     *          1 if the first unsigned integer is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(unsigned int *)a)<(*(unsigned int *)b)) + ((*(unsigned int *)a)>(*(unsigned int *)b));
    if (*(unsigned int *)a == *(unsigned int *)b) {
        return 0;
    } else if (*(unsigned int *)a < *(unsigned int *)b) {
        return -1;
    } else {
        return 1;
    }
}

int lintcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two long integers
     *
     *      INPUTS:
     *          a: pointer to the first long integer
     *          b: pointer to the second long integer
     *          datatype_size: size of the long integers
     *
     *      OUTPUT:
     *          -1 if the first long integer is less than the second
     *          0 if the long integers are equal
     *          1 if the first long integer is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(long int *)a)<(*(long int *)b)) + ((*(long int *)a)>(*(long int *)b));
    if (*(long int *)a == *(long int *)b) {
        return 0;
    } else if (*(long int *)a < *(long int *)b) {
        return -1;
    } else {
        return 1;
    }
}

int ulintcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two unsigned long integers
     *
     *      INPUTS:
     *          a: pointer to the first unsigned long integer
     *          b: pointer to the second unsigned long integer
     *          datatype_size: size of the unsigned long integers
     *
     *      OUTPUT:
     *          -1 if the first unsigned long integer is less than the second
     *          0 if the unsigned long integers are equal
     *          1 if the first unsigned long integer is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(unsigned long int *)a)<(*(unsigned long int *)b)) + ((*(unsigned long int *)a)>(*(unsigned long int *)b));
    if (*(unsigned long int *)a == *(unsigned long int *)b) {
        return 0;
    } else if (*(unsigned long int *)a < *(unsigned long int *)b) {
        return -1;
    } else {
        return 1;
    }
}

int llintcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two long long integers
     *
     *      INPUTS:
     *          a: pointer to the first long long integer
     *          b: pointer to the second long long integer
     *          datatype_size: size of the long long integers
     *
     *      OUTPUT:
     *          -1 if the first long long integer is less than the second
     *          0 if the long long integers are equal
     *          1 if the first long long integer is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(long long int *)a)<(*(long long int *)b)) + ((*(long long int *)a)>(*(long long int *)b));
    if (*(long long int *)a == *(long long int *)b) {
        return 0;
    } else if (*(long long int *)a < *(long long int *)b) {
        return -1;
    } else {
        return 1;
    }
}

int ullintcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two unsigned long long integers
     *
     *      INPUTS:
     *          a: pointer to the first unsigned long long integer
     *          b: pointer to the second unsigned long long integer
     *          datatype_size: size of the unsigned long long integers
     *
     *      OUTPUT:
     *          -1 if the first unsigned long long integer is less than the second
     *          0 if the unsigned long long integers are equal
     *          1 if the first unsigned long long integer is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(unsigned long long int *)a)<(*(unsigned long long int *)b)) + ((*(unsigned long long int *)a)>(*(unsigned long long int *)b));
    if (*(unsigned long long int *)a == *(unsigned long long int *)b) {
        return 0;
    } else if (*(unsigned long long int *)a < *(unsigned long long int *)b) {
        return -1;
    } else {
        return 1;
    }
}




// Floats
int floatcmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two floats
     *
     *      INPUTS:
     *          a: pointer to the first float
     *          b: pointer to the second float
     *          datatype_size: size of the floats
     *
     *      OUTPUT:
     *          -1 if the first float is less than the second
     *          0 if the floats are equal
     *          1 if the first float is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(float *)a)<(*(float *)b)) + ((*(float *)a)>(*(float *)b));
    if (*(float *)a == *(float *)b) {
        return 0;
    } else if (*(float *)a < *(float *)b) {
        return -1;
    } else {
        return 1;
    }
}




// Doubles
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
    UNUSED_K(datatype_size);
    //return -((*(double *)a)<(*(double *)b)) + ((*(double *)a)>(*(double *)b));
    if (*(double *)a == *(double *)b) {
        return 0;
    } else if (*(double *)a < *(double *)b) {
        return -1;
    } else {
        return 1;
    }
}

int ldoublecmpK(const void *a, const void *b, size_t datatype_size) {
    /* Compares two long doubles
     *
     *      INPUTS:
     *          a: pointer to the first long double
     *          b: pointer to the second long double
     *          datatype_size: size of the long doubles
     *
     *      OUTPUT:
     *          -1 if the first long double is less than the second
     *          0 if the long doubles are equal
     *          1 if the first long double is greater than the second
     *
     */
    UNUSED_K(datatype_size);
    //return -((*(long double *)a)<(*(long double *)b)) + ((*(long double *)a)>(*(long double *)b));
    if (*(long double *)a == *(long double *)b) {
        return 0;
    } else if (*(long double *)a < *(long double *)b) {
        return -1;
    } else {
        return 1;
    }
}




// Binary
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




#endif // CMPSTD_KUTILS_C