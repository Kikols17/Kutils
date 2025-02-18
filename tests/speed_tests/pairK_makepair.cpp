#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <utility>

using namespace std;

int main(int argc, const char* argv[]) {
    long long int n = atoll(argv[1]);


    pair<int,char> p;
    clock_t start = clock();
    for (long long int i=0; i<n; i++) {
        p = make_pair(0, 'c');
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}