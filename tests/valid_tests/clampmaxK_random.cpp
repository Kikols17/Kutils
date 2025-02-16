#include <bits/stdc++.h>


using namespace std;


int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    for (int i=0; i<n; i++) {
        int a = rand();
        int max = rand();

        cout << a << " " << max <<  ": " << clamp(a, 0, max) << endl;
    }

    return 0;
}