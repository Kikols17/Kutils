#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"



int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    for (int i=0; i<n; ++i) {
        int a = rand();
        int b = rand();
        printf("%d %d: %d\n", a, b, MAXK(a, b));
    }

    return 0;
}