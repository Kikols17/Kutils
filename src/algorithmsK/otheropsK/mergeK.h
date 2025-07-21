#ifndef MERGEK_H
#define MERGEK_H

// This is the template macro for the "mergeK_<type>" function
/*
    DEFINE_MERGEK(TYPE, TYPENAME, COMPARE)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> mergeK_int(...) ])
        -> COMPARE      (comparison function [ ex: ( (a) < (b) ) ])






    TYPE* mergeK_<type>(TYPE* begin1, TYPE* end1, TYPE* begin2, TYPE* end2, TYPE* output):
        Merges two sorted arrays arrays (array1 and array2), into output array.
        Make sure that output array's size is not less than both arrays', as it
        will result of Segmentation Fault.


        -> TYPE* begin1 (first element of the first array [ ex: array1[0] ])
        -> TYPE* end1   (first element after the first array that does not belong [ex: array1[n1] ])
        -> TYPE* begin2 (first element of the second array [ ex: array2[0] ])
        -> TYPE* end2   (first element after the second array that does not belong [ex: array2[n2] ])
        -> TYPE* output (first element of the output array. Make sure it's size is not less than both arrays')
        -> return       (first element in "output" that is not on the merge)
 */

#define DEFINE_MERGEK(TYPE, TYPENAME, COMPARE) \
    \
TYPE* mergeK_##TYPENAME(TYPE* begin1, TYPE* end1, TYPE* begin2, TYPE* end2, TYPE* output) { \
    if (COMPARE(*(end2-1), *(end1-1))) { \
        while (begin1 != end1) { \
            if (COMPARE(*begin1, *begin2)) { \
                *output = *begin2; \
                ++begin2; \
            } else { \
                *output = *begin1; \
                ++begin1; \
            } \
            ++output; \
        } \
        while (begin2 != end2) { \
            *output = *begin2; \
            ++begin2; \
            ++output; \
        } \
        return output; \
    } else { \
        while (begin2 != end2) { \
            if (COMPARE(*begin2, *begin1)) { \
                *output = *begin1; \
                ++begin1; \
            } else { \
                *output = *begin2; \
                ++begin2; \
            } \
            ++output; \
        } \
        while (begin1 != end1) { \
            *output = *begin1; \
            ++begin1; \
            ++output; \
        } \
        return output; \
    } \
}

#endif
