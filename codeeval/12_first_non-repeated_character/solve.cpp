// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <string>
#include <ext/hash_map>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            __gnu_cxx::hash_map<char, int> counts;
            for (int i = 0; i < line.length(); i++) {
                if (counts.find(line[i]) == counts.end()) {
                    counts.insert(pair<char, int>(line[i], 0));
                }
                counts[line[i]]++;
            }
            for (int i = 0; i < line.length(); i++) {
                if (counts[line[i]] == 1) {
                    cout << line[i] << endl;
                    break;
                }
            }
        }
    }
}

