#include <stdlib.h>
#include "stackK.h"

DEFINE_STACKK(int, int)



int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    stackK_int stk;
    stackK_int_init(&stk, 1);

    stackK_int_push(&stk, 0);
    for (long long int i=0; i<n; i++) {
        //stackK_int_topset(&stk, i);
        stk.data[stk.size-1] = i;
    }

    return 0;
}