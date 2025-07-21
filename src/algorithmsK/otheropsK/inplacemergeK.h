#ifndef INPLACEMERGEK_H
#define INPLACEMERGEK_H

// This is the template macro for the "inplacemergeK_<type>" function
/*
    DEFINE_INPLACEMERGEK(TYPE, TYPENAME, COMPARE)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> inplacemergeheapK_int(...) ])
        -> COMPARE      (comparison function [ ex: ( (a) < (b) ) ])






    TYPE* inplacemergeheapK_<type>(TYPE* begin, TYPE* mid, TYPE* end):
        Merges two sorted sequential subarrays (begin to mid and mid to end).
        The first subarray is [begin, mid) and the second is [mid, end).
        Uses heap allocation for temporary storage, fit for all uses, but is
        slower than the stack version.


        -> TYPE* begin  (first element of the first subarray [ ex: array1[0] ])
        -> TYPE* mid    (first element of the second subarray [ ex: array1[n1] = array2[0] ])
        -> TYPE* end    (first element after the second subarray that does not belong [ex: array2[n2] ])
        -> return       (void)
    
    TYPE* inplacemergeheapK_<type>(TYPE* begin, TYPE* mid, TYPE* end):
        Merges two sorted sequential subarrays (begin to mid and mid to end).
        The first subarray is [begin, mid) and the second is [mid, end).
        Uses stack allocation for temporary storage. Use only when the size of
        the arrays are not larger than the max stack size, as a stack overflow
        may occur (system dependent, only use for couple thousand byte sized
        arrays to be sure, test on various machines for your specific datatype).
        Faster than the heap version.



        -> TYPE* begin  (first element of the first subarray [ ex: array1[0] ])
        -> TYPE* mid    (first element of the second subarray [ ex: array1[n1] = array2[0] ])
        -> TYPE* end    (first element after the second subarray that does not belong [ex: array2[n2] ])
        -> return       (void)
 */

#define DEFINE_INPLACEMERGEK(TYPE, TYPENAME, COMPARE) \
    \
void inplacemergeheapK_##TYPENAME(TYPE* begin, TYPE* mid, TYPE* end) { \
    size_t n1 = mid - begin; \
    TYPE* temp = (TYPE*)malloc(n1*sizeof(TYPE)); \
    for (size_t i=0; i<n1; ++i) { \
        temp[i] = begin[i]; \
    } \
    TYPE* left = temp; \
    TYPE* left_end = temp+n1; \
    if (COMPARE(*(end-1), *(mid-1))) { \
        while (left < left_end) { \
            if (COMPARE(*mid, *left)) { \
                *begin++ = *left++; \
            } else { \
                *begin++ = *mid++; \
            } \
        } \
        /* No remaining elements in the right subarray, no need to copy */ \
    } else { \
        while (mid < end) { \
            if (COMPARE(*left, *mid)) { \
                *begin++ = *mid++; \
            } else { \
                *begin++ = *left++; \
            } \
        } \
        /* Only copy remaining elements from the left subarray */ \
        while (left < left_end) { \
            *begin++ = *left++; \
        } \
    } \
    free(temp); \
} \
    \
    \
void inplacemergestackK_##TYPENAME(TYPE* begin, TYPE* mid, TYPE* end) { \
    size_t n1 = mid - begin; \
    TYPE temp[n1]; \
    for (size_t i=0; i<n1; ++i) { \
        temp[i] = begin[i]; \
    } \
    TYPE* left = temp; \
    TYPE* left_end = temp+n1; \
    if (COMPARE(*(end-1), *(mid-1))) { \
        while (left < left_end) { \
            if (COMPARE(*mid, *left)) { \
                *begin++ = *left++; \
            } else { \
                *begin++ = *mid++; \
            } \
        } \
        /* No remaining elements in the right subarray, no need to copy */ \
    } else { \
        while (mid < end) { \
            if (COMPARE(*left, *mid)) { \
                *begin++ = *mid++; \
            } else { \
                *begin++ = *left++; \
            } \
        } \
        /* Only copy remaining elements from the left subarray */ \
        while (left < left_end) { \
            *begin++ = *left++; \
        } \
    } \
}

#endif
