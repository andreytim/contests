// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <ext/hash_set>

using namespace std;
using namespace __gnu_cxx;

int IsHappyOne(int n) {
    hash_set<int> used;
    int curr = n;
    while (used.find(curr) == used.end() && curr != 1) {
        used.insert(curr);
        int digit_squares_sum = 0;
        while (curr > 0) {
            digit_squares_sum += pow(curr % 10, 2);
            curr /= 10;
        }
        curr = digit_squares_sum;
    }
    return (curr == 1) ? 1 : 0;
}

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            int n;
            istringstream iss(line);
            iss >> n;
            cout << IsHappyOne(n) << endl;
        }
    } else {
        cout << "Unable to open the file!" << endl;
    }
    return 0;
}

