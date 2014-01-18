// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
    string name;
    set<string> ordered_names;
    ifstream f("names.txt");
    if (f.is_open()) {
        while (getline(f, name, ',')) {
            ordered_names.insert(name);
        }
        f.close();
    }
    int total = 0, k = 1;
    for (set<string>::const_iterator it = ordered_names.begin(); it != ordered_names.end(); it++, k++) {
        for (int i = 1; i < (*it).size() - 1; i++) { 
            total += ((*it)[i] - 'A' + 1) * k; 
        }
    }
    cout << total << endl;
}

