#ifndef STABLEPARTITIONK_H
#define STABLEPARTITIONK_H

// This is the template macro for the "stablepartitionheapK_<type>_<func>" and "stablepartitionstackK_<type>_<func>" functions
/*
    DEFINE_STABLEPARTITIONK(TYPE, TYPENAME, FUNC, FUNCNAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> stablepartitionheapK_int_isEven(...) ])
        -> FUNC         (function that will be used to partition the array [ ex: isEven ])
        -> FUNCNAME     (name that created function will take [ ex: isEven -> stablepartitionheapK_int_isEven(...) ])






    void stablepartitionheapK_<type>_<func>(TYPE* begin, TYPE* end):
        Partitions the array in two parts based on the function FUNC.
        Maintains the relative order of elements in each part.
        Uses heap allocation for temporary storage, fit for all uses, but is
        slower than the stack version.


        -> TYPE* begin  (first element of the first array [ ex: array[0] ])
        -> TYPE* end    (first element after the first array that does not belong [ex: array[n] ])
        -> return       (void)

    void stablepartitionstackK_<type>_<func>(TYPE* begin, TYPE* end):
        Partitions the array in two parts based on the function FUNC.
        Maintains the relative order of elements in each part.
        Uses stack allocation for temporary storage. Use only when the size of
        the arrays are not larger than the max stack size, as a stack overflow
        may occur (system dependent, only use for couple thousand byte sized
        arrays to be sure, test on various machines for your specific datatype).
        Faster than the heap version.


        -> TYPE* begin  (first element of the first array [ ex: array[0] ])
        -> TYPE* end    (first element after the first array that does not belong [ex: array[n] ])
        -> return       (void)
 */

#define DEFINE_STABLEPARTITIONK(TYPE, TYPENAME, FUNC, FUNCNAME) \
    \
void stablepartitionheapK_##TYPENAME##_##FUNCNAME(TYPE* begin, TYPE* end) { \
    TYPE* begint = begin; \
    TYPE* bufferf = (TYPE*)malloc((end-begin) * sizeof(TYPE)); \
    TYPE* beginf = bufferf; \
    while (begin != end) { \
        if (FUNC(*begin)) { \
            *begint = *begin; \
            ++begint; \
            ++begin; \
            continue; \
        } else { \
            *beginf = *begin; \
            ++beginf; \
            ++begin; \
            continue; \
        } \
    } \
    \
    beginf = bufferf; \
    while (begint != end) { \
        *begint = *beginf; \
        ++begint; \
        ++beginf; \
    } \
    free(bufferf); \
} \
    \
    \
void stablepartitionstackK_##TYPENAME##_##FUNCNAME(TYPE* begin, TYPE* end) { \
    TYPE* begint = begin; \
    TYPE bufferf[(end-begin)]; \
    TYPE* beginf = bufferf; \
    while (begin != end) { \
        if (FUNC(*begin)) { \
            *begint = *begin; \
            ++begint; \
            ++begin; \
            continue; \
        } else { \
            *beginf = *begin; \
            ++beginf; \
            ++begin; \
            continue; \
        } \
    } \
    \
    beginf = bufferf; \
    while (begint != end) { \
        *begint = *beginf; \
        ++begint; \
        ++beginf; \
    } \
}

#endif
