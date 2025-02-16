#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    int n = atoll(argv[1]);
    srand(n);

    for (int i = 0; i < n; ++i) {
        int a = rand();
        int b = rand();
        a = min(a, b);
    }

    return 0;
}