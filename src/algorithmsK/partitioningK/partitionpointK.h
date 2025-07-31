#ifndef PARTITIONPOINTK_H
#define PARTITIONPOINTK_H

// This is the template macro for the "partitionpoint_<type>_<func>" function
/*
    DEFINE_PARTITIONPOINTK(TYPE, TYPENAME, FUNC, FUNCNAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> partitionpointK_int_isEven(...) ])
        -> FUNC         (function that will be used to partition the array [ ex: isEven ])
        -> FUNCNAME     (name that created function will take [ ex: isEven -> partitionpointK_int_isEven(...) ])






    void partitionpointK_##TYPENAME##_##FUNCNAME(TYPE* begin, TYPE* end) {
        Returns the partition point of the array based on the function FUNC.
        Utilizes a binary search to find the first element that does not satisfy
        the FUNC condition.


        -> TYPE* begin  (first element of the first array [ ex: array[0] ])
        -> TYPE* end    (first element after the first array that does not belong [ex: array[n] ])
        -> return       (first element that does not satisfy the FUNC condition, or end if all elements satisfy the condition)
 */

#define DEFINE_PARTITIONPOINTK(TYPE, TYPENAME, FUNC, FUNCNAME) \
    \
TYPE* partitionpointK_##TYPENAME##_##FUNCNAME(TYPE* begin, TYPE* end) { \
    TYPE* left = begin; \
    TYPE* right = end; \
    while (left < right) { \
        TYPE* mid = left+(right-left) / 2; \
        if (FUNC(*mid)) { \
            left = mid + 1; \
        } else { \
            right = mid; \
        } \
    } \
    return left; \
}

#endif
