// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int fact(int n) {
    return (n < 2) ? 1 : n * fact(n-1);
}

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            if (!line.empty()) {
                int N = 0, S = 0, P = 1;
                stringstream ss(line);
                string nstr, vstr; 
                getline(ss, nstr, ';'); getline(ss, vstr, ';');
                stringstream nss(nstr); nss >> N;
                if (N > 2) {
                    stringstream vss(vstr); string vel;
                    while (getline(vss, vel, ',')) {
                        stringstream elss(vel);
                        int el; elss >> el;
                        S += el + 1;
                        P += (el + 1)*(el + 1);
                    }
                    int X = N * (N + 1) / 2 - S;
                    int Y = (N * (N + 1) * (2*N + 1) / 6 - P) / X;
                    cout << (Y - X) / 2 << endl;
                }
            }
        }
    }
}

