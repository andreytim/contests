// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f,line)) {
            for (int i = 0; i < line.length(); i++) {
                if ((i == 0 || (i > 0 && line[i - 1] == ' ')) && line[i] >= 'a' && line[i] <= 'z') {
                    line[i] = line[i] - 'a' + 'A';
                }
            }
            cout << line << endl;
        }
        f.close();
    }
}
