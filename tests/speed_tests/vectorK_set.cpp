#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);

    vector<int> vec = vector<int>(n);

    for (long long int i=0; i<n; i++) {
        vec[i] = i;
    }

    return 0;
}
