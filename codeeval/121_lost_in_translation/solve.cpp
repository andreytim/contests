// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <string>
#include <ext/hash_map>

using namespace std;

__gnu_cxx::hash_map<char, char> tr;

void init_map() {
    tr['a'] = 'y'; tr['b'] = 'h'; tr['c'] = 'e';
    tr['d'] = 's'; tr['e'] = 'o'; tr['f'] = 'c';
    tr['g'] = 'v'; tr['h'] = 'x'; tr['i'] = 'd';
    tr['j'] = 'u'; tr['k'] = 'i'; tr['l'] = 'g';
    tr['m'] = 'l'; tr['n'] = 'b'; tr['o'] = 'k';
    tr['p'] = 'r'; tr['q'] = 'z'; tr['r'] = 't';
    tr['s'] = 'n'; tr['t'] = 'w'; tr['u'] = 'j';
    tr['v'] = 'p'; tr['w'] = 'f'; tr['x'] = 'm';
    tr['y'] = 'a'; tr['z'] = 'q';
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    init_map();
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            cout << (line[i] == ' ' ? ' ' : tr[line[i]]);
        }
        cout << endl;
    }
}

