#ifndef PAIRK_H
#define PAIRK_H

#include <stdlib.h>


#define DEFINE_PAIRK(TYPE0, TYPE1) \
  \
typedef struct { \
  TYPE0 first; \
  TYPE1 second; \
}pairK_##TYPE0##_##TYPE1; \
  \
void pairK_##TYPE0##_##TYPE1##_init(pairK_##TYPE0##_##TYPE1 *pair, TYPE0 init_first, TYPE1 init_second) { \
    pair->first = init_first; \
    pair->second = init_second; \
} \
pairK_##TYPE0##_##TYPE1 pairK_##TYPE0##_##TYPE1##_make_pair(TYPE0 first, TYPE1 second) { \
    pairK_##TYPE0##_##TYPE1 pair; \
    pair.first = first; \
    pair.second = second; \
    return pair; \
}

#endif