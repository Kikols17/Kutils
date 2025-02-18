#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>


using namespace std;

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = 0;
    }

    clock_t start = clock();
    for (int i=0; i<5; ++i) {
        int* p = upper_bound(&array[0], &array[n], 0);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);

    return 0;
}