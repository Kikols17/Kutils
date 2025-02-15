#ifndef MAXELEMENTK_H
#define MAXELEMENTK_H

// This is the template macro for the "maxelementK_<type>" function
/*
    DEFINE_MAXELEMENTK(TYPE, TYPENAME)
        -> TYPE             (type [ ex: int ])
        -> TYPENAME         (name that created function will take [ ex: int -> maxelementK_int(...) ])






    TYPE* maxelementK_<type>(TYPE* begin, TYPE* end):
        Find the pointer to the first maximum element in the range defined by "begin" and "end".
        
        -> TYPE begin     (pointer to the first element of the array [ ex: array[0] ])
        -> TYPE end       (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> return         (pointer to the first maximum element in the range)
 */

#define DEFINE_MAXELEMENTK(TYPE, TYPENAME) \
  \
TYPE* maxelementK_##TYPENAME(TYPE* begin, TYPE* end) { \
    TYPE* max = begin; \
    while (++begin!=end) { \
        max = *max>*begin ? max:begin; \
    } \
    return max; \
}

#endif
