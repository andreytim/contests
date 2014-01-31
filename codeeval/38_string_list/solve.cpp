// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

bool not_first = false;

void recperm(const set<char>& chars, const string& str, int lim) {
    if (str.length() == lim) {
        if (not_first) cout << ",";
        else not_first = true;
        cout << str;
    } else {
        for (set<char>::const_iterator it = chars.begin(); it != chars.end(); it++) {
            recperm(chars, str + *it, lim);
        }
    }
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        not_first = false;
        stringstream ss(line);
        int n; ss >> n; ss.ignore();
        set<char> chars; char ch; 
        while (ss >> ch) chars.insert(ch);
        recperm(chars, "", n);
        cout << endl;      
    }
}

