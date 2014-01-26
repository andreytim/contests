// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <sstream>
#include <ext/hash_map>
#include <ext/hash_set>

using namespace std;
using namespace __gnu_cxx;

const int BEGIN = 0;
const int END = 1;

bool check_chain(hash_map<int,int>* chain) {
    hash_set<int> visited;
    int curr = (*chain)[BEGIN];
    int size = 1;
    while (curr != END) {
        int next = (*chain)[curr];
        if (visited.find(next) != visited.end()) return false;
        visited.insert(next);
        curr = next;
        size++;
    }
    return size == chain->size();
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        hash_map<int,int> chain;
        char ch;
        int curr_src;
        bool dst = false;
        while (ss >> ch) {
            int val;
            if (ch >= '0' && ch <= '9') {
                ss.putback(ch);
                ss >> val;
            } else if (ch == 'B') { ss >> ch; ss >> ch; val = BEGIN; }
            else if (ch == 'E') val = END;
            else continue;
            if (dst) {
                chain[curr_src] = val;
                dst = false;
            } else {
                curr_src = val;
                dst = true;
            }
        }
        cout << (check_chain(&chain) ? "GOOD" : "BAD") << endl;
    }
}
