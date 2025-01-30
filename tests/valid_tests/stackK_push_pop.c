#include <stdio.h>
#include <stdlib.h>
#include "stackK.h"

DEFINE_STACKK(int, int)


int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);
    srand(n);

    stackK_int stk;
    stackK_int_init(&stk, 1);

    for (int i=0; i<n; i++) {
        if (rand()%3) {
            stackK_int_push(&stk, i);
        } else if (!(stk.size==0)) {
            stackK_int_pop(&stk);
        }
    }

    for (;!(stk.size==0);) {
        printf("%d\n", stk.data[stk.size-1]);
        stackK_int_pop(&stk);
    }
    printf("%ld\n", stk.size);

    return 0;
}