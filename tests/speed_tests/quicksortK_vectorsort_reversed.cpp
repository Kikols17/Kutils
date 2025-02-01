#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int main(int argc, const char* argv[]) {
    long long int n = atoll(argv[1]);
    srand(n);

    vector<int> vec = vector<int>(n);

    for (long long int i=0; i<n; i++) {
        vec[n-1-i] = i;
    }

    sort(vec.begin(), vec.end());

    return 0;
}
