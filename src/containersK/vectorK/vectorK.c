#include <stdio.h>

#include "vectorK.h"


DEFINE_VECTORK(int);



int main() {
    vectorK_int vec;
    vectorK_int_init(&vec, 1);

    //struct vectorK_vectorK_int vec2;

    for (long long int i=0; i<1000000000; i++) {
        vectorK_int_pushback(&vec, 0);
    }

    //printf("size=%ld, capacity=%ld\n", vec.size, vec.capacity);
    

    return 0;
}