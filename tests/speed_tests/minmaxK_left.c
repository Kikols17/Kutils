#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "minmaxK.h"



int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);

    clock_t start = clock();
    for (int i=0; i<n; ++i) {
        int a=5;
        int b=1;
        int min, max;
        MINMAXK(a, b, min, max);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}