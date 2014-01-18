// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string LongestWord(const string &str) {
    stringstream ss(str);
    string item, maxs;
    int maxl = 0;
    while (getline(ss, item, ' ')) {
        if (item.length() > maxl) {
            maxl = item.length();
            maxs = item;
        }
    }
    return maxs;
}

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    string line;
    if (f.is_open()) {
        while (getline(f, line)) {
            cout << LongestWord(line) << endl;
        }
    } else {
        cout << "Unable to open the file!\n";
    }
}
