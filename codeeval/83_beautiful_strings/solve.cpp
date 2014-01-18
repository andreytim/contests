// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int CalcBeauty(string &str) {
    int counts[26] = { 0 };
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            counts[str[i] - 'a']++;
        }
    }
    sort(counts, counts + 26);
    int mult = 26, i = 25, beauty = 0;
    while (counts[i] > 0 && i >= 0) {
        beauty += counts[i] * mult;
        i--;
        mult--;
    }
    return beauty;
}

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string l;
        while (getline(f, l)) {
            transform(l.begin(), l.end(), l.begin(), ::tolower);
            cout << CalcBeauty(l) << endl;
        }
    }
    f.close();
}
