#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {
    long long int n = atoi(argv[1]);

    vector<int> vec = vector<int>();


    for (long long int i=0; i<n; i++) {
        vec.push_back(0);
    }

    return 0;
}