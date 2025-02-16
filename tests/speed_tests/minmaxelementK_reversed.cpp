#include <bits/stdc++.h>



using namespace std;

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    long long int* array = (long long int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = n-i;
    }

    long long int* max = min_element(&array[0], &array[n]);

    return 0;
}