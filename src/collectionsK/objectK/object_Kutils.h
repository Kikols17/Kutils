#ifndef OBJECT_KUTILS_H
#define OBJECT_KUTILS_H

#include <stdlib.h>

typedef struct objectK {
    void *data;
    size_t datatype_size;
    void (*cpy)(void *dest, const void *src, size_t datatype_size);
    int id;
} objectK;


objectK *objectK_init(size_t datatype_size, void (*cpy)(void *dest, const void *src, size_t datatype_size));
int objectK_copyto(objectK *dest, objectK *src);
objectK *objectK_copy(objectK *object);

void objectK_free(objectK *object);


void objectK_set(objectK *object, void *data);
void objectK_get(objectK *object, void *data);


#endif // OBJECT_KUTILS_H