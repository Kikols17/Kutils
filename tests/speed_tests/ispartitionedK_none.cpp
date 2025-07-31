#include <bits/stdc++.h>





int n;

using namespace std;


int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = n/2+i/2;
    }

    clock_t start = clock();
    for (int i=0; i<10; ++i) {
        bool result = is_partitioned(array, array+n, [](int e) { return (e>(n/2) == 0); });
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);
    
    return 0;
}