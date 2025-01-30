#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;


int main(int argc, const char *argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    stack<int> stk = stack<int>();


    stk.push(n);
    for (int i=0; i<n; i++) {
        if (rand()%2) {
            stk.top() = rand();
        } else {
            cout << stk.top() << endl;
        }
    }

    return 0;
}
