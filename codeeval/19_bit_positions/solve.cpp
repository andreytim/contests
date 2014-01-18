// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool solve(const string &str) {
    stringstream ss(str);
    string item;
    int x, p1, p2;
    getline(ss, item, ',');
    istringstream iss1(item);
    iss1 >> x;
    getline(ss, item, ',');
    istringstream iss2(item);
    iss2 >> p1;
    getline(ss, item, ',');
    istringstream iss3(item);
    iss3 >> p2;
    
    return ((x & (1 << (p1 - 1))) == 0) == ((x & (1 << (p2 - 1))) == 0);
}

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string l;
        while (getline(f, l)) {
            cout << boolalpha << solve(l) << endl;
        }
    }
    f.close();
}

