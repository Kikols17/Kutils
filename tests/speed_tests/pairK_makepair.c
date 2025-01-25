#include <stdlib.h>
#include "pairK.h"

DEFINE_PAIRK(int, char, int_char)


int main(int argc, const char* argv[]) {
    long long int n = atoll(argv[1]);


    pairK_int_char p;
    for (long long int i=0; i<n; i++) {
        p = pairK_int_char_makepair(0, 'c');
    }


    return 0;
}