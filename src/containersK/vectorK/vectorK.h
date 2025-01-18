#ifndef VECTORK_H
#define VECTORK_H

#include <stdlib.h>
#include <stdbool.h>

// This is the template for vectorK_<type>, and all its functions
/*
    vectorK_<type>:
        -> <type> data      (dinarray that stores the elements)
        -> size_t size      (number of elements in the dinarray)
        -> size_t capacity  (size of the allocated memory for the dinarray)





    void vectorK_<type>_init(vectorK_<type>* vec, size_t initual_capacity):
        Initializes the vector given, be careful with double inits and initializing
        without mallocing or declaring first. This function only alters memory at the
        given location, it does not malloc it.

        -> vectorK_<type>* vec   (pointer to the pos of the vector, you have to malloc or declare it first)
        -> size_t initual_capacity      (size of the allocated memory that you want to start with, it better be a multiple of 2, 1 is recommended)
        -> RETURN           void
    

    void vectorK_<type>_free(vectorK_<type>* vec):
        Frees the dinarray and 0s all it's values.
        DOES NOT FREE THE MEMORY OF THE VECTORK ITSELF!
        Also does not free the memory of any elements pointed to, free that first if you don't want to leak memory

        -> vectorK_<type>* vec   (pointer to the pos of the vector)





    void vectorK_<type>_pushback(vectorK_<type>* vec, <type> element):
        Appends the given element to the end of the array.
        Doubles the capacity and reallocs the array if more space is needed.

        -> vectorK_<type>* vec   (pointer to the pos of the vector)
        -> <type> element               (element being pushed back)


    void vectorK_<type>_popback(vectorK_<type>* vec):
        Removes the last element of the array, by decreasing the size by one.
        DOES NOT CHECK FOR size<0!

        -> vectorK_<type>* vec   (pointer to the pos of the vector)
    

    void vectorK_<type>_resize(vectorK_<type>* vec):
        Changes the capacity and reallocs the array to the smallest 2^n number that is still greater than size
        Make sure your capacity always is a power of 2,by always creating the vectorK's with initial_capacity a power of 2

        -> vectorK_<type>* vec   (pointer to the pos of the vector)





    void vectorK_<type>_set(vectorK_<type>* vec, size_t index, <type> element):
        Sets the given element to the given index on the vectorK
        SHOULD NOT USE, JUST WRITE "vec->data[index] = element" INSTEAD! (if i can, ill make this func a macro instead)
        DOES NOT CHECK FOR size OR capacity, NOT MEMORY SAFE!

        -> vectorK_<type>* vec   (pointer to the pos of the vector)
        -> size_t index                 (index where to write the element)
        -> <type> element               (element to be writed to the index of the dinarray)
    

    <type> vectorK_<type>_set(vectorK_<type>* vec, size_t index):
        Returns the element at the index on the vectorK
        SHOULD NOT USE, JUST WRITE "vec->data[index]" INSTEAD! (if i can, ill make this func a macro instead)
        DOES NOT CHECK FOR size OR capacity, NOT MEMORY SAFE!

        -> vectorK_<type>* vec   (pointer to the pos of the vector)
        -> size_t index                 (index where to write the element)
        -> RETURN                       (element at the index)





    <type> *vectorK_<type>_begin(vectorK_<type>* vec):
        Returns a pointer to the first element of the vectorK
        SHOULD NOT USE, JUST WRITE "vec->data" INSTEAD! (if i can, ill make this func a macro instead)

        -> vectorK_<type>* vec   (pointer to the pos of the vector)


    <type> *vectorK_<type>_end(vectorK_<type>* vec):
        Returns a pointer to the last element of the vectorK
        SHOULD NOT USE, JUST WRITE "vec->data+vec->size" INSTEAD! (if i can, ill make this func a macro instead)

        -> vectorK_<type>* vec   (pointer to the pos of the vector)


    bool vectorK_<type>_empty(vectorK_<type>* vec):
        Returns a true if the vectorK is empty
        SHOULD NOT USE, JUST WRITE "vec->size==0" INSTEAD! (if i can, ill make this func a macro instead)

        -> vectorK_<type>* vec   (pointer to the pos of the vector)
        -> RETURN                       (boolean, true if empty, false if not)


    size_t vectorK_<type>_size(vectorK_<type>* vec):
        Returns the size of the vectorK
        SHOULD NOT USE, JUST WRITE "vec->size" INSTEAD! (if i can, ill make this func a macro instead)

        -> vectorK_<type>* vec   (pointer to the pos of the vector)
        -> RETURN                       (size_t, number of elements in the vectorK)

 */



#define DEFINE_VECTORK(TYPE) \
  \
typedef struct { \
    TYPE* data; \
    size_t size; \
    size_t capacity; \
}vectorK_##TYPE; \
  \
void vectorK_##TYPE##_init(vectorK_##TYPE* vec, size_t initial_capacity) { \
    vec->data = (TYPE*)malloc(initial_capacity * sizeof(TYPE)); \
    vec->size = 0; \
    vec->capacity = initial_capacity; \
} \
  \
void vectorK_##TYPE##_free(vectorK_##TYPE* vec) { \
    free(vec->data); \
    vec->data = NULL; \
    vec->size = 0; \
    vec->capacity = 0; \
} \
  \
  \
  \
  \
  \
void vectorK_##TYPE##_pushback(vectorK_##TYPE* vec, TYPE element) { \
    if (vec->size == vec->capacity) { \
        vec->capacity *= 2; \
        vec->data = (TYPE*)realloc(vec->data, vec->capacity * sizeof(TYPE)); \
    } \
    vec->data[vec->size++] = element; \
} \
  \
void vectorK_##TYPE##_popback(vectorK_##TYPE* vec) { \
    vec->size--; \
} \
  \
void vectorK_##TYPE##_resize(vectorK_##TYPE* vec) { \
    size_t new_capacity = 1; \
    while (new_capacity < vec->size) { \
            new_capacity *= 2; \
    } \
    vec->capacity = new_capacity; \
    vec->data = (TYPE*)realloc(vec->data, vec->capacity * sizeof(TYPE)); \
} \
  \
  \
  \
  \
  \
void vectorK_##TYPE##_set(vectorK_##TYPE* vec, size_t index, TYPE element) { \
    vec->data[index] = element; \
} \
  \
TYPE vectorK_##TYPE##_get(vectorK_##TYPE* vec, size_t index) { \
    return vec->data[index]; \
} \
  \
  \
  \
  \
  \
TYPE *vectorK_##TYPE##_begin(vectorK_##TYPE* vec) { \
    return vec->data; \
} \
  \
TYPE *vectorK_##TYPE##_end(vectorK_##TYPE* vec) { \
    return vec->data+vec->size; \
} \
  \
bool vectorK_##TYPE##_empty(vectorK_##TYPE* vec) { \
    return vec->size==0; \
} \
  \
size_t vectorK_##TYPE##_size(vectorK_##TYPE* vec) { \
    return vec->size; \
}


#endif