#include <stdlib.h>
#include "minmaxK.h"



int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);

    for (int i=0; i<n; ++i) {
        int a=1;
        int b=5;
        int min, max;
        MINMAXK(a, b, min, max);
    }

    return 0;
}