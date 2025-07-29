#include <bits/stdc++.h>



int n;

using namespace std;


int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n * sizeof(int));
    int* true_array = (int*)malloc(n * sizeof(int));
    int* false_array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = i;
        cout << array[i] << endl;
    }
    cout << endl << endl;

    pair<int*, int*> ends;
    ends = partition_copy(array, array + n, true_array, false_array, [](int x) { return x % 2 == 0; });

    cout << ends.first - true_array << endl;
    for (int* it = true_array; it != ends.first; ++it) {
        cout << *it << endl;
    }
    cout << endl;

    cout << ends.second - false_array << endl;
    for (int* it = false_array; it != ends.second; ++it) {
        cout << *it << endl;
    }
    cout << endl;

    free(array);
    free(true_array);
    free(false_array);
    
    return 0;
}