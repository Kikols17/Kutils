#include <stdlib.h>
#include <iostream>
#include <utility>

using namespace std;


void printpair(pair<int,int> p);


int main(int argc, const char* argv[]) {
    int n = atoi(argv[1]);

    srand(n);

    for (int i=0; i<n; i++) {
        printpair( make_pair(rand(), rand()) );
    }

    return 0;
}




void printpair(pair<int,int> p) {
    cout << p.first << " - " << p.second << endl;
}
