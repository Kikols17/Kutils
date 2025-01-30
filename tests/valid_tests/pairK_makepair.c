#include <stdlib.h>
#include <stdio.h>
#include "pairK.h"

DEFINE_PAIRK(int, int, int_int)


void printpair(pairK_int_int p);


int main(int argc, const char* argv[]) {
    int n = atoi(argv[1]);

    srand(n);

    for (int i=0; i<n; i++) {
        printpair( pairK_int_int_makepair(rand(), rand()) );
    }

    return 0;
}




void printpair(pairK_int_int p) {
    printf("%d - %d\n", p.first, p.second);
}
