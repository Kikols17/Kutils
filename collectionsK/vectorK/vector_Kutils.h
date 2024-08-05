#ifndef VECTOR_KUTILS_H
#define VECTOR_KUTILS_H

#include "../dinarrayK/dinarray_Kutils.h"

#include <stdio.h>
#include <stdlib.h>


// Vector struct
typedef struct vectorK {
    dinarrayK* dinarray;    // pointer to the dinarrayK
    int size;               // size of the vector (number of elements it contains in its data) (must be <= than capacity)
    int (*resize_func)(int, int);      // pointer to the function for resizing the dinarrayK
} vectorK;


vectorK *init_vectorK(size_t datatype_size, size_t capacity, int (*resize_func)(int, int));
vectorK *copy_vectorK(vectorK *v);
int copyto_vectorK(vectorK *dest, vectorK *src);

void free_vectorK(vectorK *v);


void *begin_vectorK(vectorK *v);
void *end_vectorK(vectorK *v);


void *get_vectorK(vectorK *v, size_t index);
void *set_vectorK(vectorK *v, size_t index, void *element);


void *pushback_vectorK(vectorK *v, void *element);
void *popback_vectorK(vectorK *v);




int defresize_vectorK(int new_size, int cur_capacity);



#endif // VECTOR_KUTILS_H