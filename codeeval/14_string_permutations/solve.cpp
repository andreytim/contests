// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

bool first;

void permutations(string line, const string& curr) {
    if (line.length() > 0) {
        for (int i = 0; i < line.length(); i++) {
            permutations(
                line.substr(0, i) + line.substr(i + 1, line.length() - i), 
                curr + line[i]);
        }
    } else {
        if (!first) cout << ",";
        first = false;
        cout << curr;
    }
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        sort(line.begin(), line.end());
        first = true;
        permutations(line, "");
        cout << endl;
    }
}

