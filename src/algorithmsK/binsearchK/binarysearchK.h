#ifndef BINARYSEARCHK_H
#define BINARYSEARCHK_H

// This is the template macro for the "binarysearchK<type>" function
/*
    DEFINE_BINARYSEARCHK(TYPE, TYPENAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> binarysearchK_int(...) ])
        -> COMPARE      (comparison function [ ex: ( (a) < (b) ) ])






    TYPE* binarysearchK_<type>(TYPE* begin, TYPE* end, TYPE value):
        Find the pointer to the first element that is equal to "value" in the range defined by "begin" and "end".
        The range is assumed to be sorted with COMPARE.
        Utilizes binary search algorithm.

        -> TYPE* begin  (pointer to the first element of the array [ ex: array[0] ])
        -> TYPE* end    (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> TYPE value   (value to compare with)
        -> return       (index of the first element that is equal to "value" in the range)
 */

#define DEFINE_BINARYSEARCHK(TYPE, TYPENAME, COMPARE) \
  \
TYPE* binarysearchK_##TYPENAME(TYPE* begin, TYPE* end, TYPE value) { \
    while (begin < end) { \
        TYPE* mid = begin+(end-begin)/2; \
        if (COMPARE(*mid, value)) { \
            end = mid; \
        } else if (COMPARE(value, *mid)) { \
            begin = mid+1; \
        } else { \
            return mid; \
        } \
    } \
    return end; \
}

#endif
