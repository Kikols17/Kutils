#include <stdlib.h>
#include <iostream>
#include <algorithm>


using namespace std;

bool condition(int x) {
    return x > 5;
}

int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);

    int *array = (int*)malloc(n*sizeof(n));
    for (long long int i=0; i<n; i++) {
        array[i] = 0;
    }

    int res = count_if(&array[0], &array[n], condition);

    return 0;
}