#ifndef CMPSTD_KUTILS_H
#define CMPSTD_KUTILS_H

#include <stdlib.h>


/* This file contains the standard comparison functions for the Kutils library (all the C default datatypes).
 * If you are looking to add custom comparison functions, you can add them to "cmpCST_Kutils.*" files.
 */


/* Standard comparison functions */
int charcmpK(const void *a, const void *b, size_t size);
int scharcmpK(const void *a, const void *b, size_t size);
int ucharcmpK(const void *a, const void *b, size_t size);

int intcmpK(const void *a, const void *b, size_t size);
int shintcmpK(const void *a, const void *b, size_t size);
int ushintcmpK(const void *a, const void *b, size_t size);
int uintcmpK(const void *a, const void *b, size_t size);
int lintcmpK(const void *a, const void *b, size_t size);
int ulintcmpK(const void *a, const void *b, size_t size);
int llintcmpK(const void *a, const void *b, size_t size);
int ullintcmpK(const void *a, const void *b, size_t size);

int floatcmpK(const void *a, const void *b, size_t size);

int doublecmpK(const void *a, const void *b, size_t size);
int ldoublecmpK(const void *a, const void *b, size_t size);

int bincmpK(const void *a, const void *b, size_t size);


#endif // CMPSTD_KUTILS_H