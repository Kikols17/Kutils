#ifndef CMP_KUTILS_H
#define CMP_KUTILS_H

#include <stdlib.h>


/* Standard comparison functions */
int intcmpK(const void *a, const void *b, size_t size);
int doublecmpK(const void *a, const void *b, size_t size);
int charcmpK(const void *a, const void *b, size_t size);
int bincmpK(const void *a, const void *b, size_t size);


#endif