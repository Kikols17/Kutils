#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    vector<int> vec;

    for (long long int i=0; i<n; i++) {
        vec = vector<int>();
        vec.clear();
    }

    return 0;
}