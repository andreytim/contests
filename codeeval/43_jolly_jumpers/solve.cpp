// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            stringstream nums(line);
            int n, curr, prev; nums >> n; 
            if (n > 1) {
                nums >> prev;
                int v[n];
                fill(v, v + n, 0);
                while (nums >> curr) {
                    v[abs(curr - prev)] = 1;
                    prev = curr;
                }
                int i;
                for (i = 1; i < n; i++) {
                    if (v[i] == 0) break;
                }
                if (i != n) cout << "Not jolly" << endl;
                else cout << "Jolly" << endl;
            } else {
                cout << "Jolly" << endl;
            }
        }
    }
}

