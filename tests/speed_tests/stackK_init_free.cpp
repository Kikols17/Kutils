#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    stack<int> stk;

    clock_t start = clock();
    for (long long int i=0; i<n; i++) {
        stk = stack<int>();
        while (!stk.empty()) {
            stk.pop();
        }
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}