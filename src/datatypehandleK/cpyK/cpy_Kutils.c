#ifndef CPY_KUTILS_C
#define CPY_KUTILS_C

#include <stdlib.h>
#include <string.h>

#include "cpy_Kutils.h"
#include "../../macro_Kutils.h"


/* Standard copy functions */

// Characters
void charcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the character from src to dest
     * [ATTENTION] This function is specific for char type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(char *)dest = *(char *)src;
}

void scharcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the signed character from src to dest
     * [ATTENTION] This function is specific for signed char type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(signed char *)dest = *(signed char *)src;
}

void ucharcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the unsigned character from src to dest
     * [ATTENTION] This function is specific for unsigned char type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(unsigned char *)dest = *(unsigned char *)src;
}




// Integers
void intcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the integer from src to dest
     * [ATTENTION] This function is specific for int type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(int *)dest = *(int *)src;
}

void shintcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the signed integer from src to dest
     * [ATTENTION] This function is specific for signed int type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(signed int *)dest = *(signed int *)src;
}

void ushintcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the unsigned short integer from src to dest
     * [ATTENTION] This function is specific for unsigned short int type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(unsigned short int *)dest = *(unsigned short int *)src;
}

void uintcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the unsigned integer from src to dest
     * [ATTENTION] This function is specific for unsigned int type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(unsigned int *)dest = *(unsigned int *)src;
}

void lintcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the long integer from src to dest
     * [ATTENTION] This function is specific for long int type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(long int *)dest = *(long int *)src;
}

void ulintcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the unsigned long integer from src to dest
     * [ATTENTION] This function is specific for unsigned long int type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(unsigned long int *)dest = *(unsigned long int *)src;
}

void llintcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the long long integer from src to dest
     * [ATTENTION] This function is specific for long long int type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(long long int *)dest = *(long long int *)src;
}

void ullintcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the unsigned long long integer from src to dest
     * [ATTENTION] This function is specific for unsigned long long int type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(unsigned long long int *)dest = *(unsigned long long int *)src;
}




// Floats
void floatcpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the float from src to dest
     * [ATTENTION] This function is specific for float type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(float *)dest = *(float *)src;
}




// Doubles
void doublecpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the double from src to dest
     * [ATTENTION] This function is specific for double type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(double *)dest = *(double *)src;
}

void ldoublecpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the long double from src to dest
     * [ATTENTION] This function is specific for long double type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    UNUSED_K(datatype_size);
    *(long double *)dest = *(long double *)src;
}




// Binary
void bincpyK(void *dest, const void *src, size_t datatype_size) {
    /* Copy the binary data from src to dest
     * [ATTENTION] This function is specific for binary data type
     *
     *      INPUTS:
     *          void *dest: pointer to the destination
     *          const void *src: pointer to the source
     *          size_t datatype_size: size of the data to be copied
     *
     */
    memcpy(dest, src, datatype_size);
}




#endif // CPY_KUTILS_C