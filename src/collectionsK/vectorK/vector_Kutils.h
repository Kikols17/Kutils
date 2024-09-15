#ifndef VECTOR_KUTILS_H
#define VECTOR_KUTILS_H

#include "../dinarrayK/dinarray_Kutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Vector struct
typedef struct vectorK {
    dinarrayK* dinarray;    // pointer to the dinarrayK
    size_t size;            // size of the vector (number of elements it contains in its data) (must be <= than capacity)
    size_t (*resize_func)(size_t, size_t);      // pointer to the function for resizing the dinarrayK
} vectorK;


vectorK *vectorK_init(size_t datatype_size, size_t capacity, size_t (*resize_func)(size_t, size_t));
vectorK *vectorK_copy(vectorK *v);
int vectorK_copyto(vectorK *dest, vectorK *src);

void vectorK_free(vectorK *v);


void *vectorK_begin(vectorK *v);
void *vectorK_end(vectorK *v);


void *vectorK_get(vectorK *v, size_t index);
void *vectorK_set(vectorK *v, size_t index, void *element);


void *vectorK_pushback(vectorK *v, void *element);
void *vectorK_popback(vectorK *v);




size_t vectorK_defresize(size_t new_size, size_t cur_capacity);
size_t vectorK_tightresize(size_t new_size, size_t cur_capacity);



#endif // VECTOR_KUTILS_H