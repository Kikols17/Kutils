#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "vectorK.h"

DEFINE_VECTORK(int, int)

int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    vectorK_int v;

    clock_t start = clock();
    for (long long int i=0; i<n; i++) {
        vectorK_int_init(&v, 1);
        vectorK_int_free(&v);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}