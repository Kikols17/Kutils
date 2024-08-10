#ifndef SWAP_KUTILS_C
#define SWAP_KUTILS_C

#include <stdlib.h>
#include <string.h>

#include "swap_Kutils.h"


/* Standard swapping functions */
void charswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for characters
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    char temp = *(char *)a;
    *(char *)a = *(char *)b;
    *(char *)b = temp;
}



void intswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for integers
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}

void shintswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for short int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    short int temp = *(short int *)a;
    *(short int *)a = *(short int *)b;
    *(short int *)b = temp;
}

void lintswapK(void *a, void *b, size_t datetype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for long int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    long int temp = *(long int *)a;
    *(long int *)a = *(long int *)b;
    *(long int *)b = temp;
}

void llintswapK(void *a, void *b, size_t datetype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for long long int
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    long long int temp = *(long long int *)a;
    *(long long int *)a = *(long long int *)b;
    *(long long int *)b = temp;
}



void floatswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for floats
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    float temp = *(float *)a;
    *(float *)a = *(float *)b;
    *(float *)b = temp;
}



void doubleswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for doubles
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    double temp = *(double *)a;
    *(double *)a = *(double *)b;
    *(double *)b = temp;
}

void ldoubleswapK(void *a, void *b, size_t datatype_size) {
    /* Swaps the contents of two memory locations of size 'size'
     * [ATTENTION] All implementations of this function must follow these INPUTS/OUTPUT
     * [ATTENTION] This function is specific for doubles
     *
     *      INPUTS:
     *          a: pointer to the first memory location
     *          b: pointer to the second memory location
     *          datatype_size: size of the memory locations
     *
     */
    long double temp = *(long double *)a;
    *(long double *)a = *(long double *)b;
    *(long double *)b = temp;
}



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




#endif