#include <stdlib.h>
#include <iostream>
#include <algorithm>


using namespace std;



int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);
    srand(n);

    int *array = (int*)malloc(n*sizeof(n));
    for (long long int i=0; i<n; i++) {
        array[i] = rand()%10;
    }

    cout << endl << count(&array[0], &array[n], 5) << endl;

    return 0;
}