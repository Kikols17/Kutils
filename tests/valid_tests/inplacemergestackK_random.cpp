#include <bits/stdc++.h>



using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*2*sizeof(int));

    // Fill array with sorted random numbers
    array[0] = rand() % 10;
    cout << array[0] << endl;
    for (int i=1; i<n; ++i) {
        array[i] = array[i-1] + (rand() % 10);
        cout << array[i] << endl;
    }
    cout << endl;
    // Fill array2 with sorted random numbers
    array[n] = rand() % 10;
    cout << array[n] << endl;
    for (int i=n+1; i<n*2; ++i) {
        array[i] = array[i-1] + (rand() % 10);
        cout << array[i] << endl;
    }
    cout << endl;

    inplace_merge(array, array + n, array + n*2);

    for (int i=0; i<n*2; ++i) {
        cout << array[i] << endl;
    }
    cout << endl;

    free(array);

    return 0;
}