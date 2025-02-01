#include <stdlib.h>
#include <stdio.h>
#include "vectorK.h"
#include "sortsK.h"


#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_VECTORK(int, int)
DEFINE_QUICKSORTK(int, int, MY_COMPARE)

int main(int argc, const char* argv[]) {
    long long int n = atoll(argv[1]);
    srand(n);

    vectorK_int vec;
    vectorK_int_init(&vec, n); vec.size = n;
    for (long long int i=0; i<n; i++) {
        vec.data[n-1-i] = i;
    }

    quicksortK_int(vectorK_int_begin(&vec), vectorK_int_end(&vec));

    return 0;
}
