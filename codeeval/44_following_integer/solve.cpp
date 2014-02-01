// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        bool inversion_found = false;
        for (int i = line.length()-2; i >= 0; i--) {
            if (line[i] < line[i+1]) {
                inversion_found = true;
                int min = i+1, minn = line[i+1];
                for (int j = i+2; j < line.length(); j++) {
                    if (line[j] < minn && line[j] > line[i]) {
                        min = j;
                        minn = line[j];
                    }
                }
                line[i] ^= line[min];
                line[min] ^= line[i];
                line[i] ^= line[min];
                sort(line.begin() + i + 1, line.end());
                break;
            }
        }
        if (inversion_found) {
            cout << line << endl;
        } else {
            sort(line.begin(), line.end());
            int j = 0;
            while (line[j] == '0') j++;
            if (j > 0) {
                line[0] = line[j];
                line[j] = '0';
            }
            cout << line[0]; cout << '0';
            for (int i = 1; i < line.length(); i++) {
                cout << line[i];
            }
            cout << endl;
        }
    }   
}
