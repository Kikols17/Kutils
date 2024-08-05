#ifndef PAIR_KUTILS_H
#define PAIR_KUTILS_H

#include <stdlib.h>

typedef struct pairK {
    void *first;
    void *second;
    size_t first_datatype_size;
    size_t second_datatype_size;
} pairK;


pairK *pairK_init(size_t first_datatype_size, size_t second_datatype_size);
pairK *pairK_copy(pairK *pair);
int pairK_copyto(pairK *dest, pairK *src);

void pairK_free(pairK *pair);


void pairK_set(pairK *pair, void *first, void *second);
void pairK_setfirst(pairK *pair, void *first);
void pairK_setsecond(pairK *pair, void *second);

#endif // PAIR_KUTILS_H