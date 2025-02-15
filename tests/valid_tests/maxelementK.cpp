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

    cout << "\nMax: " << (int)(max_element(&array[0], &array[n])-&array[0]) << endl;

    free(array);

    return 0;
}