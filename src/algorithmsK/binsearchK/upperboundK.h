#ifndef UPPERBOUNDK_H
#define UPPERBOUNDK_H

// This is the template macro for the "upperboundK<type>" function
/*
    DEFINE_UPPERBOUNDK(TYPE, TYPENAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> lowerboundK_int(...) ])
        -> COMPARE      (comparison function [ ex: ( (a) < (b) ) ])






    TYPE* upperboundK_<type>(TYPE* begin, TYPE* end, TYPE value):
        Find the pointer to the first element that is greater than "value" in the range defined by "begin" and "end".
        The range is assumed to be sorted with COMPARE.
        Utilizes binary search algorithm.

        -> TYPE* begin  (pointer to the first element of the array [ ex: array[0] ])
        -> TYPE* end    (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> TYPE value   (value to compare with)
        -> return       (index of the first element that is greater than "value" in the range)
 */

#define DEFINE_UPPERBOUNDK(TYPE, TYPENAME, COMPARE) \
  \
TYPE* upperboundK_##TYPENAME(TYPE* begin, TYPE* end, TYPE value) { \
    size_t count = end-begin; \
    while (count!=0) { \
        size_t step = count>>1; \
        TYPE* mid = begin+step; \
        if (COMPARE(*mid, value)) { \
            count = step; \
        } else { \
            begin = ++mid; \
            count -= step+1; \
        } \
    } \
    return begin; \
}

#endif
