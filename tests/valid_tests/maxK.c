#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"

int main() {
    int a, b;

    a = 0;
    b = 1;
    printf("%d\n", MAXK(a, b));

    a = 5;
    b = 3;
    printf("%d\n", MAXK(a, b));

    a = 7;
    b = 7;
    printf("%d\n", MAXK(a, b));

    return 0;
}