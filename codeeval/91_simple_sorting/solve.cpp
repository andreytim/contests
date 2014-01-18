// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

multiset<float> GetSorted(const string &str) {
    multiset<float> res;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ' ')) {
        float val;
        istringstream ss(item);
        ss >> val;
        res.insert(val);
    }
    return res;
}

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    string line;
    if (f.is_open()) {
        while(getline(f, line)) {
            multiset<float> sorted = GetSorted(line);
            multiset<float>::const_iterator it;
            for (it = sorted.begin(); it != --sorted.end(); it++) {
                cout << fixed << setprecision(3) << *it << " ";
            }
            cout << fixed << std::setprecision(3) << *it <<  endl;
        }
    }
}
