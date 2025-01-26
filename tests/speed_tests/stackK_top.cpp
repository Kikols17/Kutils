#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;


int main(int argc, char const *argv[]) {
    long long int n = atoll(argv[1]);

    stack<int> stk = stack<int>();


    stk.push(0);
    for (long long int i=0; i<n; i++) {
        int j = stk.top();
        
    }

    return 0;
}