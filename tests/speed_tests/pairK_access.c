#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pairK.h"

DEFINE_PAIRK(int, int, int_int)

int main(int argc, const char* argv[]) {
    long long int n = atoll(argv[1]);


    pairK_int_int p = pairK_int_int_makepair(1, 0);
    clock_t start = clock();
    for (long long int i=0; i<n; i++) {
        int temp = p.first;
        p.first = p.second;
        p.second = temp;
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}