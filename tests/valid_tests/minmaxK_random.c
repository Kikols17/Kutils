#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"



int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    for (int i=0; i<n; ++i) {
        int a = rand();
        int b = rand();
        int min, max;
        MINMAXK(a, b, min, max);
        printf("%d %d: %d %d\n", a, b, min, max);
    }

    return 0;
}