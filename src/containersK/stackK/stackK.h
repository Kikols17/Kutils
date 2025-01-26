#ifndef STACKK_H
#define STACKK_H

#include <stdlib.h>
#include <stdbool.h>


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
TYPE stackK_##TYPENAME##_top(stackK_##TYPENAME* stk, size_t index) { \
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