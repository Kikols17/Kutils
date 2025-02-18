#ifndef EQUALRANGEK_H
#define EQUALRANGEK_H

// This is the template macro for the "equalrangeK<type>" function
/*
    DEFINE_EQUALRANGEK(TYPE, TYPENAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> equalrangeK_int(...) ])
        -> COMPARE      (comparison function [ ex: ( (a) < (b) ) ])
        -> EQUAL        (equality function [ ex: ( (a) == (b) ) ])






    void equalrangeK_<type>(TYPE* begin, TYPE* end, TYPE value, TYPE** lower, TYPE** upper):
        Find the pointers to the first and last element in the range that is equal to "value" in the sorted array.
        The range is assumed to be sorted with COMPARE.
        Utilizes binary search algorithm.

        -> TYPE* begin  (pointer to the first element of the array [ ex: array[0] ])
        -> TYPE* end    (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> TYPE value   (value to compare with)
        -> TYPE** lower (pointer to the pointer to the first element that is equal to "value" in the range)
        -> TYPE** upper (pointer to the pointer to the first element after the last element that is equal to "value" in the range)
        -> return       (index of the first element that is equal to "value" in the range)
 */

#define DEFINE_EQUALRANGEK(TYPE, TYPENAME, COMPARE) \
  \
void equalrangeK_##TYPENAME(TYPE* begin, TYPE* end, TYPE value, TYPE** lower, TYPE** upper) { \
    *lower = end; \
    *upper = end; \
    size_t count = end-begin; \
    size_t step; \
    TYPE* mid; \
    while (count!=0) { \
        step = count/2; \
        mid = begin+step; \
        if (COMPARE(value, *mid)) { \
            begin = ++mid; \
            count -= step+1; \
        } else { \
            count = step; \
        } \
    } \
    *lower = begin; \
    count = end-begin; \
    while (count!=0) { \
        step = count/2; \
        mid = begin+step; \
        if (COMPARE(*mid, value)) { \
            count = step; \
        } else { \
            begin = ++mid; \
            count -= step+1; \
        } \
    } \
    *upper = begin; \
}

#endif
