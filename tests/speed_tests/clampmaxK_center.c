#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "minmaxK.h"



int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);

    clock_t start = clock();
    for (int i=0; i<10000; i++) {
        int a = CLAMPMAXK(5, 10);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}