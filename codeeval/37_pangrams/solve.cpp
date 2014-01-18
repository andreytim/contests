// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
           vector<bool> letters(26, false);
           for (int i = 0; i < line.length(); i++) {
                char ch = line[i];
                if (ch >= 'A' && ch <= 'Z') letters[ch - 'A'] = true;
                else if (ch >= 'a' && ch <= 'z') letters[ch - 'a'] = true;
            }
            int count = 0;
            for (int i = 0; i < letters.size(); i++) {
                if (!letters[i]) {
                    count++;
                    cout << (char)('a' + i);
                }
            }
            if (count == 0) cout << "NULL";
            cout << endl;
        }
    }
}

