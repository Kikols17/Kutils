#ifndef MINELEMENTK_H
#define MINELEMENTK_H

// This is the template macro for the "minelementK_<type>" function
/*
    DEFINE_MINELEMENTK(TYPE, TYPENAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> minelementK_int(...) ])






    TYPE minelementK_<type>(TYPE* begin, TYPE* end):
        Find the minimum element in the range defined by "begin" and "end".
        
        -> TYPE* begin  (pointer to the first element of the array [ ex: array[0] ])
        -> TYPE* end    (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> return       (the minimum element in the range)
 */

#define DEFINE_MINELEMENTK(TYPE, TYPENAME) \
  \
TYPE* minelementK_##TYPENAME(TYPE* begin, TYPE* end) { \
    TYPE* min = begin; \
    while (++begin!=end) { \
        min = *min<*begin ? min:begin; \
    } \
    return min; \
}

#endif
