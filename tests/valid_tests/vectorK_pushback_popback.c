#include <stdio.h>
#include <stdlib.h>
#include "vectorK.h"

DEFINE_VECTORK(int, int);


int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);
    srand(n);

    vectorK_int vec;
    vectorK_int_init(&vec, 1);

    for (int i=0; i<n; i++) {
        if (rand()%3) {
            vectorK_int_pushback(&vec, i);
        } else if (!(vec.size==0)) {
            vectorK_int_popback(&vec);
        }
    }

    int size = vec.size;
    for (int i=0; i<size; i++) {
        printf("%d\n", vec.data[i]);
    }
    printf("%ld - %ld\n", vec.size, vec.capacity);

    return 0;
}