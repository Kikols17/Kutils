#ifndef MINMAXELEMENTK_H
#define MINMAXELEMENTK_H

// This is the template for the "minmaxelementK_<type>" function
/*
    DEFINE_MINMAXELEMENTK(TYPE, TYPENAME)
        -> TYPE             (type [ ex: int ])
        -> TYPENAME         (name that created function will take [ ex: int -> minmaxelementK_int(...) ])






    void minmaxelementK_<type>(TYPE* begin, TYPE* end, TYPE* min, TYPE* max):
        Find the minimum and maximum element in the range defined by "begin" and "end".
        
        -> TYPE begin     (pointer to the first element of the array [ ex: array[0] ])
        -> TYPE end       (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> TYPE min       (pointer to the variable where to store the smallest element)
        -> TYPE max       (pointer to the variable where to store the greatest element)
 */

#define DEFINE_MINMAXELEMENTK(TYPE, TYPENAME) \
  \
void minmaxelementK_##TYPENAME(TYPE* begin, TYPE* end, TYPE* min, TYPE* max) { \
    *min = *max = *begin; \
    while (++begin!=end) { \
        *min = *min < *begin ? *min : *begin; \
        *max = *max > *begin ? *max : *begin; \
    } \
}

#endif
