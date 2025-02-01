#include <stdlib.h>
#include <stdio.h>



int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void test(long long int n);


int main(int argc, const char* argv[]) {
    
    test(atoll(argv[1]));

    return 0;
}



void test(long long int n) {
    int *array = (int*)malloc(n*sizeof(int));

    for (long long int i=0; i<n; i++) {
        array[i] = i;
    }

    qsort(array, n, sizeof(int), compare);
}