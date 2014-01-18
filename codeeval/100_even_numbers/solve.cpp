// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string l;
        while (getline(f, l)) {
            istringstream iss(l);
            int n;
            iss >> n;
            cout << !(n & 1) << endl;
        }
    }
    f.close();
}
