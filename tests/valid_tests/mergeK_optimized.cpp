#include <bits/stdc++.h>


using namespace std;



int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array1 = (int*)malloc(n*sizeof(int));
    int* array2 = (int*)malloc(n*sizeof(int));

    // Fill array1 with sorted random numbers
    array1[0] = rand() % 10;
    cout << array1[0] << endl;
    for (int i = 1; i < n; ++i) {
        array1[i] = array1[i-1] + (rand() % 10);
        cout << array1[i] << endl;
    }
    cout << endl;
    // Fill array2 with sorted random numbers
    array2[0] = array1[n-1] + (rand() % 10);
    cout << array2[0] << endl;
    for (int i = 1; i < n; ++i) {
        array2[i] = array2[i-1] + (rand() % 10);
        cout << array2[i] << endl;
    }
    cout << endl;

    int* output = (int*)malloc(n*2*sizeof(int));

    cout << ( merge(array1, array1+n, array2, array2+n, output) - output ) << endl << endl;

    for (int i=0; i<n*2; ++i) {
        cout << output[i] << endl;
    }

    free(array1);
    free(array2);
    free(output);

    return 0;
}