// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    unsigned long n;
    while (cin >> n) {
        int count = 0;
        while (n != 0) {
            n -= pow(2, floor(log2(n)));
            count++;
        }
        cout << count % 3 << endl;
    }
}

