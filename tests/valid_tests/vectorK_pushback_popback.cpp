#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);
    srand(n);

    vector<int> vec = vector<int>();


    for (int i=0; i<n; i++) {
        if (rand()%3) {
            vec.push_back(i);
        } else if (!vec.empty()) {
            vec.pop_back();
        }
    }

    int size = vec.size();
    for (int i=0; i<size; i++) {
        cout << vec[i] << endl;
    }
    cout << vec.size() << " - " << vec.capacity() << endl;

    return 0;
}