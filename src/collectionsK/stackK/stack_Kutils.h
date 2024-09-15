#ifndef STACK_KUTILS_H
#define STACK_KUTILS_H


#include "../vectorK/vector_Kutils.h"


typedef struct stackK {
    vectorK *vector;
} stackK;



stackK *stackK_init(size_t datatype_size, size_t capacity, int (*resize_func)(int, int));
stackK *stackK_copy(stackK *s);
int stackK_copyto(stackK *dest, stackK *src);

void stackK_free(stackK *s);


void *stackK_begin(stackK *s);
void *stackK_end(stackK *s);


void *stackK_push(stackK *s, void *element);
void *stackK_pop(stackK *s);
void *stackK_top(stackK *s, void *element);




#endif // STACK_KUTILS_H