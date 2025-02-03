#ifndef QUICKSORTK_H
#define QUICKSORTK_H

#include <stdlib.h>
#include <stdbool.h>

// This is the template for the "quicksortK_<type>" function
/*
    DEFINE_QUICKSORTK(TYPE, TYPENAME, COMPARE)
        -> TYPE             (type [ ex: int ])
        -> TYPENAME         (name that created function will take [ ex: int -> quicksortK_int(...) ])
        -> COMPARE(a,b)     (compare expression [ ex: #define MY_COMPARE(a, b) ((a)>(b)) ])





    void quicksortK_<type>(<type>* begin, <type>* end):
        Quicksorts the given array, that starts at "begin" and who's last element is the one before "end".
        This implementation avoids recursive calls for speed. The todo stack is alloced in the heap, otherwise
        the number of elements would be limited by the max size of the stack frame, which depends on OS.
        The stack has size N/2 (because each entry todo entry requires 2 parameters)

        -> <type> begin     (pointer to the first element of the array [ ex: array[0] ])
        -> <type> end       (pointer to the first element after the array that does not belong [ex: array[n] ])

 */

#define DEFINE_QUICKSORTK(TYPE, TYPENAME, COMPARE) \
    \
void quicksortK_##TYPENAME(TYPE* begin, TYPE* end) { \
    TYPE** stack = (TYPE**)malloc((end-begin)*sizeof(TYPE*)+((end-begin)%2)); \
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

#endif
