#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    long long int n = atoll(argv[1]);

    long long int* array = (long long int*)malloc(n*sizeof(long long int));
    for (int i=0; i<n; ++i) {
        array[i] = i;
    }

    clock_t start = clock();
    for (int i=0; i<5; i++) {
        long long int* max = max_element(&array[0], &array[n]);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}