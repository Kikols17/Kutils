#include <bits/stdc++.h>


using namespace std;


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    for (int i=0; i<n; ++i) {
        int a = rand();
        int b = rand();
        
        pair<int, int> temp = minmax(a, b);
        cout << a << " " << b << ": " << temp.first << " " << temp.second << endl;
    }

    return 0;
}