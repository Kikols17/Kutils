#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;



int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);

    vector<int> vec = vector<int>();


    srand(n);
    for (int i=0; i<n; i++) {
        vec.push_back(rand());
    }

    for (int i=0; i<n; i++) {
        cout << vec[i] << endl;
    }
    cout << vec.size() << " - " << vec.capacity() << endl;


    return 0;
}