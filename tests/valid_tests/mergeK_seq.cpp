#include <bits/stdc++.h>


using namespace std;



int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array1 = (int*)malloc(n*sizeof(int));
    int* array2 = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array1[i] = i;
        cout << array1[i] << endl;
    }
    cout << endl;
    for (int i=0; i<n; ++i) {
        array2[i] = i;
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