#ifndef PARTITIONCOPYK_H
#define PARTITIONCOPYK_H

// This is the template macro for the "partitioncopyK_<type>_<func>" function
/*
    DEFINE_PARTITIONCOPYK(TYPE, TYPENAME, FUNC, FUNCNAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> partitioncopyK_int_isEven(...) ])
        -> FUNC         (function that will be used to partition the array [ ex: isEven ])
        -> FUNCNAME     (name that created function will take [ ex: isEven -> partitioncopyK_int_isEven(...) ])






    void partitioncopyK_<type>_<func>(TYPE* begin, TYPE* end, TYPE* begint, TYPE* beginf, TYPE** endt, TYPE** endf):
        Partitions the array in two parts based on the function FUNC.
        Elements for which FUNC returns true will be copied to begint, and the
        false ones in the beginf. The pointer to the first element that does not
        belong to the first part, and the first element of the second part is
        written to endt and endf respectively.


        -> TYPE* begin  (first element of the first array [ ex: array[0] ])
        -> TYPE* end    (first element after the first array that does not belong [ex: array[n] ])
        -> TYPE* begint (first element of the array where true elements will be copied [ ex: true_array[0] ])
        -> TYPE* beginf (first element of the array where false elements will be copied [ ex: false_array[0] ])
        -> TYPE** endt  (first element after the true array that does not belong [ex: true_array[n] ])
        -> TYPE** endf  (first element after the false array that does not belong [ex: false_array[n] ])
        -> return       (void)
 */

#define DEFINE_PARTITIONCOPYK(TYPE, TYPENAME, FUNC, FUNCNAME) \
    \
void partitioncopyK_##TYPENAME##_##FUNCNAME(TYPE* begin, TYPE* end, TYPE* begint, TYPE* beginf, TYPE** endt, TYPE** endf) { \
    while (begin != end) { \
        if (FUNC(*begin)) { \
            *begint = *begin; \
            ++begint; \
        } else { \
            *beginf = *begin; \
            ++beginf; \
        } \
        ++begin; \
    } \
    *endt = begint; \
    *endf = beginf; \
}

#endif
