#ifndef INPLACEMERGEK_H
#define INPLACEMERGEK_H

// This is the template macro for the "inplacemergeK_<type>" function
/*
    DEFINE_INPLACEMERGEK(TYPE, TYPENAME, COMPARE)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> inplacemergeK_int(...) ])
        -> COMPARE      (comparison function [ ex: ( (a) < (b) ) ])






    TYPE* inplacemergeK_<type>(TYPE* begin, TYPE* mid, TYPE* end):
        Merges two sorted sequential subarrays (begin to mid and mid to end) in-place.
        The first subarray is [begin, mid) and the second is [mid, end).


        -> TYPE* begin  (pointer to the first element of the first subarray [ ex: array1[0] ])
        -> TYPE* mid    (pointer to the first element of the second subarray [ ex: array1[n1] = array2[0] ])
        -> TYPE* end    (pointer to the first element after the second subarray that does not belong [ex: array2[n2] ])
        -> return       (void)
 */

#define DEFINE_INPLACEMERGEK(TYPE, TYPENAME, COMPARE) \
    \
void inplacemergeK_##TYPENAME(TYPE* begin, TYPE* mid, TYPE* end) { \
    TYPE* left = begin; \
    TYPE* right = mid; \
    while (left < mid && right < end) { \
        if (COMPARE(*right, *left)) { \
            left++; \
        } else { \
            TYPE temp = *right; \
            TYPE* p = right; \
            while (p > left) { \
                *p = *(p - 1); \
                p--; \
            } \
            *left = temp; \
            left++; \
            mid++; \
            right++; \
        } \
    } \
}

#endif
