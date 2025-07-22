#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>


using namespace std;


int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);
    
    int *array = (int*)malloc(n*sizeof(int));
    for (long long int i=0; i<n; i++) {
        array[i] = i;
    }

    clock_t start = clock();
    for (int i=0; i<10; i++) {
        int *res = is_sorted_until(&array[0], &array[n]);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}
