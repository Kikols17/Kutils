#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"



int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    for (int i=0; i<n; i++) {
        int a = rand();
        int min = rand();

        printf("%d %d: %d\n", a, min, CLAMPMINK(a, min));
    }

    return 0;
}