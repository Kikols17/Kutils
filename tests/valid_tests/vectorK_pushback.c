#include <stdlib.h>
#include <stdio.h>
#include "vectorK.h"

DEFINE_VECTORK(int, int)



int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);

    vectorK_int v;
    vectorK_int_init(&v, 1);

    srand(n);
    for (int i=0; i<n; i++) {
        vectorK_int_pushback(&v, rand());
    }

    for (int i=0; i<n; i++) {
        printf("%d\n", v.data[i]);
    }
    printf("%ld - %ld\n", v.size, v.capacity);


    return 0;
}