#ifndef PARTITIONK_H
#define PARTITIONK_H

// This is the template macro for the "partitionK_<type>" function
/*
    DEFINE_PARTITIONK(TYPE, TYPENAME, FUNC, FUNCNAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> partitionK_int_isEven(...) ])
        -> FUNC         (function that will be used to partition the array [ ex: isEven ])
        -> FUNCNAME     (name that created function will take [ ex: isEven -> partitionK_int_isEven(...) ])






    TYPE* partitionK_<type>(TYPE* begin, TYPE* end):
        Partitions the array in two parts based on the function FUNC.
        Elements for which FUNC returns true will be in the first part, and the
        false ones in the second. The pointer to the first element that does not
        belong to the first part, and the first element of the second part is
        returned.


        -> TYPE* begin  (first element of the first array [ ex: array[0] ])
        -> TYPE* end    (first element after the first array that does not belong [ex: array[n] ])
        -> return       (first element of the second part [ ex: array[y] ])
 */

#define DEFINE_PARTITIONK(TYPE, TYPENAME, FUNC, FUNCNAME) \
    \
TYPE* partitionK_##TYPENAME##_##FUNCNAME(TYPE* begin, TYPE* end) { \
    while (begin != end && FUNC(*begin)) { \
        ++begin; \
    } \
    while (begin != end && !FUNC(*(--end))) { \
        end; \
    } \
    if (begin == end) return begin; \
    ++end; \
    \
    while (begin != end) { \
        TYPE temp = *begin; \
        *begin = *(end-1); \
        *(--end) = temp; \
        ++begin; \
        while (begin != end && FUNC(*begin)) { \
            ++begin; \
        } \
        while (begin != end && !FUNC(*(end-1))) { \
            --end; \
        } \
    } \
    return begin; \
}

#endif
