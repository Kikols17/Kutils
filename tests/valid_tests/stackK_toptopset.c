#include <stdio.h>
#include <stdlib.h>
#include "stackK.h"

DEFINE_STACKK(int, int);


int main(int argc, const char *argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    stackK_int stk;
    stackK_int_init(&stk, 1);

    stackK_int_push(&stk, n);
    for (int i=0; i<n; i++) {
        if (rand()%2) {
            stackK_int_topset(&stk, rand());
        } else {
            printf("%d\n", stackK_int_top(&stk));
        }
    }

    return 0;
}
