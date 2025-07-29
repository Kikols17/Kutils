#include <bits/stdc++.h>



int n;

using namespace std;


int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = i;
        cout << array[i] << endl;
    }
    cout << endl << endl;

    stable_partition(array, array + n, [](int x) { return x>=0; });

    for (int i=0; i<n; ++i) {
        cout << array[i] << endl;
    }

    free(array);

    return 0;
}