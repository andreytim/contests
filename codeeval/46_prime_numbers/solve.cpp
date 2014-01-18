// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
       int n;
        while (f >> n) {
            vector<bool> sieve(n, true);
            for (int i = 2; i < n; i++) {
                if (sieve[i]) {
                    if (i > 2) cout << ",";
                    cout << i;
                    for (int k = i; k < n; k += i) {
                        sieve[k] = false;
                    }
                }
            }
            cout << endl;
        }
    }
}

