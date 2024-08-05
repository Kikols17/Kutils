#ifndef DINARRAY_KUTILS_H
#define DINARRAY_KUTILS_H

#include <stdlib.h>

typedef struct dinarrayK {
    void *data;
    size_t datatype_size;
    size_t capacity;
} dinarrayK;


dinarrayK *init_dinarrayK(size_t datatype_size, size_t capacity);
dinarrayK *copy_dinarrayK(dinarrayK *dinarray);
int copyto_dinarrayK(dinarrayK *dest, dinarrayK *src);

void free_dinarrayK(dinarrayK *dinarray);


void *begin_dinarrayK(dinarrayK *dinarray);
void *end_dinarrayK(dinarrayK *dinarray);


void *get_dinarrayK(dinarrayK *dinarray, size_t index);
void *set_dinarrayK(dinarrayK *dinarray, size_t index, void *element);


int resize_dinarrayK(dinarrayK *dinarray, size_t new_capacity);


#endif // DINARRAY_KUTILS_H