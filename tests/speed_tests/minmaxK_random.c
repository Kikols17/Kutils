#include <stdlib.h>
#include "minmaxK.h"



int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);
    srand(n);

    for (int i = 0; i < n; ++i) {
        int a = rand();
        int b = rand();
        int min, max;
        MINMAXK(a, b, min, max);
    }

    return 0;
}