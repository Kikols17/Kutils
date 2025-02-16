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


    auto minmax = minmax_element(&array[0], &array[n]);
    cout << "\nMin: " << *minmax.first << "\nMax: " << *minmax.second << endl;

    free(array);

    return 0;
}