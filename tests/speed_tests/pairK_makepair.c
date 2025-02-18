#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pairK.h"

DEFINE_PAIRK(int, char, int_char)

int main(int argc, const char* argv[]) {
    long long int n = atoll(argv[1]);


    pairK_int_char p;
    clock_t start = clock();
    for (long long int i=0; i<n; i++) {
        p = pairK_int_char_makepair(0, 'c');
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}