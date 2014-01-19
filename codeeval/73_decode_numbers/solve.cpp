// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        if (line.length() == 1) { cout << "1" << endl; continue; }
        if (line.empty()) continue;
        vector<int> v(2,1);
        for (int i = 1; i < line.length(); i++) {
            if ((line[i] < '7' && line[i - 1] == '2') || (line[i - 1] == '1')) {
                v.push_back(v.back() + v[v.size() - 2]);
            } else {
                v.push_back(v.back());
            }
        }
        cout << v.back() << endl;
    }
}

