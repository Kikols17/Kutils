#include <bits/stdc++.h>




using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array1 = (int*)malloc(n*sizeof(int));
    int* array2 = (int*)malloc(n*sizeof(int));

    // Fill array1 with sorted random numbers
    array1[0] = rand() % 10;
    for (int i = 1; i < n; ++i) {
        array1[i] = array1[i-1] + (rand() % 10);
    }
    // Fill array2 with sorted random numbers
    array2[0] = rand() % 10;
    for (int i = 1; i < n; ++i) {
        array2[i] = array2[i-1] + (rand() % 10);
    }

    int* output = (int*)malloc(n*2*sizeof(int));

    clock_t start = clock();
    int* output_end = merge(array1, array1+n, array2, array2+n, output);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array1);
    free(array2);
    free(output);

    return 0;
}