// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    int depth;
    while (cin >> depth) {
        int init_arr[3] = { 0, 1, 0 };
        vector<int> level(init_arr, init_arr + 3);
        for (int i = 0; i < depth; i++) {
            for (int k = 1; k < level.size() - 1; k++) {
                cout << level[k] << " ";
            }
            vector<int> next_level;
            next_level.push_back(0);
            for (int k = 0; k < level.size() - 1; k++) {
                next_level.push_back(level[k] + level[k + 1]);
            }
            next_level.push_back(0);
            level = next_level;
        }
        cout << endl;
    }
}

