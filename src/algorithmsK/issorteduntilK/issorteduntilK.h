#ifndef ISSORTEDUNTIL_H
#define ISSORTEDUNTIL_H

#include <stdlib.h>
#include <stdio.h>

// This is the template for the "issorteduntilK_<type>" function
/*
    DEFINE_ISSORTEDUNTILK(TYPE, TYPENAME, COMPARE)
        -> TYPE             (type [ ex: int ])
        -> TYPENAME         (name that created function will take [ ex: int -> issorteduntilK_int(...) ])
        -> COMPARE(a,b)     (compare expression [ ex: #define MY_COMPARE(a, b) ((a)>(b)) ])





    <type>* issorteduntilK_<type>(<type>* begin, <type>* end):
        Iteratively checks if a range that starts at "begin" and who's last element is the one before "end"
        is sorted according to the COMPARE macro.
        If you want to check if a range is sorted, simply use the same COMPARE that you would use to sort it.

        -> <type> begin     (pointer to the first element of the array [ ex: array[0] ])
        -> <type> end       (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> <type>* RETURN   (pointer to the first element that is not sorted. If range is sorted, it will be "end")

 */

#define DEFINE_ISSORTEDUNTILK(TYPE, TYPENAME, COMPARE) \
  \
TYPE* issorteduntilK_##TYPENAME(TYPE* begin, TYPE* end) { \
    while (begin < end-1) { \
        if (COMPARE(*begin, *(begin+1))) { \
            return begin+1; \
        } \
        ++begin; \
    } \
    return end; \
}

#endif