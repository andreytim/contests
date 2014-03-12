// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    long long n;
    while (cin >> n) {
        char op, c; cin >> c;
        while (c != '+' && c != '-') cin >> c;
        op = c; cin >> c;
        string s; getline(cin, s);
        int d = pow(10.0, (double) s.length() + 1);
        if (op == '+')
            cout << (n / d + n % d) << endl;
        else
            cout << (n / d - n % d) << endl;
    }
}

