#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    vector<int> vec = vector<int>();


    clock_t start = clock();
    for (long long int i=0; i<n; i++) {
        vec.push_back(0);
    }
    for (long long int i=0; i<n; i++) {
        vec.pop_back();
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}