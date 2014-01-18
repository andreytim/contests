// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

bool IsArmstrongNumber(string &strn) {
    int N = strn.length();
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += pow(strn[i] - '0', N);
    }
    istringstream iss(strn);
    int n;
    iss >> n;
    return n == total;
}

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string l;
        while (getline(f, l)) {
            cout << (IsArmstrongNumber(l) ? "True" : "False") << endl;
        }
    } else {
        cout << "Unable to open the file!" << endl;
    }
    f.close();
    return 0;
}
