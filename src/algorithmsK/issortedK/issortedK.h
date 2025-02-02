#ifndef ISSORTED_H
#define ISSORTED_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define DEFINE_ISSORTEDK(TYPE, TYPENAME, COMPARE) \
  \
bool issortedK_##TYPENAME(TYPE* begin, TYPE* end) { \
    while (begin < end-1) { \
        if (COMPARE(*begin, *(begin+1))) { \
            return false; \
        } \
        ++begin; \
    } \
    return true; \
}

#endif