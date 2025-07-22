#ifndef ISSORTED_H
#define ISSORTED_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// This is the template for the "issortedK_<type>" function
/*
    DEFINE_ISSORTEDK(TYPE, TYPENAME, COMPARE)
        -> TYPE             (type [ ex: int ])
        -> TYPENAME         (name that created function will take [ ex: int -> issortedK_int(...) ])
        -> COMPARE(a,b)     (compare expression [ ex: #define MY_COMPARE(a, b) ((a)>(b)) ])





    bool issortedK_<type>(<type>* begin, <type>* end):
        iteratively checks if a range that starts at "begin" and who's last element is the one before "end"
        is sorted according to the COMPARE macro.
        If you want to check if a range is sorted, simply use the same COMPARE that you would use to sort it.

        -> <type> begin     (pointer to the first element of the array [ ex: array[0] ])
        -> <type> end       (pointer to the first element after the array that does not belong [ex: array[n] ])

 */

#define DEFINE_ISSORTEDK(TYPE, TYPENAME, COMPARE) \
  \
bool issortedK_##TYPENAME(TYPE* begin, TYPE* end) { \
    while (begin < end-1) { \
        if (COMPARE(*begin, *(begin+1))) { \
            return false; \
        } \
        ++begin; \
    } \
    return true; \
}

#endif
