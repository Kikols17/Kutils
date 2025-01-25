#ifndef PAIRK_H
#define PAIRK_H

#include <stdlib.h>


// This is the template for pairK_<type0_type1>, and all its functions
/*
    pairK_<type0_type1>:
        -> <type0> first            (first element of pairK)
        -> <type1> second           (second element of pairK)





    pairK_<type0_type1> pairK_<type0_type1>_makepair(<type0> first, <type1> second):
        Returns a pairK with the given values.

        -> <type0> first            (first element of pairK)
        -> <type1> second           (second element of pairK)
        -> RETURN   pairK_<type0_type1>

*/

#define DEFINE_PAIRK(TYPE0, TYPE1, TYPENAME) \
  \
typedef struct { \
  TYPE0 first; \
  TYPE1 second; \
}pairK_##TYPENAME; \
  \
pairK_##TYPENAME pairK_##TYPENAME##_makepair(TYPE0 first, TYPE1 second) { \
    pairK_##TYPENAME pair; \
    pair.first = first; \
    pair.second = second; \
    return pair; \
}

#endif