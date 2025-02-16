#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"



int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    for (int i=0; i<n; i++) {
        int a = rand();
        int min = rand();
        int max = rand();
        if (min > max) {
            int temp = min;
            min = max;
            max = temp;
        }

        printf("%d %d %d: %d\n", a, min, max, CLAMPK(a, min, max));
    }

    return 0;
}