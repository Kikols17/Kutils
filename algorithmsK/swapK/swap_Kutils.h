#ifndef SWAP_KUTILS_H
#define SWAP_KUTILS_H

#include <stdlib.h>


/* Standard swapping functions */
void charswapK(void *a, void *b, size_t datatype_size);
void scharswapK(void *a, void *b, size_t datatype_size);
void ucharswapK(void *a, void *b, size_t datatype_size);

void intswapK(void *a, void *b, size_t datatype_size);
void shintswapK(void *a, void *b, size_t datatype_size);
void ushintswapK(void *a, void *b, size_t datatype_size);
void uintswapK(void *a, void *b, size_t datatype_size);
void lintswapK(void *a, void *b, size_t datatype_size);
void ulintswapK(void *a, void *b, size_t datatype_size);
void llintswapK(void *a, void *b, size_t datatype_size);
void ullintswapK(void *a, void *b, size_t datatype_size);

void floatswapK(void *a, void *b, size_t datatype_size);

void doubleswapK(void *a, void *b, size_t datatype_size);
void ldoubleswapK(void *a, void *b, size_t datatype_size);

void binswapK(void *a, void *b, size_t size);


#endif