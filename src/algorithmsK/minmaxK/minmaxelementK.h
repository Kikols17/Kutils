#ifndef MINMAXELEMENTK_H
#define MINMAXELEMENTK_H

// This is the template for the "minmaxelementK_<type>" function
/*
    DEFINE_MINMAXELEMENTK(TYPE, TYPENAME)
        -> TYPE         (type [ ex: int ])
        -> TYPENAME     (name that created function will take [ ex: int -> minmaxelementK_int(...) ])






    void minmaxelementK_<type>(TYPE* begin, TYPE* end, TYPE* min, TYPE* max):
        Find the minimum and maximum element in the range defined by "begin" and "end".
        
        -> TYPE* begin  (pointer to the first element of the array [ ex: array[0] ])
        -> TYPE* end    (pointer to the first element after the array that does not belong [ex: array[n] ])
        -> TYPE** min   (pointer to the variable where to store the pointer to the first smallest element)
        -> TYPE** max   (pointer to the variable where to store the pointer to the last greatest element)
 */

#define DEFINE_MINMAXELEMENTK(TYPE, TYPENAME) \
  \
void minmaxelementK_##TYPENAME(TYPE* begin, TYPE* end, TYPE** min, TYPE** max) { \
    TYPE *min_temp, *max_temp; \
    min_temp = max_temp = begin; \
    while (++begin != end) { \
        TYPE* i = begin; \
        if (++begin == end) { \
            if (*i<*min_temp) { \
                min_temp = i; \
            } else if (*i>=*max_temp) { \
                max_temp = i; \
            } \
            break; \
        } else { \
            if (*begin<*i) { \
                if (*begin<*min_temp) { \
                    min_temp = begin; \
                } \
                if (*i>=*max_temp) { \
                    max_temp = i; \
                } \
            } else { \
                if (*i<*min_temp) { \
                    min_temp = i; \
                } \
                if (*begin>=*max_temp) { \
                    max_temp = begin; \
                } \
            } \
        } \
    } \
    *min = min_temp; \
    *max = max_temp; \
}

#endif
