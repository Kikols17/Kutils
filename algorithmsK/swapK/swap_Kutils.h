#ifndef SWAP_KUTILS_H
#define SWAP_KUTILS_H

#include <stdlib.h>


/* Standard swapping functions */
void intswapK(void *a, void *b, size_t datatype_size);
void doubleswapK(void *a, void *b, size_t datatype_size);
void charswapK(void *a, void *b, size_t datatype_size);
void binswapK(void *a, void *b, size_t size);


#endif