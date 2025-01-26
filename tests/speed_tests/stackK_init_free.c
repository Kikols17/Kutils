#include <stdlib.h>
#include "stackK.h"

DEFINE_STACKK(char, char)



int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    stackK_char stk;

    for (long long int i=0; i<n; i++) {
        stackK_char_init(&stk, 1);
        stackK_char_free(&stk);
    }



    return 0;
}