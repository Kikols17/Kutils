#ifndef SWAPSTD_KUTILS_C
#define SWAPSTD_KUTILS_C

#include <stdlib.h>
#include <string.h>

#include "swapSTD_Kutils.h"
#include "../../macro_Kutils.h"


/* This file contains the standard swapping functions for the Kutils library (all the C default datatypes).
 * If you are looking to add custom swapping functions, you can add them to "swapCST_Kutils.*" files.
 */


/* Standard swapping functions */

// Charachter
void charswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the chars at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for characters
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    char temp = *(char *)a;
    *(char *)a = *(char *)b;
    *(char *)b = temp;
}

void scharswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the signed chars at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for signed chars
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    signed char temp = *(signed char *)a;
    *(signed char *)a = *(signed char *)b;
    *(signed char *)b = temp;
}

void ucharswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the unsigned chars at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for unsigned chars
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    unsigned char temp = *(unsigned char *)a;
    *(unsigned char *)a = *(unsigned char *)b;
    *(unsigned char *)b = temp;
}




// Integers
void intswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps ints at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for integers
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}

void shintswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the short ints at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for short int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    short int temp = *(short int *)a;
    *(short int *)a = *(short int *)b;
    *(short int *)b = temp;
}

void ushintswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the unsigned short ints at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for unsigned short int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    unsigned short int temp = *(unsigned short int *)a;
    *(unsigned short int *)a = *(unsigned short int *)b;
    *(unsigned short int *)b = temp;
}

void uintswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the unsigned ints at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for unsigned integers
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    unsigned int temp = *(unsigned int *)a;
    *(unsigned int *)a = *(unsigned int *)b;
    *(unsigned int *)b = temp;
}

void lintswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the long ints at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for long int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    long int temp = *(long int *)a;
    *(long int *)a = *(long int *)b;
    *(long int *)b = temp;
}

void ulintswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the unsigned long ints at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for unsigned long int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    unsigned long int temp = *(unsigned long int *)a;
    *(unsigned long int *)a = *(unsigned long int *)b;
    *(unsigned long int *)b = temp;
}

void llintswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the long long ints at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for long long int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    long long int temp = *(long long int *)a;
    *(long long int *)a = *(long long int *)b;
    *(long long int *)b = temp;
}

void ullintswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the unsigned long long ints at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for unsigned long long int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    unsigned long long int temp = *(unsigned long long int *)a;
    *(unsigned long long int *)a = *(unsigned long long int *)b;
    *(unsigned long long int *)b = temp;
}




// Floats
void floatswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the floats at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for floats
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    float temp = *(float *)a;
    *(float *)a = *(float *)b;
    *(float *)b = temp;
}




// Doubles
void doubleswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the doubles at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for doubles
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    double temp = *(double *)a;
    *(double *)a = *(double *)b;
    *(double *)b = temp;
}

void ldoubleswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps long doubles at the memory locations pointed by 'a' and 'b'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for doubles
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    UNUSED_K(datatype_size);
    long double temp = *(long double *)a;
    *(long double *)a = *(long double *)b;
    *(long double *)b = temp;
}




// Binary
void binswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    char temp[datatype_size];
    memcpy(temp, a, datatype_size);
    memcpy(a, b, datatype_size);
    memcpy(b, temp, datatype_size);
}




#endif // SWAPSTD_KUTILS_C