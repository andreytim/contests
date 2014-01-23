// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool check_line(const string &line) {
    int po_count = 0, so_count = 0, sc_count = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '(') {
            if (i > 0 && line[i-1] == ':') so_count++;
            else po_count++;
        } else if (line[i] == ')') {
            if (i == 0 || line[i-1] != ':') {
                if (po_count == 0 && so_count == 0) return false;
                else if (po_count > 0) po_count--; 
                else so_count--;
            } else sc_count++;
        }
    }
    return (po_count - sc_count <= 0 ? true : false);
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        cout << (check_line(line) ? "YES" : "NO") << endl;
    }
}
