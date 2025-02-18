#include <bits/stdc++.h>


using namespace std;



int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = i;
        cout << array[i] << endl;
    }

    int value = rand()%n;
    cout << "\nvalue: " << value << endl;


    pair<int*,int*> p = equal_range(&array[0], &array[n], value);
    cout << "equalrange: " << p.first-&array[0] << " " << p.second-&array[0] << endl;

    free(array);

    return 0;
}