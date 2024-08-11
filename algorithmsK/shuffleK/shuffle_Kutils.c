#ifndef SHUFFLE_KUTILS_C
#define SHUFFLE_KUTILS_C



#include <stdlib.h>

void shuffleK(void *begin, void *end, size_t datatype_size, void (*swap)(void *, void *)) {
    size_t n = (end - begin) / datatype_size;
    for (size_t i = 0; i < k; i++) {
        size_t j = i + rand() % (n - i);
        void *tmp = malloc(datatype_size);
        memcpy(tmp, begin + i * datatype_size, datatype_size);
        memcpy(begin + i * datatype_size, begin + j * datatype_size, datatype_size);
        memcpy(begin + j * datatype_size, tmp, datatype_size);
        free(tmp);
    }
}



#endif