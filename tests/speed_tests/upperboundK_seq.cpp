#include <bits/stdc++.h>



using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = i;
    }

    int* p = upper_bound(&array[0], &array[n], n*(3/7));

    free(array);

    return 0;
}