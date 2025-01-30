#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;


int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);
    srand(n);

    stack<int> stk = stack<int>();


    for (int i=0; i<n; i++) {
        if (rand()%3) {
            stk.push(i);
        } else if (!stk.empty()) {
            stk.pop();
        }
    }

    for (;!stk.empty();) {
        cout << stk.top() << endl;
        stk.pop();
    }
    cout << stk.size() << endl;

    return 0;
}