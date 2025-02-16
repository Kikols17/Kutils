#include <bits/stdc++.h>


using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    for (int i=0; i<n; ++i) {
        int a = rand();
        int b = rand();
        cout << a << " " << b << ": " << max(a, b) << endl;
    }

    return 0;
}