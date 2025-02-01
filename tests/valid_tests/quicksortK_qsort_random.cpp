#include <stdlib.h>
#include <iostream>

using namespace std;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void test(long long int n);


int main(int argc, const char* argv[]) {
    srand(atoll(argv[1]));
    
    test(atoll(argv[1]));

    return 0;
}



void test(long long int n) {
    int *array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; i++) {
        array[i] = rand();
    }

    qsort(array, n, sizeof(int), compare);

    for (int i=0; i<n; i++) {
        cout << array[i] << endl;
    }
}