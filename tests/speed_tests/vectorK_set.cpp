#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;


int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);

    vector<int> vec = vector<int>(n);


    clock_t start = clock();
    for (long long int i=0; i<n; i++) {
        vec[i] = i;
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}
