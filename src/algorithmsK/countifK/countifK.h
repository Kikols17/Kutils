#ifndef COUNTIFK_H
#define COUNTIFK_H

#include <stdlib.h>
#include <stdbool.h>

// This is the template for the "countifK_<type>" function
/*
    DEFINE_COUNIFTK(TYPE, TYPENAME, CONDITION)
        -> TYPE             (type [ ex: int ])
        -> TYPENAME         (name that created function will take [ ex: int -> countifK_int(...) ])
        -> CONDITION        (condition to check [ ex: countifK_pairK_int_int(...) -> pairK.first > pairK.second ])





    void countifK_<type>(<type>* begin, <type>* end):
        Count the number of times the condition is satisfied in the range defined by "begin" and "end".

        -> <type> begin     (pointer to the first element of the array [ ex: array[0] ])
        -> <type> end       (pointer to the first element after the array that does not belong [ex: array[n] ])

 */

#define DEFINE_COUNTIFK(TYPE, TYPENAME, CONDITION) \
    \
int countifK_##TYPENAME(TYPE* begin, TYPE* end) { \
    int count = 0; \
    while (begin!=end) { \
        if ( CONDITION(begin) ) { \
            ++count; \
        } \
        ++begin; \
    } \
    return count; \
}

#endif
