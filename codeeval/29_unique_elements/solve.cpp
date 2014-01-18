// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> RemoveDups(const string &str) {
    vector<string> res;
    stringstream ss(str);
    string item;
    string prev = "";
    while (getline(ss, item, ',')) {
        if (prev != item) {
            res.push_back(item);
        }
        prev = item;
    }
    return res;
}

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    string line;
    if (f.is_open()) {
        while(getline(f, line)) {
            vector<string> no_dups = RemoveDups(line);
            for (int i = 0; i < no_dups.size() - 1; i++) {
                cout << no_dups[i] << ",";
            }
            cout << no_dups[no_dups.size() - 1] << endl;
        }
    }
}
