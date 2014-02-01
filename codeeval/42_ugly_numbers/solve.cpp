// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

enum Ops { NONE, PLUS = '+', MINUS = '-' };

bool is_ugly(long long n) {
    return n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0;
}

long long read_number(const string& str, int* pos) {
    long long res = 0;
    while (isdigit(str[*pos])) res = res*10 + (str[(*pos)++] - '0');
    return res;
}

long long eval(const string& str) {
    int i = 0;
    long long res = read_number(str, &i);
    while (i < str.length()) {
        Ops op = Ops(str[i++]);
        long long next = read_number(str, &i);
        if (op == PLUS) res += next;
        else res -= next;
    } 
    return res;
}

int rec_count(const string& str, const string& expr, int i) {
    if (i == str.length()) {
        long long res = eval(expr);
        return is_ugly(res) ? 1 : 0;
    } else {
        return rec_count(str, expr + str[i], i+1) +
            rec_count(str, expr + '+' + str[i], i+1) +
            rec_count(str, expr + '-' + str[i], i+1);
    }
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        cout << rec_count(line, string(1, line[0]), 1) << endl;
    }
}

