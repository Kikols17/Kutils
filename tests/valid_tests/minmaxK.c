#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"

int main() {
    int a, b;
    int min, max;

    a = 0;
    b = 1;
    MINMAXK(a, b, min, max);
    printf("%d %d: %d %d\n", a, b, min, max);

    a = 5;
    b = 3;
    MINMAXK(a, b, min, max);
    printf("%d %d: %d %d\n", a, b, min, max);

    a = 7;
    b = 7;
    MINMAXK(a, b, min, max);
    printf("%d %d: %d %d\n", a, b, min, max);

    return 0;
}