#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main(int argc, const char *argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    vector<int> vec = vector<int>(n);

    for (int i=0; i<n; i++) {
        vec[i] = i;
    }


    for (int i=0; i<n; i++) {
        int a = (rand()%n);
        int b = (rand()%n);

        int temp = vec[a];
        vec[a] = vec[b];
        vec[b] = temp;
    }


    for (int i=0; i<n; i++) {
        cout << vec[i] << endl;
    }

    return 0;
}
