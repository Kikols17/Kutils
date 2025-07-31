#include <bits/stdc++.h>




using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = rand();
        cout << array[i] << endl;
    }

    for (int i=0; i<10; ++i) {
        cout << (partition(array, array+n, [](int e) { return (e%2 == 0); }) - array) << endl;
    }

    free(array);
    
    return 0;
}