#include <stdlib.h>
#include <stdbool.h>

#define DEFINE_QUICKSORTK(TYPE, TYPENAME, COMPARE) \
    \
void quicksortK_##TYPENAME(TYPE* begin, TYPE* end) { \
    TYPE** stack = (TYPE**)malloc((end-begin)*sizeof(TYPE*)); \
    TYPE** top = stack; \
    *top++ = begin; \
    *top++ = end; \
    \
    while (top > stack) { \
        end = *--top; \
        begin = *--top; \
        \
        if (begin >= end-1) { \
            continue; \
        } \
        \
        TYPE* mid = begin + (end-begin) / 2; \
        if (COMPARE(*begin, *mid)) { \
            TYPE temp = *begin; \
            *begin = *mid; \
            *mid = temp; \
        } \
        if (COMPARE(*begin, *(end-1))) { \
            TYPE temp = *begin; \
            *begin = *(end-1); \
            *(end-1) = temp; \
        } \
        if (COMPARE(*mid, *(end-1))) { \
            TYPE temp = *mid; \
            *mid = *(end-1); \
            *(end-1) = temp; \
        } \
        TYPE temp = *begin; \
        *begin = *mid; \
        *mid = temp; \
        \
        TYPE* pivot = begin; \
        TYPE* left = begin+1; \
        TYPE* right = end-1; \
        while (left <= right) { \
            while (left < end && !COMPARE(*left, *pivot)) { \
                left++; \
            } \
            while (right > begin && COMPARE(*right, *pivot)) { \
                right--; \
            } \
            if (left < right) { \
                TYPE temp = *left; \
                *left = *right; \
                *right = temp; \
            } \
        } \
        temp = *pivot; \
        *pivot = *right; \
        *right = temp; \
        \
        if (right-begin > end-(right+1)) { \
            *top++ = begin; \
            *top++ = right; \
            *top++ = right+1; \
            *top++ = end; \
        } else { \
            *top++ = right+1; \
            *top++ = end; \
            *top++ = begin; \
            *top++ = right; \
        } \
    } \
    free(stack); \
}
