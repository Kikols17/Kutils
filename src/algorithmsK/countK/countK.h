#ifndef COUNTK_H
#define COUNTK_H

#include <stdlib.h>
#include <stdbool.h>

// This is the template for the "countK_<type>" function
/*
    DEFINE_COUNTK(TYPE, TYPENAME)
        -> TYPE             (type [ ex: int ])
        -> TYPENAME         (name that created function will take [ ex: int -> countK_int(...) ])





    void countK_<type>(<type>* begin, <type>* end, <type> val):
        Count the number of times "val" appears in the range defined by "begin" and "end".

        -> <type> begin     (pointer to the first element of the array [ ex: array[0] ])
        -> <type> end       (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> <type> val       (value to count)

 */

#define DEFINE_COUNTK(TYPE, TYPENAME) \
    \
int countK_##TYPENAME(TYPE* begin, TYPE* end, TYPE val) { \
    int count = 0; \
    while (begin!=end) { \
        if (*begin++==val) { \
            ++count; \
        } \
    } \
    return count; \
}

#endif
