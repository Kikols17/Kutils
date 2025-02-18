#include <bits/stdc++.h>




using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = 0;
    }


    clock_t start = clock();
    for (int i=0; i<100; i++) {

        pair<int*,int*> p = equal_range(&array[0], &array[n], 5);
    }
    clock_t end = clock();
    double delta_sec = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", delta_sec);


    free(array);

    return 0;
}