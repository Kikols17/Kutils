#ifndef ISPARTITIONEDK_H
#define ISPARTITIONEDK_H

// This is the template macro for the "ispartitionedK_<type>_<func>" function
/*
    DEFINE_ISPARTITIONEDK(TYPE, TYPENAME, FUNC, FUNCNAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> ispartitionedK_int_isEven(...) ])
        -> FUNC         (function that will be used to partition the array [ ex: isEven ])
        -> FUNCNAME     (name that created function will take [ ex: isEven -> ispartitionedK_int_isEven(...) ])






    bool ispartitionedK_<type>_<func>(TYPE* begin, TYPE* end):
        Checks if the array is partitioned based on the function FUNC.


        -> TYPE* begin  (first element of the first array [ ex: array[0] ])
        -> TYPE* end    (first element after the first array that does not belong [ex: array[n] ])
        -> return       (first element of the second part [ ex: array[y] ])
 */

#define DEFINE_ISPARTITIONEDK(TYPE, TYPENAME, FUNC, FUNCNAME) \
    \
bool ispartitionedK_##TYPENAME##_##FUNCNAME(TYPE* begin, TYPE* end) { \
    --end; \
    while (FUNC(*begin)) { \
        if (begin == end) { \
            return true; \
        } \
        ++begin; \
    } \
    while (!FUNC(*(end))) { \
        if (begin == end) { \
            return true; \
        } \
        --end; \
    } \
    return false; \
}

#endif
