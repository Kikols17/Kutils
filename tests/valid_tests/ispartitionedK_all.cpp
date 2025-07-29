#include <bits/stdc++.h>




int n;

using namespace std;


int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i/2;
        cout << array[i] << endl;
    }
    cout << endl;

    cout << (is_partitioned(array, array+n, [](int e) { return (e>(n/2) == 0); })) << endl;

    free(array);
    
    return 0;
}