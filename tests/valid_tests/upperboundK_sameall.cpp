#include <bits/stdc++.h>


using namespace std;



int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        //array[i] = 0;
        cout << array[i] << endl;
    }

    cout << "\nupperbound: " << (int)(upper_bound(&array[0], &array[n], 0)-&array[0]) << endl;

    free(array);

    return 0;
}