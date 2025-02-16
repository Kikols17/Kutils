#include <bits/stdc++.h>


using namespace std;


int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    for (int i=0; i<n; i++) {
        int a = rand();
        int min = rand();
        int max = rand();
        if (min > max) {
            int temp = min;
            min = max;
            max = temp;
        }

        cout << a << " " << min << " " << max <<  ": " << clamp(a, min, max) << endl;
    }

    return 0;
}