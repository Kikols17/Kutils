#include <iostream>
#include <utility>

using namespace std;


int main(int argc, const char* argv[]) {
    long long int n = atoll(argv[1]);


    pair<int,int> p = make_pair(1, 0);
    for (long long int i=0; i<n; i++) {
        int temp = p.first;
        p.first = p.second;
        p.second = temp;
    }


    return 0;
}