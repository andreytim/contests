// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

long long solve(const string &str) {
    stringstream ss(str);
    string item;
    int x, n;
    getline(ss, item, ',');
    istringstream iss1(item);
    iss1 >> x;
    getline(ss, item, ',');
    istringstream iss2(item);
    iss2 >> n;

    int dim = -1, i = 1;
    long long nn = n;
    while (n > 0) { dim++; n >>= 1; }
    while (nn < x) { nn = i++ << dim; }
    return nn;
}

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string l;
        while (getline(f, l)) {
            cout << solve(l) << endl;
        }
    }
    f.close();
}

