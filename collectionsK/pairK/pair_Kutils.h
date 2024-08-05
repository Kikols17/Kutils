#ifndef PAIR_KUTILS_H
#define PAIR_KUTILS_H

#include <stdlib.h>

typedef struct pairK {
    void *first;
    void *second;
    size_t first_datatype_size;
    size_t second_datatype_size;
} pairK;


pairK *init_pairK(size_t first_datatype_size, size_t second_datatype_size);
pairK *copy_pairK(pairK *pair);
int copyto_pairK(pairK *dest, pairK *src);

void free_pairK(pairK *pair);


void set_pairK(pairK *pair, void *first, void *second);
void setfirst_pairK(pairK *pair, void *first);
void setsecond_pairK(pairK *pair, void *second);

#endif // PAIR_KUTILS_H