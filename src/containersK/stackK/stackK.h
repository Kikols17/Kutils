#ifndef STACKK_H
#define STACKK_H

#include <stdlib.h>
#include <stdbool.h>

// This is the template for stackK_<type>, and all its functions
/*
    stackK_<type>:
        -> <type> data              (dinarray that stores the elements)
        -> size_t size              (number of elements in the dinarray)
        -> size_t capacity          (size of the allocated memory for the dinarray)





    void stackK_<type>_init(stackK_<type>* stk, size_t initual_capacity):
        Initializes the stack given, be careful with double inits and initializing
        without mallocing or declaring first. This function only alters memory at the
        given location, it does not malloc it.

        -> stackK_<type>* stk       (pointer to the pos of the stack, you have to malloc or declare it first)
        -> size_t initual_capacity  (size of the allocated memory that you want to start with, it better be a multiple of 2, 1 is recommended)
        -> RETURN           void


    void stackK_<type>_free(stackK_<type>* stk):
        Frees the dinarray and 0s all it's values.
        DOES NOT FREE THE MEMORY OF THE STACKK ITSELF!
        Also does not free the memory of any elements pointed to, free that first if you don't want to leak memory

        -> stackK_<type>* stk       (pointer to the pos of the stack)





    void stackK_<type>_push(stackK_<type>* stk, <type> element):
        Appends the given element to the end of the array.
        Doubles the capacity and reallocs the array if more space is needed.

        -> stackK_<type>* stk       (pointer to the pos of the stack)
        -> <type> element           (element being pushed back)


    void stackK_<type>_pop(stackK_<type>* stk):
        Removes the last element of the array, by decreasing the size by one.
        DOES NOT CHECK FOR size<0!

        -> stackK_<type>* stk       (pointer to the pos of the stack)


    void stackK_<type>_tightresize(stackK_<type>* stk):
        Changes the capacity and reallocs the array to the smallest 2^n number that is still greater than size
        This function can also be called to resize the array to a 2^n capacity. If you for whatever reason create a
        stack with not 2^n initial capacity, or resize one with stackK_<type>_reserver(stk), you can call this to fix that.

        -> stackK_<type>* stk       (pointer to the pos of the stack)


    void stackK_<type>_reserve(stackK_<type>* stk, size_t new_capacity):
        Changes the capacity and reallocs the array into the given capacity.

        -> stackK_<type>* stk       (pointer to the pos of the stack)
        -> size_t new_capacity      (size of the realloced array)





    void stackK_<type>_topset(stackK_<type>* stk, <type> element):
        Sets the top element of the stackK to the given element
        SHOULD NOT USE, JUST WRITE "stk->data[stk->size-1]=element" INSTEAD! (if i can, ill make this func a macro instead)
        DOES NOT CHECK FOR EMPTY STACKK, NOT MEMORY SAFE!

        -> stackK_<type>* stk       (pointer to the pos of the stack)
        -> <type> element           (value that top will be set to)


    <type> stackK_<type>_top(stackK_<type>* stk):
        Returns the top element of the stackK
        SHOULD NOT USE, JUST WRITE "stk->data[stk->size-1]" INSTEAD! (if i can, ill make this func a macro instead)
        DOES NOT CHECK FOR EMPTY STACKK, NOT MEMORY SAFE!

        -> stackK_<type>* stk       (pointer to the pos of the stack)
        -> RETURN                   (element at the index)





    <type> *stackK_<type>_begin(stackK_<type>* stk):
        Returns a pointer to the first element of the stackK
        SHOULD NOT USE, JUST WRITE "stk->data" INSTEAD! (if i can, ill make this func a macro instead)

        -> stackK_<type>* stk      (pointer to the pos of the stack)


    <type> *stackK_<type>_end(stackK_<type>* stk):
        Returns a pointer to the last element of the stackK
        SHOULD NOT USE, JUST WRITE "stk->data+stk->size" INSTEAD! (if i can, ill make this func a macro instead)

        -> stackK_<type>* stk      (pointer to the pos of the stack)


    bool stackK_<type>_empty(stackK_<type>* stk):
        Returns a true if the stackK is empty
        SHOULD NOT USE, JUST WRITE "stk->size==0" INSTEAD! (if i can, ill make this func a macro instead)

        -> stackK_<type>* stk       (pointer to the pos of the stack)
        -> RETURN                   (boolean, true if empty, false if not)


    size_t stackK_<type>_size(stackK_<type>* stk):
        Returns the size of the stackK
        SHOULD NOT USE, JUST WRITE "stk->size" INSTEAD! (if i can, ill make this func a macro instead)

        -> stackK_<type>* stk       (pointer to the pos of the stack)
        -> RETURN                   (size_t, number of elements in the stackK)

 */

#define DEFINE_STACKK(TYPE, TYPENAME) \
  \
typedef struct { \
    TYPE* data; \
    size_t size; \
    size_t capacity; \
}stackK_##TYPENAME; \
  \
void stackK_##TYPENAME##_init(stackK_##TYPENAME* stk, size_t initial_capacity) { \
    stk->data = (TYPE*)malloc(initial_capacity * sizeof(TYPE)); \
    stk->size = 0; \
    stk->capacity = initial_capacity; \
} \
  \
void stackK_##TYPENAME##_free(stackK_##TYPENAME* stk) { \
    free(stk->data); \
    stk->data = NULL; \
    stk->size = 0; \
    stk->capacity = 0; \
} \
  \
  \
  \
  \
  \
void stackK_##TYPENAME##_push(stackK_##TYPENAME* stk, TYPE element) { \
    if (stk->size == stk->capacity) { \
        stk->capacity *= 2; \
        stk->data = (TYPE*)realloc(stk->data, stk->capacity * sizeof(TYPE)); \
    } \
    stk->data[stk->size++] = element; \
} \
  \
void stackK_##TYPENAME##_pop(stackK_##TYPENAME* stk) { \
    stk->size--; \
} \
  \
void stackK_##TYPENAME##_tightresize(stackK_##TYPENAME* stk) { \
    size_t new_capacity = 1; \
    while (new_capacity < stk->size) { \
            new_capacity *= 2; \
    } \
    stk->capacity = new_capacity; \
    stk->data = (TYPE*)realloc(stk->data, stk->capacity * sizeof(TYPE)); \
} \
  \
void stackK_##TYPENAME##_reserve(stackK_##TYPENAME* stk, size_t new_capacity) { \
    stk->capacity = new_capacity; \
    stk->data = (TYPE*)realloc(stk->data, stk->capacity * sizeof(TYPE)); \
} \
  \
  \
  \
  \
  \
void stackK_##TYPENAME##_topset(stackK_##TYPENAME* stk, TYPE element) { \
    stk->data[stk->size-1] = element; \
} \
  \
TYPE stackK_##TYPENAME##_top(stackK_##TYPENAME* stk) { \
    return stk->data[stk->size-1]; \
} \
  \
  \
  \
  \
  \
TYPE *stackK_##TYPENAME##_begin(stackK_##TYPENAME* stk) { \
    return stk->data; \
} \
  \
TYPE *stackK_##TYPENAME##_end(stackK_##TYPENAME* stk) { \
    return stk->data+stk->size; \
} \
  \
bool stackK_##TYPENAME##_empty(stackK_##TYPENAME* stk) { \
    return stk->size==0; \
} \
  \
size_t stackK_##TYPENAME##_size(stackK_##TYPENAME* stk) { \
    return stk->size; \
}

#endif
