// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

enum Ops { NONE, PLUS = '+', MINUS = '-' };

bool is_ugly(long long n) {
    return n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0;
}

long long read_number(const vector<char>& str, int* pos) {
    long long res = 0;
    while (isdigit(str[*pos]) && (*pos) < str.size()) res = res*10 + (str[(*pos)++] - '0');
    return res;
}

long long eval(const vector<char>& str) {
    int i = 0;
    long long res = read_number(str, &i);
    while (i < str.size()) {
        Ops op = Ops(str[i++]);
        long long next = read_number(str, &i);
        if (op == PLUS) res += next;
        else res -= next;
    } 
    return res;
}

int rec_count(const string& str, vector<char>& expr, int i) {
    if (i == str.length()) {
        long long res = eval(expr);
        return is_ugly(res) ? 1 : 0;
    } else {
        expr.push_back(str[i]);
        int count = rec_count(str, expr, i+1);
        expr.pop_back(); 
        expr.push_back('+'); expr.push_back(str[i]);
        count += rec_count(str, expr, i+1);
        expr.pop_back(); expr.pop_back();
        expr.push_back('-'); expr.push_back(str[i]);
        count += rec_count(str, expr, i+1);
        expr.pop_back(); expr.pop_back();
        return count;
    }
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        vector<char> expr(1, line[0]);
        cout << rec_count(line, expr, 1) << endl;
    }
}

