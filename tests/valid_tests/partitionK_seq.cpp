#include <bits/stdc++.h>



using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i;
        cout << array[i] << endl;
    }
    cout << endl;

    cout << (partition(array, array+n, [](int a) { return (a % 2 == 0); }) - array) << endl << endl;

    for (int i=0; i<n; ++i) {
        cout << array[i] << endl;
    }

    free(array);
    
    return 0;
}