// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <string>
#include <ext/hash_set>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            line.erase(0, line.find_first_not_of(' '));
            __gnu_cxx::hash_set<char> to_delete;
            for (int i = line.find(", ") + 2; i < line.length(); i++) {
                to_delete.insert(line[i]);
            }
            for (int i = 0; i < line.find(", "); i++) {
                if (to_delete.find(line[i]) == to_delete.end()) {
                    cout << line[i]; 
                }
            }
            cout << endl;
        }
    }
}

