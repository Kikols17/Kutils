#include <stdlib.h>
#include "vectorK.h"

DEFINE_VECTORK(int)



int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    vectorK_int v;
    vectorK_int_init(&v, 1);

    for (long long int i=0; i<n; i++) {
        vectorK_int_pushback(&v, i);
    }

    return 0;
}