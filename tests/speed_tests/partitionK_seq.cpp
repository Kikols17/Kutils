#include <bits/stdc++.h>




using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i;
    }

    clock_t start = clock();
    partition(array, array+n, [](int e) { return (e%2 == 0); });
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);
    
    return 0;
}