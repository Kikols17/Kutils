#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectorK.h"

DEFINE_VECTORK(int, int);


int main(int argc, const char *argv[]) {
    long long int n = atoi(argv[1]);

    vectorK_int vec;
    vectorK_int_init(&vec, n);

    clock_t start = clock();
    for (long long int i=0; i<n; i++) {
        vec.data[i] = i;
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}
