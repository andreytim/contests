// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    vector<int> prev(2, 0);
    while (getline(cin, line)) {
        stringstream ss(line);
        int n, i = 0;
        vector<int> next(1, 0); 
        //cout << 0 << " ";
        while (ss >> n) { 
            next.push_back(max(prev[i] + n, prev[i+1] + n));
            i++; 
            //cout << next.back() << " ";
        }
        next.push_back(0);
        //cout << 0 << endl;
        prev = next;
    }
    cout << *max_element(prev.begin(), prev.end()) << endl;
}

