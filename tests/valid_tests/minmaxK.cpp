#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    pair<int, int> temp;

    a = 0;
    b = 1;
    temp = minmax(a, b);
    cout << a << " " << b << ": " << temp.first << " " << temp.second << endl;

    a = 5;
    b = 3;
    temp = minmax(a, b);
    cout << a << " " << b << ": " << temp.first << " " << temp.second << endl;

    a = 7;
    b = 7;
    temp = minmax(a, b);
    cout << a << " " << b << ": " << temp.first << " " << temp.second << endl;

    return 0;
}