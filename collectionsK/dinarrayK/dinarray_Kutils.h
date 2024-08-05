#ifndef DINARRAY_KUTILS_H
#define DINARRAY_KUTILS_H

#include <stdlib.h>

typedef struct dinarrayK {
    void *data;
    size_t datatype_size;
    size_t capacity;
} dinarrayK;


dinarrayK *dinarrayK_init(size_t datatype_size, size_t capacity);
dinarrayK *dinarrayK_copy(dinarrayK *dinarray);
int dinarrayK_copyto(dinarrayK *dest, dinarrayK *src);

void dinarrayK_free(dinarrayK *dinarray);


void *dinarrayK_begin(dinarrayK *dinarray);
void *dinarrayK_end(dinarrayK *dinarray);


void *dinarrayK_get(dinarrayK *dinarray, size_t index);
void *dinarrayK_set(dinarrayK *dinarray, size_t index, void *element);


int dinarrayK_resize(dinarrayK *dinarray, size_t new_capacity);


#endif // DINARRAY_KUTILS_H