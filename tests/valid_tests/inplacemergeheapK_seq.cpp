#include <bits/stdc++.h>



using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*2*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i;
        cout << array[i] << endl;
    }
    cout << endl;
    for (int i=n; i<n*2; ++i) {
        array[i] = i;
        cout << array[i] << endl;
    }
    cout << endl;

    inplace_merge(array, array+n, array+n*2);

    for (int i=0; i<n*2; ++i) {
        cout << array[i] << endl;
    }

    free(array);

    return 0;
}