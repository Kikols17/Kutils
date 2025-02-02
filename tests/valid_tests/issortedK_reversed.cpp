#include <stdlib.h>
#include <iostream>
#include <algorithm>


using namespace std;


int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);
    
    int *array = (int*)malloc(n*sizeof(int));
    for (long long int i=0; i<n; i++) {
        array[n-1-i] = i;
    }

    cout << 1*is_sorted(&array[0], &array[n]) << endl;

    return 0;
}
