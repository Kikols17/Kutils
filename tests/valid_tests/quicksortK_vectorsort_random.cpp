#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int main(int argc, const char* argv[]) {
    long long int n = atoll(argv[1]);
    srand(n);

    vector<int> vec = vector<int>(n);

    for (int i=0; i<n; i++) {
        vec[i] = rand();
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }

    return 0;
}
