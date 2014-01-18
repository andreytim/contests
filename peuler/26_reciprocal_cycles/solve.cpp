// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int LIMIT = 1000;

int GetCycleSize(int n) {
    vector<int> checked;
    int num = 1, denom = n;
    cout << "n: " << n << " --- ";
    cout << "0.";
    while (true) {
        num *= 10;
        int digit = num / n;
        cout << digit;
        if (find(checked.begin(), checked.end(), num) == checked.end()) {
            checked.push_back(num);
        } else {
            int csize = distance(find(checked.begin(), checked.end(), num), checked.end());
            cout << num << "; cycle detected, size = " << csize << endl;
            return csize;
        }
       if (digit != 0) {
            num -= n * digit;
            if (num == 0) break;
        }
    }
    cout << endl;
    return 0;
}

int main() {
    int msize = 0, mn = 1;
    for (int i = 2; i < 1000; i++) {
        int size = GetCycleSize(i);
        if (size > msize) { msize = size; mn = i; }
    }
    cout << mn << " - " << msize << endl;
}

