#include <bits/stdc++.h>


using namespace std;



int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*5*sizeof(int));
    for (int i=0; i<n*5; i+=5) {
        array[i] = i;
        array[i+1] = i;
        array[i+2] = i;
        array[i+3] = i;
        array[i+4] = i;
        cout << array[i] << endl << array[i+1] << endl << array[i+2] << endl << array[i+3] << endl << array[i+4] << endl;
    }

    int value = rand()%n;
    cout << "\nvalue: " << value << endl;


    pair<int*,int*> p = equal_range(&array[0], &array[n*5], value);
    cout << "equalrange: " << p.first-&array[0] << " " << p.second-&array[0] << endl;

    free(array);

    return 0;
}