#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;


int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    stack<int> stk = stack<int>();


    for (long long int i=0; i<n; i++) {
        stk.push(i);
    }
    for (long long int i=0; i<n; i++) {
        stk.pop();
    }

    return 0;
}