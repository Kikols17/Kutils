#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);
    srand(n);

    clock_t start = clock();
    for (int i = 0; i < n; ++i) {
        int a = rand();
        int b = rand();
        
        pair<int, int> p = minmax(a, b);
    }
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}