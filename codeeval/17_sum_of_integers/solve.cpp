// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            stringstream ss(line);
            vector<int> v;
            string item;
            while (getline(ss, item, ',')) {
                stringstream iss(item);
                int n;
                iss >> n;
                v.push_back(n);
            }
            int curr_s = 0, max_s = INT_MIN;
            for (int i = 0; i < v.size(); i++) {
                if (curr_s < 0) {
                    curr_s = 0;
                }
                curr_s += v[i];
                max_s = max(max_s, curr_s);
            }
            cout << max_s << endl;
        }
    }
}
