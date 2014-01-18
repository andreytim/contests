// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            stringstream ss(line);
            string s1, s2;
            getline(ss, s1, ',');
            getline(ss, s2, ',');
            if (s1.length() >= s2.length()) {
                if (s1.substr(s1.length() - s2.length()) == s2) {
                    cout << "1" << endl;
                } else {
                    cout << "0" << endl;
                }
            }
        }
    }
}
