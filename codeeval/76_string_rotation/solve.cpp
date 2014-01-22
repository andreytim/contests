// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        string str1, str2; stringstream ss(line);
        getline(ss, str1, ',');
        getline(ss, str2, ',');
        if (str1.length() != str2.length()) {
            cout << "False" << endl;
        }
        int i;
        for (i = 0; i < str1.length(); i++) {
            int j;
            for (j = 0; j < str2.length(); j++) {
                if (str1[(i + j) % str1.length()] != str2[j]) {
                    break;
                }
            }
            if (j == str2.length()) break;
        }
        if (i == str1.length()) cout << "False" << endl;
        else cout << "True" << endl;
    }
}
