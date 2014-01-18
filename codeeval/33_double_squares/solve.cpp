// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        int nt;
        f >> nt;
        while (nt-- > 0) {
            int n, res = 0;
            f >> n;
            if (n < 2) {
                cout << 1 << endl;
                continue;
            }
            for (int i = 0; i*i < n/2; i++) {
                int j = n - i*i;
                int root = floor(sqrt(j));
                if (root * root == j) {
                    res++;
                    //cout << i << "^2 + " << root << "^2 = " << n << ";";
                }
            }
            cout << res << endl;
        }
    }
}

