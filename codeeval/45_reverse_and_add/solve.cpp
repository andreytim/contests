// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int reverse(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        int n;
        while (f >> n) {
            int r = reverse(n), count = 0;
            while (n != r) {
                n += r;
                r = reverse(n);
                count++;
            }
            cout << count << " " << n << endl;
        }
    }
}

