// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int n = 0, curr = 0, counter = 1;
        ss >> curr;
        while (ss >> n) {
            if (n != curr) { 
                cout << counter << " " << curr << " ";
                curr = n;
                counter = 1;
            } else counter++;
        }
        cout << counter << " " << curr << endl;
    }
}
