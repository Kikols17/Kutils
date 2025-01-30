#include <stdio.h>
#include <stdlib.h>
#include "vectorK.h"

DEFINE_VECTORK(int, int);


int main(int argc, const char *argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    vectorK_int vec;
    vectorK_int_init(&vec, n);
    for (int i=0; i<n; i++) {
        vec.data[i] = i;
    }


    for (int i=0; i<n; i++) {
        int a = (rand()%n);
        int b = (rand()%n);

        int temp = vec.data[a];
        vec.data[a] = vec.data[b];
        vec.data[b] = temp;
    }


    for (int i=0; i<n; i++) {
        printf("%d\n", vec.data[i]);
    }

    return 0;
}
