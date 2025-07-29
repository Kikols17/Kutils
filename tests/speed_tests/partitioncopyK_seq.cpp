#include <bits/stdc++.h>




int n;

using namespace std;


int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n * sizeof(int));
    int* true_array = (int*)malloc(n * sizeof(int));
    int* false_array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = i;
    }

    pair<int*, int*> ends;
    clock_t start = clock();
    for (int i=0; i<20; ++i) {
        ends = partition_copy(array, array + n, true_array, false_array, [](int x) { return x % 2 == 0; });
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);
    free(true_array);
    free(false_array);
    
    return 0;
}